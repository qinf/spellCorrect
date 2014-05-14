/*
 * MutexLock.h
 *
 *  Created on: Apr 14, 2014
 *      Author: qinf
 */

#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_

#include <pthread.h>

class MutexLock {
	friend class Condition;
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
private:
	pthread_mutex_t _lock;
};

#endif /* MUTEXLOCK_H_ */
