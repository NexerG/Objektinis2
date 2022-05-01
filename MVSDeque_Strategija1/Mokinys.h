#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <deque>
#include <list>

using std::deque;
using std::vector;
using std::list;
using std::string;

class Mokinys2
{
public:

	string vardas, pavarde;
	deque<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;

	Mokinys2();
	~Mokinys2();

private:

};

Mokinys2::Mokinys2()
{
}

Mokinys2::~Mokinys2()
{
}

struct Mokinys
{
	string vardas, pavarde;
	deque<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};