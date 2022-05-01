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


        Book(const char* author, const char * title, int volume)
        {
            this->author = (char*)author;
            this->title = (char*)title;
            this->volume = volume;
        }

        ~Book()
        {
            // delete[] this->author;
            // delete[] this->title;
        }

        Book(const Book& book)
        {
            this->author = (char *)book.author;
            this->title = (char *)book.title;
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
            out << (const char *)book.author << " '" << (const char*)book.title << " ' - " << book.volume << endl;
        };
};

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    const char* author = "Jonathan Swift";
    const char* title = "Guliver";
    int volume = 10;
    Book book1 = Book("Jonathan Swift", "Guliver", 10);
    Book book2 = Book("Oscar Wilde", "The Happy Prince", 0);
    cout << book1;
    cout << book2;

    // Book book2 = book1;
    // cout << book2;
}