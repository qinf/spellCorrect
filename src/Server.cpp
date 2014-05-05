/*************************************************************************
	> File Name: Server.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月05日 星期一 14时45分47秒
 ************************************************************************/

#include "Server.h"
#include <fstream>
using namespace std;

ifstream &open_file(ifstream &in, const string &file);
void get_ip_and_port_from_conf(ifstream &in, string &ip, int  &port);

int main(int argc, char *argv[])
{
	string conf_file = "../conf/spellCorrect.conf";
	ifstream in;
	open_file(in, conf_file);
	if(!in)
		throw runtime_error("failed to open conf");
	string ip;
	int port;
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

	cout << ip << endl << port << endl;
}
