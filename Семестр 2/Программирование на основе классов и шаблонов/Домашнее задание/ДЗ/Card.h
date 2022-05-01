#include <iostream>
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

        friend void operator<< (std::ostream& out, Card card)
        {
            out << card.name << " " << FormatDate(card.date) << " " << FormatTime(card.time) << std::endl;
        };

        std::string getName() { return this->name; }
        int* getDate() { return this->date; }
        int getTime() { return this->time; }

        void Print()
        {
            std::cout << this->name << " " << FormatDate(this->date) << " " << FormatTime(this->time) << std::endl;
        };
};
