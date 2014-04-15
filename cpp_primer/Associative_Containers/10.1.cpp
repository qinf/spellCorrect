/*
 * 10.1.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

void get_pair(std::istream &in, vector< pair<string, int> > &vec);
void get_pair2(std::istream &in, vector< pair<string, int> > &vec);
void get_pair3(std::istream &in, vector< pair<string, int> > &vec);

int main(int argc, char **argv) {
	vector< pair<string, int> > vec;
//	get_pair(cin, vec);
//	get_pair2(cin, vec);
	get_pair3(cin, vec);
	for(vector< pair<string, int> >::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
}

void get_pair(std::istream &in, vector< pair<string, int> > &vec) {
	string str;
	int ival;
	pair<string, int> pair;
	while(in >> str >> ival) {
		pair = make_pair(str, ival);
		vec.push_back(pair);
	}
}
void get_pair2(std::istream &in, vector< pair<string, int> > &vec) {
	string str;
	int ival;
	pair<string, int> pair;
	while(in >> str >> ival) {
		pair.first = str;
		pair.second = ival;
		vec.push_back(pair);
	}
}
void get_pair3(std::istream &in, vector< pair<string, int> > &vec) {
	string str;
	int ival;
	while(in >> str >> ival) {
		pair<string, int> pair(str, ival);
		vec.push_back(pair);
	}
}
