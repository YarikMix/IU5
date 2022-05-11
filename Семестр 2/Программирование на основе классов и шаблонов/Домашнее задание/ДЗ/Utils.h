#pragma once
#include <string>
std::string FormatDate(int* date);
std::string FormatTime(int time);
std::string GetRandomName();
int* GetDate(std::string raw);
int GetRandomInt(int min, int max);
int* GetRandomDate();