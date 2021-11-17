#include "Iteration.h"
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_ITER 5000000

double Iteration(double start, double end, double eps, double(f(double x)))
{
	double x0 = start;
	double x1 = end;
	int iter = 0;

	do
	{
		x1 = f(x0);
		x0 = x1;
		iter++;
	} while (abs(x1 - x0) < eps && iter < MAX_ITER);

	cout << "Количество итераций " << iter << endl;
	return x1;
}