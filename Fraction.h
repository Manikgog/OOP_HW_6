#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

class Fraction {
private:
	int _numerator;
	int _denominator;
	int gcd(int a, int b);
public:
	Fraction();

	explicit Fraction(int numerator, int denominator);

	void SetDenominator(int denominator);

	void SetNumerator(int numerator);

	void SetBoth(int numerator, int denominator);

	int GetDenominator() const;

	int GetNumerator() const;

	void Print() const;

	Fraction operator*(const Fraction& f);

	Fraction operator/(const Fraction& f);

	Fraction operator+(const Fraction& f);

	Fraction operator-(const Fraction& f);

	Fraction operator++();

	Fraction operator++(int);

	Fraction operator--();

	Fraction operator--(int);

};



#endif
