#include <iostream>
using namespace std;

double** CreateMatrix(int N)
{
    double** A = new double* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N];
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    }
    return A;
}

void PrintMatrix(double** A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n\n";
}

void Proizv(double** A, int N)
{
    double res = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j > N - i - 1)
                res *= A[i][j];
           
    cout << res << endl;
}

int main()
{
    int N = 3;
    double** A = CreateMatrix(N);
    PrintMatrix(A, N);
    Proizv(A, N);
    return 1;
}