/*************************************************************************
 > File Name: dirct.cpp
 > Author: qinf
 > Mail:
 > Created Time: 2014年05月07日 星期三 14时42分27秒
 ************************************************************************/

#include "dirct.h"
#include "MutexLock.cpp"
#include "EncodingConverter.h"
using namespace std;

Dirct *Dirct::_p_instance = NULL;
MutexLock Dirct::_lock;

Dirct *Dirct::get_instance() {
	if (_p_instance == NULL) {
		_lock.lock();
		if (_p_instance == NULL) {
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
	while (getline(in, line)) {
		pos = line.find("\t"); //gbk_word_map是以'\t'分开的
		word = line.substr(0, pos);
		count = atoi(line.substr(pos + 1).c_str());
		_word_map.insert(make_pair(word, count));
//		cout << trans.gbk_to_utf8(word) << "\t" << count << endl;
	}
	in.close();
	return _word_map;
}
std::map<std::string, int> Dirct::get_map() {
	return _word_map;
}

void Dirct::build_index(const std::string &dirct_file) {

	cout << "建立索引中..." << endl;
	ifstream in;
	in.close();
	in.clear();
	in.open(dirct_file.c_str());
	string line, word;
	int pos, count;
//	EncodingConverter trans; //词典里本来就是gbk格式的
	set<int> index_set; //存储vector中的下标
	index_set.clear();
	while (getline(in, line)) {
		pos = line.find("\t");
		word = line.substr(0, pos);
		count = atoi(line.substr(pos + 1).c_str());
		uint16_t first;
		if (word[0] >= 0x81 && word[0] <= 0xFE) { //是汉字，则取前两个字符
			first = word[0] << 8 + word[1];
		} else {
			first = word[0];
		}
		//处理word_vec,添加word和词频。
		word_vec.push_back(make_pair(word, count));
		//处理index_map,添加索引和下标集合
		if (0 == index_map.count(first)) {
			index_set.clear();
//			index_map.insert(make_pair<uint16_t, set<int> >(first, index_map.at(first).insert(word_vec.size()-1)));
		}
		index_set.insert(word_vec.size() - 1);
		index_map[first] = index_set;
	}

	cout << "索引建立完毕" << endl;
}

std::vector<std::pair<std::string, int> >* Dirct::get_word_vec() {
	return &word_vec;
}
std::unordered_map<std::uint16_t, std::set<int> >* Dirct::get_index_map() {
	return &index_map;
}
