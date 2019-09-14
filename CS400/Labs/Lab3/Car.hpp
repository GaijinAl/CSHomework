/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW 2
 * Description: Car class header file
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <iostream>

using std::string;

class Car
{
	public:
		// Default constructor
		Car() {};
		// Specified constructor
		Car(int id, string make, string model, string color)
		{_id = id; _make = make; _model = model; _color = color;}
		int getId()
		{return _id;}
		string getMake()
		{return _make;}
		string getModel()
		{return _model;}
		string getColor()
		{return _color;}

	private:
		int _id;
		string _make;
		string _model;
		string _color;
};

#endif
