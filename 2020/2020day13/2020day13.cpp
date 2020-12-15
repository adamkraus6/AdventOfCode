#include "../../max.h"
#include <iostream>
#include <fstream>

using namespace std;

int solveFirstDeparture(vector<int> IDs, int timestamp);
long long magicTimestamp(vector<string> buses);
long long modInv(int a, int m);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if(!fin.is_open()) exit(0);

	string line;
	int timestamp;

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

	cout << "Magic timestamp for departures" << endl << magicTimestamp(buses) << endl;
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

long long magicTimestamp(vector<string> buses)
{
	long long t;
	vector<long long> num, rem, pp, inv;

	// calculate offset
	for (int i = 0; i < (int)buses.size(); i++)
	{
		if (buses[i] != "x")
		{
			int id = stoi(buses[i]);
			num.push_back(id);
			int offset = id - i;
			while (offset < 0)
			{
				offset += id;
			}
			rem.push_back(offset);
		}
	}

	long long prod = 1;
	for (int i = 0; i < (int)num.size(); i++)
	{
		prod *= num[i];

		pp.push_back(prod / num[i]);

		inv.push_back(modInv(pp[i], num[i]));
	}

	unsigned long long sum = 0;
	for (int i = 0; i < (int)rem.size(); i++)
	{
		sum += (rem[i] * pp[i] * inv[i]);
	}

	t = sum % prod;

	return t;
}

// from https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
long long modInv(int a, int m)
{
	long long m0 = m, t, q;
	long long x0 = 0, x1 = 1;

	if (m == 1)
		return 0;

	// Apply extended Euclid Algorithm 
	while (a > 1)
	{
		// q is quotient 
		q = a / m;

		t = m;

		// m is remainder now, process same as 
		// euclid's algo 
		m = a % m, a = t;

		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}

	// Make x1 positive 
	if (x1 < 0)
		x1 += m0;

	return x1;
}