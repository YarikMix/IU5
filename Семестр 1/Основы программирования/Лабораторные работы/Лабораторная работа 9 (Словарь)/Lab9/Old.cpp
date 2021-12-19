#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define filename "dict.txt"
using namespace std;

// ������� �� ����� �������
void PrintVector(vector<string>& vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << endl;
}

// ���������, �������� �� ������� �����
bool Check(vector<string>& vec, string word)
{
    for (int i = 0; i < vec.size(); i++)
    {
        string data = vec.at(i);

        if (data.find(word) != -1)
            return true;

    }
    return false;
}

// ��������� �����
int Translate(vector<string>& vec, string target)
{
    // ���� ����� ��� � �������, �� ������� �� �������
    if (!Check(vec, target))
    {
        cout << "����� '" << target << "' ��� � �������!";
        return -1;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        string data = vec.at(i);

        int next = data.find("=");
        string word = data.substr(0, next - 1);
        string translate = data.substr(next + 2);

        if (target == word)
        {
            cout << "������ '" << target << "' ����������� ��� '" << translate << "'\n";
            return 0;
        }


    }
    return -1;
}

// ��������� ����� � �������
int Add(vector<string>& vec, string word, string translate)
{
    // ���� ����� ��� ������������ � �������, �� ������� �� �������
    if (Check(vec, word))
    {
        cout << "����� '" << word << "' ��� ���� � �������!";
        return -1;
    }

    string str = "\n" + word + " = " + translate;
    ofstream file;

    file.open(filename, ios::app);
    file << str;
    file.close();

    return 0;
}

// ������� ����� �� �������
int Remove(vector<string>& vec, string word)
{
    // ���� ����� ��� � �������, �� ������� �� �������
    if (!Check(vec, word))
    {
        cout << "����� '" << word << "' ��� � �������!";
        return -1;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        string data = vec.at(i);

        // ���������, ���� ���� ����������, �� ������� ������ �� �����
        if (data.find(word) != -1)
        {
            vec.erase(vec.begin() + i);

            ofstream outfile(filename);
            if (outfile.is_open())
            {
                copy(vec.begin(), vec.end(), ostream_iterator<string>(outfile, ""));
                outfile.close();
            }
            return 0;
        }

    }
}

vector<string> LoadDictionary()
{

    string str;
    vector<string> arr;
    ifstream file;

    file.open(filename, ios::binary);

    while (getline(file, str))
        arr.push_back(str);

    file.close();

    return arr;
}

/*
int main()
{
    setlocale(LC_ALL, "Russian");

    vector<string> arr = LoadDictionary();
    PrintVector(arr);
    Add(arr, "�����", "Banana");
    Translate(arr, "������");
    Remove(arr, "Banana");
    return 0;
}
*/