/*************************************************************************
	> File Name: Task.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 09时32分54秒
 ************************************************************************/

#include "Task.h"
#include <iostream>
#include <cstring>
using namespace std;

Task::Task() {

}

Task::~Task() {

}

void Task::set_task(const string& task) {
	_task = task;
}
std::string Task::get_task() {
	return _task;
}
void Task::set_addr(struct sockaddr_in &addr) {
	_addr = addr;
}
struct sockaddr_in Task::get_addr() {
	return _addr;
}

Task& Task::operator=(const Task &task) {
	_task = task._task;
//	_addr = task._addr;
	_addr.sin_family = task._addr.sin_family;
	_addr.sin_port = task._addr.sin_port;
	_addr.sin_addr = task._addr.sin_addr;

	return *this;
}
