/*
 * 10.23.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: qinf
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

ifstream& open_file(ifstream &in, const string &file);
void restricted_wc(ifstream &remove_file, map<string, int> &word_count);

int main(int argc, char **argv) {
	ifstream excluded_file;
	map<string, int> word_count;
	if (!open_file(excluded_file, argv[1]))
		throw runtime_error("no excluded file");
	restricted_wc(excluded_file, word_count);

	//打印map
	for (map<string, int>::const_iterator iter = word_count.begin(); iter != word_count.end(); ++iter)
		cout << iter->first << " " << iter->second << endl;
}

//打开文件
ifstream& open_file(ifstream &in, const string &file) {
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

void restricted_wc(ifstream &remove_file, map<string, int> &word_count) {
	vector<string> excluded; // set to hold words we'll ignore
	string remove_word;
	while(remove_file >> remove_word)
		excluded.push_back(remove_word);
	//cout << excluded.size() << "============" << endl;
	string word;
	vector<string>::iterator iter = excluded.begin();
	map<string, int>::iterator it;
	while(cin >> word) {
		//判断word是否在单词排除集excluded中
		while(iter != excluded.end()) {
			if (word == *iter)
				break;
			else {
				++iter;
				//cout << "0000000000" << endl;
			}
		}
		//如果迭代完excluded，说明单词不存在于排除集中
		if (iter == excluded.end()) {
			//单词已存在于word_count中
			//cout << word << "------------" << endl;
			if ((it = word_count.find(word)) != word_count.end())
				++it->second;
			else
				word_count.insert(make_pair(word, 1));
		}
		//单词存在于排除集excluded中 或者单词单词不存在最后都要更新iter到begin位置
		iter = excluded.begin();
	}
}
