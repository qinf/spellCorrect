/*
 * ProduceThread.h
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#ifndef PRODUCETHREAD_H_
#define PRODUCETHREAD_H_

#include "WorkingQueue.h"
#include <iostream>

class ProduceThread {
public:
	ProduceThread(WorkingQueue *queue);
	~ProduceThread();
	void start();
	static void *thread_func(void *arg);//静态方法(参数列表不同 （void*）和(Thread::))无法传递，将this以参数形式传给函数
	void run();
	void jion();
private:
	pthread_t _tid;
	WorkingQueue* _queue;
};

#endif /* PRODUCETHREAD_H_ */
