#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utils.h"
#include "Card.h"
using namespace std;

vector<Card> cards;

void PrintCards(vector<Card> cards)
{
    for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
    {
        Card card = (*it);
        cout << card.getName() << " " << FormatDate(card.getDate()) << " " << FormatTime(card.getTime()) << endl;
    }
}

void CreateFile(vector<Card> cards)
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
}

void AddCard(string name, int date[3], int duration)
{
    Card card(name, date, duration);
    cards.push_back(card);
}

Card FindCard(string name)
{
    for (auto& card : cards)
    {
        if (card.getName() == name)
        {
            return card;
        }
    }
    cout << "Карта с именем '" << name << "' не найдена" << endl;
}

void LoadCards()
{
    string line;
    string filename = "cards.txt";
    ifstream file(filename, ios::binary);

    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }

    file.close();
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    int date1[3] = { 21, 9, 2003 };
    int date2[3] = { 4, 9, 2003 };
    AddCard("Hugh Jaynus", date1, 152);
    AddCard("John Landa", date2, 152);
    
    
    // Card card = FindCard("John Landa");
    // cout << FormatDate(card.getDate()) << endl;

    // PrintCards(cards);
    CreateFile(cards);

    LoadCards();
}
