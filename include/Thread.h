/*************************************************************************
	> File Name: Thread.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 15时09分52秒
 ************************************************************************/

#ifndef THREAD_H_
#define THREAD_H_

#include "noncopyable.h"
#include <pthread.h>

//class Thread: public noncopyable {,这里有错误
class Thread {
public:
	Thread();
	~Thread();
	static void *thread_func(void* arg);
	void start();
	void join();
	virtual void run() = 0; //纯虚函数，由派生来实现
private:
	pthread_t _tid;
};

#endif /* THREAD_H_ */
