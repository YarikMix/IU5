#include <iostream>
#include <random>
using namespace std;

int Random(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int** CreateMatrix(int N, int M)
{
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
        for (int j = 0; j < M; j++)
            A[i][j] = Random(-10, 10);
    }
    return A;
}

int* CreateArray(int N)
{
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = 0;
    return arr;
}

void FillArray(int** A, int* arr, int N, int M)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (A[i][j] > 0)
                arr[j] += 1;
}

void PrintMatrix(int** A, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n\n";
}

void PrintArray(int* arr, int N)
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}

int main()
{
    int N = 3;
    int M = 4;
    int** A = CreateMatrix(N, M);
    int* arr = CreateArray(M);
    PrintMatrix(A, N, M);
    FillArray(A, arr, N, M);
    PrintArray(arr, M);
}
