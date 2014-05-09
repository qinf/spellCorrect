/*************************************************************************
	> File Name: WorkThread.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时47分37秒
 ************************************************************************/

#ifndef WORKTHREAD_H_
#define WORKTHREAD_H_

#include "Thread.h"
#include "EditDistance.h"
#include "Log.h"

class ThreadPool;

class WorkThread: public Thread { //可复制
public:
	void run(); //真正处理任务的函数
	void process_task(); //去哪里找线程池
	void regist_thread_pool(ThreadPool *p_thread_pool);
	void get_udp_server_fd(int server_fd);
private:
	ThreadPool *_p_thread_pool;
};

#endif /* WORKTHREAD_H_ */
