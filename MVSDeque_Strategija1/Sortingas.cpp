#include "Sortingas.h"
#include <iomanip>
#include <iostream>


//bool Var(Mokinys2 mok1, Mokinys2 mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
//bool Pav(Mokinys2 mok1, Mokinys2 mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean
//bool Pazimys(Mokinys2 mok1, Mokinys2 mok2) { return (mok1.rez < mok2.rez); };	//rikiavimo boolean

void RikVarPav(deque<Mokinys2>& mok, char rus)
{
	//if (rus == 'p')
	//	sort(mok.begin(), mok.end(), Pav);
	//if (rus == 'v')
	//	sort(mok.begin(), mok.end(), Var);
}

void SRSmegNemk(deque<Mokinys2>& mok, int kiek, deque<Mokinys2>& Smegenines, deque<Mokinys2>& Nemoksos)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	//sort(mok.begin(), mok.end(), Pazimys);
	for (deque<Mokinys2>::iterator it=mok.begin(); it != mok.end(); it++)
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