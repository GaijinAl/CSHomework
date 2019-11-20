/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW08
 * main.cpp: Reads in a coding scheme that is used to decode a textfile.
 */

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void decodeFile(string iFile, string oFile, map<string,char> code);
void readEncoding(const string encodingFile, map<string,char>& code);


int main()
{
	const string encodingFile = "huff.sch";
	const string encodedFile = "alice.huff";
	const string decodedFile = "alice_decoded.txt";

	map<string,char> code;

	// Reads in the encoding
	readEncoding(encodingFile, code); 

	// To be used for presentation
//	for (auto c : code)
//	{
//		cout << c.first << " : " << c.second << endl;
//	}

	// Decodes the file to a new one
	decodeFile(encodedFile, decodedFile, code);

	return 0;
}

// Reads in the Huffman coding scheme from a textfile.
void readEncoding(const string encodingFile, map<string,char>& code)
{
	ifstream inFile(encodingFile);
	
	// Open check
	if (inFile.is_open())
	{
		string delimiter = ":";
		string line;
		string huffCode;
		char ch;

		// Get each line
		while (getline(inFile, line))
		{
			// Dont truncate the newline since it is part of the code
			line += '\n';
			// Finds position of ':' and takes string before that as code
			huffCode = line.substr(0, line.find(delimiter));
			// Character is 1 after the delimiter
			ch = line[line.find(delimiter) + 1];

			
			code[huffCode] = ch;
		}
	}
	inFile.close();
}

// Outputs a file using an encoding stored in the map
void decodeFile(string iFile, string oFile, map<string,char> code)
{
	ifstream inFile(iFile);
	ofstream outFile(oFile);

	if (inFile.is_open())
	{
		string segment;
		char ch;
		while (inFile.get(ch))
		{
			string chAsStr(1, ch);
			segment.append(chAsStr);

			// Checks if the current string is an encoded string
			if (!(code.find(segment) == code.end()))
			{
				// Match found, so decode it
				outFile << code[segment];
				segment.clear();
			}
		}
	}

	inFile.close();
	outFile.close();

	return;
}
