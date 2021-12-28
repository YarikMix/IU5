#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "Header.h"
using namespace std;

struct Contest {
    string name;
    int bDate[3];
    int cDate[3];
    int gender;
    int score[4];
    int sum;
};

vector<Contest> table;

// Возращает true, если в спике уже есть участник с именем name, в обратном случае возращает false
bool isDuplicate(string name)
{
    for (int i = 0; i < table.size(); i++)
        if (table[i].name == name)
            return true;

    return false;
}

// Добавляет нового участника в список
void NewMember(string name, int bDate_day, int bDate_month, int bDate_year, int cDate_day, int cDate_month, int cDate_year, int gender, int score0, int score1, int score2, int score3)
{
    table.push_back(Contest());
    int i = table.size() - 1;

    table[i].name = name;
    table[i].bDate[0] = bDate_day;
    table[i].bDate[1] = bDate_month;
    table[i].bDate[2] = bDate_year;
    table[i].cDate[0] = cDate_day;
    table[i].cDate[1] = cDate_month;
    table[i].cDate[2] = cDate_year;
    table[i].gender = gender;
    table[i].score[0] = score0;
    table[i].score[1] = score1;
    table[i].score[2] = score2;
    table[i].score[3] = score3;
    table[i].sum = score0 + score1 + score2 + score3;
}

// Добавляет n участников в список
void AddMembers(int n = 1)
{
    string name;
    int bDate[3];
    int cDate[3];
    int gender;
    int score[4];
    int sum;

    for (int i = 0; i < n; i++) {
        table.push_back(Contest());
        int j = table.size() - 1;

        cout << "\n\nУчастник №" << j + 1 << endl;

        name = GetName();

        GetBirthdayDate(bDate);
        GetСompetitionDate(bDate, cDate);
        gender = GetGender();
        GetScore(score, gender);

        table[j].name = name;
        table[j].bDate[0] = bDate[0];
        table[j].bDate[1] = bDate[1];
        table[j].bDate[2] = bDate[2];
        table[j].cDate[0] = cDate[0];
        table[j].cDate[1] = cDate[1];
        table[j].cDate[2] = cDate[2];
        table[j].gender = gender;
        table[j].score[0] = score[0];
        table[j].score[1] = score[1];
        table[j].score[2] = score[2];
        table[j].score[3] = score[3];
        table[j].sum = Sum(score, 4);
    }
}

// Фильтрует список участников по возрасту
void AgeFilter()
{
    for (int i = 0; i < table.size(); i++)
    {
        int age = difference(table[i].bDate, table[i].cDate) / 365;

        if (age < 16)
        {
            cout << "Участник " << table[i].name << " слишком молод для соревнований" << endl;
            table.erase(table.begin() + i);
            i--;
        }
        else if (age > 70)
        {
            cout << "Участник " << table[i].name << " слишком стар для соревнований" << endl;
            table.erase(table.begin() + i);
            i--;
        }

    }
    cout << "\n\n\n";
}

// Сортирует список участников по набранным баллам, полу, возрасту и алфавиту
void SortMembers()
{
    for (int i = 0; i < table.size() - 1; i++)
        for (int j = 0; j < table.size() - i - 1; j++)
        {
            // cout << "Сравниваем " << test[j].name << " и " << test[j + 1].name << "\n\n\n";

            if (table[j].sum < table[j + 1].sum)
                swap(table[j], table[j + 1]);

            else if (table[j].sum == table[j + 1].sum)
            {
                if (table[j].gender < table[j + 1].gender)
                    swap(table[j], table[j + 1]);

                else if (table[j].gender == table[j + 1].gender)
                {
                    if (difference(table[j].bDate, table[j + 1].bDate) < 0)
                        swap(table[j], table[j + 1]);
                    
                    else if (difference(table[j].bDate, table[j + 1].bDate) == 0)
                    {
                        
                        if (table[j].name > table[j + 1].name)
                            swap(table[j], table[j + 1]);

                    }
                    
                }
            }

            // ShowMembers(true);

        }
}

// Выводит таблицу участников соревнований
void ShowMembers()
{
    h1("| Место |      Имя      | Дата рождения | Дата проведения соревнований | Пол | Баллы №1 | Баллы №2 | Баллы №3 | Баллы №4 | Итоговые баллы |");
    
    for (int i = 0; i < table.size(); i++) {
        cout << setw(5) << i + 1 << setw(5);
        cout.width(18);
        cout << right << table[i].name;
        cout.width(13);
        cout << FormatDate(table[i].bDate);
        cout.width(22);
        cout << FormatDate(table[i].cDate);
        cout.width(15);
        cout << ShowGender(table[i].gender);
        cout.width(9);
        cout << table[i].score[0];
        cout.width(11);
        cout << table[i].score[1];        
        cout.width(11);
        cout << table[i].score[2];
        cout.width(11);
        cout << table[i].score[3];
        cout.width(15);
        cout << table[i].sum;
        cout << "\n";
    }
    cout << "\n\n\n";
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    

    NewMember("Голиков Д.Д.",    13, 5, 2010, 27, 12, 2021, 0, 4, 5, 7, 6);
    NewMember("Харитонова Н.А.", 13, 5, 1980, 27, 12, 2100, 1, 6, 7, 6, 6);

    NewMember("Попов С.Ф.", 16, 1, 2004, 27, 12, 2021, 0, 8, 7, 5, 8);
    NewMember("Юдина Л.Л.", 16, 1, 2004, 27, 12, 2021, 1, 8, 7, 5, 8);

    NewMember("Бочарова А.З.", 7, 5, 1997, 27, 12, 2021, 1, 10, 10, 10, 10);
    NewMember("Полякова С.К.", 7, 5, 1997, 27, 12, 2021, 1, 10, 10, 10, 10);

    NewMember("Осипов М.П.",   21, 10, 1989, 27, 12, 2021, 0, 10, 8, 9, 10);
    NewMember("Щербаков М.М.", 21, 10, 2005, 27, 12, 2021, 0, 10, 8, 9, 10);
    
    
    int n;
    cout << "Введите количество участников\n> ";
    cin >> n;
    AddMembers(n);
    

    AgeFilter();
    SortMembers();
    ShowMembers();

}