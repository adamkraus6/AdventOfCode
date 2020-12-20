#include "../../max.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>

using namespace std;

int wireA(vector<string> instructions);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> instructions;
	for (string line; getline(fin, line);)
	{
		instructions.push_back(line);
	}
	fin.close();

	cout << "Wire A Signal" << endl << wireA(instructions) << endl;
}

int wireA(vector<string> instructions)
{
	regex number("[0-9]");
	unordered_map<string, int> wires;

	for (string ins : instructions)
	{
		vector<string> parts = split(ins, ' ');

		if (parts[1] == "->")
		{
			if (regex_match(parts[0], number))
			{
				wires[parts[2]] = stoi(parts[0]);
			}
			else {
				wires[parts[2]] = wires[parts[0]];
			}
		}
		else if (parts[0] == "NOT")
		{
			wires[parts[3]] = ~wires[parts[1]];
		}
		else if (parts[1] == "AND")
		{
			wires[parts[4]] = wires[parts[0]] & wires[parts[2]];
		}
		else if (parts[1] == "OR")
		{
			wires[parts[4]] = wires[parts[0]] | wires[parts[2]];
		}
		else if (parts[1] == "LSHIFT")
		{
			wires[parts[4]] = wires[parts[0]] << stoi(parts[2]);
		}

		else if (parts[1] == "RSHIFT")
		{
			wires[parts[4]] = wires[parts[0]] >> stoi(parts[2]);
		}
	}

	return wires["a"];
}

/*
ToDo:
Number from 0 to 65535
Run AFTER, not during
*/