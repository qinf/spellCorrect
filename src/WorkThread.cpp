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
#include <iostream>

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
		//使用索引不再使用原来的map
//		map<std::string, int> word_map = _p_thread_pool->get_dirct()->get_map(); //获取word_map
//				_p_thread_pool->get_dirct()->get_word_map(map_file); //这里是重新建立了map

//获取索引的相关数据结构
		std::vector<std::pair<std::string, int> > *p_word_vec =
				_p_thread_pool->get_dirct()->get_word_vec();
		std::unordered_map<std::uint16_t, std::set<int> > *p_index_map =
				_p_thread_pool->get_dirct()->get_index_map();

		std::string correct_word;
		//查询Cache中是否存在
		string key = task.get_task();
		if (_cache.is_key_in_map(key)) {
//			std::cout << "cached !" << std::endl ;
			correct_word = _cache.get_hash_map_value(key);
		} else {
			//修改查询逻辑，使用索引数据结构

//			map<std::string, int>::iterator iter = word_map.begin();
//			int min = 9999, count;
//
//			for (; iter != word_map.end(); ++iter) {
//				//先找一个最小的即可
//				count = edit_dis.get_edit_distance(key, iter->first);
//				if (count < min) {
//					min = count;
//					correct_word = iter->first;
//				}
//			}

			uint16_t first; //查询词的首字母或者第一个汉字
			if (key[0] >= 0x81 && key[0] <= 0xFE) { //是汉字，则取前两个字符
				first = key[0] << 8 + key[1];
			} else {
				first = key[0];
			}
			std::unordered_map<std::uint16_t, std::set<int> >::iterator index_iter = p_index_map->find(first);
			if(index_iter != p_index_map->end()) {
				set<int> word_set = index_iter->second;
				int min = 9999, count; //min记录最小的编辑距离
				for(set<int>::iterator it = word_set.begin(); it != word_set.end(); ++it) {
					count = edit_dis.get_edit_distance(key, (*p_word_vec)[*it].first);
					if (count < min) {
						min = count;
						correct_word = (*p_word_vec)[*it].first;
					}
				}
			} else {
				//未检索到key，则原值返回
				correct_word = key;
			}

			//将新查询放入缓存
			//std::cout <<"______________________"<<__TIME__ << std::endl ;
			_cache.add_to_hash_map(key, correct_word);
			cout << "key :" << key << " value: "
					<< _cache.get_hash_map_value(key) << "size: " << _cache.get_word_hash_map_size() << endl;
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

Cache& WorkThread::get_cache() {
	std::cout << "workthread cache size: " << _cache.get_word_hash_map_size() << std::endl;
	return _cache;
}

void WorkThread::regist_thread_pool(ThreadPool *p_thread_pool) {
	_p_thread_pool = p_thread_pool;
}
