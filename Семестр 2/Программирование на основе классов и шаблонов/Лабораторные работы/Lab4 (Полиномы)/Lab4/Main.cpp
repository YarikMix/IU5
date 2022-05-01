#include "Term.h"
#include "Polynomial.h"
using namespace std;


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");

    Polynomial p1, p2;

    p1 += Term(1, 1);
    p1 += Term(-2, 0);

    p2 += Term(1, 1);
    p2 += Term(2, 0);

    cout << p1 * p2;
    
}