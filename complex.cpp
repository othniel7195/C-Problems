#include "pch.h"
#include "complex.h"
#include <iostream>
using namespace std;

complex::~complex() {

}
complex& complex::operator += (const complex& c2) {
	this->rel += c2.rel;
	this->img += c2.img;
	return *this;
}

complex& complex::operator++ () {
	++(this->rel);
	++(this->img);
	return *this;
}


ostream& operator <<(ostream &os, const complex  &c1) {
	return os << "(real:" << c1.real() << "," << "imge:" << c1.imge()<<")";
}




