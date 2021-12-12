#pragma once
double** CreateMatrix(int N);
double** ReadMatrix(const char* filename, int N);
double** CreateZeroMatrix(int N);
double** GenerateMatrix(int N);
double** CloneMatrix(double** A, int N);
void FillMatrix(double** A, int N);
void PrintMatrix(double** A, int N);
void Clear(double** arr, int N);

