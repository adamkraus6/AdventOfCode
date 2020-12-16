#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int solveErrorRate(vector<vector<string>> validity, vector<vector<string>> tickets);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<vector<string>> validity;
	vector<vector<string>> tickets;
	string line;
	for (int i = 0; i < 20; i++)
	{
		getline(fin, line);
		int pos = (int)line.find(": ");
		vector<string> rule = split(line.substr(pos + 2), ' ');

		validity.push_back(rule);
	}

	for (int i = 0; i < 3; i++)
	{
		getline(fin, line);
	}
	tickets.push_back(split(line, ','));

	for (int i = 0; i < 3; i++)
	{
		getline(fin, line);
	}
	tickets.push_back(split(line, ','));

	while (getline(fin, line))
	{
		tickets.push_back(split(line, ','));
	}

	cout << "Ticket scanning error rate" << endl << solveErrorRate(validity, tickets) << endl;
}

int solveErrorRate(vector<vector<string>> validity, vector<vector<string>> tickets)
{
	int errorRate = 0;
	
	// for each ticket
	for (int i = 1; i < (int)tickets.size(); i++)
	{
		// for each value in ticket
		for (int j = 0; j < (int)tickets[i].size(); j++)
		{
			int value = stoi(tickets[i][j]);

			bool valid = false;
			for (int k = 0; k < (int)validity.size(); k++)
			{
				vector<string> rule = validity[k];
				vector<string> first = split(rule[0], '-'), second = split(rule[2], '-');
				int min1 = stoi(first[0]), max1 = stoi(first[1]), min2 = stoi(second[0]), max2 = stoi(second[1]);

				if (inBetween(value, min1, max1, true) || inBetween(value, min2, max2, true))
				{
					valid = true;
				}
			}

			if (!valid)
			{
				errorRate += value;
			}
		}
	}

	return errorRate;
}