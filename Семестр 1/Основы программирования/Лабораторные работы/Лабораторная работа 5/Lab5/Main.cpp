#include <iostream>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "Utils.h"
#include "Randomizer.h"
using namespace std;

void test(int size, bool bymax)
{
	h2("Массив размером ", size);
	int* arr = CreateArray(size);
	cout << "Исходный массив - ";
	printArray(arr, size);
	cout << endl;

	int compCount; // число сравнений
	int swapCount; // число перестановок
	int SSminComp, SSmaxComp, BSComp;
	int SSminSwap, SSmaxSwap, BSSwap;
	int* aCopy1;
	int* aCopy2;
	int* aCopy3;

	aCopy1 = CopyArray(arr, size);
	SelectionSortMax(aCopy1, size, compCount, swapCount, bymax);
	SSminComp = compCount;
	SSminSwap = swapCount;

	aCopy2 = CopyArray(arr, size);
	SelectionSortMin(aCopy2, size, compCount, swapCount, bymax);
	SSmaxComp = compCount;
	SSmaxSwap = swapCount;

	aCopy3 = CopyArray(arr, size);
	BubbleSort(aCopy3, size, compCount, swapCount, bymax);
	BSComp = compCount;
	BSSwap = swapCount;

	printString(" ");
	printString("Сравнений");
	printString("Перестановок");
	printString("Массив");
	cout << "\n";
	printString("Выбор по минимуму");
	printNumber(SSminComp);
	printNumber(SSminSwap);
	printArray(aCopy1, size);
	cout << "\n";
	printString("Выбор по максимуму");
	printNumber(SSmaxComp);
	printNumber(SSmaxSwap);
	printArray(aCopy2, size);
	cout << "\n";
	printString("Метод пузырька");
	printNumber(BSComp);
	printNumber(BSSwap);
	printArray(aCopy3, size);

	cout << "\n\n";

	cout << "Отсортированный массив - ";
	printArray(aCopy3, size);
	cout << "\n\n";
	arr = CopyArray(aCopy3, size);

	aCopy1 = CopyArray(arr, size);
	SelectionSortMax(aCopy1, size, compCount, swapCount, bymax);
	SSminComp = compCount;
	SSminSwap = swapCount;

	aCopy2 = CopyArray(arr, size);
	SelectionSortMin(aCopy2, size, compCount, swapCount, bymax);
	SSmaxComp = compCount;
	SSmaxSwap = swapCount;

	aCopy3 = CopyArray(arr, size);
	BubbleSort(aCopy3, size, compCount, swapCount, bymax);
	BSComp = compCount;
	BSSwap = swapCount;

	printString(" ");
	printString("Сравнений");
	printString("Перестановок");
	printString("Массив");
	cout << "\n";
	printString("Выбор по минимуму");
	printNumber(SSminComp);
	printNumber(SSminSwap);
	printArray(aCopy1, size);
	cout << "\n";
	printString("Выбор по максимуму");
	printNumber(SSmaxComp);
	printNumber(SSmaxSwap);
	printArray(aCopy2, size);
	cout << "\n";
	printString("Метод пузырька");
	printNumber(BSComp);
	printNumber(BSSwap);
	printArray(aCopy3, size);

	cout << "\n\n";

	cout << "Отсортированный массив - ";
	printArray(aCopy3, size);
	cout << "\n\n";
	arr = CopyArray(aCopy3, size);

	aCopy1 = CopyArray(arr, size);
	SelectionSortMax(aCopy1, size, compCount, swapCount, !bymax);
	SSminComp = compCount;
	SSminSwap = swapCount;

	aCopy2 = CopyArray(arr, size);
	SelectionSortMin(aCopy2, size, compCount, swapCount, !bymax);
	SSmaxComp = compCount;
	SSmaxSwap = swapCount;

	aCopy3 = CopyArray(arr, size);
	BubbleSort(aCopy3, size, compCount, swapCount, !bymax);
	BSComp = compCount;
	BSSwap = swapCount;

	printString(" ");
	printString("Сравнений");
	printString("Перестановок");
	printString("Массив");
	cout << "\n";
	printString("Выбор по минимуму");
	printNumber(SSminComp);
	printNumber(SSminSwap);
	printArray(aCopy1, size);
	cout << "\n";
	printString("Выбор по максимуму");
	printNumber(SSmaxComp);
	printNumber(SSmaxSwap);
	printArray(aCopy2, size);
	cout << "\n";
	printString("Метод пузырька");
	printNumber(BSComp);
	printNumber(BSSwap);
	printArray(aCopy3, size);

	cout << "\n\n";
	delete[] aCopy1, aCopy2, aCopy3;
}

int main()
{
	system("chcp 1251 > nul");
	Randomize();

	h1("Сортировка по возрастанию");

	test(5, true);
	test(100, true);
	test(1000, true);

	h1("Сортировка по убыванию");

	test(5, false);
	test(100, false);
	test(1000, false);
}
