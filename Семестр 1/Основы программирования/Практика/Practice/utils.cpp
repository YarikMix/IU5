#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include "Header.h"
#define ERROR_MESSAGE "������ ������� �����������! ���������� ��� ���"
using namespace std;

// ����������� ����� �� ������� [left, right]
int Input(string message, int left, int right)
{
    int tmp;

    while (true)
    {
        cout << message << "\n> ";
        cin >> tmp;

        if (!cin.fail() && (tmp >= left && tmp <= right))
        {
            break;
        }

        cout << ERROR_MESSAGE << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return tmp;
}

// ����������� ��� ���������
string GetName()
{
    string name;
    cin.ignore(1000, '\n');

    while (true)
    {
        cout << "������� ��� ���������\n> ";
        getline(cin, name);

        if (isString(name))
            if (!isDuplicate(name))
                break;
            else
                cout << "�������� � ����� ������ ��� ���� � ������!" << endl;

        else
            cout << ERROR_MESSAGE << endl;

    }

    cout << "\n\n";

    return name;
}

// ����������� ���� �������� ���������
void GetBirthdayDate(int birthday[3])
{
    while (true)
    {
        birthday[0] = Input("������� ���� ��������", 1, 31);
        birthday[1] = Input("������� ����� ��������", 1, 12);
        birthday[2] = Input("������� ��� ��������");

        if (CheckDate(birthday))
            break;
        else
            cout << ERROR_MESSAGE << endl;
    }

    cout << "\n\n";
}

// ����������� ���� ������������
void Get�ompetitionDate(int birthday[3], int competition[3])
{
    while (true)
    {
        competition[0] = Input("������� ���� ���������� ������������", 1, 31);
        competition[1] = Input("������� ����� ���������� ������������", 1, 12);
        competition[2] = Input("������� ��� ���������� ������������");

        if (CheckDate(competition) && difference(birthday, competition) > 0)
            break;
        else
            cout << ERROR_MESSAGE << endl;
    }

    cout << "\n\n";
}

// ����������� ���
int GetGender()
{
    int gender = Input("������� ��� (0 - �������, 1 �������)", 0, 1);
    cout << "\n\n";
    return gender;
}

// ����������� ���������� ����� �� ������ ����������
void GetScore(int arr[4], int gender)
{
    arr[0] = Input("����� �� ������� ����������", 0, 10);
    arr[1] = Input("����� �� ��������� �� �������", 0, 10);
    arr[2] = Input("����� �� ������� ������", 0, 10);

    if (gender == 0)
        // ���� �������� - �������
        arr[3] = Input("����� �� ���������� �� �������", 0, 10);
    else
        // ���� �������� - �������
        arr[3] = Input("����� �� ���������� �� ������", 0, 10);

}

// ��������� ������ �������
int GetConsoleWidth()
{
	COORD* Chars;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(hCon, &csbInfo);
	int width = csbInfo.srWindow.Right - csbInfo.srWindow.Left;
	return width;
}

// ������������� �������� *
string operator * (string a, int b) {
	string output = "";
	while (b--)
		output += a;

	return output;
}

// ������� ��������� �� �����
void h1(const char* s)
{
	int width = GetConsoleWidth();
	cout << string("-") * width << endl;
	cout << s << endl;
	cout << string("-") * width << endl;
}

// ��������� ����� ��������� ������� arr �������� n
int Sum(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res += arr[i];

	return res;
}

// ��������� true, ���� ������ ��������� ������� �� ����, false � �������� ������
bool isString(string s)
{
	return !std::any_of(s.begin(), s.end(), ::isdigit);
}

// ��������� ���� �� ������������
bool CheckDate(int date[3])
{
	struct tm a = { 0, 0, 0, date[0], date[1] - 1, date[2] - 1900 };
	time_t x = mktime(&a);
	return x != (time_t)(-1);
}

// ��������� ������� � ���� ����� ����� ������
double difference(int bDay[3], int cDay[3])
{
	struct tm a = { 0, 0, 0, bDay[0], bDay[1] - 1, bDay[2] - 1900 };
	struct tm b = { 0, 0, 0, cDay[0], cDay[1] - 1, cDay[2] - 1900 };

	time_t x = mktime(&a);
	time_t y = mktime(&b);

	if (x != (time_t)(-1) && y != (time_t)(-1))
		return difftime(y, x) / (60 * 60 * 24);

	return 0;
}

// ��������� ���
string ShowGender(int gender)
{
	if (gender == 0)
		return "�";
	else
		return "�";
}

// ��������� ���� � ������� ��.��.��
string FormatDate(int date[3])
{
	return to_string(date[0]) + "." + to_string(date[1]) + "." + to_string(date[2]);
}
