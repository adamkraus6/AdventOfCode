#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int solveCaptchaNext(string cap);
int solveCaptchaHalf(string cap);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	string line;
	getline(fin, line);

	cout << "Captcha solution (based on next character)" << endl << solveCaptchaNext(line) << endl;

	cout << "Captcha solution (based on halfway around)" << endl << solveCaptchaHalf(line) << endl;
}

int solveCaptchaNext(string cap)
{
	int sol = 0;

	for (int i = 0; i < cap.length(); i++)
	{
		if (cap[i] == cap[(i + 1) % cap.length()])
		{
			sol += cap[i] - '0';
		}
	}

	return sol;
}

int solveCaptchaHalf(string cap)
{
	int sol = 0;

	for (int i = 0; i < cap.length(); i++)
	{
		if (cap[i] == cap[(i + (cap.length() / 2)) % cap.length()])
		{
			sol += cap[i] - '0';
		}
	}

	return sol;
}