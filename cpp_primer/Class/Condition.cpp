/*
 * Condition.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: qinf
 */

#include "Condition.h"
#include <stdexcept>

Condition::Condition(MutexLock *p_lock) : _p_lock(p_lock) {
	// TODO Auto-generated constructor stub
	if (pthread_cond_init(&_cond, NULL) == -1)
		throw std::runtime_error ("cond init fail!");
}
Condition::~Condition() {
	pthread_cond_destroy(&_cond);
}
void Condition::wait() {
	pthread_cond_wait(&_cond, &_p_lock->_lock);//_p_lock是指向MutexLock的一个指针
}
void Condition::notify() {
	pthread_cond_signal(&_cond);
}
void Condition::notifyAll() {
	pthread_cond_broadcast(&_cond);
}

