#include "StudentsTable.h"

const int GRADE = 8;
const int AGE = 64;

int compareByName(const Student &lhs, const Student &rhs)
{
	return stricmp(lhs.name.c_str(), rhs.name.c_str());
}

int compareBySubject(const Student &lhs, const Student &rhs)
{
	return stricmp(lhs.subject.c_str(), rhs.subject.c_str());
}

int compareByDate(const Student &lhs, const Student & rhs)
{
	return stricmp(lhs.date.c_str(), rhs.date.c_str());
}

StudentsTable::StudentsTable(const string & fileName)
{
	ifstream in(fileName);
	Student check;
	while (!in.eof())
	{
		in >> check;
		if (in.eof())
			break;
		if(validateData(check))
			table.add(check);
	}
	in.close();

	tableSize = table.getSize();
}

void StudentsTable::sortBy(const string& criterion,const string & order)
{
	if (stricmp(criterion.c_str(), "grade") == 0)
	{
		sortByGrade();
	}
	else if (stricmp(criterion.c_str(), "age") == 0)
	{
		sortByAge();
	}
	else if (stricmp(criterion.c_str(), "name") == 0)
	{
		HeapSort(compareByName);
	}
	else if (stricmp(criterion.c_str(), "subject") == 0)
	{
		HeapSort(compareBySubject);
	}
	else if (stricmp(criterion.c_str(), "date") == 0)
	{
		HeapSort(compareByDate);
	}
	else
	{
		cout << "invalid criterion \n";
	}

	// if we want to print the table in descending order 
	// we simply print the table from the end to the beginning
	if (stricmp(order.c_str(), "asc") == 0)
		table.print();
	else
		table.printBackward();
}

bool StudentsTable::validateData(const Student & check) const
{
	if (check.grade < 2 || check.grade > 6)
		return false;
	if (check.age < 18)
		return false;

	return true;
}

/*
* To sort by age we use counting sort - unstable, linear time, don`t use comparisons
*/
void StudentsTable::sortByAge()
{
	DynamicArray<Student> modify = table;

	unsigned int countingArr[AGE] = { 0, };

	//count all students age
	for (size_t i = 0; i < tableSize; i++)
	{
		countingArr[modify[i].age]++;
	}

	//correct index in the new array
	for (size_t i = 1; i < AGE; i++)
	{
		countingArr[i] += countingArr[i - 1];
	}

	//built sorted array
	int index = 0;
	for (size_t i = 0; i < tableSize; i++)
	{
		index = countingArr[modify[i].age] - 1;
		countingArr[modify[i].age] --;
		table[index] = modify[i];
	}
}

/*
* To sort by grade we use counting sort
*/
void StudentsTable::sortByGrade()
{
	DynamicArray<Student> modify = table;

	unsigned int countingArr[GRADE] = { 0, };

	//count all students grade
	for (size_t i = 0; i < tableSize; i++)
	{
		countingArr[modify[i].grade]++;
	}

	//correct index in the new array
	for (size_t i = 1; i < GRADE; i++)
	{
		countingArr[i] += countingArr[i - 1];
	}

	//built sorted array
	int index = 0;
	for (size_t i = 0; i < tableSize; i++)
	{
		index = countingArr[modify[i].grade] - 1;
		countingArr[modify[i].grade] --;
		table[index] = modify[i];
	}
}

/* 
*  Heap Sort can sort different field of Student, thanks to the comparator
*  O(nlong), in-place
*/
void  StudentsTable::siftDown(int size, int parent,const comparator & function)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if ((child + 1) < size) // has 2 children
		{
			if (function(table[child],table[child + 1]) < 0)
				child++;
		}
		if (function(table[parent],table[child]) < 0)
		{
			swap(table[parent], table[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void StudentsTable::HeapSort(const comparator & function)
{
	//built max Heap
	int start = (tableSize / 2);
	for (int i = start; i >= 0; i--)
	{
		siftDown(tableSize, i, function);
	}

	//Sorting
	for (size_t i = tableSize - 1; i > 0; i--)
	{
		swap(table[0], table[i]);
		siftDown(i, 0,function);
	}
}
