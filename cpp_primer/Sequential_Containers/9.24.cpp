/*
* 9.24.cpp
*
*  Created on: Apr 13, 2014
*      Author: qinf
*/

#include <iostream>
#include <vector>
#include <stdexcept>

int getFirstItme(std::vector<int> ivec) {
	if (!ivec.empty())
		return ivec[0];
	else
		throw std::exception("ivec is empty");
}

int getFirstItme_2(std::vector<int> ivec) {
	if (!ivec.empty())
		return ivec.front();//返回的是引用
	else
		throw std::exception("ivec is empty");
}

int getFirstItme_3(std::vector<int> ivec) {
	if (!ivec.empty())
		return *(ivec.begin());
	else
		throw std::exception("ivec is empty");
}
