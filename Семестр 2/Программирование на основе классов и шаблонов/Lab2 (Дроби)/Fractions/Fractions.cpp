#include <iostream>
#include <string>
#include "string.h"
#include <format>
#include <iomanip> 
#include <sstream>
#include <cmath>
#include <math.h>
using namespace std;

int NOD(int x, int y);

int dot(float x, int precision = 8)
{
    stringstream ss;
    ss << setprecision(precision) << x;
    string strNum = ss.str();
    size_t pos = strNum.find('.');
    int N;

    if (pos != strNum.npos)
    {
        N = strNum.size() - 1 - pos;
    }
    else
    {
        cout << "Ошибка!" << endl;
        N = -1;
    }

    return N;
}


class Fraction
{
    private:
        int top;
        int bottom;
    public:

        Fraction()
        {
            top = 1;
            bottom = 1;
        }

        Fraction(int a, int b = 1, int c = 1)
        {
            top = a / NOD(a, b) * c;
            bottom = b / NOD(a, b);
        }

        Fraction(float x, bool round = true)
        {
            int N = dot(x);
            top = x * pow(10, N);
            bottom = pow(10, N);

            if (round)
            {
                int nod = NOD(top, bottom);
                top /= nod;
                bottom /= nod;
            }
        }

        Fraction(double x, bool round = true)
        {
            int N = dot(x);
            top = x * pow(10, N);
            bottom = pow(10, N);

            if (round)
            {
                int nod = NOD(top, bottom);
                top /= nod;
                bottom /= nod;
            }
        }

        // Конструктор копирования
        Fraction(const Fraction &f)
        {
            top = f.top;
            bottom = f.bottom;
        }
        
        // Перегруженные операторы присваивания
        Fraction operator= (Fraction f)
        {
            this->top = f.top;
            this->bottom = f.bottom;
            return *this;
        }
        Fraction operator+= (Fraction f)
        {
            this->top += f.top;
            this->bottom += f.bottom;
            return *this;
        }
        Fraction operator*= (Fraction f)
        {
            this->top *= f.top;
            this->bottom *= f.bottom;
            return *this;
        }

        // Друзья класса
        friend Fraction operator+ (Fraction f1, Fraction f2);
        friend Fraction operator- (Fraction f1, Fraction f2);
        friend Fraction operator* (Fraction f1, Fraction f2);
        friend Fraction operator/ (Fraction f1, Fraction f2);
        friend bool operator> (Fraction f1, Fraction f2);
        friend bool operator< (Fraction f1, Fraction f2);
        friend bool operator== (Fraction f1, Fraction f2);
        friend bool operator!= (Fraction f1, Fraction f2);
        friend bool operator>= (Fraction f1, Fraction f2);
        friend bool operator<= (Fraction f1, Fraction f2);
        friend void operator<< (ostream& out, Fraction f1);
};

Fraction operator+(Fraction f1, Fraction f2)
{
    return Fraction(f1.top * f2.bottom + f1.bottom * f2.top, f1.bottom * f2.bottom);
}

Fraction operator-(Fraction f1, Fraction f2)
{
    return Fraction(f1.top * f2.bottom - f1.bottom * f2.top, f1.bottom * f2.bottom);
}

Fraction operator*(Fraction f1, Fraction f2)
{
    return Fraction(f1.top * f2.top, f1.bottom * f2.bottom);
}

Fraction operator/(Fraction f1, Fraction f2)
{
    return Fraction(f1.top * f2.bottom, f1.bottom * f2.top);
}

bool operator>(Fraction f1, Fraction f2)
{
    return f1.top * f2.bottom - f2.top * f1.bottom > 0;
}

bool operator<(Fraction f1, Fraction f2)
{
    return f1.top * f2.bottom - f2.top * f1.bottom < 0;
}

bool operator==(Fraction f1, Fraction f2)
{
    return f1.top * f2.bottom - f2.top * f1.bottom == 0;
}

bool operator!=(Fraction f1, Fraction f2)
{
    return f1.top * f2.bottom - f2.top * f1.bottom != 0;
}

bool operator>=(Fraction f1, Fraction f2)
{
    return (f1.top / f1.bottom) >= (f2.top / f2.bottom);
}

bool operator<=(Fraction f1, Fraction f2)
{
    return (f1.top / f1.bottom) <= (f2.top / f2.bottom);
}

void operator<<(ostream& out, Fraction f)
{  
    if (f.bottom == 1)
        out << f.top << endl;
    else
        out << f.top << "/" << f.bottom << endl;
}


Fraction Max(Fraction f1, Fraction f2)
{
    return f1 > f2 ? f1 : f2;
}

int NOD(int x, int y)
{
    if (y == 0) return x;
    return NOD(y, x % y);
}

Fraction Input()
{
    cout << "Введите числитель:\n> ";
    int x;
    cin >> x;

    if (x == 0)
    {
        return Fraction(x);
    }

    cout << "Введите знаменатель:\n> ";
    int y;
    cin >> y;

    while (y == 0)
    {
        cout << "Знаменатель не может быть равен нулю!" << endl;
        cout << "Введите знаменатель:\n> ";
        cin >> y;
    }

    return Fraction(x, y);
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    float pi = 3.1415926;
    Fraction a, b(-2), c(-8, 3), d(2, 2, 3), e(d), f(pi, false);

    cout << a;
    cout << b;
    cout << c;
    cout << d;
    cout << f;

    /*
    Fraction f1(12.32);
    cout << "Первая дробь: " << f1.show() << endl << endl;

    Fraction f2(2, 3);
    cout << "Вторая дробь: " << f2.show() << endl << endl;

    cout << "Большая дробь: " << Max(f1, f2).show() << endl << endl;

    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    cout << "Сумма: " << f3.show() << endl;
    cout << "Разность: " << f4.show() << endl;
    cout << "Произведение: " << f5.show() << endl;
    cout << "Частное: " << f6.show() << endl;

    cout << "f1 < f2: " << (f1 < f2) << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;
    cout << "f1 <= f2: " << (f1 <= f2) << endl;
    cout << "f1 >= f2: " << (f1 >= f2) << endl;
    */

    return 0;
}