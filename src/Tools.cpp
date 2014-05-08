/*************************************************************************
	> File Name: Tools.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 14时56分14秒
 ************************************************************************/

#include "Tools.h"
using namespace std;

Tools::Tools(std::string &conf_path):_conf_path(conf_path) {

}
Tools::~Tools() {

}
std::string Tools::get_word_map_file_path() {
	ifstream instream;
	string line;
	string word_map_file_path;
	int pos;
	open_file(instream, _conf_path);
	getline(instream, line);
	pos = line.find("word_map=");
	while(string::npos == pos) {
		getline(instream, line);
		pos = line.find("word_map=");
	}
	word_map_file_path = line.substr(pos+9);
	return word_map_file_path;
}

ifstream &Tools::open_file(ifstream &in, string &file) {
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}