/*************************************************************************
 > File Name: WorkThread.cpp
 > Author: qinf
 > Mail:
 > Created Time: 2014年05月04日 星期日 15时47分51秒
 ************************************************************************/

#include "WorkThread.h"
#include "ThreadPool.h"
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "server_client_func.h"
#include "UDPServer.h"
#include "EncodingConverter.h"

void WorkThread::run() {
	//process task
	while (true) {
		process_task();
	}
}
void WorkThread::process_task() {
	//任务队列是否为空
	Task task;
	struct sockaddr_in addr;

	EditDistance edit_dis;
	if (!_p_thread_pool->is_task_queue_empty()) {
		_p_thread_pool->get_task_from_pool(task);
		addr = task._addr;

		//待处理,找到map映射文件
		string map_file;
		string conf_file =
				"/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
		Tools tools(conf_file);
		map_file = tools.get_word_map_file_path();
		map<std::string, int> word_map = _p_thread_pool->get_dirct()->get_map(); //获取word_map
//				_p_thread_pool->get_dirct()->get_word_map(map_file); //这里是重新建立了map

		std::string correct_word;
		//查询Cache中是否存在
		string key = task.get_task();
		if (_cache.is_key_in_map(key)) {
			correct_word = _cache.get_hash_map_value(key);
			cout << "cache test --------" << endl;
		} else {
			map<std::string, int>::iterator iter = word_map.begin();
			int min = 9999, count;

			for (; iter != word_map.end(); ++iter) {
				//先找一个最小的即可
				count = edit_dis.get_edit_distance(key, iter->first);
				if (count < min) {
					min = count;
					correct_word = iter->first;
				}
			}
			//将新查询放入缓存
			//std::cout <<"______________________"<<__TIME__ << std::endl ;
			_cache.add_to_hash_map(key, correct_word);
			cout << "key :" << key << " value: "
					<< _cache.get_hash_map_value(key) << endl;
		}

		//向客户端发送正确的单词
		int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
		if (-1 == socket_fd)
			Log::get_instance()->write("send right word to client failed!");
		//发送数据
		char *send_buf = new char[1024];
		memset(send_buf, 0, 1024);

		strcpy(send_buf, correct_word.c_str());

		EncodingConverter trans;
		cout << "WorkThread:" << trans.gbk_to_utf8(string(send_buf)) << endl;

		if (-1
				== sendto(socket_fd, send_buf, strlen(send_buf), 0,
						(struct sockaddr*) &addr, sizeof(addr)))
			Log::get_instance()->write(
					"workThread send data to client failed!");
		close(socket_fd);
	}
}

Cache WorkThread::get_cache() {
	return _cache;
}

void WorkThread::regist_thread_pool(ThreadPool *p_thread_pool) {
	_p_thread_pool = p_thread_pool;
}
