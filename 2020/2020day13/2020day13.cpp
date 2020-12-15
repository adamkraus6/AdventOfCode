#include "../../max.h"
#include <iostream>
#include <fstream>

using namespace std;

int solveFirstDeparture(vector<int> IDs, int timestamp);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if(!fin.is_open()) exit(0);

	string line;
	int timestamp, firstDepart;

	getline(fin, line);
	timestamp = stoi(line);

	getline(fin, line);
	vector<string> buses = split(line, ',');

	fin.close();

	vector<int> busIDs;
	for (int i = 0; i < (int)buses.size(); i++)
	{
		if (buses[i] != "x")
		{
			busIDs.push_back(stoi(buses[i]));
		}
	}

	cout << "Product of minute wait and Bus ID for first departure" << endl << solveFirstDeparture(busIDs, timestamp) << endl;
}

int solveFirstDeparture(vector<int> IDs, int timestamp)
{
	int firstDepart = ceil(timestamp / IDs[0] + 1) * (double)IDs[0], busID = IDs[0];

	for (int i = 1; i < (int)IDs.size(); i++)
	{
		int timeDepart = ceil(timestamp / IDs[i] + 1) * (double)IDs[i];
		
		if (timeDepart < firstDepart)
		{
			firstDepart = timeDepart;
			busID = IDs[i];
		}
	}

	return (firstDepart - timestamp) * busID;
}

/*
Part 2 Answer: 530015546283687 (NOT FROM MY SOLUTION)
https://github.com/zv0n/advent_of_code_2020/blob/master/13/main.cpp
Look into Chinese Remainder Theorem
*/