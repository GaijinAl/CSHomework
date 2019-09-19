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

using std::string;


// DO HIS STUPID IMPLEMENTATION OF ALL IN 1 FILE!!!!
//
//
//
//
//
//
//
//
//
//
//

int main()
{
	string file = "nums.txt";

	// Init a LinkedList
	LinkedList list;
	//list.del(0);

	// Read in the data
	std::ifstream inFile;
	inFile.open(file);
	if (inFile.is_open())
	{
		int currentNum;
		string tempNumStr;
		string line;
		int inListNum;
		int carry = 0;
		int sum;

		getline(inFile, line);
		for (char& c : line)
		{
			//std::string singleNumStr(1, c);
			//currentNum = std::stoi(singleNumStr);
			currentNum = c - '0';
			if (currentNum >= 0 && currentNum <= 9)
			{
				list.add_head_1(currentNum);
			}
		}
		for (int i = 0; i < 10; i++)
		{
			list.add_head_1(0);
		}

		int count = 1;
		Node* currNode;
		while (getline(inFile, line))
		{
			currNode = list.head;
			for (char& c: line)
			{
				
				currentNum = c - '0';
				if (currentNum >= 0 && currentNum <= 9)
				{
					sum = currNode->data + currentNum + carry;
					currNode->data = sum % 10;
					carry = sum / 10;
					currNode = currNode->next;
				}
			}

			//count++;
			//std::stringstream lineStream(line);
			//std::cout << line << std::endl;


			//currentNum = stoi(line);
			//std::cout << currentNum << std::endl;
		}
	}
	else
	{
		std::cerr << "File can not open" << std::endl;
		exit(1);
	}

	// Closes the file
	inFile.close();

	list.traverse();

	return 0;
}
