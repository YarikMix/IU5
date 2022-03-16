// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stack>
#include "stack.h"
using namespace std;

int nod(int &n){
	int d=2;
	while(n%d!=0){
		d++;
	}
	n /= d;
	return d;
}

void main(){
	
	setlocale(0,"russian");
	stack<int> adiv;
	stack<int> ddiv;
	int n;
	cout << "Введите число для разложения: ";
	cin >> n;

	while(n!=1){
	adiv.push(nod(n));
	}

	cout << "Количество множителей: " << adiv.size() << endl;
	cout << "* ";
	while (!adiv.empty()) {
       cout << adiv.top() << " * ";
	   ddiv.push(adiv.top());
       adiv.pop();
	}
	cout <<endl << "* ";

	while(!ddiv.empty()){
		cout << ddiv.top() << " * ";
		ddiv.pop();
	}

	myStack dzstack;
	myStack dzstack2;
	n = 0;
	cout << endl <<"Попробуйте еще раз: ";
	cin >> n;

	while(n!=1)
	{
		dzstack.push(nod(n));
	}
	
	int d=0;
	cout << "* ";
	while( dzstack.pop(d))
	{
		dzstack2.push(d);
		cout << d <<" * ";
	}
	
	cout << endl << "* ";

	while( dzstack2.pop(d))
	{
		cout << d <<" * ";
	}
	
	cout << endl;
	system("pause");
}

