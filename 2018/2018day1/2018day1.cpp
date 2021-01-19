#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int resultFreq(vector<int> changes);

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