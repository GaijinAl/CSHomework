/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW 5
 * main.cpp: Solves the n-queen problem
 */

#include <iostream>

using std::cout;
using std::endl;

// Tries all of the permutation using backtracing
void enumerate(int arr[], int size, int row);
// Prints a permutation
void printPermutation(int arr[], int n);
// Checks if a permutation is valid
bool isConsistent(int arr[], int n);

// Count the total number of valid permutations found so far
// This can not go in the other functions due to recursion
int permutationCount = 0;

int main ()
{
	const int N = 5;
	int arr[5];

	enumerate(arr, N, 0);

	return 0;
}

// Tries all the permutations using backtracing
void enumerate(int arr[], int size, int currentRow)
{
	// If have reached the last index(row), then it is a valid permuation, so print
	if (currentRow == size)
	{
		printPermutation(arr, 5);
	}
	else
	{
		// Goes up each row, tries to place a new number and checks if valid
		for (int i = 1; i < size + 1; i++)
		{
			arr[currentRow] = i;

			// If valid, go to next row(index)
			if (isConsistent(arr, currentRow))
			{
				enumerate(arr, size, currentRow + 1);
			}
		}
	}
}

// Prints a permutation
void printPermutation(int arr[], int n)
{
	// Increase number of found valid permutations
	permutationCount++; 

	cout << "P#" << permutationCount;
	for (int i = 0; i < n; i++)
	{
		cout << ' ' << arr[i];
	}

	cout << endl;

	return;
}

// Checks if a single placement of a number(at position n) is valid
bool isConsistent(int arr[], int n)
{
	// Check if there are any other instances of that number(n) in the array
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[n])
		{
			return false;
		}
	}

	// If no conflicts found, valid
	return true;
}
