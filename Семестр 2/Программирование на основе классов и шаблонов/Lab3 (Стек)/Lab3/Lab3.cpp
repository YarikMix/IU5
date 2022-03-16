#include <iostream>
#include "myStack.h"
using namespace std;

int nod(int& n) {
	int d = 2;
	while (n % d != 0) {
		d++;
	}
	n /= d;
	return d;
}


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

	myStack adiv;
	myStack ddiv;
	int n;
	cout << "Введите число для разложения: ";
	cin >> n;

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

	cout << endl;
}