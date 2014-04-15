/*
* 9.34.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void toUpper(string &str);
void eraseFromStr(string &str);
void getStr(std::istream &in);

int main(int argc, char **argv) {
	string str;
//	while (std::cin >> str)
//		//toUpper(str);
//		eraseFromStr(str);

	getStr(std::cin);
}

void toUpper(string &str) {
	string::iterator iter;
	for (iter = str.begin(); iter != str.end(); ++iter) {
		if (!isupper(*iter))
			*iter = toupper(*iter);
	}
	std::cout << str << std::endl;
}

void eraseFromStr(string &str) {
	string::iterator iter;
	for (iter = str.begin(); iter != str.end(); ++iter) {
		if (isupper(*iter)) {
			str.erase(iter);
			--iter;
		}
	}

	std::cout << str << std::endl;
}

void getStr(std::istream &in) {
	char ch;
	vector<char> cvec;
	while(in >> ch)
		cvec.push_back(ch);
	string str(cvec.begin(), cvec.end());
	std::cout << str << std::endl;
}
