#include "../../max.h"
#include <iostream>
#include <fstream>

using namespace std;

void highLowID(vector<string> partitions, int& high, int& low);
int findEmptySeat(vector<string> partitions);

int rows = 128, cols = 8;

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);
	
	int highestID = 0, lowestID = rows * cols;
	vector<string> partitions;
	string line;

	while (getline(fin, line))
	{
		partitions.push_back(line);
	}

	fin.close();

	highLowID(partitions, highestID, lowestID);

	cout << "Highest Seat ID" << endl << highestID << endl;

	cout << "Empty Seat ID" << endl << findEmptySeat(partitions) << endl;
}

void highLowID(vector<string> partitions, int& highest, int& lowest)
{
	for (int i = 0; i < (int)partitions.size(); i++)
	{
		string key = partitions[i];
		string row = key.substr(0, 7), col = key.substr(7, 3);
		int r, c, id, min, max, mid;

		// find row
		min = 0, max = rows - 1;
		for (int j = 0; j < 6; j++)
		{
			mid = (min + max) / 2;

			if (row.at(j) == 'F')
			{
				max = mid;
			}
			else {
				min = mid + 1;
			}
		}
		r = (row.at(6) == 'F') ? min : max;

		// find col
		min = 0, max = cols - 1;
		for (int j = 0; j < 2; j++)
		{
			mid = (min + max) / 2;

			if (col.at(j) == 'L')
			{
				max = mid;
			}
			else {
				min = mid + 1;
			}
		}
		c = (col.at(2) == 'L') ? min : max;

		id = r * 8 + c;
		if (id > highest)
		{
			highest = id;
		}
		if (id < lowest)
		{
			lowest = id;
		}
	}
}

int findEmptySeat(vector<string> partitions)
{
	int highest = 0, lowest = 1024;
	highLowID(partitions, highest, lowest);
	bool seatOccupied[128 * 8] = { 0 };

	for (int i = 0; i < (int)partitions.size(); i++)
	{
		string key = partitions[i];
		string row = key.substr(0, 7), col = key.substr(7, 3);
		int r, c, id, min, max, mid;

		// find row
		min = 0, max = 127;
		for (int j = 0; j < 6; j++)
		{
			mid = (min + max) / 2;

			if (row.at(j) == 'F')
			{
				max = mid;
			}
			else {
				min = mid + 1;
			}
		}
		r = (row.at(6) == 'F') ? min : max;

		// find col
		min = 0, max = 7;
		for (int j = 0; j < 2; j++)
		{
			mid = (min + max) / 2;

			if (col.at(j) == 'L')
			{
				max = mid;
			}
			else {
				min = mid + 1;
			}
		}
		c = (col.at(2) == 'L') ? min : max;

		id = r * 8 + c;
		seatOccupied[id] = true;
	}

	for (int i = lowest; i < highest; i++)
	{
		if (!seatOccupied[i])
		{
			return i;
		}
	}

	return 0;
}