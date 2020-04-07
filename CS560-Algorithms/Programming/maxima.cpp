/*
* Names: Alexander Van Maren
* WSUID: J527E389
* CS 560: Programming Assignment
* maxima.cpp : Takes in a number of point sets and determines
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const string IN_FILE = "points1";
const string OUT_FILE = "maxout.out";

// Structure for a point read in from file
struct Point
{
	float x;
	float y;
	bool maximal; // True if maximal
	int where; // This point's index

	Point();
	Point(float x, float y, bool max, int w) :
		x(x), y(y), maximal(max), where(w) {}
};

Point** readInPoints(ifstream& inFile);
void printPoints(Point** points);
void mergeSort(Point** arr, int first, int last);
void merge(Point** arr, int first, int mid, int last);

int numPoints = 0;

int main()
{
	ifstream inFile;
	inFile.open(IN_FILE);

	Point** points;
	points = readInPoints(inFile);

	mergeSort(points, 1, numPoints);
	cout << "exit sort" << endl;

	printPoints(points);
	cout << "exit print";

	// clear memory
	inFile.close();
	delete[] points;
	points = nullptr;

	return 0;
}

// Performs merge sort on the points array
void mergeSort(Point** arr, int first, int last)
{
	if (first < last)
	{
		int mid = floor((first + last) / 2);
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

void merge(Point** arr, int first, int mid, int last)
{
	int leftSize = mid - first + 1;
	int rightSize = last - mid;

	Point** leftArr;
	leftArr = new Point*[leftSize];
	Point** rightArr;
	rightArr = new Point*[rightSize];

	for (int i = 0; i < leftSize; i++)
	{
		// just copying addresses!
		leftArr[i] = arr[first + i];
	}
	for (int j = 0; j < rightSize; j++)
	{
		rightArr[j] = arr[mid + j + 1];
	}

	int i = 0;
	int j = 0;
	int k = first;
	//for (k = first; k < last; k++)
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i]->x <= rightArr[j]->x)
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < leftSize)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < rightSize)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}

}

// Reads how many points to read in
// Then reads in that many number of points
// Outputs an array of Point pointers
Point** readInPoints(ifstream& inFile)
{


	// Used to construct Point structs
	string inX;
	string inY;
	bool inMax;
	int inWhere;

	string count;

	// Get number of points    
	if (inFile.is_open())
	{
		getline(inFile, count); // get count of points
		numPoints = stoi(count);
		cout << "numPoints " << numPoints << endl;
	}

	Point** points;
	points = new Point*[(numPoints + 1)]; // Not using index 0 as told by instr

	// Get the points
	if (inFile.is_open())
	{
		char delimeter = ' ';
		string line;

		// getline(inFile, line);
		// //Separate x _ _ _ y
		// inX = line.substr(0, line.find(delimeter));
		// inY = line.substr(line.find(delimeter));
		// points[2] = new Point(stof(inX), stof(inY), false, 2);

		// Read in number of points told to read (1000)
		for (int i = 1; i < (numPoints + 1); i++)
		{
			getline(inFile, line);
			//Separate x _ _ _ y
			inX = line.substr(0, line.find(delimeter));
			inY = line.substr(line.find(delimeter));
			points[i] = new Point(stof(inX), stof(inY), false, i);
		}
	}


	//points[1] = new Point(0,1,true,4);
	//points[1] = new Point(0,2,true,4);
	//points[2] = new Point(0,3,true,4);

	return points;
}


void printPoints(Point** points)
{
	for (int i = 1; i < (numPoints + 1); i++)
	{
		if (points[i] != nullptr)
		{
			cout << points[i]->x << ' ' << points[i]->y << endl;
		}
		else
		{
			cout << "NULL ";
		}
	}
}