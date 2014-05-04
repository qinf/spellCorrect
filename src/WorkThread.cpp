/*************************************************************************
	> File Name: WorkThread.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时47分51秒
 ************************************************************************/

#include "WorkThread.h"
#include "ThreadPool.h"

void WorkThread::run() {
	//process task
}
void WorkThread::process_task() {

}
void WorkThread::regist_thread_pool(ThreadPool *p_thread_pool) {
	_p_thread_pool = p_thread_pool;
}
