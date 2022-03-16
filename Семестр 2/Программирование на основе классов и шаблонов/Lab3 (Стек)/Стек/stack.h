class myElem{
public:
	int Info;
	myElem * Next;

	//constructors
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

void myStack::push(int info){
	myElem* temp = new myElem(info);
	temp->Next = Current;
	Current = temp;
}

bool myStack::pop(int& info ){
	if ( Current == NULL)
		return false;
	info = Current->Info;
	myElem* temp = Current->Next;
	delete Current;
	Current = temp;
	return true;
}



