/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 2
 * Description: Array list class, .cpp file
 */

#include "ArrayList.hpp"

// Default constructor for the list
template<class T>
ArrayList<T>::ArrayList()
{
	int defaultCap = 8;
	_pa = new T[defaultCap];
	_size = 0;
	_capacity = defaultCap;

	return;
}
// Constructs array list with certain capacity
template<class T>
ArrayList<T>::ArrayList(int capacity)
{
	if (capacity > 0)
	{
		_pa = new T[capacity];
		_size = 0;
		_capacity = capacity;
	}
	else
	{
		ArrayList();
	}

	return;
}
// Copy constructor
template<class T>
ArrayList<T>::ArrayList(const ArrayList& that)
{
	this->_size = that._size;
	this->_capacity = that._capacity;

	this->_pa = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		this->_pa[i] = that._pa[i];
	}

	return;
}
// Assignment operator for copy
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& that)
{
	if (this != &that)
	{
		this->_size = that._size;
		this->_capacity = that._capacity;
		
		T* temp = _pa;
		this->_pa = new T[_capacity];
		for (int i = 0; i < _size; i++)
		{
			this->_pa[i] = that._pa[i];
		}
	}
}
// Destructor
template<class T>
ArrayList<T>::~ArrayList()
{
}
// Adds element to end of list
template<class T>
void ArrayList<T>::push_back(T elem)
{
}
// Removes and returns last element
template<class T>
T ArrayList<T>::pop()
{
}
// Returns element at index
template<class T>
T ArrayList<T>::get(int index)
{
}
// Set an element at the index
template<class T>
void ArrayList<T>::set(int index, T elem)
{
}
// Adds an element to end of list
template<class T>
void ArrayList<T>::add(T elem)
{
}
// Adds element to list at index
template<class T>
void ArrayList<T>::add(int index, T elem)
{
}
// Deletes element at index
template<class T>
void ArrayList<T>::del(int index)
{
}
// Returns the size of the list
template<class T>
int ArrayList<T>::size()
{
}
// Returns the capacity of the list
template<class T>
int ArrayList<T>::capacity()
{
}
// Prints the list
template<class T>
void ArrayList<T>::traverse()
{
}
// Returns true if the size equals the capacity
template<class T>
bool ArrayList<T>::_isFull()
{
}
// Doubles the capacity
template<class T>
void ArrayList<T>::_doubleCapacity()
{
}
