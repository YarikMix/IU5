#include "Utils.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string FormatDate(int* date)
{
    return to_string(date[0]) + "." + to_string(date[1]) + "." + to_string(date[2]);
}

string FormatTime(int time)
{
    string res;
    if (time >= 3600) res += to_string(time / 3600) + "h ";
    if (time >= 60) res += to_string(time / 60 % 60) + "m ";
    if (time >= 0) res += to_string(time % 60) + "s";
    return res;
}

int* GetDate(string raw)
{
    int* date = new int[3];
    int day, month, year;
    int pos = 0;

    pos = raw.find(".");
    day = stoi(raw.substr(0, pos));
    raw.erase(0, pos + 1);

    pos = raw.find(".");
    month = stoi(raw.substr(0, pos));
    raw.erase(0, pos + 1);

    pos = raw.find(".");
    year = stoi(raw.substr(0, pos));

    date[0] = day;
    date[1] = month;
    date[2] = year;

    return date;
}

string GetRandomName()
{
    vector<string> names{ "John", "Robert", "John", "Mary", "Patricia", "Jennifer" };
    vector<string> surnames{ "Smith", "Johnson", "Williams", "Brown", "James", "Miller" };

    int i = rand() % names.size();
    string name = names[i];

    int j = rand() % surnames.size();
    string surname = surnames[j];

    string fullname = name + " " + surname;
    return fullname;
}

int GetRandomInt(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}

int * GetRandomDate()
{
    int * test = new int[3];
    test[0] = GetRandomInt(1, 31);
    test[1] = GetRandomInt(1, 12);
    test[2] = GetRandomInt(1900, 2022);
    return test;
}

bool CheckDate(string raw)
{
    int day, month, year;
    int pos = 0;

    pos = raw.find(".");
    day = stoi(raw.substr(0, pos));
    raw.erase(0, pos + 1);

    pos = raw.find(".");
    month = stoi(raw.substr(0, pos));
    raw.erase(0, pos + 1);

    pos = raw.find(".");
    year = stoi(raw.substr(0, pos));

    return (1 <= day && day <= 31)     &&
           (1 <= month && month <= 12) &&
           (1 <= year && year <= 2022) ? true : false;
}

string InputName()
{
    string name;
    cout << "¬ведите им€ абонента\n> ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    return name;
}

int* InputDate()
{
    string raw;
    cout << "¬ведите дату разговора\n> ";
    cin >> raw;
    while (!CheckDate(raw))
    {
        cout << "¬ведена некорректна€ дата" << endl;
        cout << "¬ведите дату разговора\n> ";
        cin >> raw;
    }
    return GetDate(raw);
}

int InputDuration()
{
    int duration;    
    cout << "¬ведите врем€ разговора\n> ";
    cin >> duration;
    while (duration < 0)
    {
        cout << "¬рем€ разговора должно быть неотрицательным числом" << endl;
        cout << "¬ведите врем€ разговора\n> ";
        cin >> duration;
    }
    return duration;
}