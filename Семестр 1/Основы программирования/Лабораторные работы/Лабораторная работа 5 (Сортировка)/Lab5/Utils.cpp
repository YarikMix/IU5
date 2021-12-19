#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include "Utils.h"
#include "Randomizer.h"
using namespace std;

void printArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i > 5)
		{
			cout << "...";
			break;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
}

void FillArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = iRandom(1, 9);
}

int* CreateArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = iRandom(1, 9);;
	return arr;
}

int* CopyArray(int* source, int size) {
	int* newArr = new int[size];
	for (int i = 0; i < size; i++)
		newArr[i] = source[i];
	return newArr;
}

void DisplaySolution(const int n) {
	cout << left << setw(16) << n;
}

void printString(const char *s) 
{
	cout << left << setw(32) << s;
}

void printNumber(int n) 
{
	cout << left << setw(32) << n;
}

string operator * (string a, unsigned int b) {
	string output = "";
	while (b--) {
		output += a;
	}
	return output;
}

string retrieveString(const char* buf) {

	size_t len = 0;
	while (buf[len] != '\0') {
		len++;
	}

	return string(buf, len);

}

void h1(const char *s) 
{
	// HWND hWnd = GetConsoleWindow();
	// RECT rc;
	// GetClientRect(hWnd, &rc);
	// int w = rc.right;
	int n = (unsigned)strlen(s); // длина строки
	string l = string("#") * (0.5 * (118 - n));
	cout << string("#") * 120 << endl;
	cout << l << " " << s << " " << l << endl;
	cout << string("#") * 120 << "\n\n\n";
}

void h2(const char* s, int i)
{
	string s2 = string(s) + to_string(i);
	int n = s2.length(); // длина строки
	string l = string("-") * (0.5 * (118 - n));
	
	cout << l << " " << s2 << " " << l << "\n\n";
}