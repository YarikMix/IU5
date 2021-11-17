#include <time.h>	// time
#include <stdlib.h> // srand, rand
#include <iostream>
#include "Randomizer.h"

using namespace std;

int iRandom(int a, int b)
{
	return a + (b - a + 1) * rand() / RAND_MAX;
}
double dRandom(int a, int b)
{
	return a + (b - a) * rand() / (double)RAND_MAX;
}

void Randomize() {
	srand((unsigned int)time(NULL));
}