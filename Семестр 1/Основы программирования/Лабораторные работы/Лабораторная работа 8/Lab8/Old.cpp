#include "Old.h"
#include <iomanip>
#define width 80
using namespace std;

// Факториал
double Fact(int n)
{
    long int f = 1;
    for (int k = 1; k < (n + 1); k++) f *= k;
    return (long double)f;
}

int get_setprecision(int N)
{
    return int(width / N - 4);
}

double GetA(int i, int j, int x, int sign) {
    return pow(sign * x, i) / pow(Fact(j), i);
}

void FillMatrix(double** A, int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        // Элементы, лежащие ниже главной диагонали
        for (int j = 0; j < i; j++)
            A[i][j] = pow(x, i) / pow(Fact(j), i);

        // Элементы, лежащие выше главной диагонали
        for (int j = i + 1; j < N; j++)
            A[i][j] = pow(-x, i) / pow(Fact(j), i);
    }
}

void Leha(double** A, int N, int x)
{
    A[0][1] = GetA(1, 2, x, 1);
    A[1][0] = GetA(2, 1, x, -1);
    for (int i = 0; i < N - 1; i++) {
        int I = i + 1;
        if (i != 0) {
            A[i][i + 1] = (A[i - 1][i + 1] * x) / Fact(I + 1);
        }
        for (int j = i + 2; j < N; j++) {
            int J = j + 1;
            A[i][j] = A[i][j - 1] / pow(J, I);
        }
    }
    for (int i = 2; i < N; i++) {
        int I = i + 1;
        A[i][0] = -A[i - 1][0] * x;
        for (int j = 1; j < i; j++) {
            int J = j + 1;
            A[i][j] = A[i][j - 1] / pow(J, I);
        }
    }
}
