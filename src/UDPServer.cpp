/*************************************************************************
	> File Name: UDPServer.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月06日 星期二 22时05分18秒
 ************************************************************************/

#include "UDPServer.h"

UDPServer::UDPServer(const string &ip, const int &port) {
	
	string work_dirc = "/home/qinf/workspace/spellCorrect";
	/*
	if(fork()!=0) //父进程退出
		exit(0);
	setsid(); //成为新进进程组组长和新会话领导，脱离终端控制
	chdir(work_dirc.c_str()); //设置新的工作目录
	//重设文件访问权限掩码
	//尽可能关闭所有从父进程继承过来的打开文件
	*/
	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == server_fd)
		Log::get_instance()->write("server_fd socket");
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

	//bind
	if(-1 == bind(server_fd,(struct sockaddr*)&server_addr, sizeof(server_addr))) {
		Log::get_instance()->write("client bind");
	}
}

UDPServer::~UDPServer() {
	close(server_fd);
}

int UDPServer::recvn(int recv_fd, char* recv_buf, int len, struct sockaddr_in &src_addr, int &addrlen) {
	int sum = 0;
	int nrecv;
	while(sum < len) {
		nrecv = recvfrom(recv_fd, &recv_buf[sum], len-sum, 0, (struct sockaddr*)&src_addr, (socklen_t *)&addrlen);
		if(-1 == nrecv)
			Log::get_instance()->write("recfrom failed!");
		sum += nrecv;
	}
	recv_buf[sum] = '\0';
	return sum;
}

int UDPServer::sendn(int send_fd, char* send_buf, int len, struct sockaddr_in &addr) {
	int sum = 0;
	int nsend;
	while(sum < len) {
		nsend = sendto(send_fd, send_buf+sum, len-sum, 0, (struct sockaddr*)&addr, sizeof(addr));
		if(-1 == nsend)
			Log::get_instance()->write("server sendto failed!");
		sum += nsend;
	}

	return sum;
}

//启动UDP服务器
void UDPServer::start(ThreadPool &thread_pool) {
//	fd_set fd_read, fd_read_back;
//	struct timeval tm;
//	FD_ZERO(&fd_read);
	//监听socket上的输入
//	FD_SET(server_fd, &fd_read);
//	tm.tv_sec = 3;
//	tm.tv_usec = 0;
	int addr_len = sizeof(client_addr);
	char *recv_buf = new char[1024];
	while(1) {
//		tm.tv_sec = 3;
//		tm.tv_usec = 0;
//		fd_read_back = fd_read;
		std::cout << "recv。。。" << std::endl ;
//		select(1024, &fd_read_back, NULL, NULL, &tm);
//		if(FD_ISSET(server_fd, &fd_read_back)) {

			//接受数据
			memset(recv_buf, 0, 1024);
			memset(&client_addr, 0, sizeof(client_addr));
			cout << "================" << endl;
			if (-1 == recvfrom(server_fd, recv_buf, 1024, 0, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len))
				Log::get_instance()->write("UDPServer recv data from client failed!");
			cout << "server recv: " << recv_buf << endl;
			Task task;
			task.set_task(recv_buf);
			task.set_addr(client_addr);
			//输出地址
			//cout << "UDPServer: " << task._addr.sin_addr.s_addr << endl;

			if(!thread_pool.add_task_to_pool(task)) {
				Log::get_instance()->write("failed to add task to pool");
			}
			cout << "-----------------------------" << endl;
			//cout << "queue size: " << thread_pool.get_task_queue_size() << endl;
//		}
	}
}

int UDPServer::get_server_fd() {
	return server_fd;
}
