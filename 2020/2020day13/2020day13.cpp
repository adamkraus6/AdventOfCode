#include "../../max.h"

using namespace std;

int solveFirstDeparture(vector<int> IDs, int timestamp);

int main(int argc, char** argv)
{
	ifstream fin;
	string line;
	int timestamp, firstDepart;

	if (argc != 2)
	{
		cout << "Usage: 2020day13.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	getline(fin, line);
	timestamp = stoi(line);

	getline(fin, line);
	vector<string> buses = split(line, ',');

	vector<int> busIDs;
	for (int i = 0; i < (int)buses.size(); i++)
	{
		if (buses[i] != "x")
		{
			busIDs.push_back(stoi(buses[i]));
		}
	}

	firstDepart = solveFirstDeparture(busIDs, timestamp);

	cout << "Product of minute wait and Bus ID for first departure" << endl << firstDepart << endl;
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