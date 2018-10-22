#pragma once
#include "DynamicArray.h"

/// Reverse the given dynamic array
/// @param[in] Elements The input array.
/// @return Reversed DynamicArray of Elements 
template <typename Type> 
DynamicArray<Type> reverse(const DynamicArray<Type>& Elements)
{
	DynamicArray<Type> Result;
	for (int i = Elements.getSize(); i > 0; i--)
	{
		Result.add(Elements[i-1]);
	}
	return Result;
}

/// Appends the second array to the first one.
/// @param[in] First The first of input arrays.
/// @param[in] Second The second of input arrays.
/// @return DynamicArray which is merged from input arrays.
template <typename Type>
DynamicArray<Type> merge(const DynamicArray<Type>& First, const DynamicArray<Type>& Second)
{
	DynamicArray<Type> Result;
	for (int i = 0; i < First.getSize(); i++)
	{
		Result.add(First[i]);
	}
	for (int i = 0; i < Second.getSize(); i++)
	{
		Result.add(Second[i]);
	}
	return Result;
}

/// Checks if the first of the arrays contains the second one.
/// @param[in] First The first of input arrays, it must be sorted.
/// @param[in] Second The second of input arrays,	it must be sorted.
/// @return True if second set is a subset of the first array.
template <typename Type>
bool includes(const DynamicArray<Type>& First, const DynamicArray<Type>& Second)
{
	for (int FirstIt = 0, SecondIt = 0; SecondIt < Second.getSize(); FirstIt++)
	{
		if ((FirstIt == First.getSize()) || First[FirstIt] > Second[SecondIt])
		{
			return false;
		}

		if (First[FirstIt] <= Second[SecondIt])
		{
			SecondIt++;
		}
	}
	return true;
}

/// Filters the given array by some condition.
/// @param[in] First The first of input arrays.
/// @param[in] Func The condition, it must take one argument and returns boolean.
/// @return DynamicArray which every element satisfies the condition.
template <typename Type, typename Functor>
DynamicArray<Type> filter(const DynamicArray<Type>& Elements, Functor Func)
{
	DynamicArray<Type> Result;
	for (int i = 0; i < Elements.getSize(); i++)
	{
		if (Func(Elements[i]))
		{
			Result.add(Elements[i]);
		}
	}
	return Result;
}

/// Applies to every element given function.
/// @param[in] First The first of input arrays.
/// @param[in] Func The function which will be applied over the elements,
/// it must take one argument and returns same type of object.
/// @return DynamicArray which have elements of the given array with applied function.
template <typename Type, typename Functor>
DynamicArray<Type> for_each(const DynamicArray<Type>& Elements, Functor Func)
{
	DynamicArray<Type> Result;
	for (int i = 0; i < Elements.getSize(); i++)
	{
		Result.add(Func(Elements[i]));
	}
	return Result;
}
