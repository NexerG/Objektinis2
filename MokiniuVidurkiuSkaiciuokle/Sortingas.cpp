#include "Sortingas.h"
#include <iomanip>
#include <iostream>


bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean

void rikiavimas(deque<Mokinys>& mok, int ciklas)
{
	sort(mok[ciklas].paz.begin(), mok[ciklas].paz.end());
}

void RikVarPav(deque<Mokinys>& mok, char rus, int ciklas)
{
	if (rus == 'p')
		sort(mok.begin(), mok.end(), Pav);
	if (rus == 'v')
		sort(mok.begin(), mok.end(), Var);
}

deque<Mokinys> SRSmeg(deque<Mokinys>& mok, int kiek)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	deque<Mokinys> Smegenines;
	for (int i = 0; i < mok.size(); i++)
	{
		if (SkVid(mok, i, kiek) >= 5)
		{
			Smegenines.push_back(mok[i]);		//taip idedama iskarto reiksme
			mok.erase(mok.begin()+i);			//labai letas, nes perkuriamas masyvas/ galima naudoti POP kad paskutini isimt
			i--;
		}
	}
	return Smegenines;
}

deque<Mokinys> SRNemk(deque<Mokinys>& mok, int kiek)	//studentu su vidurkiais maziau negu 5 isrinkimas
{
	deque<Mokinys> Nemoksos;
	Nemoksos = mok;
	mok.clear();
	return Nemoksos;
}
