/*
* 9.26.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <vector>
#include <list>

int main(int argc, char **argv) {
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	std::vector<int> ivec(ia, ia + 11);
	std::list<int> lst(ia, ia + 11);
	std::vector<int>::iterator iter_vec;
	for (iter_vec = ivec.begin(); iter_vec != ivec.end(); ++iter_vec)
		if (*iter_vec % 2 == 0) {
			ivec.erase(iter_vec);
			--iter_vec;
		}
	std::list<int>::iterator iter_list;
	for (iter_list = lst.begin(); iter_list != lst.end(); ++iter_list)
		if (*iter_list % 2 != 0) {
			lst.erase(iter_list);
			--iter_list;
		}

	iter_vec = ivec.begin();
	while (iter_vec != ivec.end()) {
		std::cout << *iter_vec << " ";
		++iter_vec;
	}
	std::cout << std::endl;

	iter_list = lst.begin();
	while (iter_list != lst.end()) {
		std::cout << *iter_list << " ";
		++iter_list;
	}
	std::cout << std::endl;
}

