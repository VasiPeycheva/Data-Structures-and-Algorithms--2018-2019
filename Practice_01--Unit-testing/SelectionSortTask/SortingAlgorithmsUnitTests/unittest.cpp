#include "../SortingAlgorithms/sortingFunctions.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(SelectionSort)
	{
	public:

		TEST_METHOD(BasicTest)
		{
			int expected[] = { 1, 1, 2, 2, 2, 4, 4, 4, 5, 6, 9, 22, 34 };
			int arr[] = { 9, 1, 2, 34, 4, 4, 2, 1, 5, 2, 6, 22, 4 };
			int size = sizeof(arr) / sizeof(int);
			selectionSort(arr, size);
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], arr[i]);
			}
		}
		TEST_METHOD(NullValue)
		{
			int* arr = NULL;
			selectionSort(arr, 0);
			Assert::IsNull(arr);
		}

		TEST_METHOD(NullValueSize)
		{
			int* arr = NULL;
			selectionSort(arr, 10);
			Assert::IsNull(arr);
		}

		TEST_METHOD(SingleElement)
		{
			int arr[] = { 0 };
			selectionSort(arr, 1);
			Assert::AreEqual(0, arr[0]);
		}

		TEST_METHOD(DescendingOrder)
		{
			int expected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			int size = sizeof(arr) / sizeof(int);
			selectionSort(arr, size);
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], arr[i]);
			}
		}
		TEST_METHOD(AscendingOrder)
		{
			int expected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int size = sizeof(arr) / sizeof(int);
			selectionSort(arr, size);
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], arr[i]);
			}
		}

		TEST_METHOD(NegativeElement)
		{
			int expected[] = { -10, -4, -1, -1, 0, 2, 34 };
			int arr[] = { -10, 0, -1, 34, -1, 2, -4 };
			int size = sizeof(arr) / sizeof(int);
			selectionSort(arr, size);
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], arr[i]);
			}
		}
	};
}
