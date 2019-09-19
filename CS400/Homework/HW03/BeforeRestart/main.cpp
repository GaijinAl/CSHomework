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

using std::string;

// HAVE RIGHT ANSWER NOW JUST POP FROM BACK AND PRINT

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
		int sum = 0;

		getline(inFile, line);
		for (auto c : line)
		{
			//std::string singleNumStr(1, c);
			//currentNum = std::stoi(singleNumStr);
			currentNum = c - '0';
			if (currentNum >= 0 && currentNum <= 9)
			{
				list.add_head_1(currentNum);
			}
		}
		list.traverse();
		std::cout << std::endl << std::endl;

		for (int i = 0; i < 10; i++)
		{
			list.add_tail(0);
		}

		//int count = 1;
		Node* currNode;
		while (getline(inFile, line)) // This gives same ans if put getline inside loop
		{
//		for (int j = 0; j < 3; j++)
//			getline(inFile, line);
			line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
			currNode = list.head;
			for (int i = line.size() - 1; i >= 0; i--)
			{				
				currentNum = line[i] - '0';
				if (currentNum >= 0 && currentNum <= 9)
				{
					// Currently adding 1's place with left (largest #)
					//std::cout << "data: " << currNode->data << "cur " << currentNum << "carry " << carry << std::endl; 
					sum = currNode->data + currentNum + carry;
					carry = 0;
					//std::cout << sum << ' ';
					currNode->data = sum % 10;
					carry = sum / 10;
					currNode = currNode->next;
				}
//				else
//				{
//					currNode->data += carry;
//				}
				sum = 0;
			}

			while (carry != 0)
			{
				currNode->data += carry;
				carry = currNode->data / 10;
				currNode->data = currNode->data % 10;
				currNode = currNode->next;
			}


//			std::cout << std::endl << "Result:" ;
//			list.traverse();
//			std::cout << std::endl << std::endl;
			//std::cout << std::endl << std::endl;

			//count++;
			//std::stringstream lineStream(line);
			//std::cout << line << std::endl;


			//currentNum = stoi(line);
			//std::cout << currentNum << std::endl;
			//
			list.traverse();
			std::cout << std::endl;
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

