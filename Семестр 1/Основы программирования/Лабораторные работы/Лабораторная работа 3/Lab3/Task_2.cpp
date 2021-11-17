#include <iostream>
#include <iomanip>
#include "Task_2.h"
using namespace std;

double S(double a)
{
    double s = 1.0;
    if (a >= 0)
    {
        for (int i = 2; i <= 9; i += 2)
            s = s * i * i;
        s = s - a;
    }
    else {
        for (int i = 3; i <= 9; i += 3)
            s = s * (i - 2);
    }
    return s;
}

void task2()
{
    cout << "--- №2 ---" << endl;
    cout << "a = 5.7, S(5.7) = " << S(5.7) << endl << endl;


    double a;
    cout << "Введите a: ";
    cin >> a;
    cout << setprecision(8) << "a = " << a << ", S(" << a << ") = " << S(a) << "\n\n\n\n";
}