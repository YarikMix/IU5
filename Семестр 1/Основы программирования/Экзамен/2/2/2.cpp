#include <iostream>
#include <iomanip>
using namespace std;

int** CreateMatrix(int N)
{
    int** A = new int* [N];
    int value = 1;

    for (int i = 0; i < N; i++)
    {
        A[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            A[i][j] = value;
            value++;
        }
    }
    return A;
}

void printMatrix(int** A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << setw(4) << " ";
        cout << "\n";
    }
    cout << "\n\n\n";
}

void Clear(int** A)
{
    delete[] A;
}

int* GetArray(int* X, int N)
{
    int* B = new int[N + 1];
    for (int i = 0; i < N; i++)
    {
        B[i] = X[i];
    }
    return B;
}

void ReverseArray(int* X, int N)
{
    int i = 0;
    while (i < N)
    {
        swap(X[i], X[N]);
        i++;
        N--;
    }
}

void ReplaceArray(int** A, int* B, int N)
{
    for (int i = 0; i < N; i++)
        A[0][i] = B[i];
}

void SortMatrix(int** A, int N)
{
    int* B = GetArray(A[N - 1], N); // Получаем последнюю строку матрицы

    
    // Циклическая перестановка строк матрицы A
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j > 0; --j) {
            A[j][i] = A[j - 1][i];
        }
    }

    ReverseArray(B, N - 1); // Разворачиваем последнюю строку матрицы
    ReplaceArray(A, B, N);  // Заменяем первую строку полученной матрицы

    printMatrix(A, N);
    delete[] B;
}

int main()
{
    int N = 4;
    int** A = CreateMatrix(N);
    printMatrix(A, N);
    SortMatrix(A, N);
    Clear(A);
}
