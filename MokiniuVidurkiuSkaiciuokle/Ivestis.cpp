#include <fstream>
#include <vector>
#include "Ivestis.h"

void ivestis(deque<Mokinys>& mok, int& ciklas, int ranka, ifstream& fs, int& kiek)
{
	if (ranka == 2)
	{
		if (ciklas == -1)
			fs.ignore(999, '\n');
	}

	std::stringstream sstr;
	sstr << fs.rdbuf();
	
	string status,Nusk;
	while (std::getline(sstr, status))
	{
		std::stringstream X(status);
		mok.push_back(Mokinys());

		std::getline(X, Nusk, ' ');
		mok[ciklas].vardas = Nusk;
		std::getline(X, Nusk, ' ');
		mok[ciklas].pavarde = Nusk;

		while (std::getline(X, Nusk, ' '))
		{
			mok[ciklas].paz.push_back(std::stoi(Nusk));
		}
		ciklas++;
	}
	for (int i = 0; i < mok.size()-1; i++)
	{
		mok[i].egz = mok[i].paz[mok[i].paz.size()-1];
	}
	kiek = mok[1].paz.size();
}