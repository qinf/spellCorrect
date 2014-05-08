/*************************************************************************
	> File Name: Log.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月06日 星期二 16时22分47秒
 ************************************************************************/

#include "Log.h"
#include <fstream>
#include <cstdio>
#include <string>
#include <ctime>
#include <iomanip>
#include "server_client_func.h"
using namespace std;

Log *Log::_p_instance = NULL;
MutexLock Log::_lock;

Log *Log::get_instance() {
	if(_p_instance == NULL) {
		_lock.lock();
		if(_p_instance == NULL) {
			_p_instance = new Log();
		}
		_lock.unlock();
	}
	return _p_instance;
}

void Log::write(const string &log) {

	string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	ifstream in;
	string line;
	string log_file;
	open_file(in, conf_file);
	getline(in, line);
	string::size_type pos;
	while(string::npos == (pos = line.find("log=")))
		getline(in, line);
	log_file = line.substr(pos+4);
	in.close();
	//重定向输出到日志文件
	std::freopen(log_file.c_str(), "a+", stdout);
	//std::time_t result = std::time(NULL);
	//cout << std::put_time(std::localtime(&result), "%c %Z") << "/t/t" << log << endl;
	cout << log << endl;
	std::fclose(stdout);
}

