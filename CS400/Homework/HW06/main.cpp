/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * main.cpp
 * Description: 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>


using namespace std;


class Process
{
	public:
		Process() {}
		Process(int i, int aTime, int timeNeed)
			: id(i), arrival_time(aTime), time_needed(timeNeed), finished_time(-1) {}
		int id;
		int arrival_time;
		int time_needed;
		int finished_time;

	private:
};

// Reads in the data from a file and puts in to an ArrayList
void readData(vector<Process>& vec, string file)
{
	std::ifstream inFile;
	inFile.open(file);
	if (inFile.is_open())
	{
		string line;
		// Temporary values read in to create Car objects
		string idStr;
		int id;
		string arrivalStr;
		int arrival;
		string needStr;
		int need;

		// Read in all cars, fileds seperated by commas
		while (getline(inFile, line))
		{
			stringstream lineStream(line);
			getline(lineStream, idStr, ' ');
			id = stoi(idStr);
			getline(lineStream, arrivalStr, ' ');
			arrival = stoi(arrivalStr);
			getline(lineStream, needStr, ' ');
			need = stoi(needStr);
			// cout << idStr << arrivalStr << needStr << endl;
			// cout << id << arrival << need << endl;
			Process p(id, arrival, need);
			// cout << "ID" << p.id << endl;
			vec.push_back(p);
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

// Returns true if all processess are finished
bool allProcessesFinished(vector<Process>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].finished_time < 0)
		{
			return false;
		}
	}

	// If all have a valid finish time, return true
	return true;
}

int main()
{
	vector<Process> processes;
	vector<Process> finishedP;
	// Reads in the data and puts the processes in a vector
	readData(processes, "round_robin.txt");

	int const QUANTUM = 4;
	int relativeQuant = 0;
	queue<Process> processQ;
	int time = 0;

	while (!allProcessesFinished(processes))
	{
		// While current process not finished and quantum not finished
		while (relativeQuant < QUANTUM && processQ.front().finished_time > 0)
		{
			// Check for new process arrival, if one arrives, queue it
			for (int i = 0; i < processes.size(); i++)
			{
				cout << i << '\t';
				if (processes[i].arrival_time == time)
				{
					processQ.push(processes[i]);
					cout << "push " << processes[i].id << "@t= " << time << endl;
				}
			}
			cout << "EXIT FOR ";

			// Decreaste the time needed
			processQ.front().time_needed--;

			// Check if the process is done
			if (processQ.front().time_needed < 1)
			{
				processQ.front().finished_time = time;
			}
			
			// Increase the time
			time++;
			relativeQuant++;
			cout << relativeQuant;
		}

		// Finished quantum or process finished

		// If finished, remove it from the queue
		if (processQ.front().finished_time > 0)
		{
			finishedP.insert(finishedP.begin(), processQ.front());
			processQ.pop();
		}
		// Still not done, so put in back of queue
		else
		{
			processQ.push(processQ.front());
			processQ.pop();
		}

		// Reset the quantum timer
		relativeQuant = 0;
	}

	// All processes finished
		

	return 0;
}
