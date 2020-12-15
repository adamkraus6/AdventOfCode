#include "../../max.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int solveJoltDiff(vector<int> adapters);
bool findAdapter(vector<int> arr, int target);
long long solveDistinctArrangements(vector<int> adapters);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if(!fin.is_open()) exit(0);

	vector<int> adapters;
	int value;

	while (fin >> value)
	{
		adapters.push_back(value);
	}

	fin.close();

	cout << "Product of number of one/three jolt adapter differences" << endl << solveJoltDiff(adapters) << endl;

	cout << "Distinct arrangements of adapters" << endl << solveDistinctArrangements(adapters) << endl;
}

int solveJoltDiff(vector<int> adapters)
{
	int OneJDiff = 0, ThreeJDIff = 0, currAdapter = 0, builtIn = 0;

	// find highest adapter joltage
	for (int i = 0; i < (int)adapters.size(); i++)
	{
		builtIn = (adapters[i] > builtIn) ? adapters[i] : builtIn;
	}
	builtIn += 3;

	for (int i = 0; i < (int)adapters.size(); i++)
	{
		if (findAdapter(adapters, currAdapter + 1))
		{
			currAdapter += 1;
			OneJDiff++;
		}
		else if (findAdapter(adapters, currAdapter + 3))
		{
			currAdapter += 3;
			ThreeJDIff++;
		}
	}

	return OneJDiff * (ThreeJDIff + 1);
}

bool findAdapter(vector<int> arr, int target)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (arr[i] == target)
		{
			return true;
		}
	}

	return false;
}

long long solveDistinctArrangements(vector<int> adapters)
{
	sort(adapters.begin(), adapters.end());
	int streak = (adapters[0] == 1) ? 1 : 0;
	long long arrangements = 1;
	vector<int> mult = { 1, 1, 2, 4, 7 };

	for (int i = 0; i < (int)adapters.size() - 1; i++)
	{
		if (adapters[i] + 1 == adapters[i + 1])
		{
			streak++;
		}
		else {
			arrangements *= mult[streak];
			streak = 0;
		}
	}
	arrangements *= mult[streak];

	return arrangements;
}