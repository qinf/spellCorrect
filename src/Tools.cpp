/*************************************************************************
 > File Name: Tools.cpp
 > Author: qinf
 > Mail:
 > Created Time: 2014年05月07日 星期三 14时56分14秒
 ************************************************************************/

#include "Tools.h"
using namespace std;

Tools::Tools(const std::string &conf_path) :
		_conf_path(conf_path) {

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
	while (string::npos == pos) {
		getline(instream, line);
		pos = line.find("word_map=");
	}
	word_map_file_path = line.substr(pos + 9);
	return word_map_file_path;
}
std::string Tools::get_gbk_word_map_file_path() {
	ifstream instream;
	string line;
	string gbk_word_map_file_path;
	int pos;
	open_file(instream, _conf_path);
	getline(instream, line);
	pos = line.find("gbk_word_map=");
	while (string::npos == pos) {
		getline(instream, line);
		pos = line.find("gbk_word_map=");
	}
	gbk_word_map_file_path = line.substr(pos + 13);
	return gbk_word_map_file_path;
}

ifstream &Tools::open_file(ifstream &in, string &file) {
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}
std::string Tools::get_cache_file_path() {
	ifstream instream;
	string line;
	string cache_file_path;
	int pos;
	open_file(instream, _conf_path);
	getline(instream, line);
	pos = line.find("cache=");
	while (string::npos == pos) {
		getline(instream, line);
		pos = line.find("cache=");
	}
	cache_file_path = line.substr(pos + 6);
	return cache_file_path;
}
