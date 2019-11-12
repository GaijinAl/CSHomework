/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW3 Node.cpp
 * Description: Node struct, which is basis for LinkedList
 */

#ifndef NODE_HPP
#define NODE_HPP

#include "MyTypes.hpp"

struct Node 
{
	//typedef int dataType;

	dataType data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(dataType value) : data(value), next(nullptr) {}
};

#endif
