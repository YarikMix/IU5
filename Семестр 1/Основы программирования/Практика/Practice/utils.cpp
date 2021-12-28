#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include "Header.h"
#define ERROR_MESSAGE "Данные введены неправильно! Попробуйте ещё раз"
using namespace std;

// Запрашивает число на отрезке [left, right]
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

// Запрашивает имя участника
string GetName()
{
    string name;
    cin.ignore(1000, '\n');

    while (true)
    {
        cout << "Введите имя участника\n> ";
        getline(cin, name);

        if (isString(name))
            if (!isDuplicate(name))
                break;
            else
                cout << "Участник с таким именем уже есть в списке!" << endl;

        else
            cout << ERROR_MESSAGE << endl;

    }

    cout << "\n\n";

    return name;
}

// Запрашивает дату рождения участника
void GetBirthdayDate(int birthday[3])
{
    while (true)
    {
        birthday[0] = Input("Введите день рождения", 1, 31);
        birthday[1] = Input("Введите месяц рождения", 1, 12);
        birthday[2] = Input("Введите год рождения");

        if (CheckDate(birthday))
            break;
        else
            cout << ERROR_MESSAGE << endl;
    }

    cout << "\n\n";
}

// Запрашивает дату соревнования
void GetСompetitionDate(int birthday[3], int competition[3])
{
    while (true)
    {
        competition[0] = Input("Введите день проведения соревнований", 1, 31);
        competition[1] = Input("Введите месяц проведения соревнований", 1, 12);
        competition[2] = Input("Введите год проведения соревнований");

        if (CheckDate(competition) && difference(birthday, competition) > 0)
            break;
        else
            cout << ERROR_MESSAGE << endl;
    }

    cout << "\n\n";
}

// Запрашивает пол
int GetGender()
{
    int gender = Input("Введите пол (0 - мужской, 1 женский)", 0, 1);
    cout << "\n\n";
    return gender;
}

// Запрашивает количество очков за каждую дисциплину
void GetScore(int arr[4], int gender)
{
    arr[0] = Input("Баллы за вольные упражнения", 0, 10);
    arr[1] = Input("Баллы за отжимания на брусьях", 0, 10);
    arr[2] = Input("Баллы за опорный прыжок", 0, 10);

    if (gender == 0)
        // Если участник - мужчина
        arr[3] = Input("Баллы за упражнения на кольцах", 0, 10);
    else
        // Если участник - женщина
        arr[3] = Input("Баллы за упражнения на бревне", 0, 10);

}

// Вовращает ширину консоли
int GetConsoleWidth()
{
	COORD* Chars;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(hCon, &csbInfo);
	int width = csbInfo.srWindow.Right - csbInfo.srWindow.Left;
	return width;
}

// Перезагружает оператор *
string operator * (string a, int b) {
	string output = "";
	while (b--)
		output += a;

	return output;
}

// Выводит сообщение на экран
void h1(const char* s)
{
	int width = GetConsoleWidth();
	cout << string("-") * width << endl;
	cout << s << endl;
	cout << string("-") * width << endl;
}

// Возращает сумму элементов массива arr размером n
int Sum(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res += arr[i];

	return res;
}

// Возращает true, если строка полностью состоит из букв, false в обратном случае
bool isString(string s)
{
	return !std::any_of(s.begin(), s.end(), ::isdigit);
}

// Проверяет дату на корректность
bool CheckDate(int date[3])
{
	struct tm a = { 0, 0, 0, date[0], date[1] - 1, date[2] - 1900 };
	time_t x = mktime(&a);
	return x != (time_t)(-1);
}

// Возращает разницу в днях между двумя датами
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

// Возращает пол
string ShowGender(int gender)
{
	if (gender == 0)
		return "М";
	else
		return "Ж";
}

// Возращает дату в формате дд.мм.гг
string FormatDate(int date[3])
{
	return to_string(date[0]) + "." + to_string(date[1]) + "." + to_string(date[2]);
}
