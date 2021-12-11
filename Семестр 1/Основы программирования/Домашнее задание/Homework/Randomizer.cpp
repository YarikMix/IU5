#include <time.h>	// time
#include <stdlib.h> // srand, rand
#include <iostream>
#include "Header.h"

using namespace std;

void Randomize()
{
    srand((unsigned int)time(NULL));
}

char* CreateArray(int size) {
    srand((unsigned int)time(NULL));

    static const char alphanum[] =
        "0123456789"
        "{|}~ "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    char* s = new char[size];
    for (int i = 0; i < size; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[size] = 0;
    return s;
}