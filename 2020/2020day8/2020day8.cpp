#include "../../max.h"
#include <fstream>
#include <iostream>>

using namespace std;

int solveFirstRun(vector<string> instructions, vector<bool> ran);
int solveFixedRun(vector<string> instructions, vector<bool> ran);
int tryRun(vector<string> instructions, vector<bool> ran);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> instructions;
	vector<bool> ran;
	string line;

	while (getline(fin, line))
	{
		instructions.push_back(line);
		ran.push_back(false);
	}

	fin.close();

	cout << "Accumulator value after instructions run once" << endl << solveFirstRun(instructions, ran) << endl;

	cout << "Accumulator value after changing one instruction" << endl << solveFixedRun(instructions, ran) << endl;
}

int solveFirstRun(vector<string> instructions, vector<bool> ran)
{
	int acc = 0;

	for (int i = 0; i < (int)instructions.size(); i++)
	{
		if (ran[i] == true)
		{
			return acc;
		}
		string instruction = instructions[i];
		string cmd = instruction.substr(0, 3);
		int value = stoi(instruction.substr(4));

		ran[i] = true;

		if (cmd == "acc")
		{
			acc += value;
		}
		else if (cmd == "jmp")
		{
			i += value - 1;
		}
	}

	return acc;
}

int solveFixedRun(vector<string> instructions, vector<bool> ran)
{
	for (int i = 0; i < (int)instructions.size(); i++)
	{
		string cmd = instructions[i].substr(0, 3);
		if (cmd == "jmp")
		{
			instructions[i].replace(0, 3, "nop");
		}
		else if (cmd == "nop")
		{
			instructions[i].replace(0, 3, "jmp");
		}

		int run = tryRun(instructions, ran);
		if (run != 0)
		{
			return run;
		}
		
		instructions[i].replace(0, 3, cmd);
	}

	return 0;
}

int tryRun(vector<string> instructions, vector<bool> ran)
{
	int acc = 0;
	
	for (int i = 0; i < (int)instructions.size(); i++)
	{
		if (ran[i] == true)
		{
			return 0;
		}
		string instruction = instructions[i];
		string cmd = instruction.substr(0, 3);
		int value = stoi(instruction.substr(4));

		ran[i] = true;

		if (cmd == "acc")
		{
			acc += value;
		}
		else if (cmd == "jmp")
		{
			i += value - 1;
		}

		if (i < 0)
		{
			return 0;
		}
	}

	return acc;
}