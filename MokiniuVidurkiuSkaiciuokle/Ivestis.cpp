#include <fstream>
#include <vector>
#include "Ivestis.h"

void ivestis(std::vector<Mokinys>& mok, int& ciklas, int ranka, ifstream& fs, int& kiek)
{
	if (ranka == 1)											//ivestis ranka
	{
		mok.push_back(Mokinys());
		cout << "Iveskite mokinio varda\n";
		cin >> mok[ciklas].vardas;
		cout << "Iveskite mokinio pavarde\n";
		cin >> mok[ciklas].pavarde;
	}

	//namu darbu pazimiu generavimas
	char status;
	int vieta = 0;
	if (ciklas == -1)
		fs.ignore(999, '\n');

	while (fs >> status)
	{
		if (status > 57)
		{
			ciklas++;
			mok.push_back(Mokinys());
			fs.putback(status);
			fs >> mok[ciklas].vardas >> mok[ciklas].pavarde;
			vieta = 0;
		}
		mok[ciklas].paz.push_back(vieta);
		if (status != '\n' && status != ' ' && status <= 57)
		{
			if (status != '0')
			{
				mok[ciklas].paz.push_back(vieta);
				mok[ciklas].paz[vieta] = std::stoi(&status);
				vieta++;
				mok[ciklas].egz = mok[ciklas].paz[vieta - 1];
			}
			else
			{	
				mok[ciklas].paz[vieta - 1] = mok[ciklas].paz[vieta - 1] * 10;
			}
		}
	}
	kiek = vieta - 1;
}