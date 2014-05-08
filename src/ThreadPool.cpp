/*************************************************************************
	> File Name: ThreadPool.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时47分10秒
 ************************************************************************/

#include "ThreadPool.h"

ThreadPool::ThreadPool(vector<WorkThread>::size_type max_thread):
	_task_queue(), _max_thread(max_thread), _thread_vector(_max_thread), is_started(false), _lock(), _cond(&_lock){
	for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
		iter->regist_thread_pool(this); //将自己反注册到工作线程中
}
ThreadPool::~ThreadPool() {
	stop_thread_pool();
}

void ThreadPool::start_thread_pool() {
	is_started = true;
	for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
		iter->start();
	//建立词典
	_dirct = Dirct::get_instance();
	string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	Tools *tools = new Tools(conf_file);
	string word_map_file_path = tools->get_word_map_file_path();
	_dirct->get_word_map(word_map_file_path);
}

void ThreadPool::stop_thread_pool() {
	if (is_started == false)
		return;
	if (is_started == true)	{
		is_started = false;
		_cond.notify_all();
		for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
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
	while(is_started && _task_queue.empty())
		_cond.wait();
	if(!is_started) {
		_lock.unlock();
		_cond.notify_all();
	} else if(!_task_queue.empty()) {
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
