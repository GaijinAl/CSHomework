/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 6
 * main.cpp: Main function for testing of queue classes
 */

#include <iostream>
#include "queues.hpp"

using std::cout;
using std::endl;

int main()
{
	ArrayQueue<int> aQ;
	for (int i = 1; i < 5; i++)
	{
		aQ.enqueue(i);
	}
	cout << aQ.dequeue() << endl;

	ListQueue<int> lQ;
	for (int i = 1; i < 5; i++)
	{
		lQ.enqueue(i);
	}
	cout << lQ.dequeue() << endl;

	StackQueue<int> sQ;
	for (int i = 1; i < 5; i++)
	{
		sQ.enqueue(i);
	}
	cout << sQ.dequeue() << endl;

	return 0;
}
