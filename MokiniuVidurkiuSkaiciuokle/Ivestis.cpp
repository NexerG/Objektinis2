#include <fstream>
#include <vector>
#include "Ivestis.h"

void ivestis(list<Mokinys>& mok, int& ciklas, int ranka, ifstream& fs)
{
	std::list<Mokinys>::iterator it;
	it = mok.begin();

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
		Mokinys dummy;
		std::stringstream X(status);

		std::getline(X, Nusk, ' ');
		dummy.vardas = Nusk;

		std::getline(X, Nusk, ' ');
		dummy.pavarde = Nusk;

		while (std::getline(X, Nusk, ' '))
		{
			dummy.paz.push_back(std::stoi(Nusk));
		}
		ciklas++;
		dummy.egz = dummy.paz[dummy.paz.size() - 1];
		mok.push_back(dummy);
	}
}