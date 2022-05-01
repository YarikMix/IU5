#include <cstddef>

class Elem {
	public:
		int Info;
		Elem* Next;

		Elem() :Next(NULL), Info(0) {}
		Elem(int info) :Next(NULL), Info(info) {}
};


class Stack
{
	private:
		Elem* Current;
		int n;
	public:
		Stack() {
			Current = NULL;
		}
		inline ~Stack();
		inline void push(int info);
		inline bool pop(int& info);
		inline bool empty(int info);
		inline int size();
};

Stack::~Stack() {
	while (Current) {
		Elem* temp = Current->Next;
		delete Current;
		Current = temp;
		n--;
	}
}

void Stack::push(int info) {
	Elem* temp = new Elem(info);
	temp->Next = Current;
	Current = temp;
	n++;
}

bool Stack::pop(int& info) {
	if (Current == NULL)
		return false;
	info = Current->Info;
	Elem* temp = Current->Next;
	delete Current;
	Current = temp;
	n++;
	return true;
}

bool Stack::empty(int info) {
	return Current == NULL;
}

int Stack::size() {
	return  n;
}