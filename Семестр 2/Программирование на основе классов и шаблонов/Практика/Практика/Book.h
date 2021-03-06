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
        this->volume = 0;
    }

    Book(const char* author, const char* title, int volume)
    {
        this->author = _strdup(author);
        this->title = _strdup(title);
        this->volume = volume;
    }

    Book(const Book& book)
    {
        this->author = _strdup(book.author);
        this->title = _strdup(book.title);
        this->volume = book.volume;
    }

    ~Book()
    {
        this->author = _strdup("");
        this->title = _strdup("");
        cout << "!" << endl;
        delete this->author;
        delete this->title;
        this->author = nullptr;
        this->title = nullptr;
    }

    Book operator= (Book book)
    {
        this->author = _strdup(book.author);
        this->title = _strdup(book.title);
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
            cout << "?????????? ??????? ????????????? ?????!\n";
        }
        return *this;
    }

    friend void operator<< (ostream& out, Book book) {
        if (book.author != NULL)
            out << (const char*)book.author << " ";
        else if (book.title != NULL)
            out << " '" << (const char*)book.title << " ' - ";
        out << book.volume << endl;
    };
};