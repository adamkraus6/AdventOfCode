#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

int solveGoldBags(unordered_map<string, vector<string>>& whatBagsHolds);
bool canHoldGold(string bagName, unordered_map<string, vector<string>>& whatBagsHolds);

int main(int argc, char** argv)
{
	ifstream fin;
	string line;
	int bagsHoldGold;

	if (argc != 2)
	{
		cout << "Usage: 2020day7.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	unordered_map<string, vector<string>> whatBagsHolds;

	while (getline(fin, line))
	{
		vector<string> held;
		string parentBag;

		int a = (int)line.find("bags");
		parentBag = line.substr(0, a - 1);

		// if bag holds other bags
		if (line.find("no other bags") == string::npos)
		{
			int next = a + 1;
			while (next != string::npos && line.find_first_of("0123456789", next) != string::npos)
			{
				int num = (int)line.find_first_of("0123456789", next);
				int bag = (int)line.find("bag", num);

				string whatIsHeld = line.substr(num + 2, bag - num - 3);
				
				held.push_back(whatIsHeld);

				next = bag + 1;
			}
		}

		whatBagsHolds[parentBag] = held;
	}

	bagsHoldGold = solveGoldBags(whatBagsHolds);

	cout << "Bags that can eventually hold gold" << endl << bagsHoldGold << endl;
}

int solveGoldBags(unordered_map<string, vector<string>>& whatBagsHolds)
{
	int sum = 0;

	for (auto it = whatBagsHolds.begin(); it != whatBagsHolds.end(); it++)
	{
		if (canHoldGold(it->first, whatBagsHolds))
		{
			sum++;
		}
	}

	return sum;
}

bool canHoldGold(string bagName, unordered_map<string, vector<string>>& whatBagsHolds)
{
	bool can = false;
	vector<string> canHold = whatBagsHolds[bagName];

	for (int i = 0; i < (int)canHold.size(); i++)
	{
		if (canHold[i] == "shiny gold")
		{
			can = true;
			break;
		}

		can = (canHoldGold(canHold[i], whatBagsHolds)) ? true : can;
		if (can)
		{
			break;
		}
	}

	return can;
}