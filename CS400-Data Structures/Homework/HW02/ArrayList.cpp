/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 2
 * Description: Array list class, .cpp file
 */

#include "Car.hpp"
#include "ArrayList.hpp"
#include <iostream>

using std::cout;
using std::cerr;

// Default constructor for the list
ArrayList::ArrayList()
{
	int defaultCap = 8;
	_pa = new Car[defaultCap];
	_size = 0;
	_capacity = defaultCap;

	return;
}

// Constructs array list with certain capacity
ArrayList::ArrayList(int capacity)
{
	if (capacity < 0)
	{
		capacity = 0;
	}
	if (capacity > 0)
	{
		_pa = new Car[capacity];
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
ArrayList::ArrayList(const ArrayList& that)
{
	this->_size = that._size;
	this->_capacity = that._capacity;

	this->_pa = new Car[_capacity];

	for (int i = 0; i < _size; i++)
	{
		this->_pa[i] = that._pa[i];
	}

	return;
}

// Assignment operator for copy
ArrayList& ArrayList::operator=(const ArrayList& that)
{
	if (this != &that)
	{
		Car* temp = _pa;

		this->_size = that._size;
		this->_capacity = that._capacity;
		this->_pa = new Car[_capacity];

		for (int i = 0; i < _size; i++)
		{
			this->_pa[i] = that._pa[i];
		}

		delete[] temp;
	}

	return *this;
}

// Destructor
ArrayList::~ArrayList()
{
	delete[] _pa;
}

// Adds element to end of list
void ArrayList::push_back(Car elem)
{
	add(elem);
}

// Removes and returns last element
Car ArrayList::pop()
{
	if (_size <= 0)
	{
		cerr << "Fail to exec pop(). ArrayList empty.";
		exit(1);
	}
	else
	{
		_size--;
		return _pa[_size];
	}
}

// Returns element at index
Car ArrayList::get(int index)
{
	if (index >= _size || index < 0)
	{
		cerr << "Fail to exec get(). ArrayList empty.";
		exit(1);
	}
	else
	{
		return _pa[index];
	}
}

// Set an element at the index
void ArrayList::set(int index, Car elem)
{
	if (index >= _size || index < 0)
	{
		cerr << "Fail to exec set().";
		exit(1);
	}
	else
	{
		_pa[index] = elem;
		return;
	}

}

// Adds an element to end of list
void ArrayList::add(Car elem)
{
	if (_isFull())
	{
		_doubleCapacity();
		add(elem);
	}
	else
	{
		_pa[_size] = elem;
		_size++;
		return;
	}
}

// Adds element to list at index
void ArrayList::add(int index, Car elem)
{
	if (index > _size || index < 0)
	{
		cerr << "Fail to exec add().";
		exit(1);
	}

	if (_isFull())
	{
		_doubleCapacity();
		add(index, elem);
	}
	else
	{
		// Case1: Add and shift
		// Case2: Add with no shift
		// Shift 0 or more elements
		for (int i = _size - 1; i >= index; --i)
		{
			_pa[i +1] = _pa[i];
		}
		_pa[index] = elem;
		_size++;

		return;
	}

}

// Deletes element at index
void ArrayList::del(int index)
{
	if (index >= _size || index < 0)
	{
		cerr << "Fail to exec del().";
		exit(1);
	}
	else
	{
		for (int i = index; i < _size; i ++)
		{
			_pa[i] = _pa[i+1];
		}
		_size--;
		
		return;
	}
}

// Returns the size of the list
int ArrayList::size()
{
	return _size;
}
// Returns the capacity of the list
int ArrayList::capacity()
{
	return _capacity;
}
// Prints the list
void ArrayList::traverse()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _pa[i].getId() << ", " << _pa[i].getMake() << ", " << 
			_pa[i].getModel() << ", " << _pa[i].getColor() << std::endl;
	}

	return;
}

// Returns true if the size equals the capacity
bool ArrayList::_isFull()
{
	return (_capacity == _size);
}

// Doubles the capacity
void ArrayList::_doubleCapacity()
{
	Car *temp = new Car[_capacity * 2];

	for (int i = 0; i < _size; i++)
	{
		temp[i] = _pa[i];
	}

	_capacity *= 2;

	delete[] _pa;
	_pa = temp;

	return;	 
}
