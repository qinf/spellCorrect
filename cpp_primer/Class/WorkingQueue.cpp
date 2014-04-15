/*
 * WorkingQueue.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include "WorkingQueue.h"

WorkingQueue::WorkingQueue() : _cond(&_lock){
	// TODO Auto-generated constructor stub
	srand(time(NULL));
}
WorkingQueue::~WorkingQueue() {

}
int WorkingQueue::consume() {
	_lock.lock();
	int ret;
	while(_queue.empty())
		_cond.wait();
	ret = _queue.front();
	_queue.pop();
	_lock.unlock();
	return ret;
}
void WorkingQueue::produce(int num) {
	_lock.lock();
	_queue.push(num);
	_cond.notify();
	_lock.unlock();
}

