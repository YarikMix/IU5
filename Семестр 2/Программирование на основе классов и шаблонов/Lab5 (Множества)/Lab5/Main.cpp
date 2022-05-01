#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MySet
{
    private:
        int size;
        string* elements;
    public:
        MySet() {
            this->size = 0;
            this->elements = nullptr;
        }

        MySet(const string a) {
            this->size = 1;
            this->elements = new string[1];
            this->elements[0] = a;
        }

        MySet(const MySet &mySet) {
            this->size = mySet.size;
            this->elements = new string[size];
            for (int i = 0; i < size; ++i) {
                this->elements[i] = mySet.elements[i];
            }
        }

        ~MySet() {
            delete[] this->elements;
        }

        int Size() {
            return size;
        }

        bool isElement(string a) {
            for (int i = 0; i < size; ++i) {
                if (a == this->elements[i]) {
                    return true;
                }
            }
            return false;
        }

        MySet addElement(string a) {
            if (!isElement(a)) {
                size++;
                auto* temp = new string[size];
                for (int i = 0; i < size - 1; ++i) {
                    temp[i] = this->elements[i];
                }
                temp[size - 1] = a;
                swap(temp, this->elements);
                delete[] temp;
            }
            return *this;
        }

        MySet deleteElement(string a) {
            if (isElement(a)) {
                size--;
                int t = 0;
                auto* temp = new string[size];
                for (int i = 0; i < size + 1; ++i) {
                    if (a != this->elements[i]) {
                        temp[i - t] = this->elements[i];
                    }
                    else {
                        t = 1;
                    }
                }
                swap(temp, this->elements);
                delete[] temp;
            }
            return *this;
        }

        string operator[](int i) {
            return this->elements[i];
        }

        MySet operator=(MySet set) {
            auto* temp = new string[set.size];
            size = set.size;
            for (int i = 0; i < size; ++i) {
                temp[i] = set.elements[i];
            }
            swap(temp, this->elements);
            delete[] temp;
            return *this;
        }

        MySet operator+=(MySet set) {
            for (int i = 0; i < set.size; ++i) {
                addElement(set.elements[i]);
            }
            return *this;
        }

        MySet operator-=(MySet set) {
            for (int i = 0; i < set.size; ++i) {
                deleteElement(set[i]);
            }
            return *this;
        }

        MySet operator*=(MySet set) {
            for (int i = 0; i < size; ++i) {
                if (!set.isElement(elements[i])) {
                    deleteElement(elements[i]);
                }
            }
            return *this;
        }

        friend bool operator==(MySet a, MySet b) {
            if (a.Size() != b.Size()) {
                return false;
            }
            else {
                for (int i = 0; i < a.Size(); ++i) {
                    if (!a.isElement(b[i])) {
                        return false;
                    }
                }
                return true;
            }
        }

        friend bool operator!=(MySet a, MySet b) {
            return !(a == b);
        }

        friend MySet operator+(MySet a, MySet b) {
            MySet temp(a);
            temp += b;
            return temp;
        }

        friend MySet operator-(MySet a, MySet b) {
            MySet temp(a);
            temp -= b;
            return temp;
        }

        friend MySet operator*(MySet a, MySet b) {
            MySet temp(a);
            temp *= b;
            return temp;
        }

        friend ostream &operator<<(ostream& out, MySet set) {
            if (set.Size() != 0) {
                out << "{ ";
                if (set.Size() != 1) {
                    for (int i = 0; i < set.Size() - 1; ++i) {
                        cout << set[i] << ", ";
                    }
                }
                cout << set[set.Size() - 1] << " }";
            }
            else {
                out << "{ }";
            }

            return out;
        }
};

int main()
{
    MySet a, b("1"), c("2"), d(b), e(b + c), f(d * e), g(e - b);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;

    cout << boolalpha << (c != b) << endl;

}
