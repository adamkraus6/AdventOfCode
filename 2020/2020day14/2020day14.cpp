#include "../../max.h"
#include <unordered_map>

using namespace std;

long long int solveSumMemory(vector<string> lines);
long long bitStringToNum(string mask);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);
	string line;
	vector<string> lines;

	while (getline(fin, line))
	{
		lines.push_back(line);
	}

	cout << solveSumMemory(lines) << endl;
}

long long int solveSumMemory(vector<string> lines)
{
	unordered_map<int, long long int> m;
	long long mask = 0;

	for (int i = 0; i < (int)lines.size(); i++)
	{
		string line = lines[i];
		if (line.substr(0, 4) == "mask")
		{
			string m = line.substr(7);
			for (int j = 0; j < m.length(); j++)
			{
				if (m.at(j) == 'X')
				{
					m.replace(j, 1, "0");
				}
			}
			mask = bitStringToNum(m);
		}
		else {
			int bracket = (int)line.find_first_of("]", 4);
			int address = stoi(line.substr(4, bracket - 4));
			long long value = stoll(line.substr(bracket + 4));

			value = value | mask;

			m[address] = value;
		}
	}

	long long sum = 0;

	for (auto it = m.begin(); it != m.end(); it++)
	{
		sum += it->second;
	}

	return sum;
}

long long bitStringToNum(string mask)
{
	long long num = 0;

	for (int i = 0; i < mask.length(); i++)
	{
		if (mask.at(i) == '1')
		{
			num += (long long)pow(2, mask.length() - i - 1);
		}
	}

	return num;
}