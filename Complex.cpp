#include "Complex.h"

Complex::Complex() : _a(0), _bi(0){}

Complex::Complex(int a, int bi) : _a(a), _bi(bi) {}

Complex::~Complex(){}

void Complex::Print()
{
	std::cout << _a;
	if (_bi > 0)
		 std::cout << "+" << _bi << 'i';
	else
		std::cout << _bi << 'i';
}

Complex Complex::operator+(const Complex& c)
{
	return Complex(_a + c._a, _bi + c._bi);
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(_a - c._a, _bi - c._bi);
}

Complex Complex::operator*(const Complex& c)
{
	int a = _a * c._a + _bi * c._bi * (-1);
	int b = _a * c._bi + _bi * c._a;
	return Complex(a, b);
}

Complex Complex::operator/(const Complex& c)
{
	Complex sopr(c._a, -(c._bi));
	int a = _a * sopr._a + _bi * sopr._bi * (-1);
	int b = _a * sopr._bi + _bi * sopr._a;
	Complex numerator(a, b);
	a = c._a * sopr._a;
	b = -1 * (c._bi * sopr._bi);
	int d = a + b;
	return Complex(numerator._a / d, numerator._bi/ d);
}