/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW3 Node.cpp
 * Description: Node struct, which is basis for LinkedList
 */

#ifndef NODE_HPP
#define NODE_HPP

struct Node 
{
	dataType data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(dataType value) : data(value), next(nullptr) {}
};

#endif
