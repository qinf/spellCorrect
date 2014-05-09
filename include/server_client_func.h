/*************************************************************************
	> File Name: server_client_func.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月05日 星期一 21时08分43秒
 ************************************************************************/

#ifndef SERVER_CLIENT_H_
#define SERVER_CLIENT_H_

#include "Log.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
using namespace std;

void get_ip_and_port_from_conf(string &ip, int &port, const string &conf_file);
ifstream &open_file(ifstream &in, const string &file);
ofstream &open_output_file(ofstream &out, const string &file);
void get_ip_and_port_from_conf(ifstream &in, string &ip, int  &port);
int socket_server(const string &ip, int port);
int socket_client(const string &ip, int port);
int recvn(int recv_fd, char* recv_buf, int len, struct sockaddr_in &src_addr, int &addrlen);
int sendn(int send_fd, char* send_buf, int len, struct sockaddr_in &addr);

#endif /* SERVER_CLIENT_H_ */
