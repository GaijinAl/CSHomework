/* 
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * LinkedList.cpp
 * Descrition: Implementation of LinkedList class
 */

#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
	Node* temp = new Node();
	head = temp;
}

// Traverses and prints the lsit
void LinkedList::traverse()
{
	for (Node* tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->next)
	{
		std::cout << tempPtr->data << ' ';
	}
}

// Adds to the head using reference to pointer
void LinkedList::add_head_1(dataType num)
{
	Node* temp = new Node(num);
	temp->next = head;
	head = temp;
}
// Adds to the head uing a reference to pointer without abstraction of data type
void LinkedList::add_head_1_5(dataType num)
{
	Node* temp = new Node(num);
	temp->next = head;
	head = temp;
}

//// Adds to the head using pointer to pointer
//void LinkedList::add_head_2(dataType num)
//{
//	Node* temp = new Node(num);
//	temp->next = *head;
//	*head = temp;
//}

// Adds to the end of the list
void LinkedList::add_tail(dataType num)
{
	if (head == nullptr)
	{
		add_head_1(num);
		return;
	}

	// Now loop until the last node
	NodePtr curr = head;
	while (curr->next != nullptr)
	{
		curr = curr->next;
	}

	Node* temp = new Node(num);
	curr->next = temp;
	
	return;
}
// Searches for a specific element
Node* LinkedList::search(dataType num)
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
void LinkedList::del(dataType num)
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
void LinkedList::search(NodePtr& node, int value)
{
	node->data = value;

	return;
}
