/*
 * 10.9.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	string word;
	map<string, int> word_count;
	while (cin >> word) {
		++word_count[word];
	}

	for (map<string, int>::iterator map_it = word_count.begin();
			map_it != word_count.end(); ++map_it) {
		cout << map_it->first << " " << map_it->second << endl;
	}
}

