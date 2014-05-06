/*************************************************************************
	> File Name: process_data.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月06日 星期二 10时37分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include "server_client_func.h"
using namespace std;

void get_data_file_name_from_conf(string &data_file, const string &conf_file);
void get_word_map_from_data(map<string, int> &word_map, const string &data_file);
void save_word_map_to_file(map<string, int> &word_map, const string &word_map_file);
ofstream& open_output_file(ofstream &out, const string &file);

int main()
{
	string conf_file = "/home/qinf/workspace/spellCorrect/conf/spellCorrect.conf";
	string data_file;
	string word_map_file = "/home/qinf/workspace/spellCorrect/data/word_map.txt";
	//从配置文件中读取数据文件名
	get_data_file_name_from_conf(data_file, conf_file);
	cout << data_file << endl;
	//处理数据文件
	map<string, int> word_map;
	get_word_map_from_data(word_map, data_file);
	save_word_map_to_file(word_map, word_map_file);
	return 0;
}

void get_data_file_name_from_conf(string &data_file, const string &conf_file) {
	
	ifstream infile;
	open_file(infile, conf_file);
	if (!infile)
		throw runtime_error("failed to open conf file");

	string line;
	string::size_type pos;
	getline(infile, line);
	while(string::npos == (pos = line.find("data=")))
		getline(infile, line);
	data_file = line.substr(pos+5);
	infile.close();
}
void get_word_map_from_data(map<string, int> &word_map, const string &data_file) {
	ifstream infile;
	open_file(infile, data_file);
	if(!infile)
		throw runtime_error("failed to open data_file");
	string line, word;
	char ch;
	cout << "处理单词" << endl;
	while(getline(infile, line)) {
//		cout << line << endl;
		istringstream stream(line);
		while(stream >> word) {
			string new_word;
			//处理单词，1.大写转换为小写，2.去除标点
			for(string::size_type ix = 0; ix != word.size(); ++ix) {
				//1.大写转换为小写
				ch = word[ix];
				if(isupper(ch))
					new_word.push_back(tolower(ch));
				//2.小写时不用处理
				if(islower(ch))
					new_word.push_back(ch);
				//3.其他情况，不做处理
			}
			if ("" != new_word) {
				++word_map[new_word]; //将单词添加到word_map中
			}
		}
	}
}

void save_word_map_to_file(map<string, int> &word_map, const string &word_map_file) {
	ofstream outfile;
	open_output_file(outfile, word_map_file);
	cout << "保存单词map到文件" << endl;
	for(map<string, int>::iterator iter = word_map.begin(); iter != word_map.end(); ++iter) {
		outfile << iter->first << ":" << iter->second << endl;
	}
	outfile.close();
}

//打开输出文件函数
ofstream& open_output_file(ofstream &out, const string &file) {
	out.close();
	out.clear();
	out.open(file.c_str());
	return out;
}
