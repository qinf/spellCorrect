/*************************************************************************
	> File Name: Cache.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月10日 星期六 15时03分48秒
 ************************************************************************/

#ifndef CACHE_H_
#define CACHE_H_

#include <unordered_map>
#include <string>
#include <utility>
#include <iostream>

class Cache {
public:
	Cache();
	~Cache();
	bool is_key_in_map(std::string &key);
	std::string get_hash_map_value(std::string key);
//	void get_hash_map(std::unordered_map<std::string, std::string> hash_map);
	void add_to_hash_map(std::string key, std::string value);
private:
	std::unordered_map<std::string, std::string> _word_hash_map;//可以改进
};

#endif /* CACHE_H_ */
