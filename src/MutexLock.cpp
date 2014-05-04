/*************************************************************************
	> File Name: MutexLock.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 10时51分14秒
 ************************************************************************/

#include "MutexLock.h"
using namespace std;

MutexLock::MutexLock() {
	pthread_mutex_init(&_mutex, NULL);
}
MutexLock::~MutexLock() {
	
}

void MutexLock::lock() {
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock() {
	pthread_mutex_unlock(&_mutex);
}
