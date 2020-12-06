#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int highestSeatID(vector<string>& partitions);
int lowestSeatID(vector<string>& partitions);
int findEmptySeat(vector<string>& partitions);

int main(int argc, char** argv)
{
	ifstream fin;
	int rows = 128, cols = 8, highestID, mySeatID;
	vector<string> partitions;
	string line;

	if (argc != 2)
	{
		cout << "Usage: 2020day5.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (getline(fin, line))
	{
		partitions.push_back(line);
	}

	highestID = highestSeatID(partitions);

	cout << "Highest Seat ID" << endl << highestID << endl;

	mySeatID = findEmptySeat(partitions);

	cout << "Empty Seat ID" << endl << mySeatID << endl;
}

int highestSeatID(vector<string>& partitions)
{
	int highest = 0;

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
		highest = (id > highest) ? id : highest;
	}

	return highest;
}

int lowestSeatID(vector<string>& partitions)
{
	int lowest = highestSeatID(partitions);

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
		lowest = (id < lowest) ? id : lowest;
	}

	return lowest;
}

int findEmptySeat(vector<string>& partitions)
{
	int highest = highestSeatID(partitions), lowest = lowestSeatID(partitions);
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