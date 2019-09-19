/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW3 main.cpp
 * Description: Main function for solving Project Euler Q13 using LinedList
 */

#include "LinkedList.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

void addEulerFromFile(string file, LinkedList& list);
void printResult(LinkedList& list);

int main()
{
	string file = "nums.txt";

	// Init a LinkedList
	LinkedList list;

	// Performs addition and stores in the linked list
	addEulerFromFile(file, list);

	// Print linked list and first 10 digits
	printResult(list);

	return 0;
}

// Reads in the numbers from a file, sums them and stores them in reverse order inside the linked list
void addEulerFromFile(string file, LinkedList& list)
{	
	// Read in the data
	std::ifstream inFile;
	inFile.open(file);
	if (inFile.is_open())
	{
		
		int currentNum; // Current read in number
		string tempNumStr; // Temporary number holder
		string line; // A single line read in from the text file
		int carry = 0; // Used to carry 10s place digit
		int sum = 0; // Sum of 2 numbers and carry from previous operation

		// Gets the first line and puts in linked list in reverse
		getline(inFile, line);
		for (auto c : line)
		{
			currentNum = c - '0';
			if (currentNum >= 0 && currentNum <= 9)
			{
				list.add_head_1(currentNum);
			}
		}

		// Adds a sufficient number of zeros for the sum to extend 
		for (int i = 0; i < 1; i++)
		{
			list.add_tail(0);
		}

		// Current node
		Node* currNode;
		// read in all lines
		while (getline(inFile, line))
		{
			// Erase the '\n' at the end of the line
			line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
			// Make the current the first node
			currNode = list.head;
			// Break up the string into individual digits and sum
			for (int i = line.size() - 1; i >= 0; i--)
			{			
				// Converts the character into an int	
				currentNum = line[i] - '0';
				// To make sure no whitespace was converted into an integer
				if (currentNum >= 0 && currentNum <= 9)
				{
					// Calculates the sum
					sum = currNode->data + currentNum + carry;
					// Carry was ued from previous operation already, so reset
					carry = 0;
					// Take the 1s place and set the current node's data to it
					currNode->data = sum % 10;
					// Calculate if there was a 10s place digit for the carry
					carry = sum / 10;
					// Go to the next node
					currNode = currNode->next;
				}
				// Reset the sum
				sum = 0;
			}

			// If number extends by 1 or more digits, ensure the number extends
			while (carry != 0)
			{
				// Perform same operations from above for the new leading digits
				currNode->data += carry;
				carry = currNode->data / 10;
				currNode->data = currNode->data % 10;
				currNode = currNode->next;
			}
		}
	}
	
	// If file not able to be opened, quit
	else
	{
		std::cerr << "File can not open" << std::endl;
		exit(1);
	}

	// Closes the file
	inFile.close();

	return;
}

// Prints the final result stored in the linked list, then prints the first 10 digits of the number
void printResult(LinkedList& list)
{
	// Prints out the linked list holding sum in reverse order
	std::cout << "Final sum in reverse order: " << std::endl;	
	list.traverse();

	// Used to hold the sum in forward order
	vector<int> sumForward;
	Node* head = list.head;
	// Stores the sum in forward order in the vector
	for (Node* tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->next)
	{
		sumForward.insert(sumForward.begin(), tempPtr->data);
	}

	std::cout << std::endl;
	std::cout << "First 10 digits of the sum: ";

	// Prints the first 10 numers of the sum result
	for (int i = 0; i < 10; i++)
	{
		std::cout << sumForward[i];
	}
	std::cout << std::endl;

	return;
}
