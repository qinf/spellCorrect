/*************************************************************************
	> File Name: EditDistance.cpp
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 16时41分48秒
 ************************************************************************/

#include "EditDistance.h"

#include <iostream>
#include <stdexcept>
#include <string.h>
#include "EncodingConverter.h"

using namespace std;

EditDistance::EditDistance() {

}
EditDistance::~EditDistance() {

}

bool is_gbk_first_alpha(unsigned char c) {
	return c >= 0x81 && c <= 0xFE; //首字节范围
}

int MIN(int a, int b, int c) {
	if(a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}

// string -> uint16_t array
void parse_gbk_string(const string &s, vector<uint16_t> &vec) {
	for(string::size_type ix = 0; ix != s.size(); ++ix) {
		if(is_gbk_first_alpha(s[ix])) {
			if(ix +1 == s.size())
				throw runtime_error("invalid GBK string");

			//进行一次拼接
			unsigned char c1 = s[ix];
			unsigned char c2 = s[++ix];
			uint16_t c = (c1 << 8) + c2;
			vec.push_back(c);
		} else {
			uint16_t c = (unsigned char)s[ix];
			vec.push_back(c);
		}
	}
}

/*
 * 中文编辑距离算法
 */
int edit_distance_uint_16(const vector<uint16_t> &w1, const vector<uint16_t> &w2) {
	int len_a = w1.size();
	int len_b = w2.size();
	int memo[100][100];
	memset(memo, 0, 100*100*sizeof(int));
	for(int i = 1; i <= len_a; ++i)
		memo[i][0] = i;
	for(int j = 1; j <= len_b; ++j)
		memo[0][j] = j;
	for(int i = 1; i <= len_a; ++i) {	//i,j均从1开始
		for(int j = 1; j <= len_b; ++j) {
			if(w1[i-1] == w2[j-1]) {
				memo[i][j] = memo[i-1][j-1];
			} else {
				memo[i][j] = MIN(memo[i][j-1], memo[i-1][j], memo[i-1][j-1]) + 1;
			}
		}
	}
	return memo[len_a][len_b];
}

int EditDistance::get_edit_distance(const string &a, const string &b) {
		vector<uint16_t> w1, w2;
		parse_gbk_string(a, w1);
		parse_gbk_string(b, w2);
		return edit_distance_uint_16(w1, w2);
}

//英文处理的
//int EditDistance::get_edit_distance(const string &a, const string &b) {
//	int memo[100][100];
//	for(int i = 0; i <= a.size(); ++i)
//		memo[i][0] = i;
//	for(int j = 0; j <= b.size(); ++j)
//		memo[0][j] = j;
//
//	int i, j;
//	for(i = 1; i <= a.size(); ++i) {
//		for(j = 1; j <= b.size(); ++j) {
//			if(a[i-1] == b[j-1])
//				memo[i][j] = memo[i-1][j-1];
//			else
//				memo[i][j] = MIN(memo[i-1][j]+1, memo[i][j-1]+1, memo[i-1][j-1]+1);
//		}
//	}
//	return memo[a.size()][b.size()];
//}

int EditDistance::MIN(int a, int b, int c) {
	if(a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}


