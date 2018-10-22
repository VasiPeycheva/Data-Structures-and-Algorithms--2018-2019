#ifndef __DYNAMIC__ARRAY__
#define __DYNAMIC__ARRAY__
#include <iostream>
using namespace std;

template<class TYPE>
class DynamicArray
{
public:
	// Г4
	DynamicArray();
	DynamicArray(int);
	~DynamicArray();
	DynamicArray(const DynamicArray &);
	DynamicArray& operator=(const DynamicArray &);

public:
	void add(const TYPE &);
	bool remove(int);

	int search(const TYPE &);
	void selectionSort();
	void print() const;
	void printBackward() const;
	int getSize() const;

	const TYPE& operator[](int) const;
	TYPE& operator[](int);

private:
	void clean();
	void copy(const DynamicArray<TYPE> &);
	void resize();

	int binarySearch(const TYPE &);
	int linearSearch(const TYPE &);

private:
	TYPE* data;
	int capacity;
	int size;
	bool isSorted;

};

#include "DynamicArrayFunctions.h"

#endif // !__DYNAMIC__ARRAY__
