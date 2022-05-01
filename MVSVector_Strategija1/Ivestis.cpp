#include <fstream>
#include <vector>
#include <chrono>
#include "Ivestis.h"

using std::endl;

void ivestis(vector<Mokinys>& mok, int& ciklas, int ranka, ifstream& fs)
{
	std::vector<Mokinys>::iterator it;
	it = mok.begin();

	if (ranka == 2)
	{
		if (ciklas == -1)
			fs.ignore(999, '\n');
	}

	std::stringstream sstr;
	clock_t start = clock();
	sstr << fs.rdbuf();
	clock_t end = clock();

	
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
	cout << "Failo su " << mok.size() << " elementu nuskaitymo laikas: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
}