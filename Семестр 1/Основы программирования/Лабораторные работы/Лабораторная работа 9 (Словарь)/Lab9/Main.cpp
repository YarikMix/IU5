#include <iostream>
#include <fstream>
using namespace std;

const int max_size = 100;
const int l_word = 31;
struct Dictionary {
    char engl[l_word];	// слово по-английски
    char rus[l_word];	// слово по-русски
};

Dictionary dict[max_size];	// массив структур для хранения словаря в оперативной памяти
int n = 0;		 	        // фактическое число записей в словаре

// Эта функция (в качестве подсказки) выводит пронумерованный перечень возможных 
// действий пользователя и выполняет ввод номера выбранного действия. 
// Это число она должна вернуть в вызвавшую функцию. 
int Menu()
{
    int choose;
    cout << "\n\n\nВведите число от 1 до 7: ";

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

// Возвращает true, если слова совпадают, false в обратном случае
bool Equals(char word1[], char word2[])
{
    for (int i = 0; i < l_word; i++)
    {
        if (word1[i] != word2[i])
            return false;
        if (word1[i] == '\0' && word2[i] == '\0')
            return true;
    }

    return true;
}

// Сравнивает два слова (посимвольно)
bool Compare(char word1[], char word2[])
{
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++)
        if (word1[i] > word2[i])
            return true;
        else if (word1[i] < word2[i])
            return false;
}

// Сортирует словарь по возрастанию методом пузырька
void SortDict()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (Compare(dict[j].engl, dict[j + 1].engl))
                swap(dict[j], dict[j + 1]);

    cout << "Словарь успешно отсортирован!" << endl;
}

// Ищет слово в словаре
int Find(char word[], int mode = 2)
{
    if (mode == 0)
    {
        for (int i = 0; i < n; i++)
            if (Equals(dict[i].engl, word))
                return i;
    }
    else if (mode == 1)
    {
        for (int i = 0; i < n; i++)
            if (Equals(dict[i].rus, word))
                return i;
    }
    else if (mode == 2)
    {
        for (int i = 0; i < n; i++)
            if (Equals(dict[i].engl, word) || Equals(dict[i].rus, word))
                return i;
    }

    return -1;

}

// Переводит слово
void Translate(int mode)
{
    char word[l_word];

    if (mode == 0)
        cout << "Введите слово на английском языке - ";
    else
        cout << "Введите слово на русском языке - ";

    cin >> word;

    int index = Find(word, mode);

    if (index == -1)
        cout << "Слова '" << word << "' нет в словаре!" << endl;
    else
    {
        if (mode == 0)
            cout << "Слово '" << word << "' переводится как '" << dict[index].rus << "'" << endl;
        else
            cout << "Слово '" << word << "' переводится как '" << dict[index].engl << "'" << endl;
    }
}

// Добавляет слово в словарь
void AddWord()
{
    char word[l_word], translate[l_word];
    cout << "Введите слово - ";
    cin >> word;

    int index = Find(word);

    if (index == -1)
    {
        cout << "Введите перевод слова '" << word << "' - ";
        cin >> translate;

        strcpy_s(dict[n].rus, word);
        strcpy_s(dict[n].engl, translate);

        cout << "Слово " << word << "(" << translate << ") успешно добавлено в словарь!" << endl;
        n++;
        SortDict();
    }
    else
    {
        cout << "Слово '" << word << "' уже находится в словаре!" << endl;
    }

}

// Добавляет слово в словарь
void AddTestWord(const char word[], const char translate[])
{
    strcpy_s(dict[n].rus, word);
    strcpy_s(dict[n].engl, translate);

    n++;
}

// Удаляет слово из словаря
void RemoveWord()
{
    char word[l_word];
    cout << "Введите слово - ";
    cin >> word;

    int index = Find(word);

    if (index == -1)
        cout << "Слова '" << word << "' нет в словаре!" << endl;
    else
    {
        strcpy_s(dict[index].rus, "");
        strcpy_s(dict[index].engl, "");

        for (int i = index; i < n - 1; i++)
        {
            strcpy_s(dict[i].rus, dict[i + 1].rus);
            strcpy_s(dict[i].engl, dict[i + 1].engl);
        }

        strcpy_s(dict[n - 1].rus, "0");
        strcpy_s(dict[n - 1].engl, "0");

        n--;

        cout << "Cлово " << word << " удалено из словаря!" << endl;
    }

}

// Выводит словарь на экран
void ShowDict()
{
    for (int i = 0; i < n; i++)
        if (dict[i].rus[0] != '0')
            cout << i + 1 << ". " << dict[i].rus << " " << dict[i].engl << endl;
    cout << endl;
}

// Печатает словарь в файл
void PrintDict()
{
    const char filename[] = "dict.txt";

    ofstream f;
    f.open(filename, ios::binary);

    for (int i = 0; i < n; i++)
        f << dict[i].rus << " " << dict[i].engl << "\n";

    f.close();

    cout << "Словарь напечатан в файл 'dict.txt'" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "1 - добавление слова в словарь \n"
        << "2 - удаление слова из словаря \n"
        << "3 - перевод слов с английского на русский \n"
        << "4 - перевод слов с русского на английский \n"
        << "5 - вывод на экран словаря  \n"
        << "6 - вывод словаря в файл \n"
        << "7 - выход из программы\n";

    AddTestWord("sobaka", "dog");
    AddTestWord("kot", "cat");
    AddTestWord("mashina", "car");

    while (true) {
        switch (Menu()) {
            case 1: AddWord();    break;
            case 2: RemoveWord(); break;
            case 3: Translate(0); break;
            case 4: Translate(1); break;
            case 5: ShowDict();   break;
            case 6: PrintDict();  break;
            case 7: return 0;
            default:
                cout << "Надо вводить число от 1 до 7" << endl;
                break;
            }
    }

    return 0;
}