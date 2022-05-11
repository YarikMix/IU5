#pragma once
#include <iostream>
using namespace std; 

class Book
{
private:
    char* author;
    char* title;
    int volume;
public:
    Book()
    {
        this->author = nullptr;
        this->title = nullptr;
        this->volume = volume;
    }

    Book(const char* author, const char* title, int volume)
    {
        this->author = _strdup(author);
        this->title = _strdup(title);
        this->volume = volume;
    }

    ~Book()
    {
        delete this->author;
        delete this->title;
    }

    Book(const Book& book)
    {
        this->author = _strdup(book.author);
        this->title = _strdup(book.title);
        this->volume = book.volume;
    }

    Book operator= (Book book)
    {
        this->author = book.author;
        this->title = book.title;
        this->volume = book.volume;
        return *this;
    }

    Book operator-= (int n)
    {
        if (n >= 0)
        {
            this->volume -= min(this->volume, n);
        }
        else
        {
            cout << "Пожалуйста введите положительное число!\n";
        }
        return *this;
    }

    friend void operator<< (ostream& out, Book book) {
        out << (const char*)book.author << " '" << (const char*)book.title << " ' - " << book.volume << endl;
    };
};