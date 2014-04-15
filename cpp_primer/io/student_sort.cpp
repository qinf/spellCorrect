/*
 * student_sort.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
#include <algorithm>

using std::endl;
using std::cout;
using std::string;

struct Student {
	int id;
	string name;
	double score;
};

bool cmp(Student a, Student b) {//1.按分数排，如果分数相等按名字排，如果名字相等按id排
	if (a.score != b.score)
		return a.score < b.score;
	else if(a.name != b.name)
		return a.name > b.name;
	else
		return a.id > b.id;
}
void swap(Student &a, Student &b) {
	Student c;
	c.id = a.id;
	c.score = a.score;
	c.name = a.name;
	a.id = b.id;
	a.name = b.name;
	a.score = b.score;
	b.id = c.id;
	b.name = c.name;
	b.score = c.score;
}
void bubble_sort(Student *arr, int len, bool (*cmp)(Student, Student)) {
	for (std::size_t i = 0; i < (std::size_t)len; ++i) {
		for (std::size_t j = 0; j < len - i -1; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main()
{
	Student arr[] = {{102, "xiaoming", 68}, {100, "xiaoxin", 60}, {103, "xiaoqing", 90}};
	bubble_sort(arr, 3, cmp);
	for(std::size_t ix = 0; ix < 3; ++ix) {
		cout << "id= " << arr[ix].id << " ,name= " << arr[ix].name << " ,score= " << arr[ix].score << endl;
	}
	return 0;
}
