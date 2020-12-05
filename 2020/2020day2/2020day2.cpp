#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solveValidPassOccurences(ifstream& fin);
int solveValidPassPositions(ifstream& fin);

int main(int argc, char** argv)
{
	ifstream fin1, fin2;
	int valid1, valid2;

	if (argc != 2)
	{
		cout << "Usage: 2020day2.exe data" << endl;
		exit(0);
	}

	fin1.open(argv[1]);
	fin2.open(argv[1]);
	if (!fin1.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	valid1 = solveValidPassOccurences(fin1);

	cout << "Valid passwords based on letter occurences: " << endl << valid1 << endl;

	valid2 = solveValidPassPositions(fin2);

	cout << "Valid passwords based on letter positions: " << endl << valid2 << endl;

	fin1.close();
	fin2.close();
}

int solveValidPassOccurences(ifstream& fin)
{
	string str;
	int minOccur, maxOccur, occurences, valid = 0;
	char c;

	while (getline(fin, str, '-'))
	{
		// read in min/max allowed occurences of letter
		minOccur = stoi(str);
		getline(fin, str, ' ');
		maxOccur = stoi(str);

		// read in letter
		getline(fin, str, ' ');
		c = str.at(0);

		// read in password
		getline(fin, str, '\n');

		// determine occurences
		occurences = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (c == str.at(i))
			{
				occurences++;
			}
		}

		// determine if valid password
		if (minOccur <= occurences && occurences <= maxOccur)
		{
			valid++;
		}
	}

	return valid;
}

int solveValidPassPositions(ifstream& fin)
{
	string str;
	int pos1, pos2, valid = 0;
	char c;
	bool p, q;

	while (getline(fin, str, '-'))
	{
		// read in letter positions
		pos1 = stoi(str);
		getline(fin, str, ' ');
		pos2 = stoi(str);

		// read in letter
		getline(fin, str, ' ');
		c = str.at(0);

		// read in password
		getline(fin, str, '\n');

		// determine if valid password
		p = str.at(pos1 - 1) == c;
		q = str.at(pos2 - 1) == c;
		if ((p && !q) || (!p && q))
		{
			valid++;
		}
	}

	return valid;
}