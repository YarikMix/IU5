#include "BruteForce.h"
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_ITER 5000000

double BruteForce(double start, double end, double eps, double(f(double x)))
{
	double max_iter = MAX_ITER;
	double step = (end - start) / MAX_ITER;
	int iter = 0;
	double res = 0;
	for (double x = start; x <= end; (x += step, iter++)) {
		if (abs(f(x)) <= eps) {
			res = x;
			break;
		}
	}

	cout << "Количество итераций " << iter << endl;
	return res;
}