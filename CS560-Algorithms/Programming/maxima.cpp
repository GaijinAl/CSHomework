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
//const string OUT_FILE = "maxout.out";

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
void findMaxima(Point** arr);
void printMaxima(Point** arr);
void printPoint(Point* pt);
void printResults(Point** points);
void printFinalStats();

int numPoints;
int sortCount[10] = {0};
int maxNumA; // Number of elements in maxima
int maxCountA[10] = {0}; // Number of key comparisons in findMaxima
int pointSetNum = 0;


int main()
{
	ifstream inFile;
	inFile.open(IN_FILE);

	while (!inFile.eof())
	{
		numPoints = 0;
		maxNumA = 0;

		Point **points;
		points = readInPoints(inFile);

		mergeSort(points, 1, numPoints);
		findMaxima(points);
		printResults(points);

		// end for
		pointSetNum++;

		// clear memory
		delete[] points;
		points = nullptr;
	}
	inFile.close();

	printFinalStats();

	return 0;
}

// Prints the final statistics for all of the point sets
void printFinalStats()
{
	cout << "Statistics for the 10 iterations:" << endl << endl
		<< "Iter SortCt  MaxCtA SortCt+MaxCtA" << endl
		<< string(50, '-') << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "  " << i << "   " << sortCount[i] << "    " << maxCountA[i] << 
		string(7, ' ') << (sortCount[i] + maxCountA[i]) << endl;
	}
}

// Prints the results for a point set
void printResults(Point** points)
{
	cout << "Output for the " << pointSetNum << "-th Set of Points" << endl
		<< string(33, '=') << endl << endl
		<< "Input Size = " << numPoints << endl
		<< "sortCount = " << sortCount[pointSetNum] << endl
		<< "maxCountA = " << maxCountA[pointSetNum] << endl
		<< "maxNumA = " << maxNumA << endl << endl
		<< "Maxima(S): (where: x, y)" << endl
		<< string(27, '-') << endl;
	
	printMaxima(points);

	cout << endl << string(41, '=') << endl << endl;
}

// Finds all the maxima in a list of Ponits, sorted in descending order based on x-value
void findMaxima(Point** arr)
{
	// Add point with largest x value as maxima
	float currentMaxY = arr[numPoints]->y;
	arr[numPoints]->maximal = true;
	maxNumA++;

	for (int i = numPoints - 1; i > 0; i--)
	{
		if (arr[i]->y > currentMaxY)
		{
			currentMaxY = arr[i]->y;
			arr[i]->maximal = true;
			maxNumA++;
		}
		maxCountA[pointSetNum]++;
	}
}

// Prints out the maxima in the Point list
void printMaxima(Point** arr)
{
	for (int i = 1; i < (numPoints + 1); i++)
	{
		if (arr[i]->maximal)
		{
			cout << arr[i]->where << ":  (" << arr[i]->x << ", " 
				<< arr[i]->y << ')' << endl;
		}
	}
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

// Merge helper function of mergeSort function
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
		sortCount[pointSetNum]++;
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

	string count;

	// Get number of points    
	if (inFile.is_open())
	{
		getline(inFile, count); // get count of points
		numPoints = stoi(count);
	}

	Point** points;
	points = new Point*[(numPoints + 1)]; // Not using index 0 as told by instr

	// Get the points
	if (inFile.is_open())
	{
		char delimeter = ' ';
		string line;

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

	return points;
}

// Prints a list of points
void printPoints(Point** points)
{
	cout << "x\t\ty\t\tmaximal\t\twhere" << endl;
	for (int i = 1; i < (numPoints + 1); i++)
	{
		printPoint(points[i]);
	}
}

// Prints a single point
void printPoint(Point* pt)
{
	if (pt != nullptr)
	{
		cout << pt->x << '\t' << pt->y << '\t'
			 << pt->maximal << '\t' << pt->where << endl;
	}
	else
	{
		cout << "NULL ";
	}
}