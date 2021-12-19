#include "Task_3_S.h"
#include "Task_3_Y.h"
#include <iostream>
using namespace std;

#define eps 0.000001

double get_k(double x, int n)
{
    return -0.5 * x * x * (2 * n * n + 1) / (n * (2 * n - 1) * ( 2 * (n - 1) * (n - 1) + 1));
}

double S(double x, int & number) {
    int n = 1;
    double a = 1.0;
    double res = a;

    while (fabs(res - Y(x)) >= eps)
    {
        a = a * get_k(x, n);
        res += a;
        n++;
    }

    number = n;

    return res;
}