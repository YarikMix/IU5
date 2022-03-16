#include <cstddef>

class myElem {
	public:
		int Info;
		myElem* Next;

		myElem() :Next(NULL), Info(0) {}
		myElem(int info) :Next(NULL), Info(info) {}
};


class myStack
{
	private:
		myElem* Current;
		int n;
	public:
		myStack() {
			Current = NULL;
		}
		inline ~myStack();
		inline void push(int info);
		inline bool pop(int& info);
		inline bool empty(int info);
		inline int size() { return n; };
};

myStack::~myStack() {
	while (Current) {
		myElem* temp = Current->Next;
		delete Current;
		Current = temp;
		n--;
	}
}

void myStack::push(int info) {
	myElem* temp = new myElem(info);
	temp->Next = Current;
	Current = temp;
	n++;
}

bool myStack::pop(int& info) {
	if (Current == NULL)
		return false;
	info = Current->Info;
	myElem* temp = Current->Next;
	delete Current;
	Current = temp;
	n++;
	return true;
}

bool myStack::empty(int info) {
	return Current == NULL ? true : false;
}