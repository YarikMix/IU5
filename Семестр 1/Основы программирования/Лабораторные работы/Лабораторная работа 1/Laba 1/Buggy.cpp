#include <iostream>
using namespace std;
void buggy()
{
	const int N = 5;
	int a[N] = { 1, 2, 3, 4, 5 };
	int sum = 0, average;
	int i;
	for (i = 0; i < N; i++)
		sum += a[i];
	average = sum / N;
	cout << "average = " << average << endl;
}
