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

//���������������붨��ֿ�ʱ�������Ա������ļ����á�
//����˵������A�У���һ����������a()�����������A.h�ж������������壬
//��ô��û��Ӱ�죻�����������A.h�ж���������Ȼ����A.cpp�ж��䶨�壬��ô������������������ʹ������