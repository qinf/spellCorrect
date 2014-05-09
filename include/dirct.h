/*************************************************************************
	> File Name: dirct.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 14时42分23秒
 ************************************************************************/

#ifndef DIRCT_H_
#define DIRCT_H_

#include "MutexLock.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>

class Dirct {
public:
	static Dirct *get_instance();
	std::map<std::string, int> get_word_map(const std::string &dirct_file);
private:
	Dirct() {}
	static Dirct *_p_instance;
	static MutexLock _lock;
	std::map<std::string, int> _word_map;
};

#endif /* DIRCT_H_ */
