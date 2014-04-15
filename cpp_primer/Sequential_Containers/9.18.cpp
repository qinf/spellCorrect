/*
* 9.18.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <list>
#include <deque>

int main(int argc, char **argv) {
	std::list<int> lst;
	std::deque<int> deque1;
	std::deque<int> deque2;
	for (int i = 0; i != 10; ++i)
		lst.push_back(i);

	for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
		if (*iter % 2 == 0)
			deque1.push_back(*iter);
		else
			deque2.push_back(*iter);
	}

	for (std::deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	for (std::deque<int>::iterator iter = deque2.begin(); iter != deque2.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

