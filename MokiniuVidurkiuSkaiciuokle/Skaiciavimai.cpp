#include "Skaiciavimai.h"

double SkVid(vector<Mokinys>& mok, int ciklas, int kiek)
{
	double sum = 0, vid;								//pazymiu suma, vidurkis
	for (int i = 0; i < kiek; i++)
	{
		sum += mok[ciklas].paz[i];
	}
	vid = sum / kiek;
	mok[ciklas].rez = skaiciavimas(vid, mok, ciklas);
	return mok[ciklas].rez;
}

double skaiciavimas(double paz, std::vector<Mokinys>& mok, int ciklas)
{
	mok[ciklas].rez = 0.4 * paz + 0.6 * mok[ciklas].egz;
	return mok[ciklas].rez;
}

double SkMed(std::vector<Mokinys>& mok, int ciklas, int kiek)
{
	if (kiek % 2 == 0)
	{
		double Med; //kintamasis skirtas laikyti apskaiciuota mediana
		Med = ((mok[ciklas].paz[kiek / 2] + mok[ciklas].paz[kiek / 2 - 1]) / 2.0);
		mok[ciklas].rez = skaiciavimas(Med, mok, ciklas);
		return mok[ciklas].rez;
	}
	else
	{
		mok[ciklas].rez = skaiciavimas(mok[ciklas].paz[kiek / 2], mok, ciklas);
		return mok[ciklas].rez;
	}
}