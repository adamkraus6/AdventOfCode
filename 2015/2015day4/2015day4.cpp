#include "../../max.h"
#include <iostream>
#include "md5.h"

using namespace std;

int solveZeroHash(string key, int leadingZeros);

/*
_CRT_SECURE_NO_WARNINGS is needed to compile
Project->Properties->C/C++->Preprocessor->Preprocessor Definitions
*/

int main()
{
	string key = "bgvyzdsv";

	cout << "Number added to key for hash with 5 leading zeros" << endl <<solveZeroHash(key, 5) << endl;

	cout << "Number added to key for hash with 6 leading zeros" << endl << solveZeroHash(key, 6) << endl;

}

int solveZeroHash(string key, int leadingZeros)
{
	int h = 0;

	string str;
	for (int i = 0; i < leadingZeros; i++)
	{
		str += "0";
	}

	while (true)
	{
		string hash = md5(key + to_string(h));

		if (hash.substr(0, leadingZeros) == str)
		{
			return h;
		}

		h++;
	}

	return 0;
}