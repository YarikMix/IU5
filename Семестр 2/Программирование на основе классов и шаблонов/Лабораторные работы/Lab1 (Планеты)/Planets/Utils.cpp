#include <iostream>
#include "header.h"
#include <Windows.h>
using namespace std;

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

long int InputDiam()
{
    if (cin.fail())
    {
        return -1;
    }

    long int diam;
    cout << "Введите диаметр планеты\n> ";
    cin >> diam;

    if (cin.fail())
    {
        return -1;
    }

    while (diam <= 0)
    {
        cout << "Пожалуйста введите положительное число!\n> ";
        cin >> diam;
    }

    return diam;
}

int InputSat()
{
    if (cin.fail())
    {
        return -1;
    }

    int diam;
    cout << "Введите количество спутников\n> ";
    cin >> diam;

    if (cin.fail())
    {
        return -1;
    }

    while (diam < 0)
    {
        cout << "Пожалуйста введите неотрицательное число!\n> ";
        cin >> diam;
    }

    return diam;
}

string InputSwitch()
{
    if (cin.fail())
    {
        return "-1";
    }

    int life;
    cout << "На планете есть жизнь? 1/0\n> ";
    cin >> life;

    if (cin.fail())
    {
        return "-1";
    }

    while (life < 0 || life > 1)
    {
        cout << "Пожалуйста введите 0 или 1!\n> ";
        cin >> life;
    }

    if (life) return "true";
    return "false";
}