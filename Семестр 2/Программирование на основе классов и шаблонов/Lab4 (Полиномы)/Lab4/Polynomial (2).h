#pragma once
class Polynomial
{
    private:
        vector<Term> poly;
        int degree;
    public:
        Polynomial()
        {
            poly.push_back(Term(0, 0));
            degree = 0;
        }

        Polynomial(int n)
        {
            poly.push_back(Term(n, 0));
            degree = 0;
        }

        Polynomial(Term term)
        {
            poly.push_back(term);
            degree = max(degree, term.GetY());
        }

        // Конструктор копирования
        Polynomial(const Polynomial& p)
        {
            poly = p.poly;
            degree = p.degree;
        }

        void SetTerm(Term t, bool subtraction = false)
        {
            for (auto& term : poly)
            {
                if (term.GetY() == t.GetY())
                {
                    term.SetX(subtraction ? term.GetX() - t.GetX() : term.GetX() + t.GetX());
                }
            }
        }

        bool HaveTerm(Term t)
        {
            for (auto& term : this->poly)
            {
                if (term.GetY() == t.GetY())
                {
                    return true;
                }
            }
            return false;
        }
        
        int getDegree()
        {
            int deg = 0;

            for (auto& term : this->poly)
            {
                deg = max(deg, term.GetY());
            }

            return deg;
        }

        void Sort()
        {
            vector<Term> p;

            degree = getDegree();

            for (int i = 0; i <= degree; i++)
            {
                int x = 0;
                int y = i;
                for (auto& term : this->poly)
                {
                    if (term.GetY() == i)
                    {
                        x += term.GetX();
                    }
                }
                p.push_back(Term(x, y));
            }

            this->poly = p;
        }

        // Операторы присваивания

        void operator= (Polynomial p) {
            this->poly.clear();
            for (auto& term : p.poly)
            {
                this->poly.push_back(term);
            }

            Sort();
        };

        void operator+= (Polynomial p) {
            for (auto& term : p.poly)
            {
                this->poly.push_back(term);
            }

            Sort();
        };

        void operator-= (Polynomial p) {
            for (auto& term : p.poly)
            {
                term.SetX((-1) * term.GetX());
                this->poly.push_back(term);
            }

            Sort();
        };

        // Друзья класса

        friend Polynomial operator+ (Polynomial p1, Polynomial p2) {
            Polynomial p = Polynomial();
            for (auto& term : p1.poly)
            {
                p.poly.push_back(term);
            }

            for (auto& term : p2.poly)
            {
                p.poly.push_back(term);
            }

            p.Sort();

            return p;
        };

        friend Polynomial operator- (Polynomial p1, Polynomial p2) {
            Polynomial p = Polynomial();
            for (auto& term : p1.poly)
            {
                p.poly.push_back(term);
            }

            for (auto& term : p2.poly)
            {
                term.SetX((-1) * term.GetX());
                p.poly.push_back(term);
            }

            p.Sort();

            return p;
        };

        friend Polynomial operator* (Polynomial p1, Polynomial p2) {
            Polynomial p = Polynomial();

            for (auto& term1 : p1.poly)
            {
                for (auto& term2 : p2.poly)
                {
                    p.poly.push_back(term1 * term2);
                }
            }

            p.Sort();

            return p;
        };

        friend void operator<< (ostream& out, Polynomial p) {
            
            if (p.poly.empty())
            {
                cout << 0 << endl;
                return;
            }

            int n = 0;
            
            for (vector<Term>::iterator it = p.poly.begin(); it != p.poly.end(); ++it)
            {
                Term term = (*it);
                int X = term.GetX();
                int Y = term.GetY();

                if (term.IsZero()) continue;


                if (n == 0)
                {
                    if (X == 1)
                    {
                        out << X;
                    }
                    else if (X == -1)
                    {
                        out << "-";
                    }
                    else if (X < 0)
                    {
                        out << X;
                    }
                    else if (X > 0)
                    {
                        out << X;
                    }

                }
                else
                {
                    char symbol = X > 0 ? '+' : '-';
                    out << " " << symbol << " ";
                    if (abs(X) != 1)
                    {
                        out << abs(X);
                    }
                }

                
                Y == 0 ? out << "" : out << "x^" << Y;
                n++;

            }

            out << endl;

        };

};
