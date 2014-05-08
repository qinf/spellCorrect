/*************************************************************************
	> File Name: task_test.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月08日 星期四 10时55分48秒
 ************************************************************************/

#include "Task.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	Task task, task1;
//	memset(&task, 0, sizeof(task));
//	memset(&task1, 0, sizeof(task1));
	string tt = "hello";
	task.set_task(tt);
	task1 = task;
	cout << task1.get_task() << endl;
	return 0;
}
