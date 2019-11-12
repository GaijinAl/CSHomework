/*
 * Name: Alexander Van Maren
 * Description: Main for DynamicArray class
 */

#include <iostream>
#include "DynamicArray.hpp"

using std::cout;
using std::endl;
int main()
{
	cout << "Begin main" << endl << endl;

	DynamicArray arr1;
	cout << "Array1: ";
	arr1.fillRandom();
	arr1.print();
	cout << endl;
	arr1.sort();
	cout << "Sorted: ";
	arr1.print();
	cout << endl;

	DynamicArray arr2(8);
	arr2.fillRandom();
	cout << "Array2: ";
	arr2.print();
	cout << endl;
	arr2.sort();
	cout << "Sorted: ";
	arr2.print();
	cout << endl;

	cout << "Copy constructor" << endl;
	DynamicArray arr3(arr2);
	arr3.print();
	cout << endl;

	cout << "Operator: arr4 = arr1" << endl;
	DynamicArray arr4;
	arr4 = arr1;
	arr4.print();
	cout << endl;

	return 0;
}
