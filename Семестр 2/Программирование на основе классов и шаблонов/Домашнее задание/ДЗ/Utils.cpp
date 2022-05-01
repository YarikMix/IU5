#include "Utils.h"
#include <string>
using namespace std;

std::string FormatDate(int* date)
{
    return to_string(date[0]) + "." + to_string(date[1]) + "." + to_string(date[2]);
}

std::string FormatTime(int time)
{
    return to_string(time / 3600) + "h " + to_string(time / 60 % 60) + "m " + to_string(time % 60) + "s";
}
