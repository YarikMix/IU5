#include <iostream>
#include "header.h"
#include <Windows.h>
using namespace std;

// ��������� ������ �������
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
    cout << "������� ������� �������\n> ";
    cin >> diam;

    if (cin.fail())
    {
        return -1;
    }

    while (diam <= 0)
    {
        cout << "���������� ������� ������������� �����!\n> ";
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
    cout << "������� ���������� ���������\n> ";
    cin >> diam;

    if (cin.fail())
    {
        return -1;
    }

    while (diam < 0)
    {
        cout << "���������� ������� ��������������� �����!\n> ";
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
    cout << "�� ������� ���� �����? 1/0\n> ";
    cin >> life;

    if (cin.fail())
    {
        return "-1";
    }

    while (life < 0 || life > 1)
    {
        cout << "���������� ������� 0 ��� 1!\n> ";
        cin >> life;
    }

    if (life) return "true";
    return "false";
}