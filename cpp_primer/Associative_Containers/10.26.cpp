/*
 * 10.26.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

void find_erase_from_multimap(multimap<string, string> &multiMap, const string &name);
void equal_range_multimap(multimap<string, string> &multiMap, const string &name);

int main(int argc, char **argv) {
	multimap<string, string> multiMap;
	string name;
	multiMap.insert(make_pair("author", "A"));
	multiMap.insert(make_pair("author", "B"));
	multiMap.insert(make_pair("author", "D"));
	multiMap.insert(make_pair("author1", "A"));
	multiMap.insert(make_pair("author1", "B"));
	multiMap.insert(make_pair("author2", "C"));
	multiMap.insert(make_pair("author3", "A"));

	while (cin >> name) {
		cout << "you input: " << name << endl;
//		find_erase_from_multimap(multiMap, name);
		equal_range_multimap(multiMap, name);
		for (multimap<string, string>::iterator iter = multiMap.begin(); iter != multiMap.end(); ++iter) {
			cout << iter->first << " : " << iter->second << endl;
		}
	}

	return 0;
}

//using find and erase
void find_erase_from_multimap(multimap<string, string> &multiMap, const string &name) {
	multimap<string, string>::iterator iter = multiMap.find(name);
	string saveName = iter->first;
//	while(iter != multiMap.end() && iter->first == saveName) {
//		multiMap.erase(name);
//		saveName = iter->first;
//	}
	multiMap.erase(name);//带有一个键参数的erase版本将会删除拥有该键的所有元素

}

void equal_range_multimap(multimap<string, string> &multiMap, const string &name) {
	typedef multimap<string, string>::iterator iterMapType;

	//equal_range()返回一个pair对象，该对象存储的是multimap类型的迭代器
	pair<iterMapType, iterMapType> pos = multiMap.equal_range(name);
	if (pos.first != pos.second)
		multiMap.erase(pos.first, pos.second);
	else
		cout << "have no this key" << endl;
}
