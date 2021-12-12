#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"
using namespace std;

// ������ ��������� �������
double** CreateMatrix(int N) {
    double** E = new double* [N + 1];
    for (int i = 0; i < N; i++)
    {
        E[i] = new double[N + 1];
        for (int j = 0; j < N; j++)
            E[i][j] = 0;
        E[i][i] = 1;
    }
    return E;
}

// ������ ������� �������
double** CreateZeroMatrix(int N) {
    double** E = new double* [N + 1];
    for (int i = 0; i < N; i++)
    {
        E[i] = new double[N + 1];
        for (int j = 0; j < N; j++)
            E[i][j] = 0;
    }
    return E;
}

// ��������� ������� �� �����
double** ReadMatrix(const char* filename, int N)
{
    double** A = CreateMatrix(N);
    ifstream file;
    file.open(filename);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> A[i][j];

    file.close();

    return A;
}

// ������ ������� �� ��������� ���������
double** GenerateMatrix(int N) {
    double** A = new double* [N + 1];
    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N + 1];
        for (int j = 0; j < N; j++)
            A[i][j] = rand() % 10;
    }
    return A;
}

// ��������� ����� �������
double** CloneMatrix(double** A, int N)
{
    double** B = new double* [N];
    for (int row = 0; row < N; row++)
    {
        B[row] = new double[N];
        for (int col = 0; col < N; col++)
            B[row][col] = A[row][col];
    }
    return B;
}

// ������ ������� �� �����
void PrintMatrix(double** A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setprecision(2) << left << setw(16) << A[i][j];
        cout << endl;
    }
    cout << "\n\n\n";
}

// ������� ������
void Clear(double** A, int N)
{
    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;
}
