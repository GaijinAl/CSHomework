/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 2
 * Description: Main function, demonstrates all functions for the ArrayList class
 */

#include "ArrayList.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	ArrayList list1;
	for (int i = 0; i < 7; i++)
	{
		list1.add(i*5);
	}
	cout << "List1, Default constructed: ";
	list1.traverse();
	cout << endl;

	ArrayList list2(3);
	for (int i = 0; i < 10; i++)
	{
		list2.add(i*11);
	}
	cout << "List2, Size of 3 passed and constructed: ";
	list2.traverse();
	cout << endl;

	list1.push_back(100);
	cout << "list1.Push_back(100): ";
	list1.traverse();
	cout << endl;

	
	cout << "list1.get(3): ";
	cout << list1.get(3);
	cout << endl;

	list1.set(1, 7);
	cout << "list1.set(1,7): ";
	list1.traverse();
	cout << endl;

	list1.add(69);
	cout << "list1.add(69): ";
	list1.traverse();
	cout << endl;
	
	list1.add(0, -2);
	cout << "list1.add(0,-2): ";
	list1.traverse();
	cout << endl;
	
	list1.del(0);
	cout << "list1.del(0): ";
	list1.traverse();
	cout << endl;

	cout << "list1.size(): ";
	cout << list1.size();
	cout << endl;
	
	cout << "list1.capacity(): ";
	cout << list1.capacity();
	cout << endl;

	ArrayList list3(list1);
	cout << "Copy constructor, list3(list1)" << endl  << "list3: ";
	list3.traverse();
	cout << endl;

	list3 = list2;
	cout << "list3 = list2: ";
	list3.traverse();
	cout << endl;


	return 0;
}
