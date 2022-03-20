#include "Sortingas.h"
#include <iomanip>
#include <iostream>

bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean

void rikiavimas(vector<Mokinys>& mok, int ciklas)
{
	sort(mok[ciklas].paz.begin(), mok[ciklas].paz.end());
}

void RikVarPav(vector<Mokinys>& mok, char rus, int ciklas)
{
	if (rus == 'p')
		sort(mok.begin(), mok.end(), Pav);
	if (rus == 'v')
		sort(mok.begin(), mok.end(), Var);
}

vector<Mokinys> SRSmeg(vector<Mokinys>& mok, int kiek)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	int vieta = 0;
	vector<Mokinys> Smegenines;
	for (int i = 0; i < mok.size(); i++)
	{
		if (SkVid(mok, i, kiek) >= 5)
		{
			Smegenines.push_back(Mokinys());
			Smegenines[vieta] = mok[i];
			mok.erase(mok.begin()+i);
			i--;
			vieta++;
		}
	}
	return Smegenines;
}

vector<Mokinys> SRNemk(vector<Mokinys>& mok, int kiek)	//studentu su vidurkiais maziau negu 5 isrinkimas
{
	vector<Mokinys> Nemoksos;
	Nemoksos = mok;
	mok.clear();
	return Nemoksos;
}
