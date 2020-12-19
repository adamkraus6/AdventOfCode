#include "../../max.h"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int niceStrings(vector<string> strings);
int betterNiceStrings(vector<string> strings);

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

	cout << "Better Nice Strings" << endl << betterNiceStrings(strings) << endl;
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

int betterNiceStrings(vector<string> strings)
{
	int nice = 0;

	for (string str : strings)
	{
		bool repeatSpace = false;
		for (int i = 0; i < str.length() - 2; i++)
		{
			if (str[i] == str[i + 2])
			{
				repeatSpace = true;
				break;
			}
		}

		bool repeatPair = false;
		for (int i = 0; i < str.length() - 3; i++)
		{
			string pair1 = str.substr(i, 2);
			for (int j = i + 2; j < str.length(); j++)
			{
				string pair2 = str.substr(j, 2);
				if (pair1 == pair2)
				{
					repeatPair = true;
					goto end;
				}
			}
		}

		end:

		if (repeatSpace && repeatPair)
		{
			nice++;
		}
	}

	return nice;
}