#include <iostream>
#include <iomanip>
#include <cmath>
#include "BruteForce.h"
#include "Iteration.h"
#include "Newton.h"
#include "Bisection.h"
using namespace std;

#define precision1 7
#define eps1 0.000001

#define precision2 9
#define eps2 0.00000001

double f1(double x)
{
    return x - cos(x);
}

double f2(double x)
{
    return x - 10 * cos(x);
}

double g1(double x)
{
    return cos(x);
}

double g2(double x)
{
    return 10 * cos(x);
}

double df1(double x)
{
    return 1 + sin(x);
}

double df2(double x)
{
    return 1 + 10 * sin(x);
}

int main()
{
    system("chcp 1251 > nul");

    // cout << "--- Метод перебора ---" << endl;
    // cout << setprecision(precision1) << "x1 = " << BruteForce(0.0, 1.0, eps1, f1) << endl;
    // cout << setprecision(precision2) << "x1 = " << BruteForce(0.0, 1.0, eps2, f1) << endl;  // Не хватает времени
    // cout << setprecision(precision1) << "x2 = " << BruteForce(1.0, 2.0, eps1, f2) << endl;

    // cout << "\n\n\n\n";

    cout << "--- Метод итераций ---" << endl;
    cout << setprecision(precision1) << "x1 = " << Iteration(0.0, 1.0, eps1, g1) << endl;
    cout << setprecision(precision2) << "x1 = " << Iteration(0.0, 1.0, eps2, g1) << endl;
    cout << setprecision(precision1) << "x2 = " << Iteration(1.0, 2.0, eps1, g2) << endl;

    cout << "\n\n\n\n";

    cout << "--- Метод Ньютона ---" << endl;
    cout << setprecision(precision1) << "x1 = " << Newton(1.0, eps1, f1, df1) << endl;
    cout << setprecision(precision2) << "x1 = " << Newton(1.0, eps2, f1, df1) << endl;
    cout << setprecision(precision1) << "x2 = " << Newton(1.0, eps2, f2, df2) << endl;

    cout << "\n\n\n\n";

    cout << "--- Метод половинного деления ---" << endl;
    cout << setprecision(precision1) << "x1 = " << Bisection(0.0, 1.0, eps1, f1) << endl;
    cout << setprecision(precision2) << "x1 = " << Bisection(0.0, 1.0, eps2, f1) << endl;
    cout << setprecision(precision1) << "x1 = " << Bisection(-10000, 10000, eps1, f1) << endl;
    cout << setprecision(precision2) << "x1 = " << Bisection(-10000, 10000, eps2, f1) << endl;
    cout << setprecision(precision1) << "x2 = " << Bisection(1.0, 2.0, eps1, f2) << endl;

    return 0;
}