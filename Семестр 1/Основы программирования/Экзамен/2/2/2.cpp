/*
Задача 2
Записать в массив L количество нулевых элементов каждого столбца матрицы Z размером M x N.
*/

#include <iostream>
#include <stdlib.h> // rand, srand
#include <vector>
using namespace std;

void ShowMatrix(double** Y, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << Y[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n\n";
}

void ShowArray(double* arr, int N)
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

double** CreateMatrix(int N, int M)
{
    double** Y = new double* [N];
    for (int i = 0; i < N; i++)
        Y[i] = new double[M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            Y[i][j] = rand() % 10;

    ShowMatrix(Y, N, M);

    return Y;
}

double* CreateArray(int M)
{
    double* L = new double[M];
    for (int i = 0; i < M; i++)
        L[i] = 0;
    return L;
}

int main()
{
    srand((unsigned int)time(NULL));
    int N = 5;
    int M = 6;

    double** Y = CreateMatrix(N, M);
    double* L = CreateArray(M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (Y[i][j] == 0) L[j]++;

    ShowArray(L, M);
}
