/*
* Name: Alexander Van Maren
* WSUID: J527E389
* HW 7
* main.cpp : Encondes a textfile using Huffman coding
*/

//#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
	int weight;
	char c;
	Node* left;
	Node* right;
	Node (int val, char ch) : weight(val), c(ch), left(nullptr), right(nullptr) {}
	Node(int val) : weight(val), c('\0'), left(nullptr), right(nullptr) {}
};

struct Comparison
{
	bool const operator()(Node* a, Node* b) const { return (*a).weight > (*b).weight; }
};

//enum direction
//{
//	right, left
//};

void encodeFile(string iFile, string oFile, map<char, string> code);
void decodeFile(string iFile, string oFile, map<string, char> code);
void generateEncoding(Node* root, map<char, string>& encoding, string& code);
void constructTree(vector<Node*>& nodes);
void printInOrder(Node* root);
static bool compareNodes(const Node* a, const Node* b);
void readInFrequencies(const string file, map<char, int>& frequencies);


int main()
{
	string const file = "alice.txt";
	string const encodedFile = "enconded.txt";
	string const decodedFile = "decoded.txt";

	map<char, int> charFrequencies;
	vector<Node*> nodes;
	map<char, string> encoding;
	map<string, char> decoding;

	readInFrequencies(file, charFrequencies);

	//for (auto c : charFrequencies)
	//{
	//	cout << c.first << " : " << c.second << endl;
	//}

	// Create the nodes and store them in a vector
	for (auto c : charFrequencies)
	{
		Node* n = new Node(c.second, c.first) ;
		nodes.push_back(n);
	}
	cout << "TOTAL: " << charFrequencies.size() << endl << endl << endl;

	// Sort the vector based on weight
	std::sort(nodes.begin(), nodes.end(), compareNodes);

	constructTree(nodes);

	string code = "";
	generateEncoding(nodes[0], encoding, code);
	// Outputs encoding to a file and copies in reverse for decode
	for (auto c : encoding)
	{		
		cout << c.first << ":" << c.second << endl;
		decoding[c.second] = c.first;
	}
	
	// Outputs decoding to a file
	ofstream outFile("huff.sch");
	if (outFile.is_open())
	{
		for (auto c : decoding)
		{		
			outFile << c.second << ":" << c.first << endl;
		}
	}
	outFile.close();
	
	encodeFile(file, encodedFile, encoding);

	decodeFile(encodedFile, decodedFile, decoding);

	//for (auto n : decoding)
	//{
	//	cout << n.first << " : " << n.second << endl;
	//}
	
}

// Outputs a file using an encoding
void encodeFile(string iFile, string oFile, map<char, string> code)
{
	ifstream inFile(iFile);
	ofstream outFile(oFile);

	if (inFile.is_open())
	{
		char ch;
		while (inFile.get(ch))
		{
			// Takes each character and converts it to the encoding
			outFile << code[ch];
		}
	}

	inFile.close();
	outFile.close();

	return;
}

// Outputs a file using an encoding
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

// Constructs a binary tree from the set of sorted nodes
void constructTree(vector<Node*>& nodes)
{
	// GETTING 22622 for weight, but total chars is different in MSWord
	int sumWeight;
	while (nodes.size() > 1)
	{
		sumWeight = nodes[0]->weight + nodes[1]->weight;
		Node* branch = new Node(sumWeight);
		branch->left = nodes[0];
		branch->right = nodes[1];
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());

		if (nodes.size() == 0)
		{
			nodes.push_back(branch);
			return;
		}
		// Insert at before next highest weight
		bool inserted = false;
		for (vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
		{
			if (branch->weight <= (*it)->weight)
			{
				nodes.insert(it, branch);
				inserted = true;
				break;
			}
		}
		// If the largetst weight, put at end
		if (!inserted)
		{
			nodes.insert(nodes.end(), branch);
		}
	}
}

void generateEncoding(Node* root, map<char,string>& encoding, string& code)
{
	// If null pointer, go back up
	if (root == nullptr)
	{
		return;
	}

	// If has a character, print it and go back up
	if ((*root).c != '\0')
	{
		encoding[(*root).c] = code;
		code.erase(code.end() - 1);
		return;
	}
	// Add 0 since will go left
	code.append("0");
	generateEncoding(root->left, encoding, code);

	// If has a character, print it and go back up
	if ((*root).c != '\0')
	{
		encoding[(*root).c] = code;
		code.erase(code.end() - 1);
		return;
	}
	code.append("1");
	generateEncoding(root->right, encoding, code);

	// Going back up so remove a character
	if (!code.empty())
	{
		code.erase(code.end() - 1);
	}
}

static bool compareNodes(const Node* a, const Node* b)
{
	return (a->weight < b->weight);
}

// Reads in all characters from a text file and counts their number of occurances
void readInFrequencies(const string file, map<char, int>& frequencies)
{
	ifstream inFile(file);

	if (inFile.is_open())
	{
		char ch;
		while (inFile.get(ch))
		{
			// If the character is encountered for the first time
			if (frequencies.find(ch) == frequencies.end())
			{
				frequencies[ch] = 1;
			}
			// If it is a repeat character, increase its count
			else
			{
				frequencies[ch] = frequencies[ch] + 1;
			}
		}
	}

	inFile.close();

	return;
}
