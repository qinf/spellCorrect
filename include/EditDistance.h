/*************************************************************************
	> File Name: EditDistance.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月07日 星期三 16时41分52秒
 ************************************************************************/

#ifndef EDITDISTANCE_H_
#define EDITDISTANCE_H_

#include <string>

class EditDistance {
public:
	EditDistance();
	~EditDistance();
	int get_edit_distance(const std::string &, const std::string &);
	int MIN(int a, int b, int c);
private:
	
};

#endif /* EDITDISTANCE_H_ */
