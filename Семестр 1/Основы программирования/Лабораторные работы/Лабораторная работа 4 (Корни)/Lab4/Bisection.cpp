#include "Bisection.h"
#include <iostream>
using namespace std;

#define BISECT_STEP 0.05
#define MAX_ITER 5000000

double Bisection(double x0, double x1, double eps, double(f(double)))
{
    double left = x0;
    double right = x1;

    while (f(left) * f(right) >= 0) {
        left -= BISECT_STEP;
        right += BISECT_STEP;
    }

    double x;
    int iter = 0;
    do {
        x = (left + right) / 2;

        if (f(x) > 0)
            right = x;
        else 
            left = x;

        iter++;
    } while (fabs(f(x)) > eps && iter < MAX_ITER);

    cout << "Количество итераций " << iter << endl;
    return x;
}