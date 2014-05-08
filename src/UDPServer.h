/*************************************************************************
	> File Name: UDPServer.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月06日 星期二 22时05分11秒
 ************************************************************************/

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "Log.h"
#include "Task.h"
#include "ThreadPool.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdexcept>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

class UDPServer
{
public:
	UDPServer(const string &ip, const int &port);
	~UDPServer();
	int recvn(int recv_fd, char* recv_buf, int len, struct sockaddr_in &src_addr, int &addrlen);
	int sendn(int send_fd, char* send_buf, int len, struct sockaddr_in &addr);
	void start(ThreadPool &p_thread_pool);
private:
	int server_fd;
	struct sockaddr_in server_addr, client_addr;
	string recv_buf;
};

#endif /* UDPSERVER_H_ */

