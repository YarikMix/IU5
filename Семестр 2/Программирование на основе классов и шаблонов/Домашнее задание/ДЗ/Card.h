#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Utils.h"

class Card
{
    private:
        std::string name;
        int* date = new int[3];
        int time;
    public:
        Card(std::string name, int date[], int time)
        {
            this->name = name;
            this->date[0] = date[0];
            this->date[1] = date[1];
            this->date[2] = date[2];
            this->time = time;
        }

        std::string getName() { return this->name; }
        int* getDate() { return this->date; }
        int getTime() { return this->time; }      
        
        void ShowNotification()
        {
            float price = this->time * 2.5 / 60 * 10;
            std::cout << std::fixed << std::setprecision(2) << "Абонент " << this->name << " должен заплатить " << price << " рублей за разговор " << FormatDate(this->date) << std::endl;
        };

        friend void operator<< (std::ostream& out, Card card)
        {
            out << card.name << " " << FormatDate(card.date) << " " << FormatTime(card.time) << std::endl;
        };
};
