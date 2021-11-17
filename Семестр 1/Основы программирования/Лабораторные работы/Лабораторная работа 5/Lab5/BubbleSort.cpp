#include "BubbleSort.h"
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size, int& compCount, int& swapCount, bool bymax)
{
	compCount = swapCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = true;

		for (int j = 0; j < size - i - 1; j++)
		{
			compCount++;

			if (bymax)
			{
				if (arr[j] > arr[j + 1])
				{
					flag = false;
					swapCount++;
					swap(arr[j], arr[j + 1]);
				}
			}
			else
			{
				if (arr[j] < arr[j + 1])
				{
					flag = false;
					swapCount++;
					swap(arr[j], arr[j + 1]);
				}
			}

		}

		if (flag) 
			break;
	}
}