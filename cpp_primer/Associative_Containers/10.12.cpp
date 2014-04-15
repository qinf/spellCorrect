/*
 * 10.12.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv) {
	map<string ,int> word_count;
	string word;
	while (cin >> word) {
		pair< map<string, int>::iterator, bool> iter = word_count.insert(make_pair(word, 1));
		if(!iter.second)
			++iter.first->second;
	}
	for(map<string, int>::iterator iter = word_count.begin(); iter != word_count.end(); ++iter)
		cout << iter->first << " " << iter->second << endl;
}

