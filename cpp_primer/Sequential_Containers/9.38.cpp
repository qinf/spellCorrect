/*
 * 9.38.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void find_target1(const string &src, const string &target);
void find_target2(const string &src, const string &target);

int main(int argc, char **argv) {
	string src = "Build 2of 3configuration 5Debug 6for 7project primer_09";
	string dig = "0123456789";
	string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//find_digital1(src, alp);
	find_target2(src, dig);
}


void find_target1(const string &src, const string &target) {
	string::size_type pos = 0;
	while ((pos = src.find_first_of(target, pos)) != string::npos) {
		cout << src[pos] << " ";
		++pos;
	}
	cout << endl;
}

void find_target2(const string &src, const string &target) {
	string::size_type pos = 0;
		while ((pos = src.find_first_not_of(target, pos)) != string::npos) {
			cout << src[pos] << " ";
			++pos;
		}
		cout << endl;
}
