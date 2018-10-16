#include "sortingFunctions.h"

void swap(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int arr[], int n)
{
	//if the array is empty we have nothing to sort
	//this way we are protected from null and n > 0
	if (!arr)
		return;

	int minElement;
	int minIndex;

	for (int i = 0; i < n - 1; i++)
	{
		minElement = arr[i];
		minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (minElement > arr[j])
			{
				minElement = arr[j];
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}

