#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    // Book book1 = Book("Jonathan Swift", "Guliver", 10);
    // Book book2 = Book("Oscar Wilde", "The Happy Prince", 0);
    // Book book3 = book1;
    Book book1, book2("Jonathan Swift", "Guliver", 10), book3(book2);
    book2 -= 6;
    book2.~Book();
    cout << book2;
}