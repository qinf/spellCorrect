/*
 * Condition.h
 *
 *  Created on: Apr 14, 2014
 *      Author: qinf
 */

#ifndef CONDITION_H_
#define CONDITION_H_

#include <stdexcept>
#include "MutexLock.h"

class Condition {
public:
	Condition(MutexLock *p_lock);//2.为什么构造函数要给一个MutexLock型指针的参数  所有的条件变量都用一个锁
	~Condition();
	void wait();
	void notify();
	void notifyAll();
private:
	pthread_cond_t _cond;
//	pthread_mutex_lock *_p_lock;//1.为什么要用指针？  pthread_mutex_lock???
	MutexLock *_p_lock;
};

#endif /* CONDITION_H_ */
