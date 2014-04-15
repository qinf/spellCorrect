/*
 * WorkingQueue.h
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#ifndef WORKINGQUEUE_H_
#define WORKINGQUEUE_H_

#include "MutexLock.h"
#include "Condition.h"
#include <queue>
#include <time.h>
#include <stdlib.h>

class WorkingQueue {
public:
	WorkingQueue();
	~WorkingQueue();
	int consume();
	void produce(int num);
private:
	std::queue<int> _queue;
	MutexLock _lock;
	Condition _cond;
};

#endif /* WORKINGQUEUE_H_ */
