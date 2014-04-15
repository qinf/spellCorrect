/*
 * ProduceThread.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include "ProduceThread.h"
#include <stdlib.h>

ProduceThread::ProduceThread(WorkingQueue *queue): _tid(0), _queue(queue) {
	// TODO Auto-generated constructor stub
	srand(time(NULL));
}
ProduceThread::~ProduceThread() {

}
void ProduceThread::start() {
	pthread_create(&_tid, NULL, thread_func, this);//为啥要传一个this
}
void *ProduceThread::thread_func(void *arg) {
	ProduceThread* a_thread = static_cast<ProduceThread*>(arg);
	a_thread->run();
	return NULL;
}
void ProduceThread::run() {
	while(true) {
		int ret = rand()%100;
		_queue->produce(ret);
		std::cout << "produce a number: " << ret << std::endl;
		sleep(1);
	}
}
void ProduceThread::jion() {
	pthread_join(_tid, NULL);
}

