#include "Fraction.h"

int Fraction::gcd(int a, int b)
{
	if (a < b) {
		std::swap(a, b);
	}

	while (b) {
		a %= b;
		std::swap(a, b);
	}

	return a;
}

Fraction::Fraction() : _numerator(0), _denominator(1)
{}

Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
	int g = gcd(_numerator, _denominator);
	_numerator /= g;
	_denominator /= g;
}

void Fraction::SetDenominator(int denominator) {
	_denominator = denominator;
}


void Fraction::SetNumerator(int numerator) {
	_numerator = numerator;
}


void Fraction::SetBoth(int numerator, int denominator) {
	_denominator = denominator;
	_numerator = numerator;
}

int Fraction::GetDenominator() const {
	return _denominator;
}

int Fraction::GetNumerator() const {
	return _numerator;
}

void Fraction::Print() const {
	if (_numerator < _denominator)
		std::cout << _numerator << "/" << _denominator;
	else if (_numerator == _denominator)
		std::cout << 1;
	else
		std::cout << _numerator / _denominator << "." << (_numerator % _denominator) << "/" << _denominator;
}

Fraction Fraction::operator*(const Fraction& f)
{
	return Fraction(_numerator * f.GetNumerator(), _denominator * f.GetDenominator());;
}

Fraction Fraction::operator/(const Fraction& f)
{
	return Fraction(_numerator * f.GetDenominator(), _denominator * f.GetNumerator());
}

Fraction Fraction::operator+(const Fraction& f)
{
	int numerator, denominator;
	denominator = _denominator * f.GetDenominator();
	numerator = _numerator * f.GetDenominator() + _denominator * f.GetNumerator();
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator-(const Fraction& f)
{
	int numerator, denominator;
	denominator = _denominator * f.GetDenominator();
	numerator = _numerator * f.GetDenominator() - _denominator * f.GetNumerator();
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator+()
{
	return *this;
}

Fraction Fraction::operator-()
{
	_numerator = -_numerator;
	return *this;
}

Fraction Fraction::operator++()
{
	_numerator += _denominator;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction tmp{ _numerator, _denominator };
	++(*this);
	return tmp;
}

Fraction Fraction::operator--()
{
	_numerator -= _denominator;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction tmp{ _numerator, _denominator };
	--(*this);
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	if (std::abs(f.GetNumerator()) < f.GetDenominator())
		out << f.GetNumerator() << "/" << f.GetDenominator();
	else if (std::abs(f.GetNumerator()) == f.GetDenominator())
	{
		if(f.GetNumerator() < 0)
			out << -1;
		else
			out << 1;
	}
	else
	{
		if(f.GetNumerator() < 0)
			out << "-" << (std::abs(f.GetNumerator()) / f.GetDenominator()) << "." << ((std::abs(f.GetNumerator()) % f.GetDenominator()) << "/" << f.GetDenominator();
		else
			out << f.GetNumerator() / f.GetDenominator() << "." << f.GetNumerator() % f.GetDenominator() << "/" << f.GetDenominator();
	}
	return out;
}