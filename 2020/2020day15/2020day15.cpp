#include "../../max.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int spokenNumber(vector<int> numbers, int nth);

int main()
{
	ifstream fin;
	fin.open("data2.txt");
	if (!fin.is_open()) exit(0);

	string line;
	getline(fin, line);
	fin.close();

	vector<string> parts = split(line, ',');
	vector<int> numbers;
	for (int i = 0; i < (int)parts.size(); i++)
	{
		numbers.push_back(stoi(parts[i]));
	}


}

int spokenNumber(vector<int> numbers, int nth)
{
	map<int, int> whenLastSpoken;

	for (int i = 0; i < (int)numbers.size(); i++)
	{

	}

	for (int i = 4; i <= nth; i++)
	{

	}
}