/*************************************************************************
	> File Name: Condition.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 14时33分56秒
 ************************************************************************/

#include "Condition.h"

Condition::Condition(MutexLock *p_lock): _lock(p_lock) {
	pthread_cond_init(&_cond, NULL);
}
Condition::~Condition() {
	pthread_cond_destroy(&_cond);
}
void Condition::wait() {
	pthread_cond_wait(&_cond, &_lock->_mutex);
}
void Condition::notify() {
	pthread_cond_signal(&_cond);
}
void Condition::notify_all() {
	pthread_cond_broadcast(&_cond);
}
