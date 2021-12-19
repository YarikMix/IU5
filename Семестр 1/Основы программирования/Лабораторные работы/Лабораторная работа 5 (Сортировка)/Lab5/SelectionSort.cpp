#include "SelectionSort.h"
#include <iostream>
using namespace std;

void SelectionSortMax(int arr[], int size, int & compCount, int & swapCount, bool bymax)
{
	compCount = swapCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;

		for (int j = i + 1; j < size; j++)
		{
			compCount++;

			
			if (!bymax)
			{
				if (arr[j] > arr[k])
					k = j;
			}
			else
			{
				if (arr[j] < arr[k])
					k = j;
			}

		}

		if (k != i) {
			swapCount++;
			swap(arr[i], arr[k]);
		}
	}
}

void SelectionSortMin(int arr[], int size, int & compCount, int & swapCount, bool bymax)
{
	compCount = swapCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;

		for (int j = i + 1; j < size; j++)
		{
			compCount++;

			if (bymax)
			{
				if (arr[j] < arr[k])
					k = j;
			}
			else
			{
				if (arr[j] > arr[k])
					k = j;
			}

		}

		if (k != i) {
			swapCount++;
			swap(arr[i], arr[k]);
		}
	}
}
