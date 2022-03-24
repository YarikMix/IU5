#include "Utils.h"
#include <string>
#include "string.h"
#include <sstream>
#include <iomanip>
using namespace std;

// Возвращает НОД двух чисел
int Nod(int x, int y)
{
    if (y == 0) return x;
    return Nod(y, x % y);
}

// Возвращает количество чисел после запятой числа x
int Dot(double x, int precision)
{
    stringstream ss;
    ss << setprecision(precision) << x;
    string strNum = ss.str();
    size_t pos = strNum.find('.');
    int N;  // N - число знаков после запятой

    if (pos != strNum.npos)
    {
        // Число x - вещественное
        N = strNum.size() - 1 - pos;
    }
    else
    {
        // Число x - целое
        N = 0;
    }

    return N;
}