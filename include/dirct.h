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
#include <unordered_map>
#include <utility>
#include <stdint.h>
#include <set>
#include <vector>

class Dirct {
public:
	static Dirct *get_instance();
	std::map<std::string, int> get_word_map(const std::string &dirct_file);
	void build_index(const std::string &dirct_file); //建立索引
	std::map<std::string, int> get_map();
private:
	Dirct() {
	}
	static Dirct *_p_instance;
	static MutexLock _lock;
	std::map<std::string, int> _word_map;
	std::vector<std::pair<std::string, int> > *get_word_vec();
	std::unordered_map<std::uint16_t, std::set<int> > *get_index_map();
	/*
	 * 索引数据结构
	 * word_vec，string型存储词或者英文单词，int类型存储频率
	 * index_map uint16_t类型存储汉字第一个字或者英文第一个字母，int类型存储unint16_t在vector中的位置
	 */
	std::vector<std::pair<std::string, int> > word_vec;
	std::unordered_map<std::uint16_t, std::set<int> > index_map;
};

#endif /* DIRCT_H_ */
