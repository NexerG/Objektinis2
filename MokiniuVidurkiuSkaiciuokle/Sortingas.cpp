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

void SRSmegNemk(deque<Mokinys>& mok, int kiek, deque<Mokinys>& Smegenines, deque<Mokinys>& Nemoksos)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	for (int i = mok.size()-1; i > 0; i--)
	{
		if (SkVid(mok, i, kiek) >= 5)
		{
			Smegenines.push_back(mok[i]);		//taip idedama iskarto reiksme
			mok.pop_back();			//labai letas, nes perkuriamas masyvas/ galima naudoti POP kad paskutini isimt
		}
		else
		{
			Nemoksos.push_back(mok[i]);
			mok.pop_back();
		}
	}
}