/*
 * ConsumeThread.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include "ConsumeThread.h"
#include <stdlib.h>

ConsumeThread::ConsumeThread(WorkingQueue *queue) : _tid(0), _queue(queue){
	// TODO Auto-generated constructor stub
}
ConsumeThread::~ConsumeThread() {

}
void ConsumeThread::start() {
	pthread_create(&_tid, NULL, thread_func, this);
}
void *ConsumeThread::thread_func(void *arg) {
	ConsumeThread *a_thread = static_cast<ConsumeThread*>(arg);
	a_thread->run();
	return NULL;
}
void ConsumeThread::run() {
	while(true) {
		int iret = _queue->consume();
		std::cout << "consume a number: " << iret << std::endl;
		sleep(1);
	}
}
void ConsumeThread::jion(){
	pthread_join(_tid, NULL);
}

