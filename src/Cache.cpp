/*************************************************************************
	> File Name: Cache.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月10日 星期六 15时03分44秒
 ************************************************************************/

#include "Cache.h"
using namespace std;

Cache::Cache() {

}
Cache::~Cache() {

}
bool Cache::is_key_in_map(std::string &key) {
	cout << "size: " << _word_hash_map.size() << endl;
	if(_word_hash_map.count(key) == 0) {
		return false;
	} else {
		return true;
	}
}

std::string Cache::get_hash_map_value(std::string key) {
	return _word_hash_map.find(key)->first;
}

void Cache::add_to_hash_map(std::string key, std::string value) {
//	_word_hash_map.insert(std::make_pair<std::string, std::string>(key, value));
	_mutex.lock();
	_word_hash_map[key] = value;
	_mutex.unlock();
}

std::unordered_map<std::string, std::string> Cache::get_map() {
	return _word_hash_map;
}

Cache Cache::get_cache() {
	return *this;
}

//void get_hash_map(std::unordered_map<std::string, std::string> hash_map) {
//	_word_hash_map = hash_map;
//}
