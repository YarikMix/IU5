#include <iostream>
#include <cstdlib>    // rand(), srand()
#include <fstream>    // ifstream
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Печает текст на экран
void PrintText(char text[], int size)
{
    for (int i = 0; i < size; i++)
        cout << text[i];
    cout << endl;
}

// Генерирует текст
char* GenerateText(int size)
{
    char* text = new char[size + 1];
    const char alphanum1[] = "abcdefghijklmnopqrstuvwxyz";
    const char alphanum2[] = "abcdefghijklmnopqrstuvwxyz       ";
    // const char alphanum3[] = "abcdefghijklmnopqrstuvwxyz       ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{|}~";

    text[0] = alphanum1[rand() % (sizeof(alphanum1) - 1)];  // Первый символ не должен быть пробелом

    for (int i = 1; i < size - 1; i++)
        text[i] = alphanum2[rand() % (sizeof(alphanum2) - 1)];

    text[size - 1] = alphanum1[rand() % (sizeof(alphanum1) - 1)];  // Последний символ не должен быть пробелом


    return text;

}

// Вводим текст с клавиатуры
char* EnterText(int size)
{
    char* text = new char[size];
    cout << "Ввведите текст: ";
    cin.getline(text, size + 1);
    return text;
}

// Считывает текст из файла
char* ReadFile(const char* title, int size)
{
    char* s = new char[size];
    char ch;
    ifstream fin;
    fin.open(title);

    for (int i = 0; i < size; i++)
    {
        fin.get(ch);
        s[i] = ch;
    }

    fin.close();

    return s;

}

// Возвращает индекс последнего вхождения символа в текст
int GetLastEntry(char* text, int size, char symbol)
{
    for (int i = size; i > 0; i--)
        if (text[i] == symbol)
            return i;
    return -1;
}

// Возвращает последнее слово в тексте
char* GetLastWord(char* text, int size, int& wordsize)
{
    int p = GetLastEntry(text, size, ' ');
    int j = 0;
    int len = size - p - 1;
    char* result = new char[size - p - 1];

    for (int i = p + 1; i < size; i++)
    {
        result[j] = text[i];
        j++;
    }

    wordsize = j;

    return result;
}

// Возвращает индекс первого вхождение символва в текст (не используется)
int Find(char arr[], int size, char symbol)
{
    while (true)
    {

        for (int i = 0; i < size; i++) {

            if (arr[i] != symbol)
                if (i >= size - 1)
                    return -1;
            else
                return i;

        }
    }

}

// Проверяет, содержит ли слово данный символ (не используется)
int Сontains(char arr[], int size, char symbol)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == symbol)
            return true;
    return false;
}

// Возвращает количество пробелов в тексте
int SpacesCount(char* text, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
            count++;
    }
    return count;
}

// Возвращает массив с индексами пробелов
int* FindSpaces(char* text, int size)
{
    int* SpacesIdx = new int[SpacesCount(text, size)];  // Массив с индексами пробелов
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
        {
            SpacesIdx[j] = i;
            j++;
        }
    }

    return SpacesIdx;
}

// Возвращает true - если слово целиком состоит из пробелов, в обратном случае возвращает false
bool IsOnlyContainSpaces(char* word, int len)
{
    for (int i = 0; i < len; i++)
        if (word[i] != ' ')
            return false;
    return true;
}

// Обрезает текст по заданным границам
char* Trim(char* text, int idx1, int idx2, int& wordsize)
{
    char* result;
    int i;
    int j = 0;
    if (idx1 == 0)
    {
        result = new char[idx2 - idx1 + 1];
        for (i = idx1; i < idx2; i++)
        {
            result[j] = text[i];
            j++;
        }

    }
    else {
        result = new char[idx2 - idx1];
        for (i = idx1 + 1; i < idx2; i++)
        {
            result[j] = text[i];
            j++;
        }
    }

    wordsize = j;

    return result;
}

// Сравненивает два слова
bool CompareWord(char* word1, int size1, char* word2, int size2)
{
    if (size1 != size2) return false;

    for (int i = 0; i < size1; i++)
        if (word1[i] != word2[i]) return false;

    return true;
}

/* 
Проверяем, совпадает ли слово с конечным отрезком из алфавита(z, yz, xyz, ...)
Для этого проходимся по каждому слову (z, yz, xyz, ...) и проверяем, если 
оба слова совпадают, то возвращает true
*/
bool CheckWord(char* word, int size)
{
    char* s;
    int l = 0;
    int len;
    for (char i = 'a'; i <= 'z'; i++)
    {
        len = abs(122 - int(i) + 1);
        s = new char[len + 1];
        l = 0;
        for (char j = i; j <= 'z'; j++)
        {
            s[l] = j;
            l++;
        }

        if (CompareWord(word, size, s, len)) return true;
    }
    return false;
}

int main()
{
    srand((unsigned int)time(NULL));                        // Исправляем псевдорандом
    setlocale(LC_ALL, "rus");                               // Исправляем русский язык в консоли
    int size = 80;                                          // Количество символов в тексте

    char *text = EnterText(size);                           // Считываем текст из файла
    // char* text = GenerateText(size);                     // Генерируем текст
    // char* text = ReadFile("text.txt", size);
    PrintText(text, size);

    int lastwordlen;                                        // Длина последнего слова
    char* lastword = GetLastWord(text, size, lastwordlen);  // Последнее слово

    int spacescount = SpacesCount(text, size);              // Количество пробелов в тексте
    int* SpacesIdx = FindSpaces(text, size);                // Массив из индексов пробелов

    int lastidx;
    int nextidx;
    char* word;
    int wordlen;
    bool flag;

    cout << "Слова, удовлетворяющие условию задачи: " << endl;
    for (int k = 0; k < spacescount - 1; k++)
    {
        lastidx = SpacesIdx[k];
        nextidx = SpacesIdx[k + 1];
        word = Trim(text, lastidx, nextidx, wordlen);                      // Проходимся по каждому слову в тексте, кроме последнего
        
        bool flag1 = IsOnlyContainSpaces(word, wordlen);                   // Если слово состоит только из проблелов - пропускаем
        bool flag2 = CompareWord(lastword, lastwordlen, word, wordlen);    // Если слово совпадает с последним словом - пропускаем
        if (flag1 || flag2) continue;                                              
        
        if (CheckWord(word, wordlen)) PrintText(word, wordlen);            // Если слово удовлетворяет всем условиям - печатаем
    }
    return 0;
}