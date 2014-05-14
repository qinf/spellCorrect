/*
 * 10.25.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unistd.h>

using namespace std;
int main(int argc, char **argv) {
	vector<string> book_vec;
	set<string> readed_book_set;
	string book_name, reading_book;
	string flag, answer;
	bool timeOver = false;
	cout << "Enter book's name which you will read in 6 months:" << endl;
	while (cin >> book_name)
		book_vec.push_back(book_name);
	while (!timeOver && !book_vec.empty()) {
		cout << "Do you like read a book?(y or n)" << endl;
		cin.clear();
		cin >> answer;
		if (answer[0] == 'Y' || answer[0] == 'y') {
			cout << "----------booklist----------" << endl;
			for (vector<string>::const_iterator iter = book_vec.begin();
					iter != book_vec.end(); ++iter) {
				cout << *iter << endl;
			}
			cout << "Choose a book you want to read now:" << endl;
			cin.clear();
			cin >> reading_book;
			for (vector<string>::iterator iter = book_vec.begin();
					iter != book_vec.end(); ++iter) {
				cout << book_vec.size() << endl;
				cout << *iter << "---------" << endl;
				if (*iter == reading_book) {
					book_vec.erase(iter);//这里犯错了，删除后此时的迭代器失效
					break;
				}
			}
			readed_book_set.insert(reading_book);
			sleep(3);
			cout << "Have you readed book: " << reading_book
					<< "?(Enter y or n)" << endl;
			cin.clear();
			cin >> flag;
			if (flag == "y" || flag == "Y") {
				cout << "Congratulation! Have fun with reading" << endl;
			} else {
				cout << "Bad news!" << endl;
				readed_book_set.erase(reading_book);
				book_vec.push_back(reading_book);
			}
		}
		cout << "Time over?(yes or no)" << endl;
		cin.clear();
		cin >> answer;
		if (answer[0] == 'y' || answer[0] == 'Y')
			timeOver = true;
	}

	if (timeOver) {
		cout << "you have readed those books:" << endl;
		for (set<string>::iterator iter = readed_book_set.begin();
				iter != readed_book_set.end(); ++iter) {
			cout << *iter << endl;
		}
		cout << "books not read:" << endl;
		for (vector<string>::iterator iter = book_vec.begin();
				iter != book_vec.end(); ++iter) {
			cout << *iter << endl;
		}
	} else {
		cout << "Congratulation! You have read all the books" << endl;
	}

	return 0;
}

