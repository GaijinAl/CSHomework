// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * Lab5
 * main.cpp:  Converts infix expressions to postfix expressions
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>

using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::stack;

vector<string> split(const string& str, char delimiter);
bool isNumber(const string& str);

int main()
{
	string input;
	vector<string> tokens;
	stack<string> operatorStack;
	//	string result;

	cout << "Enter an infix string ('q' to quit): ";
	getline(std::cin, input);

	while (input != "q")
	{
		//		cout << "ENTER WHILE" << endl;
		tokens = split(input, ' ');
		for (int i = 0; i < tokens.size(); i++)
		{
			cout << tokens[i] << ' ';
		}
		cout << endl << endl;

		for (int i = 0; i < tokens.size(); i++)
		{
			// If number, print it
			if (isNumber(tokens[i]))
			{
				cout << tokens[i] << ' ';
			}

			// Else, must be an operator
			else
			{
				if (tokens[i] == ")")
				{
					while (!operatorStack.empty() && operatorStack.top() != "(")
					{
						cout << operatorStack.top() << ' ';
						operatorStack.pop();
					}

					// Get rid of the '('
					operatorStack.pop();
				}

				if (tokens[i] == "+" || tokens[i] == "-")
				{
					// Pop all other operators of equal or higher precedence

					while (!operatorStack.empty() && (operatorStack.top() == "*"
						|| operatorStack.top() == "/"
						|| operatorStack.top() == "+"
						|| operatorStack.top() == "-"))
					{
						cout << operatorStack.top() << ' ';
						operatorStack.pop();
					}

					operatorStack.push(tokens[i]);
				}

				else if (tokens[i] == "*" || tokens[i] == "/")
				{
					// Pop all operators of equal precedence
					while (!operatorStack.empty() &&
						(operatorStack.top() == "*" || operatorStack.top() == "/"))
					{
						cout << operatorStack.top() << ' ';
						operatorStack.pop();
					}

					operatorStack.push(tokens[i]);
				}

				// Lowest precedence operator, so always push
				else if (tokens[i] == "(")
				{
					operatorStack.push(tokens[i]);
				}

				// Invalid character
				else
				{
					//std::cerr << "invalid expression." << endl;
					//exit(1);
				}
			}
		}

		// If stack not empty, dump the operators (cout)
		while (!operatorStack.empty())
		{
			cout << operatorStack.top() << ' ';
			operatorStack.pop();
		}

		cout << "Enter an infix expression: ";
		getline(std::cin, input);
	}

	return 0;
}

// Splits a string into tokens, held in a vector
vector<string> split(const string& str, char delimiter)
{
	vector<string> tokens;
	string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delimiter))
	{
		//cout << token;
		tokens.push_back(token);
	}

	return tokens;
}

// Determines if a string is a number
bool isNumber(const string& str)
{
	return !str.empty()
		&& std::find_if(str.begin(), str.end(), [](char c)
	{ return !std::isdigit(c); }) == str.end();
}
