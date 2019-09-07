/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 1
 * Description: Implementation of DynamicArray class
 */

#include "DynamicArray.hpp"
#include <iostream>
#include <random>

using std::cout;

// Copy constructor for the class
DynamicArray::DynamicArray(const DynamicArray &arr)
{
	size = arr.size;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = arr.array[i];
	}
	return;
}

// Copy assignment operator
void DynamicArray::operator=(const DynamicArray &arr)
{
	this->size = arr.size;
	for (int i = 0; i < size; i++)
	{
		this->array[i] = arr.array[i];
	}
	return;
}
// Destructor
DynamicArray::~DynamicArray()
{
	delete []array;
	array = nullptr;
}

// Fills array with random numbers
void DynamicArray::fillRandom()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(-100, 100);

	for (int i = 0; i < size; i++)
	{
		array[i] = dist(mt);
	}

	return;	
}
// Sorts the array using insertion sort
void DynamicArray::sort()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; (j > 0) && (array[j] < array[j-1]); j--)
		{
			swap(j, (j-1));
		}
	}
	return;
}
// Prints the array
void DynamicArray::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	return;
}

// Swaps two elements in the array
void DynamicArray::swap(int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
	return;
}
