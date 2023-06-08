#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

class Complex
{
public:
	Complex();
	Complex(int a, int bi);
	~Complex();
	void Print();
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

private:
	double _a;
	double _bi;
};





#endif