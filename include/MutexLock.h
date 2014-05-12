/*************************************************************************
	> File Name: MutexLock.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 10时53分01秒
 ************************************************************************/

#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_

#include <pthread.h>
#include "noncopyable.h"

class MutexLock {
public:
	friend class Condition;
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
};

#endif /* MUTEXLOCK_H_ */
