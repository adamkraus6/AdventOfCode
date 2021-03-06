#include "../../max.h"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

struct passport
{
	string birthYear;
	string issueYear;
	string expYear;
	string height;
	string hairCol;
	string eyeCol;
	string passID;

	passport()
	{
		birthYear = "MISSING";
		issueYear = "MISSING";
		expYear = "MISSING";
		height = "MISSING";
		hairCol = "MISSING";
		eyeCol = "MISSING";
		passID = "MISSING";
	}
};

void addPassport(vector<passport>& passports, string& p);
int solveFields(vector<passport>& passports);
int solveValidatedFields(vector<passport>& passports);

vector<string> fields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<passport> passports;
	string line, p;

	while (getline(fin, line))
	{
		if (line.empty())
		{
			addPassport(passports, p);
		}
		else {
			p += line + ' ';
		}
	}
	addPassport(passports, p);

	fin.close();

	cout << "Passports with necessary fields" << endl << solveFields(passports) << endl;

	cout << "Passports with validated fields" << endl << solveValidatedFields(passports) << endl;
}

void addPassport(vector<passport>& passports, string& p)
{
	passport pass;
	for (int i = 0; i < (int)fields.size(); i++)
	{
		size_t pos = p.find(fields[i]);
		if (pos != string::npos)
		{
			int space = p.find(' ', pos + 4);
			string field = p.substr(pos + 4, space - pos - 4);

			switch (i)
			{
			case 0:
				pass.birthYear = field;
				break;
			case 1:
				pass.issueYear = field;
				break;
			case 2:
				pass.expYear = field;
				break;
			case 3:
				pass.height = field;
				break;
			case 4:
				pass.hairCol = field;
				break;
			case 5:
				pass.eyeCol = field;
				break;
			case 6:
				pass.passID = field;
				break;
			}
		}
	}
	passports.push_back(pass);
	p = "";
}

int solveFields(vector<passport>& passports)
{
	int valid = 0;
	bool hasFields;

	for (int i = 0; i < (int)passports.size(); i++)
	{
		passport p = passports[i];
		hasFields = p.birthYear != "MISSING" && p.issueYear != "MISSING" && p.expYear != "MISSING" && p.height != "MISSING" &&
			p.hairCol != "MISSING" && p.eyeCol != "MISSING" && p.passID != "MISSING";

		if (hasFields)
		{
			valid++;
		}
	}

	return valid;
}

int solveValidatedFields(vector<passport>& passports)
{
	int valid = 0;
	bool hasFields;
	regex hexValue("^#[0-9a-f]{6}$");
	regex col("^(amb|blu|brn|gry|grn|hzl|oth)$");
	regex ID("^[0-9]{9}$");

	for (int i = 0; i < (int)passports.size(); i++)
	{
		passport p = passports[i];
		hasFields = p.birthYear != "MISSING" && p.issueYear != "MISSING" && p.expYear != "MISSING" && p.height != "MISSING" &&
			p.hairCol != "MISSING" && p.eyeCol != "MISSING" && p.passID != "MISSING";

		if (hasFields)
		{
			int byr = stoi(p.birthYear);
			bool BYR = 1920 <= byr && byr <= 2002;

			int iyr = stoi(p.issueYear);
			bool IYR = 2010 <= iyr && iyr <= 2020;

			int eyr = stoi(p.expYear);
			bool EYR = 2020 <= eyr && eyr <= 2030;

			int hgt = stoi(p.height);
			string h = p.height.substr(p.height.length() - 2);
			bool HGT = false;
			if (h == "in")
			{
				HGT = 59 <= hgt && hgt <= 76;
			}
			else if (h == "cm")
			{
				HGT = 150 <= hgt && hgt <= 193;
			}

			bool HCL = regex_match(p.hairCol, hexValue);
			bool ECL = regex_match(p.eyeCol, col);
			bool PID = regex_match(p.passID, ID);

			if (BYR && IYR && EYR && HGT && HCL && ECL && PID)
			{
				valid++;
			}
		}
	}

	return valid;
}