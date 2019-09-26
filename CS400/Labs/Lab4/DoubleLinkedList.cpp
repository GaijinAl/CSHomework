/* 
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * LinkedList.cpp
 * Descrition: Implementation of LinkedList class
 */

#include "DoubleLinkedList.hpp"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	Node* temp = new Node();
	head = temp;
	tail = temp;
}

// Traverses and prints the lsit
void DoubleLinkedList::traverse()
{
	for (Node* tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->next)
	{
		std::cout << tempPtr->data << ' ';
	}
}

// Traverses and prints the lsit in reverse
void DoubleLinkedList::reverseTraverse()
{
	for (Node* tempPtr = tail; tempPtr != nullptr; tempPtr = tempPtr->prev)
	{
		std::cout << tempPtr->data << ' ';
	}
}

// Adds to the head using reference to pointer
void DoubleLinkedList::add_head_1(dataType num)
{
	Node* temp = new Node(num);
	temp->next = head;
	head->prev = temp;
	head = temp;
}
// Adds to the head uing a reference to pointer without abstraction of data type
void DoubleLinkedList::add_head_1_5(dataType num)
{
	Node* temp = new Node(num);
	temp->next = head;
	head->prev = temp;
	head = temp;
}

// Adds to the end of the list
void DoubleLinkedList::add_tail(dataType num)
{
	if (head == nullptr)
	{
		add_head_1(num);
		return;
	}

	// Add to the tail
	Node* temp = new Node(num);
	temp->prev = tail;
	tail->next = temp;
	temp = tail;
		
	return;
}
// Searches for a specific element
Node* DoubleLinkedList::search(dataType num)
{
	NodePtr curr = head;

	while (curr->data != num && curr != nullptr)
	{
		curr = curr->next;
	}

	// Now either end of list or found
	// If end of list
	if (curr == nullptr)
	{
		return nullptr;
	}
	else
	{
		return curr;
	}


}
// Deletes an element and its node from the list
void DoubleLinkedList::del(dataType num)
{
	// Case1: List is empty
	if (head->next == nullptr)
	{
		std::cerr << "Linked List empty";
		return;
	}

	// Case2: head node is the node being searched for
	if (head->data == num)
	{
		NodePtr temp = head;
		head = head->next;
		delete temp;
		return;
	}

	// Case3: Node in middle or last
	NodePtr prev = nullptr;
	NodePtr curr = head;
	while (curr != nullptr && curr->data != num)
	{
		prev = curr;
		curr = curr->next;
	}

	// Now either reached end of list (nurr == nullptr) or found the result
	// If no match
	if (curr == nullptr)
	{
		return;
	}

	// Match found
	else
	{
		prev->next = curr->next;
		delete curr;
		return;
	}
}

// Sets the data of a given node to value
void DoubleLinkedList::set(NodePtr& node, int value)
{
	node->data = value;

	return;
}

// Gets a copy of the head's address
Node* DoubleLinkedList::getHead()
{
	return head;
}

// Gets a copy of the tail's address
Node* DoubleLinkedList::getTail()
{
	return tail;
}
