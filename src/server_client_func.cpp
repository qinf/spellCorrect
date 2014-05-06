/*************************************************************************
	> File Name: server_client_func.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月05日 星期一 21时16分18秒
 ************************************************************************/

#include "server_client_func.h"

void get_ip_and_port_from_conf(string &ip, int &port, const string &conf_file) {
	ifstream in;
	open_file(in, conf_file);
	if (!in) {
		throw runtime_error("failed to open conf");
	}
	get_ip_and_port_from_conf(in, ip, port);
	in.close();
}

ifstream &open_file(ifstream &in, const string &file) {
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

void get_ip_and_port_from_conf(ifstream &in, string &ip, int  &port){
	string line;
	getline(in, line);
//	cout << line << "\t" << string::npos << endl;
	string::size_type pos = line.find("ip="); //ip
	if (string::npos != pos) {
		ip = line.substr(pos + 3);
	}
	getline(in, line);
	pos = line.find("port=");
	if(string::npos != pos) {
		port = atoi(line.substr(pos + 5).c_str());
	}

}

int socket_server(const string &ip, int port) {
	int server_fd;
	struct sockaddr_in server_addr;
	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == server_fd) {
		throw std::runtime_error("socket");
	}
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str()); //是这个吗？

	if(-1 == bind(server_fd,(struct sockaddr*)&server_addr, sizeof(server_addr))) {
		throw std::runtime_error("bind");
	}
	return server_fd;
}

/*
int socket_client(const string &ip, int port) {
	int client_fd;
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);

	//设置端口重用
	int reuse = 1;
	if(0 != setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR, (void*)reuse), sizeof(int));

}
*/

int recvn(int recv_fd, char * recv_buf, int len) {
	int sum = 0;
	int nrecv;
	while(sum < len) {
		nrecv = recv(recv_fd, &recv_buf[sum], len-sum, 0);
		sum += nrecv;
	}
	recv_buf[sum] = '\0';
	return sum;
}

int sendn(int send_fd, char* send_buf, int len) {
	int sum = 0;
	int nsend;
	while(sum < len) {
		nsend = send(send_fd, send_buf+sum, len-sum, 0);
		sum += nsend;
	}

	return sum;
}

