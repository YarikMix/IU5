﻿/*
Задача 1
Заполнить квадратную матрицу диагональной змейкой, начиная справа сверху
*/

#include <iostream>
#include <iomanip>
using namespace std;

double** CreateMatrix(int N)
{
    double** A = new double* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N];
        for (int j = 0; j < N; j++)
            A[i][j] = 0;
    }

    return A;
}

void ShowMatrix(double** A, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << setw(4) << " ";
        cout << endl;
    }
    cout << "\n\n\n";
}

void FillMatrix(double** A, int N)
{
    int x = 0, y = 0;
    int value = 1;

    // заполнение первой половины массива по диагонали, зигзагом, начиная слева и сверху, заканчивая  побочной диагональю
    for (int diag = 0; diag < N; diag++) // выполняем проход по диагоналям
    {
        if (diag % 2 == 0) // по четным диагоналям
        {
            x = 0; // х-координата первого элемента массива на диагонали - diag
            y = N - diag - 1; // у-координата элемента массива на диагонали - diag

            while (y <= N - 1) // пока y-координата находится в верхней части диагонали
            {
                A[x][y] = value; // записать значение в массив
                value++;
                x++;     // по горизонтали, смещаемся вправо
                y++;    // по вертикали, смещаемся вниз
            }
        }
        else // по нечетным диагоналям
        {
            x = diag; // х-координата элемента массива на диагонали - diag
            y = N - 1; // у-координата первого элемента массива на диагонали - diag

            while (x >= 0) // пока x-координата находится в левой части диагонали
            {
                A[x][y] = value; // записать значение в массив
                value++;
                x--;  // по горизонтали, смещаемся вправо
                y--;  // по вертикали, смещаемся вверх
            }
        }
       
    } 

    /*
    11    10    4    3    1
    0     12    9    5    2
    0     0     13   8    6
    0     0     0    14   7
    0     0     0    0    15
    */

    // заполнение первой половины массива по диагонали, зигзагом, начиная слева и сверху, заканчивая  побочной диагональю
    for (int diag = N - 2; diag >= 0; diag--) // выполняем проход по диагоналям
    {
        if (diag % 2 == 0) // по четным диагоналям
        {
            x = N - diag - 1; // х-координата первого элемента массива на диагонали - diag
            y = 0; // у-координата элемента массива на диагонали - diag

            while (x <= N - 1) // пока y-координата находится в верхней части диагонали
            {
                A[x][y] = value; // записать значение в массив
                value++;
                x++;     // по горизонтали, смещаемся вправо
                y++;    // по вертикали, смещаемся вниз
            }
        }
        else // по нечетным диагоналям
        {
            x = N - 1; // х-координата элемента массива на диагонали - diag
            y = diag ; // у-координата первого элемента массива на диагонали - diag

            while (y >= 0) // пока x-координата находится в левой части диагонали
            {
                A[x][y] = value; // записать значение в массив
                value++;
                x--;  // по горизонтали, смещаемся вправо
                y--;  // по вертикали, смещаемся вверх
            }
        }
    }

    /*
    11    10    4     3     1
    19    12    9     5     2
    20    18    13    8     6
    24    21    17    14    7
    25    23    22    16    15
    */
}

void Clear(double** A)
{
    delete[] A;
}

int main()
{
    int N = 5;

    double** A = CreateMatrix(N);

    FillMatrix(A, N);
    ShowMatrix(A, N);
    Clear(A);

    return 0;
}
