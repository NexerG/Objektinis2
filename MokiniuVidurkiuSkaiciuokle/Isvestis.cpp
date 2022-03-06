#include "Isvestis.h"

void isvestis(std::vector<Mokinys>& mok, int ciklas, int kiek)
{
	std::stringstream X;		//kintamasis isvedimui
	cout << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < ciklas; i++)
	{
		X << mok[i].vardas << setw(20) << right << mok[i].pavarde
			<< setw(20) << right << fixed << setprecision(2) << SkVid(mok, i, kiek)
			<< setw(15) << right << fixed << setprecision(2) << SkMed(mok, i, kiek) << endl;
		string x = X.str();
		cout << x;
	}
}