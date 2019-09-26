/* 
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * LinkedList.hpp
 * Description: Header file for LinkedList
 */

#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

typedef int dataType;

struct Node 
{
	dataType data;
	Node* next;
	Node* prev;
	Node() : data(0), next(nullptr), prev(nullptr) {}
	Node(dataType value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList
{
	public:
		// For readability of Node*
		typedef Node* NodePtr;

		// Constructor
		DoubleLinkedList();
	
		// Traverses and prints the list
		void traverse();
		// Traverses and prints the list in reverse order
		void reverseTraverse();
		// Adds to the head using reference to pointer
		void add_head_1(dataType num);
		// Adds to the head uing a reference to pointer without abstraction of data type
		void add_head_1_5(dataType num);
		// Adds to the end of the list
		void add_tail(dataType num);
		// Searches for a specific element
		Node* search(dataType num);
		// Deletes an element and its node from the list
		void del(dataType num);
		// Sets data value for a given node
		void set(NodePtr& node, int value);
		// Gets the head's address
		Node* getHead();
		// Gets a copy of the tail's address
		Node* getTail();

	private:
		NodePtr head;
		NodePtr tail;
};

#endif
