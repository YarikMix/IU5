/*
Задача 3
Записать единицы вместо положительных элементов матрицы А размером K x K, лежащих ниже побочной диагонали.
*/
#include <iostream>
#include <stdlib.h> // rand, srand
#include <iomanip> // setw
#define xmin -10
#define xmax 10
using namespace std;

void ShowMatrix(double** A, int K)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
            cout << setw(5) << A[i][j];
        cout << endl;
    }
    cout << "\n\n\n";
}

double** CreateMatrix(int K)
{
    double** A = new double*[K];
    for (int i = 0; i < K; i++)
    {
        A[i] = new double[K];
        for (int j = 0; j < K; j++)
            A[i][j] = rand() % (xmax - xmin) - xmax;
    }
    return A;
}

int main()
{
    srand((unsigned int)time(NULL));
    int K = 5;
    double** A = CreateMatrix(K);
    ShowMatrix(A, K);

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if ((j > K - i - 1) && (A[i][j] > 0)) cout << setw(5) << 1;
            else cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
}