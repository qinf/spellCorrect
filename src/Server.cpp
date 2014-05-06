/*************************************************************************
	> File Name: Server.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月05日 星期一 14时45分47秒
 ************************************************************************/

#include "server_client_func.h"

int main(int argc, char *argv[])
{
	string work_dirc = "/home/qinf/workspace/spellCorrect";
	if (fork()!= 0) //父进程退出
		exit(0);
	setsid(); //成为新进程组组长和新回话领导，脱离终端控制
	chdir(work_dirc.c_str()); //设置工作目录
	//重设文件访问权限掩码
	//尽可能关闭所有从父进程继承过来的打开文件
	string conf_file = work_dirc + "/conf/spellCorrect.conf";
	string ip;
	int port;
	int recv_fd;
	//1.从配置文件中读取ip和port
	get_ip_and_port_from_conf(ip, port, conf_file);
	//cout << ip << endl << port << endl;
	
	//2.bind
	int server_fd = socket_server(ip, port);
	if(-1 == server_fd)
		throw runtime_error("server_fd socket");
	
	//recv,先接收长度,udp用recvfrom
	int len = 0;
	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr));
	int addr_len = sizeof(client_addr);
	while (1) {
		//recvfrom第一个参数必须为服务器自身的sockfd
		recvfrom(server_fd, &len, sizeof(int), 0, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
		cout << len << endl;
	}

	return 0;
}

