#include "Sortingas.h"
#include <iomanip>
#include <iostream>


bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean
bool Pazimys(Mokinys mok1, Mokinys mok2) { return (mok1.rez < mok2.rez); };	//rikiavimo boolean

void RikVarPav(vector<Mokinys>& mok, char rus)
{
	if (rus == 'p')
		sort(mok.begin(), mok.end(), Pav);
	if (rus == 'v')
		sort(mok.begin(), mok.end(), Var);
}

void SRSmegNemk(vector<Mokinys>& mok, int kiek, vector<Mokinys>& Smegenines, vector<Mokinys>& Nemoksos)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	sort(mok.begin(), mok.end(), Pazimys);
	for (vector<Mokinys>::iterator it=mok.begin(); it != mok.end(); it++)
	{
		if (SkVid(*it) >= 5)
		{
			Smegenines.push_back(*it);		//taip idedama iskarto reiksme
			//mok.pop_back();
		}
		else
		{
			Nemoksos.push_back(*it);
			//mok.pop_back();			
		}
	}
	mok.clear();
}