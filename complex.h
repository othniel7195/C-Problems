#include <iostream>
#ifndef __COMPLEX_H_
#define __COMPLEX_H_

using namespace std;

class complex
{
public:
	complex(double r= 0, double i = 0) :rel(r), img(i) {};
	~complex();

	complex& operator += (const complex& c2);
	complex& operator ++ ();// ++a;
	
	double real() const { return rel; };
	double imge() const { return img; };
private:
	double rel;
	double img;
	
};

ostream & operator<<(ostream & os, const complex & c1);



#endif 

//是内联函数声明与定义分开时，不可以被其他文件引用。
//就是说，在类A中，有一个内联函数a()，如果我们在A.h中对其声明并定义，
//那么并没有影响；但如果我们在A.h中对其声明，然后在A.cpp中对其定义，那么不能在其他的类中再使用它。