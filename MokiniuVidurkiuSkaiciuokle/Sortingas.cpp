#include "Sortingas.h"
#include <iomanip>
#include <iostream>


bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean

void RikVarPav(list<Mokinys>& mok, char rus)
{
	//if (rus == 'p')
	//	sort(mok.begin(), mok.end(), Pav);
	//if (rus == 'v')
	//	sort(mok.begin(), mok.end(), Var);
}

void SRSmegNemk(list<Mokinys>& mok, int kiek, list<Mokinys>& Smegenines, list<Mokinys>& Nemoksos)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	for (list<Mokinys>::iterator it = mok.begin(); it != mok.end(); it++)
	{
		if (SkVid(*it) >= 5)
		{
			Smegenines.push_back(*it);		//taip idedama iskarto reiksme
			//mok.pop_front();			//labai letas, nes perkuriamas masyvas/ galima naudoti POP kad paskutini isimt
		}
		else
		{
			Nemoksos.push_back(*it);
		}
	}
	mok.clear();
}