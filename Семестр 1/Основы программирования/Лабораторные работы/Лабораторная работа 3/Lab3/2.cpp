#include <iostream>
using namespace std;

void test1()
{
    int n, m;
    int sum = 0;
    int i = 1;
    int k = 0;
    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;
    while (k < n) {
        if (i % 5 == 0 && i % m != 0) {
            k++;
            sum += i;
        }
        i += 1;
    }
    cout << sum;
}
