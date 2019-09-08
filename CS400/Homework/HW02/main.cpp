/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab 2
 * Description: Menu interface for the car ArrayList and data file
 */

#include "Car.hpp"
#include "ArrayList.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstddef>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

void readData(ArrayList& list, string file);
void writeData(ArrayList& list, string file);
void printMenu();
void searchId(ArrayList& list);
void searchMake(ArrayList& list);
void searchModel(ArrayList& list);
void searchColor(ArrayList& list);
void addNewCar(ArrayList& list);
void deleteCar(ArrayList & list);
void printCar(Car c);


int main()
{
	string file = "cars.data";
	
	ArrayList carList;

	readData(carList, file);	

	string strInput;
	int input = 0;

	while (input != -1)
	{
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

		switch (input)
		{
			case 1:
				searchId(carList);
				cout << endl;
				break;
			case 2:
				searchMake(carList);
				cout << endl;
				break;
			case 3:
				searchModel(carList);
				cout << endl;
				break;
			case 4:
				searchColor(carList);
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
				carList.traverse();
				cout << endl;
				break;
		}
	}

	// Save the cars in the ArrayList to the data file upon exit
	writeData(carList, file);

	return 0;
}

void readData(ArrayList& list, string file)
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
	else
	{
		cout << "Unable to open file";
		exit(1);
	}

	// Close the textfile
	inFile.close();

	return;

}

void writeData(ArrayList& list, string file)
{
	std::ofstream outFile;
	outFile.open(file);

	if (outFile.is_open())
	{
		// For loop for number of cars in list
		for (int i = 0; i < list.size(); i++)
		{
			outFile << list.get(i).getId() << ',' << list.get(i).getMake() 
				<< ',' << list.get(i).getModel() << ','
				<< list.get(i).getColor() << '\n';
		}
	}
	else
	{
		cout << "Unable to open file";
		exit(1);
	}
	outFile.close();
}

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

// FOR ALL OF THESE DO TRY AND THROW if not found!
// Or should I return a pointer?  
void searchId(ArrayList& list)
{
	Car c ;
	string strInput;
	int input;
	bool found = false;

	cout << "Enter ID: ";
	getline(std::cin, strInput);
	try
	{
		input = std::stoi(strInput);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	}

	for (int i = 0; i < list.size(); i++)
	{
		if (list.get(i).getId() == input)
		{
 			c = list.get(i);
			printCar(c);			
			found = true;
		}
	}

	if(!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return;
}
void searchMake(ArrayList& list)
{
	Car c ;
	string strInput;
	bool found = false;

	cout << "Enter make: ";
	getline(std::cin, strInput);

	for (int i = 0; i < list.size(); i++)
	{
		if (list.get(i).getMake() == strInput)
		{
 			c = list.get(i);			
			printCar(c);
			found = true;
		}
	}

	if (!found)	
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return;
}
void searchModel(ArrayList& list)
{
	Car c ;
	string strInput;
	bool found = false;

	cout << "Enter model: ";
	getline(std::cin, strInput);
	
	for (int i = 0; i < list.size(); i++)
	{
		if (list.get(i).getModel() == strInput)
		{
 			c = list.get(i);			
			printCar(c);
			found = true;
		}
	}

	if (!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}

	return;
}
void searchColor(ArrayList& list)
{
	Car c ;
	string strInput;
	bool found = false;

	cout << "Enter color: ";
	getline(std::cin, strInput);

	for (int i = 0; i < list.size(); i++)
	{
		if (list.get(i).getColor() == strInput)
		{
 			c = list.get(i);			
			printCar(c);
			found = true;
		}
	}

	if (!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}
	return;
}
void addNewCar(ArrayList& list)
{
	string strId;
	int id;
	string make;
	string model;
	string color;

	cout << "Enter ID: ";	
	getline(std::cin, strId);
	try
	{
		id = std::stoi(strId);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	}

	cout << "Enter make: ";
	getline(std::cin, make);

	cout << "Enter model: ";
	getline(std::cin, model);

	cout << "Enter color: ";
	getline(std::cin, color);

	Car newCar(id, make, model, color);
	list.push_back(newCar);

	return;
}

void deleteCar(ArrayList& list)
{
	string strId;
	int id;
	bool found = false;

	cout << "Enter the ID of the car to delete: ";
	//Get the ID
	getline(std::cin, strId);
	try
	{
		id = std::stoi(strId);
	}
	catch(...)
	{
		std::cerr << "Invalid input. Please try again.\n";
	
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (list.get(i).getId() == id)
		{
			list.del(i);		
			return;	
		}
	}

	if(!found)
	{
		cout << "Not found. Returning to main menu" << endl << endl;
	}
	return;
}

void printCar(Car c)
{
	cout << c.getId() << ", " << c.getMake() << ", " << 
		c.getModel() << ", " << c.getColor() << endl;

}
