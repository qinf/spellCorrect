/*
* 9.42.cpp
*
*  Created on: Apr 14, 2014
*      Author: qinf
*/

#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::stack;
using std::endl;

void word_stack(std::istream &in);

int main(int argc, char **argv) {
	word_stack(cin);
}

void word_stack(std::istream &in) {
	string word;
	stack<string> wd_stack;
	while (in >> word) {
		wd_stack.push(word);
	}

	while(!wd_stack.empty()) {
		cout << wd_stack.top() << endl;
		wd_stack.pop();
	}
}
