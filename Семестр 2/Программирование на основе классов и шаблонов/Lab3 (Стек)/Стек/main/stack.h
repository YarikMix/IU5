class myElem{
public:
	int Info;
	myElem * Next;

	myElem():Next( NULL ), Info (0){}
	myElem(int info):Next( NULL ), Info (info){}
};

class myStack
{
private:
	myElem* Current; 
public:
	myStack(){
		Current = NULL;
	}
	~myStack();
	void push(int info);
	bool pop(int&info);
};

	myStack::~myStack(){
	while(Current){
		myElem* temp = Current->Next;
		delete Current;
		Current = temp;
	}
	}

void myStack::push(int info){ //При записи в стек (операция PUSH) в начало списка добавляется узел 
	myElem* temp = new myElem(info);
	temp->Next = Current;
	Current = temp;
}

bool myStack::pop(int& info ){ //при выборке из стека (операция POP) узел удаляется из начала списка
	if ( Current == NULL)
		return false;
	info = Current->Info;
	myElem* temp = Current->Next;
	delete Current;
	Current = temp;
	return true;
}