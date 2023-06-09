#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
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

void loop()
{
	char choice = 'w';
	do
	{
		std::cout << "Для выхода из программы введите \'q\': ";
		std::cin >> choice;
		system("cls");
		std::string first_fraction;
		std::cout << "Введите первую дробь -> ";
		std::cin.ignore();
		std::getline(std::cin, first_fraction);
		std::string action;
		do {
			std::cout << "Введите действие -> ";
			std::getline(std::cin, action);
		} while (action != "+" && action != "-" && action != "*" && action != "/");
				
		std::string second_fraction;
		std::cout << "Введите вторую дробь -> ";
		std::getline(std::cin, second_fraction);

		size_t pos = first_fraction.find('/', 0);
		std::string numerator = first_fraction.substr(0, pos);
		std::string denominator = first_fraction.substr(pos + 1);
		int num = stoi(numerator);
		int den = stoi(denominator);
		Fraction f1(num, den);
		
		pos = second_fraction.find('/', 0);
		numerator = second_fraction.substr(0, pos);
		denominator = second_fraction.substr(pos + 1);
		num = stoi(numerator);
		den = stoi(denominator);
		Fraction f2(num, den);
		Fraction f3;
		if(action == "+")
			f3 = f1 + f2;
		else if(action == "-")
			f3 = f1 - f2;
		else if(action == "*")
			f3 = f1 * f2;
		else
			f3 = f1 / f2;
		f1.Print(); std::cout << ' ' << action << ' '; f2.Print(); std::cout << " = "; f3.Print(); std::cout << std::endl;
		
	} while (choice != 'q' && choice != 'Q');
}



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	
	/*
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
	*/

	loop();

	return 0;
}
