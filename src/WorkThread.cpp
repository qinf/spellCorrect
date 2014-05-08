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

void WorkThread::run() {
	//process task
	while(true) {
		process_task();
	}
}
void WorkThread::process_task() {
	//任务队列是否为空
	Task task;
	struct sockaddr_in addr;
//	addr = task.get_addr();

	EditDistance edit_dis;
	//cout << "test queue size: " << _p_thread_pool->get_task_queue_size() << endl;
	if(!_p_thread_pool->is_task_queue_empty()) {
		//cout << "pool size: " << _p_thread_pool->get_task_queue_size() << endl;
		_p_thread_pool->get_task_from_pool(task);
		addr = task._addr;
		//cout << "from WorkThread: " <<task.get_task() << endl;

		//输出地址
		//cout << "process task: addr = " << addr.sin_addr.s_addr << endl;

		//待处理,找到map映射文件
		string map_file;
		string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
		Tools tools(conf_file);
		map_file = tools.get_word_map_file_path();
		map<std::string, int> word_map = _p_thread_pool->get_dirct()->get_word_map(map_file);

		//cout << "map size: " << word_map.size() << endl;

		map<std::string, int>::iterator iter = word_map.begin();
		int min = 9999, count;
		std::string correct_word;
		for(; iter != word_map.end(); ++iter) {
			//先找一个最小的即可
			count = edit_dis.get_edit_distance(task.get_task(), iter->first);
			//cout << "wordThread edit distance : " << iter->first << endl;
			if(count < min) {
				min = count;
				//cout << "min = " << min << endl;
				correct_word = iter->first;
			}
		}

		//向客户端发送正确的单词
		int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
		if(-1 == socket_fd)
			Log::get_instance()->write("send right word to client failed!");
		//发送长度
		int len = correct_word.size();
		int i = sendto(socket_fd, &len, sizeof(int), 0, (struct sockaddr*)&addr, sizeof(addr));
		//cout << "i =" << i << endl;
		//cout << "correct_word len = " << len << endl;
		//发送数据
		char *send_buf = new char[correct_word.size()+1];
		memset(send_buf, 0, correct_word.size()+1);
		strcpy(send_buf, correct_word.c_str());
		//cout << "edit correct word : "  << send_buf << endl;
		int sum = sendn(socket_fd, send_buf, len, addr);
		//cout << "sum = " << sum << endl;
		close(socket_fd);
	}
}
void WorkThread::regist_thread_pool(ThreadPool *p_thread_pool) {
	_p_thread_pool = p_thread_pool;
}
