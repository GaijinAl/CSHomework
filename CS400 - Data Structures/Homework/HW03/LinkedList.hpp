/* 
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * LinkedList.hpp
 * Description: Header file for LinkedList
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


typedef int dataType;
struct Node 
{
	dataType data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(dataType value) : data(value), next(nullptr) {}
};

class LinkedList
{
	public:
		// For readability of Node*
		typedef Node* NodePtr;

		// Constructor
		LinkedList();
	
		// Traverses and prints the lsit
		void traverse();
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

		NodePtr head;
};

#endif
