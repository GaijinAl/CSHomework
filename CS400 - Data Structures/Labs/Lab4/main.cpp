/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 4 main.cpp
 * Description: Main function to demonstrate all functions of DoubleLinkedList clas
 */

#include "DoubleLinkedList.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	DoubleLinkedList list;
	
	for (int i = 1; i < 7; i++)
	{
		list.add_head_1(5*i);
	}

	cout << "List: ";
	list.traverse();

	cout << endl << "List (reversed): ";
	list.reverseTraverse();
	cout << endl;

	list.add_head_1(-1);
	cout << "Add_head_1(-1): ";
	list.traverse();
	cout << endl;

	list.add_tail(-2);
	cout << "Add_tail(-2): ";
	list.traverse();
	cout << endl;

	Node* found = list.search(15);
	cout << "list.search(15)->data: " << found->data << endl;

	list.del(20);
	cout << "list.del(20)): ";
	list.traverse();
	cout << endl;
	
	return 0;
}
