/*************************************************************************
	> File Name: main_test.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 10时11分49秒
 ************************************************************************/

#include "ThreadPool.h"
#include "UDPServer.h"
#include "server_client_func.h"
#include "WorkThread.h"
using namespace std;

int main(int argc, char *argv[])
{
	//1.treadpool开启
	//线程池大小为8
	ThreadPool thread_pool(8);
	thread_pool.start_thread_pool();
	//2.开启服务器
	string ip;
	int port;
	string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	get_ip_and_port_from_conf(ip, port, conf_file);
	UDPServer udp_server(ip, port);
	udp_server.start(thread_pool);

}

