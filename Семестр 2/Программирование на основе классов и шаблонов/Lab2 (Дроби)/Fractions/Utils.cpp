#include "Utils.h"
#include <string>
#include "string.h"
#include <sstream>
#include <iomanip>
using namespace std;

// ���������� ��� ���� �����
int Nod(int x, int y)
{
    if (y == 0) return x;
    return Nod(y, x % y);
}

// ���������� ���������� ����� ����� ������� ����� x
int Dot(double x, int precision)
{
    stringstream ss;
    ss << setprecision(precision) << x;
    string strNum = ss.str();
    size_t pos = strNum.find('.');
    int N;  // N - ����� ������ ����� �������

    if (pos != strNum.npos)
    {
        // ����� x - ������������
        N = strNum.size() - 1 - pos;
    }
    else
    {
        // ����� x - �����
        N = 0;
    }

    return N;
}