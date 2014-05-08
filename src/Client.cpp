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

	int client_fd, addr_len;
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
	//从终端读入待纠错的单词
	string inputword;
	while(true) {
		cin >> inputword;
		//发送长度
		int buf_len = inputword.size();
		cout << "发送长度： " << buf_len << endl;
		if(-1 == sendto(client_fd, &buf_len, sizeof(int), 0, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
			Log::get_instance()->write("client sent len failed");
		}
		//发送数据
		char *send_buf = new char[inputword.size()+1];
		memset(send_buf, 0, inputword.size()+1);
		strcpy(send_buf, inputword.c_str());
		sendn(client_fd, send_buf, buf_len, server_addr);

		//接受数据
		//1.接收长度
		int recv_len;
		int addr_len = sizeof(server_addr);
		recvfrom(client_fd, &recv_len, sizeof(int), 0, (struct sockaddr*)&server_addr, (socklen_t*)&addr_len);
		//2.接收内容
		char *recv_buf = new char[recv_len+1];
		memset(recv_buf, 0, recv_len+1);
		recvn(client_fd, recv_buf, recv_len, server_addr, addr_len);
		cout << recv_buf << endl;
	}


	return 0;
}
