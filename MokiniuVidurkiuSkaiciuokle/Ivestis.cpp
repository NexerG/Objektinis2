#include <fstream>
#include <vector>
#include "Ivestis.h"

void ivestis(std::vector<Mokinys>& mok, int ciklas, int ranka, ifstream& fs, int &kiek)
{
	mok.push_back(Mokinys());
	if (ranka == 1)											//ivestis ranka
	{
		cout << "Iveskite mokinio varda\n";
		mok.push_back(Mokinys());
		cin >> mok[ciklas].vardas;
		cout << "Iveskite mokinio pavarde\n";
		cin >> mok[ciklas].pavarde;
	}

	if (ranka == 2)											//ivestis is failo
	{
		if (ciklas == 0)
		{
			fs.ignore(999, '\n');
		}
		fs >> mok[ciklas].vardas >> mok[ciklas].pavarde;
	}

	//namu darbu pazimiu generavimas
	char status;
	int vieta = 0;
	mok[ciklas].paz.push_back(vieta);
	while (fs >> status)
	{
		//cout << status << endl;
		if (status != '\n' && status != ' ' && status <= 57)
		{
			if (status != '0')
			{
				mok[ciklas].paz.push_back(vieta);
				mok[ciklas].paz[vieta] = std::stoi(&status);
				//cout << mok[ciklas].paz[vieta]<<endl;
				vieta++;
			}
			else
			{
				mok[ciklas].paz[vieta - 1] = mok[ciklas].paz[vieta - 1] * 10;
			}
		}
		else if (status > 57)
		{
			fs.putback(status);
			break;
		}
	}
	kiek = vieta - 1;
	mok[ciklas].egz = mok[ciklas].paz[vieta - 1];
}