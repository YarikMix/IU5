#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef double (*TPF)(double);
typedef double (*TPM)(TPF f, double a, double b, int n);
struct I_print {	  //данные для печати результатов интегрирования
    const char* name; //название функции
    double i_sum;	  //значение интегральной суммы
    double i_toch;	  //точное значение интеграла
    int n;	          //число разбиений области интегрирования, при котором достигнута требуемая точность
};

void PrintTabl(I_print i_prn[], int k)
{
    const int m = 4;             //число столбцов таблицы
    int wn[m] = { 18,18,18,10 }; //ширина столбцов таблицы
    const char* title[m] = { "Function","Integral","IntSum","N " };
    int size[m];
    for (int i = 0; i < m; i++)
        size[i] = strlen(title[i]);

    //шапка таблицы
    cout << char(218) << setfill(char(196));
    for (int j = 0; j < m - 1; j++)
        cout << setw(wn[j]) << char(194);
    cout << setw(wn[m - 1]) << char(191) << endl;

    cout << char(179);
    for (int j = 0; j < m; j++)
        cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
        << setw((wn[j] - size[j]) / 2) << char(179);
    cout << endl;

    //заполнение таблицы
    for (int i = 0; i < k; i++)
    {
        cout << char(195) << fixed;
        for (int j = 0; j < m - 1; j++)
            cout << setfill(char(196)) << setw(wn[j]) << char(197);
        cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;

        cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
            << setw((wn[0] - strlen(i_prn[i].name)) / 2) << char(179);
        cout << setw(wn[1] - 1) << setprecision(6) << i_prn[i].i_toch << char(179)
            << setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
            << setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;


    }

    //низ таблицы
    cout << char(192) << setfill(char(196));
    for (int j = 0; j < m - 1; j++)
        cout << setw(wn[j]) << char(193);
    cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}

void h1(const char* s)
{
    cout << setw(38) << s << "\n\n\n";
}

double f1(double x)
{
    return x;
}

double f2(double x)
{
    return sin(22 * x);
}

double f3(double x)
{
    return x * x * x * x;
}

double f4(double x)
{
    return atan(x);
}

double IntRect(TPF f, double a, double b, int n)
{
    double h = (b - a) * 1.0 / n;
    double result = 0.0;

    for (int i = 0; i < n; i++)
        result += f(a + h * (i + 0.5));

    result *= h;

    return result;
}

double IntTrap(TPF f, double a, double b, int n)
{
    double width = (b - a) * 1.0 / n;
    double trapezoidal_integral = 0;
    double x1, x2, h;

    for (int step = 0; step < n; step++) {
        x1 = a + step * width;
        x2 = a + (step + 1) * width;
        h = x2 - x1;

        trapezoidal_integral += 0.5 * h * (f(x1) + f(x2));
    }

    return trapezoidal_integral;
}

double Integrate(TPF f, TPM method, double a, double b, double eps, int &n)
{
    n = 2;
    int i = 0;
    double diff;
    do {
        i++;
        diff = method(f, a, b, n * i) - method(f, a, b, n * (i + 1));
    } while (abs(diff)/3 > eps);
    n = n * (i + 1);
    return method(f, a, b, n * i);
}

void Do(TPM method)
{
    double a = -1;
    double b = 3;

    double epss[5] = { 0.01, 0.001, 0.0001, 0.00001, 0.000001 };

    for (int epsIndex = 0; epsIndex < 5; epsIndex++)
    {
        double eps = epss[epsIndex];

        const char* functions[4] = {
           "y=x ",
           "y=sin(22*x) ",
           "y=x^4 ",
           "y=arctg(x)  "
        };

        double Int[4] = {
            (b * b - a * a) / 2.0,
            (cos(a * 22.0) - cos(b * 22.0)) / 22.0,
            (b * b * b * b * b - a * a * a * a * a) / 5.0,
            (b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0)
        };

        int n0, n1, n2, n3;

        double IntSum[4] = {
            Integrate(f1, method, a, b, eps, n0),
            Integrate(f2, method, a, b, eps, n1),
            Integrate(f3, method, a, b, eps, n2),
            Integrate(f4, method, a, b, eps, n3)
        };

        int N[4] = {
            n0,
            n1,
            n2,
            n3
        };

        I_print printData[4];
        for (int i = 0; i < 4; i++) {
            printData[i] = { functions[i], Int[i], IntSum[i], N[i] };
        }

        cout << setw(34) << "Precision: " << eps << "\n";
        PrintTabl(printData, 4);
        cout << "\n\n\n";

    }
}

int main()
{
    // system("chcp 1251 > nul");

    h1("Rectangle method");
    Do(IntRect);
    h1("Trapeze method");
    Do(IntTrap);

    return 0;
}