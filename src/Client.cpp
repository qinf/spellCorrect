/*************************************************************************
	> File Name: Client.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月05日 星期一 14时46分43秒
 ************************************************************************/

#include "server_client_func.h"
using namespace std;

int main(int argc, char* argv[])
{
	string ip;
	int port;
	string conf_file = "../conf/spellCorrect.conf";
	get_ip_and_port_from_conf(ip, port, conf_file);
	cout << ip << endl << port << endl;

	int client_fd;
	struct sockaddr_in server_addr;
	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1==client_fd)
		throw runtime_error("fialed to generate client_fd socket");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

	//设置端口重用
	int resue = 1;
	if (0 != setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR, (void*)&resue, sizeof(int))) {
		close(client_fd);
		throw std::runtime_error("failed to set socket option!");
	}
	int ibuf = 1024;
	if (-1 == sendto(client_fd, &ibuf, sizeof(int), 0, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
		throw std::runtime_error("client send data failed!");
	}


	return 0;
}
