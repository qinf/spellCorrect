/*
 * stream_test.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: qinf
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

using std::endl;
using std::cout;
using std::string;
using std::vector;

int main() {
	vector<string> file_vec;
	string filename1 = "1.txt", filename2 = "2.txt", filename3 = "3.txt";
	file_vec.push_back(filename1);
	file_vec.push_back(filename2);
	file_vec.push_back(filename3);

	std::ifstream infile;

	vector<vector<string> > liness, wordss;
	for (vector<string>::iterator iter = file_vec.begin();
			iter != file_vec.end(); ++iter) {
		string line, word;
		vector<string> lines, words;
		infile.open((*iter).c_str());
		if (!infile) {
			throw std::runtime_error("can not open file");
		}
		while (getline(infile, line)) {
			lines.push_back(line);
			std::istringstream in_word(line);
			if (!in_word) {
				throw std::runtime_error("in_word filed");
			}
			while (in_word >> word) {
				words.push_back(word);
			}
		}
		liness.push_back(lines);
		wordss.push_back(words);
		infile.close();
	}

	for (std::size_t ix = 0; ix != file_vec.size(); ++ix) {
		cout << file_vec[ix] << " lines: " << liness[ix].size() << " words: " << wordss[ix].size() << endl;
	}
	return 0;
}

