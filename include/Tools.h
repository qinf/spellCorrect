/*************************************************************************
	> File Name: Tools.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 14时53分47秒
 ************************************************************************/

#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <fstream>
#include <iostream>
#include <string>

class Tools{
public:
	Tools(const std::string &conf_path = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf");
	~Tools();
	std::string get_word_map_file_path();
	std::ifstream &open_file(std::ifstream &in, std::string &file);
	std::string get_gbk_word_map_file_path();
	std::string get_cache_file_path();
private:
	std::string _conf_path;
};

#endif /* TOOLS_H_ */
