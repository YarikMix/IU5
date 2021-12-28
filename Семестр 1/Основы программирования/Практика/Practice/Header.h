#include <string>
using namespace std;
#pragma once

int GetConsoleWidth();
void h1(const char* s);
int Sum(int arr[], int n = 4);
bool isString(string s);
bool CheckDate(int date[3]);
double difference(int bDay[3], int cDay[3]);
string ShowGender(int gender);
string FormatDate(int date[3]);
bool isDuplicate(string name);
int Input(string message, int left = 0, int right = 9999);
string GetName();
void GetBirthdayDate(int birthday[3]);
void Get—ompetitionDate(int birthday[3], int competition[3]);
int GetGender();
void GetScore(int arr[4], int gender);