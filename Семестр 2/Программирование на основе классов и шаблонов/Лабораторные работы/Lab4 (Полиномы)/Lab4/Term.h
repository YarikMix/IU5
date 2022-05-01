#include <iostream>
#include <vector>
using namespace std;

class Term
{
    private:
        int x;
        int y;
        friend class Polynomial;
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
        Term(const Term& t)
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
        friend Term operator+ (Term t1, Term t2) { 
            if (t1.GetY() != t2.GetY())
            {
                cout << "Ошибка" << endl;
                exit(0);
            }

            return Term(t1.x + t2.x, t1.y); 
        };
        friend Term operator- (Term t1, Term t2) {
            if (t1.GetY() != t2.GetY())
            {
                cout << "Ошибка" << endl;
                exit(0);
            }

            return Term(t1.x - t2.x, t1.y);
        };
        friend Term operator* (Term t1, Term t2) { return Term(t1.x * t2.x, t1.y + t2.y); };
        friend Term operator* (double x, Term t) { return Term(x * t.x, t.y); };
        friend Term operator* (Term t, double x) { return Term(x * t.x, t.y); };
        friend void operator<< (ostream& out, Term t) {
            if (t.x == 0)
                out << 0 << endl;

            else if (t.y == 0)
                out << t.x << endl;

            else if (t.y == 1)
                out << t.x << "x" << endl;

            else
                out << t.x << "x^" << t.y << endl;
        };

        // Работа с приватными членами класса
        int GetX() { return this->x; }
        int GetY() { return this->y; }
        void SetX(int value) { this->x = value; }
        void SetY(int value) { this->y = value; }
        bool IsZero() { return this->x == 0; }
};

