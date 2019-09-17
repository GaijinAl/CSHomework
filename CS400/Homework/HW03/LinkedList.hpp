/* 
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * LinkedList.hpp
 * Description: Header file for LinkedList
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList
{
	// For readability of Node*
	typedef Node* NodePtr;

	// Traverses and prints the lsit
	void traverse(Node* head);
	// Adds to the head using reference to pointer
	void add_head_1(NodePtr& head, dataType num);
	// Adds to the head uing a reference to pointer without abstraction of data type
	void add_head_1_5(Node*& head, dataType num);
	// Adds to the head using pointer to pointer
	void add_head_2(Node** head, dataType num);
	// Adds to the end of the list
	void add_tail(NodePtr& head, dataType num);
	// Searches for a specific element
	Node* search(NodePtr& head, dataType num);
	// Deletes an element and its node from the list
	void del(NodePtr& head, dataType num);
};

#endif
