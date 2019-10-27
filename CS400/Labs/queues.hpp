/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 6
 * Queues.hpp: 3 Implementations of a queue
 */

#ifndef QUEUES_HPP
#define QUEUES_HPP

#include <iostream>
#include <list>
#include <stack>

using std::list;
using std::stack;
using std::cerr;
using std::endl;

// Implementation of a queue using a static array
template <class T>
class ArrayQueue
{
	public:
		ArrayQueue() {tail = 0; head = 0;}
		void enqueue(T item);
		T dequeue();
		bool isFull();
		bool isEmpty();

	private:
		const  static int CAP = 10;
		T arr[CAP];
		int tail;
		int head;
};

// Queue using an STL list
template <class T>
class ListQueue
{
	public:
		ListQueue() {}
		void enqueue(T item);
		T dequeue();
		bool isFull();
		bool isEmpty();

	private:
		list<T> li;
};

// Queue using the STL stack
template <class T>
class StackQueue
{
	public:
		StackQueue() {}
		void enqueue(T item);
		T dequeue();
		bool isFull();
		bool isEmpty();

	private:
		stack<T> inStack;
		stack<T> outStack;
};



// Puts an item in the back of the queue
template <class T>
void ArrayQueue<T>::enqueue(T item)
{
	if (isFull())
	{
		cerr << "Queue is full." << endl;
		return;
	}
	arr[tail] = item;
	tail = (tail + 1) % CAP;
}

// Returns item in front of the queue
template <class T>
T ArrayQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cerr << "Queue is empty" << endl;
		exit(1);
	}
	T item = arr[head];
	head = (head + 1) % CAP;
	return item;
}

// Checks if the queue is full
template <class T>
bool ArrayQueue<T>::isFull()
{
	return (head == (tail + 1) % CAP);
}

// Checks if the queue is empty
template <class T>
bool ArrayQueue<T>::isEmpty()
{
	return (tail == head);
}


// ListQueue's implementation

// Puts an item at the front of the queue
template <class T>
void ListQueue<T>::enqueue(T item)
{
	li.push_back(item);
}

// Returns item in the front of the list
template <class T>
T ListQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cerr << "List empty" << endl;
		exit(1);
	}
	T item = li.front();
	li.pop_front();
	return item;
}

// True if the list is full (never True)
template <class T>
bool ListQueue<T>::isFull()
{
	return false;
}

// Checks if the list is empty
template <class T>
bool ListQueue<T>::isEmpty()
{
	return (li.size == 0);
}


// StackQueue's implementation

// Puts an item at the front of the queue
template <class T>
void StackQueue<T>::enqueue(T item)
{
	inStack.push(item);	
}

// Returns the item at the front of the queue
template <class T>
T StackQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cerr << "Queue empty" << endl;
		exit(1);
	}

	// If the out stack is empty, move the inStack's contents to it
	if (outStack.empty())
	{
		while (!inStack.empty())
		{
			T item = inStack.top();
			outStack.push(item);
			inStack.pop();
		}
	}

	T item = outStack.top();
	outStack.pop();
	return item;
}

// True if the queue is full (never True);
template <class T>
bool StackQueue<T>::isFull()
{
	return false;
}

// Checks if the queue is empty
template <class T>
bool StackQueue<T>::isEmpty()
{
	return (inStack.empty() && outStack.emtpy());
}


#endif
