/*************************************************************************
	> File Name: Condition.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 14时24分56秒
 ************************************************************************/

#ifndef CONDITION_H_
#define CONDITION_H_

#include "noncopyable.h"
#include "MutexLock.h"

class Condition: public noncopyable {
public:
	Condition(MutexLock *p_lock);
	~Condition();
	void wait();
	void notify();
	void notify_all();
private:
	MutexLock *_lock; //使用引用和指针有区别吗？
	pthread_cond_t _cond;
};

#endif /* CONDITION_H_ */
