#include "CppUnitTest.h"
#include "../binarySearch/binarySearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace binarySearchUnitTest
{		
	TEST_CLASS(BinarySearch)
	{
	public:
		TEST_METHOD(FirstElement)
		{
			int arr[] = { 0,1,2,2,3,8,9,10 };
			int size = sizeof(arr) / sizeof(int);
			//be careful where you put expected and actual values
			Assert::AreEqual(0, binarySearch(arr, size, 0));
		}
		TEST_METHOD(LastElement)
		{
			int arr[] = { 0,1,2,2,3,8,9,10 };
			int size = sizeof(arr) / sizeof(int);
			Assert::AreEqual(7, binarySearch(arr, size, 10));
		}
		TEST_METHOD(NotValid)
		{
			int arr[] = { 0,1,2,2,3,8,9,10 };
			int size = sizeof(arr) / sizeof(int);
			Assert::AreEqual(-1, binarySearch(arr, size, -2));
		}
		TEST_METHOD(NegativeElement)
		{
			int arr[] = { -9,-8,-1,0,2,2,3,8,9,10 };
			int size = sizeof(arr) / sizeof(int);
			Assert::AreEqual(2, binarySearch(arr, size, -1));
		}

	};
}