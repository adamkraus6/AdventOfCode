#include "../../max.h"
#include <algorithm>

using namespace std;

int solveJoltDiff(vector<int> adapters);
bool findAdapter(vector<int> arr, int target);
long long solveDistinctArrangements(vector<int> adapters);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<int> adapters;
	int value, joltDiff;
	long long distinctArr;

	if (argc != 2)
	{
		cout << "Usage: 2020day10.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (fin >> value)
	{
		adapters.push_back(value);
	}

	joltDiff = solveJoltDiff(adapters);

	cout << "Product of number of one/three jolt adapter differences" << endl << joltDiff << endl;

	distinctArr = solveDistinctArrangements(adapters);

	cout << "Distinct arrangements of adapters" << endl << distinctArr << endl;
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