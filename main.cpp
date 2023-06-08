#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Fraction.h"
#include "Complex.h"

/*
Задание 1.
Создайте класс Дробь (или используйте уже ранее созданный вами). 
Используя перегрузку операторов реализуйте
для него арифметические операции для работы с дробями
(операции +, -, *, /).
*/

/*
Задание 2.
Создайте класс Complex (комплексное число) или используйте 
уже созданный вами класс.Создайте перегруженные
операторыдля реализации арифметических операций для
по работе с комплексными числами (операции +, -, *, /).
*/

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	
	
	// вычитание
	Fraction f1(6, 5);
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
	

	// сложение комплексных чисел
	Complex c1(13, 1);
	Complex c2(7, -6);
	c1.Print();
	std::cout << " + ";
	c2.Print();
	std::cout << " = ";
	Complex c3 = c1 + c2;
	c3.Print();
	std::cout << "\n\n";

	// вычитание комплексных чисел
	c1.Print();
	std::cout << " - ";
	c2.Print();
	std::cout << " = ";
	c3 = c1 - c2;
	c3.Print();
	std::cout << "\n\n";

	// умножение комплексных чисел
	c1.Print();
	std::cout << " * ";
	c2.Print();
	std::cout << " = ";
	c3 = c1 * c2;
	c3.Print();
	std::cout << "\n\n";

	// деление комплексных чисел
	c1.Print();
	std::cout << " / ";
	c2.Print();
	std::cout << " = ";
	c3 = c1 / c2;
	c3.Print();
	std::cout << "\n\n";

	return 0;
}
