/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW4 main.cpp
 * Description:  Evaluates postfix expressions read in from console.
 */

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

int main()
{
	string input = "x";
	stack<int> operandStack;
	bool spaceExpected = false;
	int result;
	int operand1;
	int operand2;

	cout << "START: (q to quit)" << endl <<
		"Enter your postfix expression: ";
	
	getline(std::cin, input);

	while (input != "q")
	{
		// New input

		spaceExpected = false;

		// Split the input
		for (unsigned int i = 0; i < input.length(); i++)
		{
			// If a space expected, check that it is and move to next character
			if (spaceExpected)
			{
				if (input[i] != ' ')
				{
					std::cerr << "Envalid string";
					exit(1);
				}
			}

			// Number or operand expected
			else
			{
				// Put digits into the stack
				if (isdigit(input[i]))
				{
					operandStack.push(input[i] - '0');
				}

				// If not a digit, then must be an operator,
				else 
				{
					// Check there are 2 operands to be used
					if (operandStack.size() < 2)
					{
						std::cerr << "Invalid string";
						exit(1);
					}

					// Pop the 2 operands
					operand2 = operandStack.top();
					operandStack.pop();
					operand1 = operandStack.top();
					operandStack.pop();

					// Check which operator
					if (input[i] == '+')
					{
						result = operand1 + operand2;
						cout << "+ result: " << result;
					}
					else if (input[i] == '-')
					{
						result = operand1 - operand2;
					}
					else if (input[i] == '*')
					{
						result = operand1 * operand2;
					}
					else if (input[i] == '/')
					{
						// Check for division by 0
						if (operand2 == 0)
						{
							std::cerr << "Division by 0";
							exit(1);
						}

						result = operand1 / operand2;
					}

					// If not one of the above 4, invalid
					else
					{
						std::cerr << "Invalid string";
						exit(1);
					}

					// Push the result to the stack
					operandStack.push(result);
				}	
			}

			// Switches the bool for expecting a space as next character
			spaceExpected = !spaceExpected;
		}

		// done with input
		// Check that there is only 1 number (result) left in the stack
		if (operandStack.size() != 1)
		{
			std::cerr << "Invalid string";
			exit(1);
		}
	
		// Display the final result
		cout << "Final result = " << operandStack.top() << endl << endl;
		operandStack.pop();

		// Ask for new input
		cout << "START: (q to quit)" << endl <<
			"Enter your postfix expression: ";
	
		getline(std::cin, input);
	} 

	return 0;
}
