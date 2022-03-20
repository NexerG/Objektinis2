#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;

struct Mokinys
{
	string vardas, pavarde;
	vector<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};