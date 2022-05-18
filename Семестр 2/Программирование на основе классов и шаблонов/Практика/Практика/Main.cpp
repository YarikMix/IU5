#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    Book book1 = Book("Jonathan Swift", "Guliver", 10);
    Book book2 = Book("Oscar Wilde", "The Happy Prince", 0);
    Book book3 = book1;
    cout << book1;
    book1 -= -5;
    book1 -= 3;
    cout << book1;

    cout << book2;
    cout << book3;

    book3 -= 124;

    cout << book3;
}