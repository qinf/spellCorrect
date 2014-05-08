/*************************************************************************
	> File Name: main.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 13时58分20秒
 ************************************************************************/

#include <iostream>
#include "MutexLock.h"
#include "server_client_func.h"
#include "Tools.h"
#include "dirct.h"
#include "Task.h"
#include "Log.h"
using namespace std;
int main()
{
//	MutexLock l;
//	l.lock();
//	l.unlock();
//	Log *log = Log::get_instance();
//	log->write("test1");
//	log->write("test2");
	
/*	Dirct *dirct = Dirct::get_instance();
	string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	Tools *tools = new Tools(conf_file);
	string word_map_file_path = tools->get_word_map_file_path();

	dirct->get_word_map(word_map_file_path);
	*/

	Task task, task1;
	memset(&task, 0, sizeof(task));
	task.set_task();

	task1 = task;
	return 0;
}

