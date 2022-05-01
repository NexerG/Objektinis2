#include "Isvestis.h"
#include <chrono>

void isvestis(deque<Mokinys> Smegenines, deque<Mokinys> Nemoksos, int ciklas, int kiek, ofstream& ofsGeri, ofstream& ofsBlogi)
{
	ofsGeri << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	ofsGeri << "----------------------------------------------------------" << endl;
	for (deque<Mokinys>::iterator it= Smegenines.begin();it!=Smegenines.end(); it++)
	{
		ofsGeri << it->vardas << setw(20) << right << it->pavarde
			<< setw(20) << right << fixed << setprecision(2) << SkVid(*it) << endl;
	}

	ofsBlogi << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	ofsBlogi << "----------------------------------------------------------" << endl;
	for (deque<Mokinys>::iterator it = Nemoksos.begin(); it != Nemoksos.end(); it++)
	{
		ofsBlogi << it->vardas << setw(20) << right << it->pavarde
			<< setw(20) << right << fixed << setprecision(2) << SkVid(*it)<<endl;
	}
	//cout << Nemoksos.size() << endl << Smegenines.size();		//debug
}