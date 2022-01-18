#include <iostream>
#include <iomanip>
using namespace std;

double** CreateMatrix(int N)
{
    double** A = new double* [N];
    int value = 1;

    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N];
        for (int j = 0; j < N; j++)
        {
            A[i][j] = value;
            value++;
        }
    }
    return A;
}

void printMatrix(double** A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << setw(4) << " ";
        cout << "\n";
    }
    cout << "\n\n\n";
}

void Clear(double** A)
{
    delete[] A;
}

double* GetArray(double* X, int N)
{
    double* B = new double[N + 1];
    for (int i = 0; i < N; i++)
    {
        B[i] = X[i];
    }
    return B;
}

void ReverseArray(double* X, int N)
{
    int i = 0;
    while (i < N)
    {
        swap(X[i], X[N]);
        i++;
        N--;
    }
}

void SortMatrix(double** A, int N)
{
    double* B = GetArray(A[N - 1], N);
    ReverseArray(B, N - 1);

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j > 0; --j) {
            A[j][i] = A[j - 1][i];
        }
    }

    
    for (int i = 0; i < N; i++)
        A[0][i] = B[i];

    printMatrix(A, N);
    delete[] B;
}

int main()
{
    int N = 4;
    double** A = CreateMatrix(N);
    printMatrix(A, N);
    SortMatrix(A, N);
    Clear(A);
}
