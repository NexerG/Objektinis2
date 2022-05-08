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
	//vardo get/set
	string getVar()
	{
		return vardas;
	}
	void setVar(string var)
	{
		vardas = var;
	}

	//pavardes get/set
	string getPav()
	{
		return pavarde;
	}
	void setPav(string pav)
	{
		pavarde = pav;
	}

	//pazymiai
	deque<int> getpazymiai()
	{
		return paz;
	}
	void setpaz(deque<int> pazymiai)
	{
		paz = pazymiai;
	}
	void pushPaz(int pazymiai)
	{
		paz.push_back(pazymiai);
	}

	//egzamino paz
	int getegz()
	{
		return egz;
	}
	void setegz(deque<int> egzaminas)
	{
		egz = egzaminas.size()-1;
	}

	//rezultatas
	double getrezultatas()
	{
		return rez;
	}
	void setRez(double rezultatas)
	{
		rez = rezultatas;
	}

	Mokinys2();
	~Mokinys2();

private:

	string vardas, pavarde;
	deque<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};

