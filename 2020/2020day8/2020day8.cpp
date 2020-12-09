#include "../../max.h"

using namespace std;

int solveFirstRun(vector<string> instructions, vector<bool> ran);
int solveFixedRun(vector<string> instructions, vector<bool> ran);
bool isInfinite(vector<string> instructions, vector<bool> ran);
int getAcc(vector<string> instructions);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<string> instructions;
	vector<bool> ran;
	string line;
	int firstRunAccumulator, fixedRunAccumulator;

	if (argc != 2)
	{
		cout << "Usage: 2020day8.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (getline(fin, line))
	{
		instructions.push_back(line);
		ran.push_back(false);
	}

	firstRunAccumulator = solveFirstRun(instructions, ran);

	cout << "Accumulator value after instructions run once" << endl << firstRunAccumulator << endl;

	fixedRunAccumulator = solveFixedRun(instructions, ran);

	cout << "Accumulator value after changing one instruction" << endl << fixedRunAccumulator << endl;
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

		if (cmd == "acc")
		{
			acc += value;
		}
		else if (cmd == "jmp")
		{
			i += value - 1;
		}

		ran[i] = true;
	}

	return acc;
}

int solveFixedRun(vector<string> instructions, vector<bool> ran)
{
	for (int i = 0; i < (int)instructions.size(); i++)
	{
		
	}

	return 0;
}