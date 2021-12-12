#include <iostream>
#include <fstream>
using namespace std;

/////////////////////////////// Функции для работы с файлами ///////////////////////////////

// Возвращет размер файла (количество символов)
streampos FileSize(const char* filename) {

    streampos fsize = 0;
    ifstream file(filename, ios::binary);

    fsize = file.tellg();
    file.seekg(0, ios::end);
    fsize = file.tellg() - fsize;
    file.close();

    return fsize;
}

// Считывает текст из файла
char* ReadFile(const char* filename)
{
    int size = FileSize(filename);  // Количество символов в файле
    char* s = new char[size + 1];
    char ch;
    ifstream file;
    file.open(filename, ios::binary);

    if (!file.is_open())
    {
        cout << "Файла " << filename << " не существует" << endl;
        exit(0);
    }

    for (int i = 0; i < size; i++)
    {
        file.get(ch);
        s[i] = ch;
    }

    file.close();

    return s;
}

// Записывает текст в файл
void WriteFile(char text[], int size, const char* filename)
{
    /*
    FILE* file = fopen(filename, "w");
    fputs(text, file);
    fclose(file);
    */
    ofstream f;
    f.open(filename, ios::binary);
    for (int i = 0; i < size; i++)
        f << text[i];
    f.close();
}

/////////////////////////////// Функции для работы с текстом ///////////////////////////////

// Выводит текст
void PrintText(char* s[], int len)
{
    for (int j = 0; j < len; j++)
        cout << s[j];
}

// Проверяет, содержит ли текст данный символ
bool Сontains(const char* filename, char symbol)
{
    char* text = ReadFile(filename);
    int size = FileSize(filename);
    for (int i = 0; i < size; i++)
        if (text[i] == symbol)
            return true;
    return false;
}

// Возвращает количество слов в тексте
int GetWordsCount(const char* filename)
{
    char* text = ReadFile(filename);
    int size = FileSize(filename);
    int count = 0;
    for (int i = 0; i < size; i++)
        if (text[i] == ' ')
            count++;
    count++;
    return count;
}

// Выводит заголовок
void h1(const char text[])
{
    cout << "\n\n\n" << text << "\n\n\n";
}

/////////////////////////////// Функции для работы с массивами и матрицами ///////////////////////////////

// Выводит массив
void PrintArray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
        cout << arr[j] << " ";
}

// Выводит квадратную матрицу A
void PrintMatrix(int** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Создаёт массив и заполняет его нулями
int* CreateArray(int N)
{
    int* arr = new int[N + 1];
    for (int i = 0; i < N; i++)
        arr[i] = 0;
    return arr;
}

// Создаёт квадратную матрицу
int** CreateMatrix(int N)
{
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[N];
        for (int j = 0; j < N; j++)
            A[i][j] = 0;
    }
    return A;
}

/////////////////////////////// Главные функции ///////////////////////////////

// Возвращает массив ключей
int* GetKeyArray(const char* filename)
{
    char* text = ReadFile(filename);
    int size = FileSize(filename);
    int temp = 0;
    int wordscount = GetWordsCount(filename);              // Количество слов в тексте (размер массива ключей)
    int* scod = CreateArray(wordscount + 1);               // Массив ключей(ключ - сумма кодов одного слова)

    int j = 1;

    scod[0] = wordscount;

    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
        {
            scod[j] %= 256;
            j++;
        }
        else
        {
            temp = (int)text[i];
            if (temp < 0) temp += 256;
            scod[j] += temp;
        }

        scod[j] %= 256;
    }

    return scod;
}

// Выводит статистику по переданному символу
void GetStatistic(int** statistic, char symbol)
{
    int temp = (int)symbol;
    if (temp < 0) temp += 256;
    cout << "Символ '" << symbol << "', код - " << temp << endl;

    if (Сontains("input.txt", symbol))
    {
        for (int i = 0; i < 256; i++)
        {
            if (statistic[temp][i] != 0)
                cout << (char)(i) << " - " << statistic[(int)(temp)][i] << endl;
            }
    }
    else
    {
        cout << "В исходном файле нет символа '" << symbol << "'";
    }
}

// Шифрует текст
char* Encode(const char* input_file, const char* keys_file, int** statistic)
{

    char* text = ReadFile(input_file);
    int size = FileSize(input_file);
    int* keys = GetKeyArray(keys_file);
    int keyscount = GetWordsCount(keys_file);


    int temp;
    char* codtext = new char[size];
    for (int i = 0; i < size; i++)
    {
        temp = (int)text[i];
        if (temp < 0) temp += 256;
        int codesymbol = (char)((temp + keys[i % keyscount]) % 256);
        codtext[i] = codesymbol;
        statistic[temp][((temp + keys[i % keyscount]) % 256)] += 1;
    }

    return codtext;
}

// Расшифровывает текст
char* Decode(const char* cipher_file, const char* keys_file)
{
    char* codtext = ReadFile(cipher_file);
    int size = FileSize(cipher_file);
    int* keys = GetKeyArray(keys_file);
    int keyscount = GetWordsCount(keys_file);

    int temp;
    char* decodtext = new char[size];
    for (int i = 0; i < size; i++)
    {
        temp = (int)codtext[i];
        if (temp < 0) temp += 256;
        decodtext[i] = (char)((temp - keys[i % keyscount]) % 256);
    }
    return decodtext;
}

// Очищаем память
void Clear(int** A, int N)
{
    for (int i = 1; i < N; i++)
        delete[] A[i];
    delete[] A;
}

int main()
{
    system("chcp 1251");
    int size = FileSize("input.txt");                                         // Количество символов в тексте
    
    int** statistic = CreateMatrix(256);
    char* codtext = Encode("input.txt", "key.txt", statistic);                // Кодирование текста
    // h1("Зашифрованный текст");
    // PrintText(codtext, size);                                              // Вывод зашифрованного текста
    WriteFile(codtext, size, "shifr.txt");                                    // Запись в файл

    char symbol = 'e';
    GetStatistic(statistic, symbol);


    // char* decodtext = Decode("shifr.txt", "key.txt");                       // Кодирование текста
    // h1("Расшифрованный текст");
    // PrintText(decodtext, size);                                             // Вывод зашифрованного текста
    // WriteFile(decodtext, size, "output.txt");                               // Запись в файл
    
    // Освобождение памяти
    Clear(statistic, size);
    delete[] codtext;                                              
    return 0;
}