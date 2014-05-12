/*************************************************************************
	> File Name: dirct.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 14时42分27秒
 ************************************************************************/

#include "dirct.h"
#include "MutexLock.cpp"
#include "EncodingConverter.h"
#include <cstdlib>
using namespace std;

Dirct *Dirct::_p_instance = NULL;
MutexLock Dirct::_lock;

Dirct *Dirct::get_instance() {
	if(_p_instance == NULL) {
		_lock.lock();
		if(_p_instance == NULL) {
			_p_instance = new Dirct();
		}
		_lock.unlock();
	}
	return _p_instance;
}
map<string, int> Dirct::get_word_map(const std::string &dirct_file) {
	ifstream in;
	in.close();
	in.clear();
	in.open(dirct_file.c_str());
	string line, word;
	int pos, count;
	EncodingConverter trans;
	while(getline(in, line)) {
		pos = line.find("\t"); //gbk_word_map是以'\t'分开的
		word = line.substr(0, pos);
		count = atoi(line.substr(pos+1).c_str());
		_word_map.insert(make_pair(word, count));
//		cout << trans.gbk_to_utf8(word) << "\t" << count << endl;
	}
	in.close();
	return _word_map;
}
std::map<std::string, int> Dirct::get_map() {
	return _word_map;
}
