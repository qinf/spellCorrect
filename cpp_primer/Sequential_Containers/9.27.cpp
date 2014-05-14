/*
* 9.27.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <algorithm>

void delete_from_list(std::istream &in);
void delete_from_deque(std::istream &in);

int main(int argc, char **argv) {
	//delete_from_list(std::cin);
	delete_from_deque(std::cin);
}

void delete_from_list(std::istream &in) {
	std::string str;
	std::list<std::string> lst;
	std::list<std::string>::iterator iter_lst, emem1;
	std::cout << "Enter some string(ctrl + d to end):" << std::endl;
	while (in >> str) {
		lst.push_back(str);
	}
	in.clear();
	for (iter_lst = lst.begin(); iter_lst != lst.end(); ++iter_lst) {
		std::cout << *iter_lst << std::endl;
	}
	std::cout << "=========================" << std::endl;
	std::string word;
	std::cout << "Enter what you want to erase: " << std::endl;
	in >> word;
	emem1 = std::find(lst.begin(), lst.end(), word);
	if (emem1 != lst.end()) {
		lst.erase(emem1);
	}
	for (iter_lst = lst.begin(); iter_lst != lst.end(); ++iter_lst) {
		std::cout << *iter_lst << std::endl;
	}
}

void delete_from_deque(std::istream &in) {
	std::string str;
	std::deque<std::string> deq;
	std::deque<std::string>::iterator iter_deq;
	std::cout << "Enter some string(ctrl + d to end):" << std::endl;
	while (in >> str) {
		deq.push_back(str);
	}
	in.clear();
	for (iter_deq = deq.begin(); iter_deq != deq.end(); ++iter_deq) {
		std::cout << *iter_deq << std::endl;
	}
	std::cout << "=========================" << std::endl;
	std::string word;
	std::cout << "Enter what you want to erase: " << std::endl;
	in >> word;

	for(iter_deq = deq.begin(); iter_deq != deq.end(); ++iter_deq) {
		if (*iter_deq == word) {
			deq.erase(iter_deq);
			--iter_deq;
		}
	}
	for (iter_deq = deq.begin(); iter_deq != deq.end(); ++iter_deq)
		std::cout << *iter_deq << std::endl;
}

