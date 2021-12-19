#include <iostream>
using namespace std;

string get_plural(int i, string s1, string s2, string s3)
{
    if (i % 100 >= 11 && i % 100 <= 20) return s3;
    else {
        if (i % 10 == 1)
            return s1;
        else if (i % 10 >= 2 && i % 10 <= 4)
            return s2;
        else
            return s3;
    }
}

string get_time(int hours, int minutes) {
    int time = hours * 3600 + minutes * 60;
    if (time >= 18000 && time < 43200) return "утра";
    else if (time >= 43200 && time < 64800) return "дня";
    else if (time >= 64800 && time < 86400) return "вечера";
    else return "ночи";
}

void print_time() {
    int hours, minutes;
    cin >> hours >> minutes;

    if (hours < 0 || hours > 24 || minutes < 0 || minutes > 60)
        cout << "Введены недопустимые данные";

    else if (hours == 12) {
        if (minutes == 0)
            cout << "Полдень";
        else {
            cout << "12 часов ";
            cout << minutes << " " << get_plural(minutes, "минута", "минуты", "минут") << " ";
            cout << "дня";
        }
    }
    
    else if ((hours == 24 || hours == 0) && minutes == 0)
        cout << "Полночь";

    else if (minutes == 0) {
        cout << hours % 12 << " " << get_plural(hours % 12, "час", "часа", "часов") << " ";
        cout << get_time(hours, minutes) << " ";
        cout << "ровно";
    }

    else {
        cout << hours % 12 << " " << get_plural(hours % 12, "час", "часа", "часов") << " ";
        cout << minutes << " " << get_plural(minutes, "минута", "минуты", "минут") << " ";
        cout << get_time(hours, minutes);
    }
  
    cout << endl;
}

int main()
{
    // setlocale(LC_ALL, "");
    system("chcp 1251 > nul");
    while (true) {
        print_time();
    }
    return 0;
}