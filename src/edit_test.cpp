/*************************************************************************
	> File Name: edit_test.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月08日 星期四 21时09分26秒
 ************************************************************************/

#include "EditDistance.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	string a = "hello";
	string b = "a";
	EditDistance edit_dis;
	int count = edit_dis.get_edit_distance(a, b);
	cout << count << endl;
}
