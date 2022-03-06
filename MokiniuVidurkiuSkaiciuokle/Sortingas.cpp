#include "Sortingas.h"

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