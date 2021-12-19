#include "Newton.h"
#include <math.h>
#include <iostream>
using namespace std;

#define MAX_ITER 5000000

double Newton(double x, double eps, double(f(double)), double(df(double)))
{
    int iter = 1;
    do 
    {
        x = x - f(x) / df(x);
        iter++;

        if (df(x) == 0)
            break;

        if (iter > MAX_ITER)
            break;
    } while (abs(f(x)) > eps);

    cout << "Количество итераций " << iter << endl;
    return x;
}