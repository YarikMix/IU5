#include <iostream>
#include "Task_1.h"
using namespace std;

int get_sum(int n, int m)
{
    int i = 1;
    int k = 0;
    int sum = 0;
    while (k < n)
    {
        if (i % 5 == 0 && i % m != 0) {
            k++;
            sum += i;
        }
        i += 1;
    }
    return sum;
}

void task1()
{
    char s = 'y';
    int n, m;

    cout << "--- №1 ---" << endl;

    while (true)
    {
        cout << "Введите n и m (n > m, m != 5)" << endl;
        cout << "n: ";
        cin >> n;
        cout << "m: ";
        cin >> m;

        if (n < m || m == 5)
            cout << "Введены недопустимые данные" << endl;
        else
            cout << "Сумма = " << get_sum(n, m) << endl;

        cout << "Продолжить работу? y/n > ";
        cin >> s;
        if (s == 'n') break;
    }
        

    cout << "\n\n\n\n";
}