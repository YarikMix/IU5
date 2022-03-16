#include <iostream>
using namespace std;

class Term
{
private:
    int x;
    int y;
public:
    Term()
    {
        x = 0;
        y = 0;
    }

    Term(int x, int y = 1)
    {
        this->x = x;
        this->y = y;
    }

    // Конструктор копирования
    Term(const Term & t)
    {
        this->x = t.x;
        this->y = t.y;
    }

    // Перегруженный оператор присваивания
    Term operator= (Term t)
    {
        this->x = t.x;
        this->y = t.y;
        return *this;
    }

    // Друзья класса
    friend Term operator+ (Term t1, Term t2);
    friend Term operator* (Term t1, Term t2);
    friend void operator<< (ostream& out, Term t1);

};

class Polynomial
{
private:
    Term poly[6];
    int degree;
public:
    Polynomial()
    {
        x = 13;
        degree = 12;
    }
};



Term operator+(Term t1, Term t2)
{
    return Term(t1.x + t2.x, t1.y);
}

Term operator*(Term t1, Term t2)
{
    return Term(t1.x * t2.x, t1.y + t2.y);
}

void operator<<(ostream& out, Term t)
{
    if (t.y == 0)
        out << t.x;
    else
        out << t.x << "x^" << t.y;
}

int main()
{
    Term t1 = Term(1, 3);
    Term t2 = Term(4, 3);
    cout << t1;
    cout << t2;
    cout << t1 + t2;
}