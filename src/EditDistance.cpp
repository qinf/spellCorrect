/*************************************************************************
	> File Name: EditDistance.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 16时41分48秒
 ************************************************************************/

#include "EditDistance.h"
#include <iostream>
using namespace std;


EditDistance::EditDistance() {

}
EditDistance::~EditDistance() {

}
int EditDistance::get_edit_distance(const string &a, const string &b) {
	int memo[100][100];
	for(int i = 0; i != a.size(); ++i)
		memo[i][0] = i;
	for(int j = 0; j != b.size(); ++j)
		memo[0][j] = j;
	
	int i, j;
	for(i = 1; i <= a.size(); ++i) {
		for(j = 1; j <= b.size(); ++j) {
			if(a[i-1] == b[j-1])
				memo[i][j] = memo[i-1][j-1];
			else
				memo[i][j] = MIN(memo[i-1][j]+1, memo[i][j-1]+1, memo[i-1][j-1]+1);
		}
	}
	return memo[a.size()][b.size()];
}

int EditDistance::MIN(int a, int b, int c) {
	if(a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}

