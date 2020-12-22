#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int part1(vector<string> strings);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> strings;
	for (string line; getline(fin, line);)
	{
		strings.push_back(line);
	}
	fin.close();

	cout << "Char of string code minus char of memory" << endl << part1(strings) << endl;
}

int part1(vector<string> strings)
{
	int stringCode = 0, charMem = 0;

	for (string str : strings)
	{
		stringCode += str.length();

		string mem = str.substr(1, str.length() - 2);
		int backslash = 0;
		for (int i = 0; i < mem.length(); i++)
		{
			if (mem[i] == '\\')
			{
				backslash++;
			}
		}
		charMem += mem.length() - backslash;
	}

	return stringCode - charMem;
}