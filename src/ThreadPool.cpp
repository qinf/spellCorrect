/*************************************************************************
 > File Name: ThreadPool.cpp
 > Author: qinf
 > Mail:
 > Created Time: 2014年05月04日 星期日 15时47分10秒
 ************************************************************************/

#include "ThreadPool.h"
#include "Tools.h"

ThreadPool::ThreadPool(vector<WorkThread>::size_type max_thread) :
		_task_queue(), _max_thread(max_thread), _thread_vector(_max_thread), is_started(
				false), _lock(), _cond(&_lock), _scan_thread(0) {
	for (vector<WorkThread>::iterator iter = _thread_vector.begin();
			iter != _thread_vector.end(); ++iter)
		iter->regist_thread_pool(this); //将自己反注册到工作线程中
}
ThreadPool::~ThreadPool() {
	stop_thread_pool();
}

void ThreadPool::start_thread_pool() {
	is_started = true;

	//建立词典
	_dirct = Dirct::get_instance();
	string conf_file =
			"/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	Tools *tools = new Tools(conf_file);
	//gbk_word_map
	string gbk_word_map_file_path = tools->get_gbk_word_map_file_path();
//	_dirct->get_word_map(gbk_word_map_file_path); //注释掉

	//建立索引
	_dirct->build_index(gbk_word_map_file_path);

	//开启工作线程
	for (vector<WorkThread>::iterator iter = _thread_vector.begin();
				iter != _thread_vector.end(); ++iter)
			iter->start();

	//开启扫描线程
	pthread_create(&_scan_thread, NULL, scan_thread_save_cache, this);
}

void *ThreadPool::scan_thread_save_cache(void *arg) {
	ThreadPool* p_thread_pool = static_cast<ThreadPool*>(arg);
	vector<WorkThread> work_threads = p_thread_pool->_thread_vector;
	//遍历工作线程vector，将每个vector中的cache存储到系统cache文件中
	//1.读配置文件，获取cache文件位置，然后
	Tools tools;
	string cache_file = tools.get_cache_file_path();
	//2.遍历线程vector，扫描cache并存储，如果处理合并cache？
	while (true) {
		//每隔5分钟遍历,先使用5秒钟进行测试
		cout << "scan thread save cache" << endl;
		sleep(5);
		for (vector<WorkThread>::iterator iter = work_threads.begin();
				iter != work_threads.end(); ++iter) {
			//将workthread中的cache写入到cache文件中
			//std::unordered_map<std::string, std::string> word_hash_map = iter->get_cache().get_map();
			Cache cache = iter->get_cache();
			ifstream infile(cache_file);
			string line;
			getline(infile, line);
			int pos;
			while(string::npos != (pos = line.find("\t"))) {
				string key = line.substr(0, pos);
				string value = line.substr(pos);
				if(!cache.is_key_in_map(key)) {
					cache.add_to_hash_map(key, value);
				}
				getline(infile, line);
			}
			infile.close();

			//将线程中的cache写入系统cache文件
			ofstream  outfile(cache_file);
			std::unordered_map<std::string, std::string> word_hash_map = iter->get_cache().get_map();
			std::unordered_map<std::string, std::string>::iterator iter1 = word_hash_map.begin();
			for(; iter1 != word_hash_map.end(); ++iter1) {
				outfile << iter1->first << "\t" << iter1->second << endl;
			}
			outfile.close();
		}
	}
	return NULL;
}

void ThreadPool::stop_thread_pool() {
	if (is_started == false)
		return;
	if (is_started == true) {
		is_started = false;
		_cond.notify_all();
		for (vector<WorkThread>::iterator iter = _thread_vector.begin();
				iter != _thread_vector.end(); ++iter)
			iter->join();
	}
	while (!_task_queue.empty()) {
		_task_queue.pop();
	}
}

bool ThreadPool::add_task_to_pool(Task task) {
	_lock.lock();
	_task_queue.push(task);
	_lock.unlock();
	_cond.notify_all();
	return true;
}

bool ThreadPool::get_task_from_pool(Task &task) {
	_lock.lock();
	while (is_started && _task_queue.empty())
		_cond.wait();
	if (!is_started) {
		_lock.unlock();
		_cond.notify_all();
	} else if (!_task_queue.empty()) {
		task = _task_queue.front();
		_task_queue.pop();
		_lock.unlock();
	}
	return true;
}

bool ThreadPool::is_task_queue_empty() {
	return _task_queue.empty();
}

queue<Task>::size_type ThreadPool::get_task_queue_size() const {
	return _task_queue.size();
}

Dirct *ThreadPool::get_dirct() {
	return _dirct;
}
