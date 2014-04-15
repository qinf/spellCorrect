/*
 * ConsumeThread.h
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#ifndef CONSUMETHREAD_H_
#define CONSUMETHREAD_H_

#include <pthread.h>
#include "WorkingQueue.h"
#include <iostream>

class ConsumeThread {
public:
	ConsumeThread(WorkingQueue *queue);
	~ConsumeThread();
	void start();
	static void *thread_func(void *arg);
	void run();
	void jion();
private:
	pthread_t _tid;
	WorkingQueue* _queue;
};

#endif /* CONSUMETHREAD_H_ */
