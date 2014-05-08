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

class Tools{
public:
	Tools(std::string &conf_path);
	~Tools();
	std::string get_word_map_file_path();
	std::ifstream &open_file(std::ifstream &in, std::string &file);
private:
	std::string _conf_path;
};

#endif /* TOOLS_H_ */
