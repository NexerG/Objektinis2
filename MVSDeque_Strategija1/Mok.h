#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <deque>
#include <list>
#include "Zmogus.h"

using std::deque;
using std::vector;
using std::list;
using std::string;

class Mokinys2:Zmogus
{
public:
	void As()
	{
		//su __super galima overridinti values is parent klases
		//__super::Kintamasis();
	}
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

	Mokinys2(const Mokinys2& objektas)
	{
		*this = objektas;
		//kopijavimo konstruktorius
		//std::cout << "kopijavimo konstruktorius";
	}

	Mokinys2& operator = (const Mokinys2& t)
	{
		this->vardas = t.vardas;
		this->pavarde = t.pavarde;
		this->paz = t.paz;
		this->egz = t.egz;
		this->rez = t.rez;
		//assignment operatorius
		//std::cout << "priskyrimo operatorius";
		return *this;
	}

	Mokinys2();
	~Mokinys2();

private:

	string vardas= "Erikas", pavarde="pavardenis2";
	deque<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};

