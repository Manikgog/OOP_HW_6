#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

/*
—оздайте класс ƒробь (или используйте уже ранее созданный вами). 
»спользу€ перегрузку операторов реализуйте
дл€ него арифметические операции дл€ работы с дроб€ми
(операции +, -, *, /).
*/
class Fraction {
private:
	int _numerator;
	int _denominator;
	int gcd(int a, int b) {
		if (a < b) {
			std::swap(a, b);
		}

		while (b) {
			a %= b;
			std::swap(a, b);
		}

		return a;
	}
public:
	Fraction() : _numerator(0), _denominator(1)
	{}

	Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
	{
		int g = gcd(_numerator, _denominator);
		_numerator /= g;
		_denominator /= g;
	}

	void SetDenominator(int denominator) {
		_denominator = denominator;
	}


	void SetNumerator(int numerator) {
		_numerator = numerator;
	}


	void SetBoth(int numerator, int denominator) {
		_denominator = denominator;
		_numerator = numerator;
	}

	int GetDenominator() const {
		return _denominator;
	}

	int GetNumerator() const {
		return _numerator;
	}

	void Print() const {
		std::cout << _numerator << "/" << _denominator;
	}

	Fraction operator*(const Fraction& f)
	{
		return Fraction(_numerator * f.GetNumerator(), _denominator * f.GetDenominator());;
	}

	Fraction operator/(const Fraction& f)
	{
		return Fraction(_numerator * f.GetDenominator(), _denominator * f.GetNumerator());
	}

	Fraction operator+(const Fraction& f)
	{
		int numerator, denominator;
		denominator = _denominator * f.GetDenominator();
		numerator = _numerator * f.GetDenominator() + _denominator * f.GetNumerator();
		return Fraction(numerator, denominator);
	}

	Fraction operator-(const Fraction& f)
	{
		int numerator, denominator;
		denominator = _denominator * f.GetDenominator();
		numerator = _numerator * f.GetDenominator() - _denominator * f.GetNumerator();
		return Fraction(numerator, denominator);
	}
	
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));
	// вычитание
	Fraction f1(3, 5);
	Fraction f2(1, 2);
	f1.Print();
	std::cout << " - ";
	f2.Print();
	std::cout << " = ";
	Fraction f3;
	f3 = f1 - f2;
	f3.Print();
	std::cout << "\n\n";

	// сложение
	f1.Print();
	std::cout << " + ";
	f2.Print();
	std::cout << " = ";
	f3 = f1 + f2;
	f3.Print(); 
	std::cout << "\n\n";

	// умножение
	f1.Print();
	std::cout << " * ";
	f2.Print();
	std::cout << " = ";
	f3 = f1 * f2;
	f3.Print();
	std::cout << "\n\n";

	// деление
	f1.Print();
	std::cout << " / ";
	f2.Print();
	std::cout << " = ";
	f3 = f1 / f2;
	f3.Print();
	std::cout << "\n\n";


	return 0;
}
