#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

// Очищаем память
void Clear(double** A, int N)
{
    for (int i = 1; i < N; i++)
        delete[] A[i];
    delete[] A;
}

// Создаём единичную матрицу
double** CreateMatrix(int N) {
    double** A = new double* [N];
    for (int i = 1; i < N; i++)
    {
        A[i] = new double[N];
        for (int j = 1; j < N; j++)
            A[i][j] = 1;
    }
    return A;
}

// Заполяем матрицу
void FillMatrix(double** A, int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++) {
            if (i == 1)
            {
                A[i][j] = 1;
            }
            else
            {
                if (j == 1)
                    A[i][j] = A[i - 1][j] / i;
                else
                    A[i][j] = pow(A[i][1], j);
            }
        }
    }
}

// Вовращает ширину консоли
int GetConsoleWidth()
{
    COORD* Chars;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;
    GetConsoleScreenBufferInfo(hCon, &csbInfo);
    int width = csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1;
    return width;
}

// Выводим матрицу на экран
void PrintDinamicMatrix(double** A, int N)
{
    int width = GetConsoleWidth();
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++) {
            int K = floor(width / N) - 1;
            if (A[i][j] > 0.01)
                cout << left << fixed << setw(K) << setprecision(K - 3) << A[i][j] << " ";
            else
                cout << left << fixed << setw(K) << setprecision(K - 7) << scientific << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n";
}

// Выводит статичную матрицу на экран
void PrintStaticMatrix(double B[10][10]) {
    double** A = new double* [10];
    for (int i = 0; i < 10; i++) {
        A[i] = new double[10];
        for (int j = 0; j < 10; j++) {
            A[i][j] = B[i][j];
        }
    }
    PrintDinamicMatrix(A, 10);
    Clear(A, 10);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int N = 17;
    if (GetConsoleWidth() / N < 9)
    {
        cout << "Невозможно напечатать матрицу!";
        return 0;
    }
   
    double** A = CreateMatrix(N + 1);
    FillMatrix(A, N + 1);
    PrintDinamicMatrix(A, N + 1);
    Clear(A, N + 1);

    double B[10][10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            B[i][j] = 10 * i + j;

    cout << "Матрица B \n\n\n";
    PrintStaticMatrix(B);

    cout << B << "  " << B[0] << "  " << B[2] << endl;
    cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
    cout << *(*(B + 1)) << "  " << *B[1] << endl;
    cout << *(B[0] + 1) << "  " << *(*B + 1) << endl;
    cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << endl;

    return 0;
}