#include <iostream>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

int N;
int K;
int width;
int counter;

class Planet {
    private:
        string name;
        long int diam;
        int sat;
        string life;

    public:
        Planet()
        {
            name = "planet_name";
            diam = 123;
            sat = 12;
            life = true;
        }

        Planet(string name, long int diam, int sat, string life)
        {
            this->name = name;
            this->diam = diam;
            this->sat = sat;
            this->life = life;
        }

        void print()
        {
            cout << left << fixed << setw(K) << this->name << " ";
            cout << left << fixed << setw(K) << this->diam << " ";
            cout << left << fixed << setw(K) << this->sat << " ";
            cout << left << fixed << setw(K) << this->life << " ";
            cout << endl;
        }

        inline string GetName() { return this->name; }
        inline long int GetDiam() { return this->diam; }
        inline int GetSat() { return this->sat; }
        inline string GetLife() { return this->life; }

        inline void SetName(string newName) { this->name = newName; };
        inline void SetDiam(long int newDiam) { this->diam = newDiam; };
        inline void SetSat(int newSat) { this->sat = newSat; };
        inline void SetLife(bool newLife) { this->life = newLife; };

        ~Planet()
        {

        }
};

Planet* planets = nullptr;

int GetPlanet(string name)
{
    for (int i = 0; i < counter; i++)
    {
        if (planets[i].GetName() == name)
        {
            return i;
        }
    }
    return -1;
}

void AddPlanet()
{
    string name;
    long int diam;
    int sat;
    string life;

    cout << "Введите название планеты\n> ";
    cin >> name;

    int i = GetPlanet(name);
    if (i != -1)
    {
        cout << "Планета с названием '" << name << "' уже существует!";
        return;
    }

    diam = InputDiam();
    sat = InputSat();
    life = InputSwitch();

    if (diam == -1 || sat == -1 || life == "-1")
    {
        cout << "Не удалось добавить планету '" << name << "'!";
        return;
    }

    planets[counter] = Planet(name, diam, sat, life);
    counter++;
    cout << "Планета '" << name << "' успешно создана!'" << endl;
}

void RemovePlanet() {
    string name;

    cout << "Введите название планеты\n> ";
    cin >> name;

    int i = GetPlanet(name);
    if (i == -1)
    {
        cout << "Планеты с названием '" << name << "' не существует!";
        return;
    };

    Planet* newPlanets = new Planet[N];

    if (counter > 1)
    {
        copy(planets, planets + i, newPlanets);
        copy(planets + i + 1, planets + N, newPlanets + i);
    }

    delete[] planets;
    planets = newPlanets;
    counter--;
    cout << "Планета '" << name << "' успешно удалена!'" << endl;
    return;
}

void Rename()
{
    string name;
    string newName;

    cout << "Введите название планеты, которую хотите переименовать\n> ";
    cin >> name;

    int i = GetPlanet(name);
    if (i == -1)
    {
        cout << "Планеты с названием '" << name << "' не существует!";
        return;
    }

    cout << "Введите новое название для планеты '" << name << "'\n> ";
    cin >> newName;

    int j = GetPlanet(newName);
    if (j != -1)
    {
        cout << "Планета с именем '" << newName << "' уже существует!";
        return;
    }

    planets[i].SetName(newName);
    cout << "Планета '" << name << "' успешно переименована в '" << newName << "'";
}

void PrintPlanets()
{
    if (counter == 0)
    {
        cout << "Список планет пуст!";
        return;
    }

    cout << left << fixed << setw(K) << "Название" << " ";
    cout << left << fixed << setw(K) << "Диаметр" << " ";
    cout << left << fixed << setw(K) << "Количество спутников" << " ";
    cout << left << fixed << setw(K) << "Жизнь" << " ";
    cout << endl;

    
    for (int i = 0; i < counter; i++)
    {
        planets[i].print();
    }
}

void PrintPlanet()
{
    string name;
    cout << "Введите название планеты\n> ";
    cin >> name;

    int i = GetPlanet(name);
    if (i == -1)
    {
        cout << "Планеты с названием '" << name << "' не существует!";
        return;
    }

    cout << left << fixed << setw(K) << "Название" << " ";
    cout << left << fixed << setw(K) << "Диаметр" << " ";
    cout << left << fixed << setw(K) << "Количество спутников" << " ";
    cout << left << fixed << setw(K) << "Жизнь" << " ";
    cout << endl;

    planets[i].print();
}

void SortByName()
{
    bool flag;
    cout << "Сортировать по возрастанию? 1/0\n> ";
    cin >> flag;

    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            if (flag ? planets[i].GetName() > planets[j].GetName() : planets[i].GetName() < planets[j].GetName())
                swap(planets[i], planets[j]);
        }
    }

    PrintPlanets();
}

void SortByDiam()
{
    bool flag;
    cout << "Сортировать по возрастанию? 1/0\n> ";
    cin >> flag;

    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            if (flag ? planets[i].GetDiam() > planets[j].GetDiam() : planets[i].GetDiam() < planets[j].GetDiam())
                swap(planets[i], planets[j]);
        }
    }

    PrintPlanets();
}

void SortBySat()
{
    bool flag;
    cout << "Сортировать по возрастанию? 1/0\n> ";
    cin >> flag;

    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            if (flag ? planets[i].GetSat() > planets[j].GetSat() : planets[i].GetSat() < planets[j].GetSat())
                swap(planets[i], planets[j]);
        }
    }

    PrintPlanets();
}

int menu()
{
    int choose;
    cout << "\n\n\nВведите число от 1 до 9: ";

    if (cin >> choose)
    {

    }
    else
    {
        cin.clear(); // put the stream back into a good state
        cin.ignore(1000, '\n'); // and remove the bad input remaining in the input buffer
    }

    return choose;
}

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    // cout << "Введите количество планет\n> ";
    // cin >> N;
    N = 10;
    counter = 4; 
    width = GetConsoleWidth();
    K = floor(width / 4) - 1;
    planets = new Planet[N];

    planets[0] = Planet("Солнце", 256, 5, "false");
    planets[1] = Planet("Земля", 128, 8, "true");
    planets[2] = Planet("Плутон", 64, 2, "false");
    planets[3] = Planet("Апалон", 32, 0, "false");
   
    cout << "1 - добавить планету \n"
         << "2 - удалить планету \n"
         << "3 - вывести информацию о всех планетах \n"
         << "4 - вывести информацию об одной планете \n"
         << "5 - изменить название планеты\n"
         << "6 - отсортировать планеты по названию \n"
         << "7 - отсортировать планеты по диаметру \n"
         << "8 - отсортировать планеты по количеству спутников\n"
         << "9 - выйти из программы\n";

    while (true) {
        switch (menu()) {
            case 1: AddPlanet(); break;
            case 2: RemovePlanet(); break;
            case 3: PrintPlanets(); break;
            case 4: PrintPlanet(); break;
            case 5: Rename(); break;
            case 6: SortByName(); break;
            case 7: SortByDiam(); break;
            case 8: SortBySat(); break;
            case 9: return 0;
            default:
                cout << "Пожалуйста введите число от 1 до 9" << endl;
                break;
        }
    }
    
    delete[] planets;
    return 0;
}