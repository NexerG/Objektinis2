#include "Sortingas.h"
#include <iomanip>
#include <iostream>

using std::set_difference;

bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };	//rikiavimo boolean
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };	//rikiavimo boolean
bool Pazimys(Mokinys mok1, Mokinys mok2) { return (mok1.rez < mok2.rez); };	//rikiavimo boolean

void RikVarPav(deque<Mokinys>& mok, char rus)
{
	/*if (rus == 'p')
		sort(mok.begin(), mok.end(), Pav);
	if (rus == 'v')
		sort(mok.begin(), mok.end(), Var);*/
}

void SRSmegNemk(deque<Mokinys>& mok, deque<Mokinys>& Smegenines, deque<Mokinys>& Nemoksos)	//studentu su vidurkiais daugiau negu 5 isrinkimas
{
	sort(mok.begin(), mok.end(), Pazimys);
	for (deque<Mokinys>::iterator it = mok.begin(); it != mok.end(); it++)
	{
		if (SkVid(*it) >= 5)
		{
			Smegenines.push_back(*it);		//taip idedama iskarto reiksme
			it = mok.erase(it);
			//mok.remove(*it);
			//mok.pop_back();
		}
		//else
		//{
		//	Nemoksos.push_back(*it);
		//	//mok.pop_back();			
		//}
	}
	//mok.clear();
}