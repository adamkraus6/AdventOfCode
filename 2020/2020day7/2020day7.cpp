#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solveGoldBags(unordered_map<string, unordered_map<string, int>>& whatBagsHolds);
bool canHoldGold(string bagName, unordered_map<string, unordered_map<string, int>>& whatBagsHolds);
int bagsIn(string baseBag, unordered_map<string, unordered_map<string, int>>& whatBagsHolds);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	string line;
	unordered_map<string, unordered_map<string, int>> whatBagsHolds;

	while (getline(fin, line))
	{
		unordered_map<string, int> held;
		string parentBag;

		int a = (int)line.find("bags");
		parentBag = line.substr(0, a - 1);

		// if bag holds other bags
		if (line.find("no other bags") == string::npos)
		{
			int next = a + 1;
			while (next != string::npos && line.find_first_of("0123456789", next) != string::npos)
			{
				int number = (int)line.find_first_of("0123456789", next);
				int bag = (int)line.find("bag", number);
				int s = (int)line.find_first_of(" ", number);
				
				int numChildBags = stoi(line.substr(number, s - number));
				string childBag = line.substr(s + 1, bag - s - 2);

				held[childBag] = numChildBags;

				next = bag + 1;
			}
		}

		whatBagsHolds[parentBag] = held;
	}

	fin.close();

	cout << "Bags that can eventually hold gold" << endl << solveGoldBags(whatBagsHolds) << endl;

	cout << "Bags inside shiny gold" << endl << bagsIn("shiny gold", whatBagsHolds) << endl;
}

int solveGoldBags(unordered_map<string, unordered_map<string, int>>& whatBagsHolds)
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

bool canHoldGold(string bagName, unordered_map<string, unordered_map<string, int>>& whatBagsHolds)
{
	bool can = false;
	unordered_map<string, int> canHold = whatBagsHolds[bagName];

	for (auto it = canHold.begin(); it != canHold.end(); it++)
	{
		if (it->first == "shiny gold")
		{
			can = true;
			break;
		}

		can = (canHoldGold(it->first, whatBagsHolds)) ? true : can;
		if (can)
		{
			break;
		}
	}

	return can;
}

int bagsIn(string baseBag, unordered_map<string, unordered_map<string, int>>& whatBagsHolds)
{
	int sum = (baseBag == "shiny gold") ? 0 : 1;
	unordered_map<string, int> bag = whatBagsHolds[baseBag];

	for (auto it = bag.begin(); it != bag.end(); it++)
	{
		string bagName = it->first;
		int bagNum = it->second;
		sum += bagNum * bagsIn(bagName, whatBagsHolds);
	}

	return sum;
}