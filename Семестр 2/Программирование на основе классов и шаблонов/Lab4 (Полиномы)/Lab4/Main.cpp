#include "Term.h"
#include "Polynomial.h"
using namespace std;


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    
    Term t1, t2(3), t3(-3, 3), t4(2, 3), t5(2, 3);
    cout << t1;
    cout << t2;
    cout << t3;

    cout << 2 * t3;
    cout << t2 * t3;
    cout << t3 + t4;

    cout << "\n\n\n\n";
    

    /*
    Polynomial t, u;

    t += Term(1, 0);
    t += Term(1, 1);

    u += Term(1, 0);
    u -= Term(1, 1);

    cout << t * u;
    */
    
    Polynomial p1, p2(t4), p3(12 * t3 +  5 * t5), p4, p5;

    cout << p1;
    cout << p2;
    cout << p3;

    cout << "\n\n\n\n";

    p4 += Term(1, 0);
    p4 += Term(3, 1);
    p5 += Term(1, 0);
    p5 -= Term(3, 1);

    cout << p4;
    cout << p5;
    cout << p4 * p5;
    
}