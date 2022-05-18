#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Utils.h"
#include "Card.h"
using namespace std;

vector<Card> cards;

void PrintCards()
{
    if (cards.empty())
    {
        cout << "Картотека пуста" << endl;
    }
    else
    {
        cout << "|          Имя          |   Дата разговора   |   Время разговора   |" << endl;
        for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
        {
            Card card = (*it);
            cout.width(20);
            cout << card.getName();
            cout.width(20);
            cout << FormatDate(card.getDate());
            cout.width(20);
            cout << FormatTime(card.getTime());
            cout.width(20);
            cout << "\n";
        }
    }
}

void UpdateFile()
{
    string filename = "cards.txt";
    ofstream f;
    f.open(filename, ios::binary);
    for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
    {
        Card card = (*it);
        f << card.getName() << " " << FormatDate(card.getDate()) << " " << card.getTime() << endl;
    }
    f.close();
    cout << "Файл обновлён" << endl;
}

void AddCard(string name, int date[3], int duration)
{
    Card card(name, date, duration);
    cards.push_back(card);
}

bool isUnique(string name, string date, int duration)
{
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        Card card = (*it);
        if (card.getName() == name && FormatDate(card.getDate()) == date && card.getTime() == duration) return false;
    }
    return true;
}

bool isUnique(string name, int* date, int duration)
{
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        Card card = (*it);
        if (card.getName() == name && FormatDate(card.getDate()) == FormatDate(date) && card.getTime() == duration) return false;
    }
    return true;
}

void InputCard()
{
    string name;
    int * date;
    int duration;

    name = InputName();
    date = InputDate();
    duration = InputDuration();

    if (isUnique(name, date, duration))
    {
        AddCard(name, date, duration);
        UpdateFile();
        cout << "Текущее количество карточек: " << cards.size() << endl;
    }
    else
    {
        cout << "Такая запись уже существует!" << endl;
    }
}

int FindCard(string name)
{
    int i = 0;  // counter.
    for (auto it = cards.begin(); it != cards.end(); it++, i++)
    {
        if (cards.at(i).getName() == name)
        {
            return i;
        }
    }
    return -1;
}

void LoadCards()
{
    string line;
    string name;
    string surname;
    string fullname;
    int * date;
    int duration;
    string filename = "cards.txt";
    ifstream file(filename, ios::binary);

    int pos = 0;
    while (file)
    {
        getline(file, line); 
        if (line.empty()) break;

        pos = line.find(" ");
        name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(" ");
        surname = line.substr(0, pos);
        fullname = name + " " + surname;
        line.erase(0, pos + 1);

        pos = line.find(" ");
        string raw = line.substr(0, pos);
        date = GetDate(raw);
        line.erase(0, pos + 1);

        pos = line.find(" ");
        duration = stoi(line.substr(0, pos));

        if (isUnique(fullname, raw, duration)) AddCard(fullname, date, duration);
    }

    file.close();

    cout << "Картотека обновлена" << endl;
    cout << "Текущее количество карточек: " + to_string(cards.size()) << endl;
}

Card GetRandomCard()
{
    int random = rand() % cards.size();
    Card card = cards[random];
    return card;
}

void GenerateCard()
{
    string name = GetRandomName();
    int* date = GetRandomDate();
    int duration = GetRandomInt(1, 600);
    AddCard(name, date, duration);
}

void GenerateCards()
{
    int count;
    cout << "Введите количество карточек\n> ";
    cin >> count;

    if (count <= 0)
    {
        cout << "Введите положительное число";
    } 
    else
    {
        for (int i = 0; i < count; i++)
        {
            GenerateCard();
        }
        cout << "Картотека успешна создана!" << endl;
        UpdateFile();
    }
}

void ShowNotification()
{
    if (cards.empty())
    {
        cout << "Картотека пуста" << endl;
    }
    else
    {
        string name = InputName();
        int i = FindCard(name);
        if (i != -1)
        {
            Card card = cards.at(i);
            card.ShowNotification();
        }
        else
        {
            cout << "Карта с именем '" << name << "' не найдена" << endl;
        }
    }
}

int Menu()
{
    int choose;
    cout << "\n\n\nВведите число от 1 до 6: ";

    if (cin >> choose)
    {

    }
    else
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return choose;
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    cout << "1 - сгенерировать картотеку \n"
         << "2 - прочитать картотеку с файла \n"
         << "3 - вывести всю картотеку \n"
         << "4 - ввести номер телефона, дату и время разговора \n"
         << "5 - вывести извещение на оплату телефонного разговора \n"
         << "6 - выйти из программы \n\n\n";

    while (true) {
        switch (Menu()) {
            case 1: GenerateCards(); break;
            case 2: LoadCards(); break;
            case 3: PrintCards(); break;
            case 4: InputCard(); break;
            case 5: ShowNotification(); break;
            case 6: return 0;
            default:
                cout << "Введите число от 1 до 6" << endl;
                break;
        }
    }

}
