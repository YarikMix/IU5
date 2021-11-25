#include <iostream>
#include <stdlib.h> // rand
#include <vector>
using namespace std;

void ShowVector(vector<double>& a)
{
    for (vector<double>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << " ";
}

void ShowMatrix(double** Y, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << Y[i][j] << " ";
        cout << endl;
    }
}

double** CreateMatrix(int N, int M)
{
    double** Y = new double* [N];
    for (int i = 0; i < N; i++)
        Y[i] = new double[M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Y[i][j] = rand() % 10;

    // ShowMatrix(Y, N, M);

    return Y;
}

double GetMaxElem(double* arr, int M)
{
    double max = 0;
    for (int i = 0; i < M; i++)
        if (max < arr[i]) max = arr[i];
    return max;
}

int main()
{
    int N = 5;
    int M = 6;

    double** Y = new double* [N];
    for (int i = 0; i < N; i++)
    {
        Y[i] = new double[M];
        for (int j = 0; j < N; j++)
            Y[i][j] = rand() % 10;
    }

    vector<double> X;

    for (int i = 0; i < N; i++)
    {
        X.push_back(GetMaxElem(Y[i], M));
    }

    for (vector<double>::iterator it = X.begin(); it != X.end(); ++it)
        cout << *it << " ";
}
