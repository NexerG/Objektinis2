#include "Isvestis.h"

void isvestis(vector<Mokinys> Smegenines, vector<Mokinys> Nemoksos, int ciklas, int kiek)
{
	ofstream ofsGeri("Smegenines.txt");
	ofsGeri << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	ofsGeri << "----------------------------------------------------------" << endl;
	for (int i = 0; i < Smegenines.size(); i++)
	{
		ofsGeri << Smegenines[i].vardas << setw(20) << right << Smegenines[i].pavarde
			<< setw(20) << right << fixed << setprecision(2) << SkVid(Smegenines, i, kiek)
			<< setw(15) << right << fixed << setprecision(2) << SkMed(Smegenines, i, kiek) << endl;
	}	
	ofsGeri.close();

	ofstream ofsBlogi("Nemoksos.txt");
	ofsBlogi << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	ofsBlogi << "----------------------------------------------------------" << endl;
	for (int i = 0; i < Nemoksos.size(); i++)
	{
		ofsBlogi << Nemoksos[i].vardas << setw(20) << right << Nemoksos[i].pavarde
			<< setw(20) << right << fixed << setprecision(2) << SkVid(Nemoksos, i, kiek)
			<< setw(15) << right << fixed << setprecision(2) << SkMed(Nemoksos, i, kiek) << endl;
	}
	//cout << Nemoksos.size() << endl << Smegenines.size();		//debug
	ofsBlogi.close();
}