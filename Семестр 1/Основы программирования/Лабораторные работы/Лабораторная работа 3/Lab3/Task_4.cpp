#include "Task_4.h"
#include <iostream>
#include <cmath>
using namespace std;

float y(int n) 
{
	if (n > 1)
		return sqrt(2 * n + y(n - 1));
	else if (n == 1)
		return sqrt(2);
	else
		return 0;
}

void task4() {
	cout << "--- №4 ---" << endl;
	cout << "y(3) = " << y(3) << endl;
	cout << "y(5) = " << y(5) << endl;
	cout << "y(10) = " << y(10) << endl << endl;

	int n;
	char s;
	while (true)
	{
		cout << "Введите n = ";
		cin >> n;
		cout << "y(" << n << ") = " << y(n) << endl << endl;

		cout << "Продолжить работу? y/n > ";
		cin >> s;
		if (s == 'n') break;
	}
}