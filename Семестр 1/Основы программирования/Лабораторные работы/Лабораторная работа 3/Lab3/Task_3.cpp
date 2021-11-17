#include "Task_3.h"
#include "Task_3_S.h"
#include "Task_3_Y.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


void printArray(const char *label, double *arr) {
    cout << left << setw(6) << label;
    for (int i = 0; i < 6; i++)
        cout << setw(6) << setprecision(7) << fixed << " " << arr[i];
    cout << endl;
}

void task3() {
    cout << "--- ¹3 ---" << endl;

    double array_x[6];
    double array_S[6];
    double array_Y[6];
    double array_N[6];

    int i = 0;
    int number;

    for (double x = 0.0; x <= 1; (x += 0.2, i++)) {
        array_x[i] = x;
        array_S[i] = S(x, number);
        array_Y[i] = Y(x);
        array_N[i] = number;
    }

    printArray("x", array_x);
    printArray("S", array_S);
    printArray("Y", array_Y);
    printArray("N", array_N);

    cout << "\n\n\n\n";
}