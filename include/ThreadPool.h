/*************************************************************************
	> File Name: ThreadPool.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时37分42秒
 ************************************************************************/

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include "noncopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include "dirct.h"
#include "Tools.h"
#include "WorkThread.h"
#include <string>
#include "Task.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <queue>
using namespace std;

class ThreadPool: public noncopyable {
public:
	ThreadPool(vector<WorkThread>::size_type max_thread);
	~ThreadPool();
	void start_thread_pool();
	void stop_thread_pool();
	bool add_task_to_pool(Task task);
	bool get_task_from_pool(Task &task);
	bool is_task_queue_empty();
	Dirct *get_dirct();
	queue<Task>::size_type get_task_queue_size() const;
private:
	queue<Task> _task_queue; //任务队列
	vector<WorkThread>::size_type _max_thread; //工作线程集大小
	vector<WorkThread> _thread_vector; //存储线程
	bool is_started; //线程池是否开启
	Dirct *_dirct; //词典指针
	MutexLock _lock;
	Condition _cond;
};

#endif /* THREADPOOL_H_ */
