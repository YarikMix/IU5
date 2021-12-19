#include <iostream>
using namespace std;

void first() 
{
	setlocale(LC_ALL, "");
	string s1, s2;
	cout << "Введите первое слово: ";
	cin >> s1;
	cout << "Введите второе слово: ";
	cin >> s2;
	cout << "Ваша строка: " << s1 + " " + s2 << endl;
}

void second()
{
	// setlocale(LC_ALL, "");
	int a, b;
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Сумма: " << a + b << endl;
}

void third()
{
	// setlocale(LC_ALL, "");
	float a, b;
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Среднее арифметическое: " << (a + b) / 2 << endl;
}

void main()
{

	system("chcp 1251 > null");
	first();
	second();
	third();
}
