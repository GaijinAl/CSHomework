/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 2
 * Description: Menu interface for the car ArrayList and data file
 */

#include "Car.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::vector;

// Reads in car data from a text file and puts it into a vector
void readData(vector<Car>& list, string file);
// Writes car data from a vector to a text file
void writeData(vector<Car>& list, string file);
// Prints the main menu
void printMenu();
// Searches for a car based on a user entered ID
int searchId(vector<Car>& list);
// Searches for a car based on a user entered make
int searchMake(vector<Car>& list);
// Searches for a car based on a user entered model
int searchModel(vector<Car>& list);
// Searches for a car based on a user entered color
int searchColor(vector<Car>& list);
// Asks for a user to enter fields for a new car and adds it to the vector
void addNewCar(vector<Car>& list);
// Asks user for an valid car ID, and deletes it from the vector
void deleteCar(vector<Car>& list);
// Prints a car's fields
void printCar(Car c);
// Prints out cars in a vector
void traverse(vector<Car> list);

int main()
{
	string file = "cars.data";	
	vector<Car> carList;

	// Reads in car data from file and puts in ArrayList
	readData(carList, file);	

	string strInput;
	int input = 0;

	int foundIndex = -1; // NOTE TO GRADER:  Told to return int for search function by Dr. Lu, but there is no use for it, so there is a warning.

	while (input != -1)
	{
		foundIndex = -1;
		printMenu();
		//Get the input
		getline(std::cin, strInput);
		try
		{
			input = std::stoi(strInput);
		}
		catch(...)
		{
			std::cerr << "Invalid input. Please try again.\n";
		}

		cout << endl;

		// Make choice based on valid input
		switch (input)
		{
			case 1:
				foundIndex = searchId(carList);
				cout << endl;
				break;
			case 2:
				foundIndex = searchMake(carList);
				cout << endl;
				break;
			case 3:
				foundIndex = searchModel(carList);
				cout << endl;
				break;
			case 4:
				foundIndex = searchColor(carList);
				cout << endl;
				break;
			case 5:
				addNewCar(carList);
				cout << endl;
				break;
			case 6:
				deleteCar(carList);
				break;
			case 7:
				traverse(carList);
				cout << endl;
				break;
		}
	}

	// Save the cars in the ArrayList to the data file upon exit
	writeData(carList, file);

	return 0;
}

// Reads in the data from a file and puts in to an ArrayList
void readData(vector<Car>& list, string file)
{
	std::ifstream inFile;
	inFile.open(file);
	if (inFile.is_open())
	{
		// Temporary values read in to create Car objects
		string line;
		string tempId;
		int id;
		string make;
		string model;
		string color;

		// Read in all cars, fileds seperated by commas
		while (getline(inFile, line))
		{
			stringstream lineStream(line);
			getline(lineStream, tempId, ',');
			id = stoi(tempId);
			getline(lineStream, make, ',');
			getline(lineStream, model, ',');
			getline(lineStream, color, ',');

			Car newCar(id, make, model, color);
			list.push_back(newCar);
		}
	}
	// Exit if file cant open
	else
	{
		cout << "Unable to open file";
		exit(1);
	}

	// Close the textfile
	inFile.close();

	return;

}

// Writes the car ArrayList data to a text file
void writeData(vector<Car>& list, string file)
{
	std::ofstream outFile;
	outFile.open(file);

	if (outFile.is_open())
	{
		// For loop for number of cars in list
		// Delimit  cars by commas
		for (int i = 0; i < list.size(); i++)
		{
			outFile << list[i].getId() << ',' << list[i].getMake() 
				<< ',' << list[i].getModel() << ','
				<< list[i].getColor() << '\n';
		}
	}
	// Abort if unable to open file
	else
	{
		cout << "Unable to open file";
		exit(1);
	}
	outFile.close();

	return;
}

// Prints the main menu
void printMenu()
{
	cout << "1. Search ID" << endl
		<< "2. Search Make" << endl
		<< "3. Search Model" << endl
		<< "4. Search Color" << endl
		<< "5. Add New Car" << endl
		<< "6. Delete Car" << endl
		<< "7. List All Cars" << endl
		<< "-1. EXIT" << endl
		<< "Select Operation: ";

}

// Searches for a car by ID and prints it to the screen
int searchId(vector<Car>& list)
{
	Car c ;
	string strInput;
	int input;
	bool found = false;
	int index;

	cout << "Enter ID: ";
	getline(std::cin, strInput);
	// Checks if input valid
	try
	{
		input = std::stoi(strInput);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	}

	// Searches based on Id entered
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getId() == input)
		{
 			c = list[i];
			printCar(c);			
			found = true;
			index = i;
		}
	}

	// If no car found
	if(!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return index;
}

// Searches for a car by make and prints it to the screen
int searchMake(vector<Car>& list)
{
	Car c ;
	string strInput;
	bool found = false;
	int index;

	cout << "Enter make: ";
	getline(std::cin, strInput);

	// Searches based on make entered
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getMake() == strInput)
		{
 			c = list[i];			
			printCar(c);
			found = true;
			index = i;
		}
	}

	// If no car found
	if (!found)	
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return index;
}

// Searches for a car by model and prints it to the screen
int searchModel(vector<Car>& list)
{
	Car c ;
	string strInput;
	bool found = false;
	int index;

	cout << "Enter model: ";
	getline(std::cin, strInput);
	

	// Searches based on the model entered
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getModel() == strInput)
		{
 			c = list[i];			
			printCar(c);
			found = true;
			index = i;
		}
	}

	// If no car found
	if (!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return index;
}

// Searches for a car by model and prints it to the screen
int searchColor(vector<Car>& list)
{
	Car c ;
	string strInput;
	bool found = false;
	int index;

	cout << "Enter color: ";
	getline(std::cin, strInput);

	// Searches based on the color entered
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getColor() == strInput)
		{
 			c = list[i];			
			printCar(c);
			found = true;
			index = i;
		}
	}

	// If no car found
	if (!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}
	return index;
}

// Adds a new car to the ArrayList
void addNewCar(vector<Car>& list)
{
	string strId;
	int id;
	string make;
	string model;
	string color;

	cout << "Enter ID: ";	
	getline(std::cin, strId);
	// Checks if valid integer
	try
	{
		id = std::stoi(strId);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	}

	// Asks user to enter the remaining fields
	cout << "Enter make: ";
	getline(std::cin, make);

	cout << "Enter model: ";
	getline(std::cin, model);

	cout << "Enter color: ";
	getline(std::cin, color);

	// Creates the car and adds it to the ArrayList
	Car newCar(id, make, model, color);
	list.push_back(newCar);

	return;
}

// Deletes a car from the list by asking for an ID from the user
void deleteCar(vector<Car>& list)
{
	string strId;
	int id;
	bool found = false;

	cout << "Enter the ID of the car to delete: ";
	//Get the ID
	getline(std::cin, strId);
	// Checks if the input is a valid integer
	try
	{
		id = std::stoi(strId);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	
	}

	// Searches for a car based on the ID
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getId() == id)
		{
			// If found, delete it
			list.erase(list.begin() + i);		
			return;	
		}
	}

	// If no car found
	if(!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}
	return;
}

// Prints a car object's characteristics
void printCar(Car c)
{
	cout << c.getId() << ", " << c.getMake() << ", " << 
		c.getModel() << ", " << c.getColor() << endl;

}

void traverse(vector<Car> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i].getId() << ", " << list[i].getMake() << ", " << 
			list[i].getModel() << ", " << list[i].getColor() << std::endl;
	}

	return;
}
