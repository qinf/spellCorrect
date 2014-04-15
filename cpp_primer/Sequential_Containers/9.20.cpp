/*
* 9.20.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <list>
#include <vector>

bool isEqual(const std::vector<int> &ivec, const std::list<int> &lst);

int main(int argc, char **argv) {
	std::vector<int> ivec;
	std::list<int> lst;
	int ival;
	std::cout << "Enter elements for vector(cltr + d to end):" << std::endl;
	while (std::cin >> ival)
		ivec.push_back(ival);
	std::cin.clear();
	std::cout << "Enter elements for list(cltr + d to end):" << std::endl;
	while (std::cin >> ival)
		lst.push_back(ival);
	bool isTure = isEqual(ivec, lst);
	if (isTure) {
		std::cout << "contains the same elements" << std::endl;
	} else {
		std::cout << "contains diffrent elements" << std::endl;
	}
	return 0;
}

bool isEqual(const std::vector<int> &ivec, const std::list<int> &lst) {
	std::vector<int>::const_iterator iter1 = ivec.begin();
	std::list<int>::const_iterator iter2 = lst.begin();
	if (ivec.size() != lst.size())
		return false;
	//for (iter1 = ivec.begin(), iter2 = lst.begin(); iter1 != ivec.end() || iter2 != lst.end(); ++iter1, ++iter2)
	for ( ; iter1 != ivec.end() || iter2 != lst.end(); ++iter1, ++iter2)
		if (*iter1 != *iter2)
			return false;
	return true;
}
