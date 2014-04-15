/*
 * MutexLock.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: qinf
 */

#include "MutexLock.h"
#include "Condition.h"
#include <stdexcept>

MutexLock::MutexLock() {
	// TODO Auto-generated constructor stub
	if (pthread_mutex_init(&_lock, NULL) == -1)
		throw std::runtime_error("Init lock fail!!");

}
MutexLock::~MutexLock() {
	pthread_mutex_destroy(&_lock);
}
void MutexLock::lock() {
	pthread_mutex_lock(&_lock);
}
void MutexLock::unlock() {
	pthread_mutex_unlock(&_lock);
}
