/*
* 9.28.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <list>
#include <vector>

int main(int argc, char **argv) {
	char *s[] = {"Hehe", "haha", "biubiu", "foo", "bar"};
	std::list<char *> lst(s, s + 5);
	std::vector<std::string> svec;
	svec.assign(lst.begin(), lst.end());

	for (std::vector<std::string>::iterator iter = svec.begin(); iter != svec.end(); ++iter)
		std::cout << *iter << std::endl;

	return 0;
}

