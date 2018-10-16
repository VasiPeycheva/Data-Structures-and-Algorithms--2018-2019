//simple example how to use the benchmark library

#include <math.h>

/*
basic : 
in your application just include the header and
call "benchmark_test_fnc" with parameter the function
you want to test
*/

/*
advanced :
there are three more parameters : 
 1) first is a time formatter - one from                       ( F_MICRO, F_MILLI, F_SEC, F_MIN, F_ALL )
	using this parameter the time will be formatted as follow : microseconds, milliseconds, seconds, minutes, all formated
	[default] : F_MICRO
	
 2) second is a name - just a string for easier output understanding
	fnc_name_to_str - could be used to create a string from function's name
	[default] : "" empty string, so nothing will be outputted
	
 3) output stream - could be each from C++ out streams
    [default] : std::cout 
*/
#include "benchmark.hpp"



void fillArr(int arr[],int n)
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

bool linearSearch(int arr[], int n, int element)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == element)
			return true;
		else
			return false;
	}
}

bool binarySearch(int arr[], int n, int element)
{
	int beg = 0;
	int end = n;
	int middle = (beg + end) / 2;

	while (beg <= end)
	{
		if (arr[middle] > element)
		{
			end = middle - 1;
			middle = (beg + end) / 2;
		}
		else if (arr[middle] < element)
		{
			beg = middle + 1;
			middle = (beg + end) / 2;
		}
		else
		{
			return true;
		}
	}

	return false;

}

void linearTest()
{
	unsigned n = 90000000;
	int* arr = new int[n];
	int searchElement = 1;
	fillArr(arr, n);
	linearSearch(arr, n, searchElement);
	delete[] arr;
}

void binaryTest()
{
	unsigned n = 90000000;
	int* arr = new int[n];
	int searchElement = 1;
	fillArr(arr, n);
	binarySearch(arr, n, searchElement);
	delete[] arr;
}

int main() {
	
	benchmark_test_fnc(linearTest, T_FORMAT::F_MICRO, fnc_name_to_str(linearTest));
	benchmark_test_fnc(binaryTest, T_FORMAT::F_MICRO, fnc_name_to_str(binaryTest));

	return 0;
}
