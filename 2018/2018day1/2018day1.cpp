#include "../../max.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int resultFreq(vector<int> changes);
int firstDupeFreq(vector<int> changes);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);
	vector<int> changes;

	for (string line; getline(fin, line);)
	{
		changes.push_back(stoi(line));
	}

	cout << "Resulting Frequency" << endl << resultFreq(changes) << endl;

	cout << "First Duplicate Frequency" << endl << firstDupeFreq(changes) << endl;
}

int resultFreq(vector<int> changes)
{
	int freq = 0;

	for (int change : changes)
	{
		freq += change;
	}

	return freq;
}

int firstDupeFreq(vector<int> changes)
{
	int freq = 0, index = 0;
	vector<int> freqs;
	bool found = false;
	
	while (!found)
	{
		freq += changes[index];

		if (find(freqs.begin(), freqs.end(), freq) != freqs.end())
		{
			return freq;
		}

		freqs.push_back(freq);

		index++;
		index = index % changes.size();
	}

	return -1;
}