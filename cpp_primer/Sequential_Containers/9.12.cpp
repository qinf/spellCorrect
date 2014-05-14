/*
* 9.12.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>

void get_string(std::vector<std::string> &svec, std::istream &in) {
	std::string str;
	while (getline(in, str))
		svec.push_back(str);
}

void get_string_list(std::list<std::string> &ls, std::istream &in) {
	std::string str;
	while (getline(in, str))
		ls.push_back(str);
}

int main(int argc, char **argv) {
	std::vector<std::string> svec;
	std::list<std::string> ls;
	std::cout << "Enter some string(ctrl+d to end):" << std::endl;
	get_string(svec, std::cin);
//	get_string_list(ls, std::cin);

	for (std::vector<std::string>::iterator it = svec.begin(); it != svec.end();
			++it) {
		std::cout << *it << std::endl;
	}

//	for (std::list<std::string>::iterator it = ls.begin(); it != ls.end(); ++it) {
//		std::cout << *it << std::endl;
//	}
}

bool exit_value(std::vector<int>::iterator first,
		std::vector<int>::iterator last, int ival) {
	while (first != last) {
		if (*first == ival)
			break;
		else {
			++first;
		}
	}
	if (first == last)
		return false;
	else
		return true;
}

std::vector<int>::iterator findInt(std::vector<int>::iterator first,
		std::vector<int>::iterator last, int ival) {
	while (first != last) {
		if (*first == ival)
			break;
		else
			++first;
	}
	return first;
}
