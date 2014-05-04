/*************************************************************************
	> File Name: main.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 13时58分20秒
 ************************************************************************/

#include <iostream>
#include "MutexLock.h"
using namespace std;
int main()
{
	MutexLock l;
	l.lock();
	l.unlock();
}

