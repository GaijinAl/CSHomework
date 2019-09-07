/*
 * Name: Alexander Van Maren
 * WSUID: J5227E389
 * Lab 2
 * Description: An array list class, header file
 */

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

class ArrayList
{
	public:
		// Default constructor
	       	ArrayList();
		// Constructs array list with certain capacity
		ArrayList(int capacity);
		// Copy constructor
		ArrayList(const ArrayList& that);
		// Assignment operator for copy
		ArrayList& operator=(const ArrayList& that);
		// Destructor
		~ArrayList();

		// Interface
		
		// Adds element to end of list
		void push_back(int elem);
		// Removes and returns last element
		int pop();
		// Returns element at index
		int get(int index);
		// Set an element at the index
		void set(int index, int elem);
		// Adds an element to end of list
		void add(int elem);
		// Adds element to list at index
		void add(int index, int elem);
		// Deletes element at index
		void del(int index);
		// Returns the size of the list
		int size();
		// Returns the capacity of the list
		int capacity();
		// Prints the list
		void traverse();

	private:
		int* _pa; // Pointer to the actual list
		int _size; // Size of the array list
		int _capacity; // Capacity of the array list

		bool _isFull(); // Returns true if size == capacity
		void _doubleCapacity(); // Doubles the capacity
};

#endif
