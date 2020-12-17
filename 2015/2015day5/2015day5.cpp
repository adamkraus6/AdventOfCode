#include "../../max.h"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int niceStrings(vector<string> strings);

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

	cout << "Nice Strings" << endl << niceStrings(strings) << endl;
}

int niceStrings(vector<string> strings)
{
	int nice = 0;

	for (string str : strings)
	{
		int vowels = 0;
		bool twiceRow = false;
		bool other = false;

		for (int i = 0; i < str.length(); i++)
		{
			char c = str.at(i);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				vowels++;
			}
		}

		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str.at(i) == str.at(i + 1))
			{
				twiceRow = true;
			}
		}

		other = str.find("ab") == string::npos && str.find("cd") == string::npos && str.find("pq") == string::npos && str.find("xy") == string::npos;


		if (vowels >= 3 && twiceRow && other)
		{
			nice++;
		}
	}

	return nice;
}