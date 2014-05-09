/*************************************************************************
	> File Name: Log.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月06日 星期二 16时22分42秒
 ************************************************************************/

#ifndef LOG_H_
#define LOG_H_

#include "MutexLock.h"
#include <iostream>
#include <string>

class Log {
public:
	static Log *get_instance();
	void write(const std::string &log);

private:
	Log(){}
	static Log *_p_instance;
	static MutexLock _lock;
};

#endif /* LOG_H_ */
