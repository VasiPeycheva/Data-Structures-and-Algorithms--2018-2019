#include <iostream>

/*
*	function will return the index of the element in the array
*	if the element is not part of the array - will return -1
*/
int binarySearch(int arr[], int size, int element)
{
	int beg = 0;
	int end = size;
	int middle = (beg + end) / 2 ;

	while (beg <= end)
	{
		if (arr[middle] > element) //the element is on the left side of the middle
		{
			end = middle - 1;
			middle = (beg + end) / 2;
		}
		else if (arr[middle] < element) //the element is on the right side of the middle
		{
			beg = middle + 1;
			middle = (beg + end) / 2;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}
