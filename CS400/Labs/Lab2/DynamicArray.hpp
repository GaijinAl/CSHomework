/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 1
 * Description: Header for dynamic array class 
 */

#include <iostream>

class DynamicArray
{
	public:
		// The dynamic array.  Make public so dont need to declare operator[]
		int* array;

		// Default constructor gives size of 10
		DynamicArray()	{size = 10; array = new int[size];}
		// Makes a dynamic array of size s
		DynamicArray(int s)
		{size = s; array = new int[size];}
		// Deep copy constructor
		DynamicArray(const DynamicArray &arr);
		// Copy assignment operator
		void operator=(const DynamicArray &arr);
		// Destructor
		~DynamicArray();

		// Fills array with random numbers
		void fillRandom();
		// Sorts the array using insertion sort
		void sort();
		// Prints the array
		void print();
		// Swaps two elements in the array
		void swap(int index1, int index2);

	private:
		int size;
};

