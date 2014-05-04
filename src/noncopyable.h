/*************************************************************************
	> File Name: noncopyable.h
	> Author: qinf
	> Mail: 
	> Created Time: 2014年05月04日 星期日 10时11分22秒
 ************************************************************************/

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

/*
 * noncopyable接口，禁止复制和复制
 * 将拷贝构造函数和赋值运算符设为私有，防止对象的复制
 * 将构造函数和析构函数设为protected，防止生成本类的对象
 */
class noncopyable {
public:
	noncopyable() {}
	～noncopyable() {}
private:
	noncopyable(const noncopyable &);
	noncopyable &operator=(const noncopyable &);
};

#endif /* NONCOPYABLE_H_ */
