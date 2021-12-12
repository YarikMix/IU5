#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"
using namespace std;

// Возвращает матрицу A без i-й строки и j-го столбца
double** Minor(double** A, int N, int i, int j) {
    double** B = CreateMatrix(N);
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < N - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < N - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            B[ki][kj] = A[ki + di][kj + dj];
        }
    }
    return B;
}

// Рекурсивное вычисление определителя
double Determinant(double** A, int N) {
    int i, j, d, k;

    double** B = CreateMatrix(N);

    j = 0; d = 0;
    k = 1; //(-1) в степени i


    if (N < 1) cout << "Определитель вычислить невозможно!";

    else if (N == 1)
        d = A[0][0];

    else if (N == 2)
        d = A[0][0] * A[1][1] - (A[1][0] * A[0][1]);

    else if (N > 2) {
        for (i = 0; i < N; i++) {
            B = Minor(A, N, i, 0);
            d = d + k * A[i][0] * Determinant(B, N - 1);
            k = -k;
        }
    }

    return d;
}

// Транспонирование матрицы
void Transposition(double** A, int N)
{
    for (int row = 0; row < N - 1; row++)
        for (int col = row + 1; col < N; col++)
            swap(A[col][row], A[row][col]);
}

// Перемножает две матрицы
double** Multiple(double** A, double** B, int N)
{
    double** C = CreateZeroMatrix(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

// Возвращает обратную матрицу
double** Inverse(double** A, int N)
{
    // Находим обратную матрицу методом алгебраических дополнений

    double temp;
    double** E = CreateMatrix(N);   // E - единичная матрица
    double** B = CloneMatrix(A, N);
    
    /*-------------- Прямой ход ---------------------------*/
    for (int k = 0; k < N; k++)
    {

        /* Если элемент на главной диагонали в исходной строке = 0, то ищем строку, где 
        элемент того же столбца не нулевой, и меняем строки местами */
        if (fabs(B[k][k]) < 1e-8)
        {
            for (int i = k + 1; i < N; i++)
            {
                if (fabs(B[i][k]) > 1e-8)
                {
                    swap(B[k], B[i]);
                    swap(E[k], E[i]);

                    break;
                }
            }
        }


        temp = B[k][k];
        

        for (int j = 0; j < N; j++)
        {
            B[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = B[i][k];

            for (int j = 0; j < N; j++)
            {
                B[i][j] -= B[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }

    }
    /*-----------------------------------------------------*/


    /*
    Привели матрицу A к ступенчатому виду
    1 .........
    0 1 .......
    0 0 1 .....
    0 0 0 1 ...
    0 0 0 0 1 .
    0 0 0 0 0 1
    */

    /*-------------- Обратный ход -------------------------*/
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = B[i][k];

            for (int j = 0; j < N; j++)
            {
                B[i][j] -= B[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    /*-----------------------------------------------------*/

    /*
    Привели матрицу A к единичному виду
    1 0 0 0 0 0
    0 1 0 0 0 0
    0 0 1 0 0 0
    0 0 0 1 0 0
    0 0 0 0 1 0
    0 0 0 0 0 1
    E - обратная матрица по отношению к A
    */

    return E;
}

int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "rus");

    int N = 4;
    double** A = ReadMatrix("matrix.txt", N);
    
    cout << "Матрица A" << "\n\n";
    PrintMatrix(A, N);

    double det = Determinant(A, N);
    cout << "Определитель: " << det << "\n\n\n";

    if (det == 0)
    {
        cout << "Матрица является вырожденной и не имеет обратной матрицы";
    }
    else
    {
        double** A_reverse = Inverse(A, N);

        cout << "Обратная матрица A^-1" << "\n\n";
        PrintMatrix(A_reverse, N);
        

        // Проверка

        cout << "Проверка A * A^-1" << "\n\n";
        PrintMatrix(Multiple(A, A_reverse, N), N);

        Clear(A_reverse, N);
    }

    Clear(A, N);
    return 0;
}
