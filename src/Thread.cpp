/*************************************************************************
	> File Name: Thread.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时16分59秒
 ************************************************************************/

#include "Thread.h"
#include <iostream>

Thread::Thread(): _tid(0) {
	
}
Thread::~Thread() {
	
}
void *Thread::thread_func(void* arg) {
	Thread* a_thread = static_cast<Thread*>(arg);
	a_thread->run();
	return NULL;
}
void Thread::start() {
	pthread_create(&_tid, NULL, Thread::thread_func, this);
}
void Thread::join() {
	pthread_join(_tid, NULL);
}
