/*************************************************************************
	> File Name: Task.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 09时32分51秒
 ************************************************************************/

#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

class Task {
public:
	Task();
	~Task();
	void set_task(const std::string &task);
	std::string get_task();
	void set_addr(struct sockaddr_in &addr);
	struct sockaddr_in get_addr();
	Task& operator=(const Task &);
	std::string _task;
	struct sockaddr_in _addr;
};

#endif /* TASK_H_ */
