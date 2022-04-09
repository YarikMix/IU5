#include <iostream>
#include "Stack.h"
using namespace std;

int nod(int& n) {
	int d = 2;
	while (n % d != 0) {
		d++;
	}
	n /= d;
	return d;
}

void Calculate(int n)
{
	if (n == 1)
	{
		cout << "Количество множителей: 1" << endl << "1" << endl << "1" << "\n\n\n";
		return;
	}

	Stack adiv;
	Stack ddiv;

	while (n != 1)
	{
		adiv.push(nod(n));
	}

	cout << "Количество множителей: " << adiv.size() << endl;

	int d = 0;
	while (adiv.pop(d))
	{
		ddiv.push(d);
		cout << d;
		if (!adiv.empty(d))
			cout << " * ";
	}

	cout << endl;

	while (ddiv.pop(d))
	{
		cout << d;
		if (!ddiv.empty(d))
			cout << " * ";
	}

	cout << "\n\n\n";
}

int getInt()
{
	double num;

	cout << "Введите число для разложения\n> ";
	cin >> num;
	while (num != static_cast<int>(num) || num <= 0)
	{
		cout << "Число должно быть целым и положительным!\n> ";
		cin >> num;
	}

	cin.ignore(80, '\n');
	return static_cast<int>(num);
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

	while (true)
	{
		int n = getInt();
		Calculate(n);
	}
}