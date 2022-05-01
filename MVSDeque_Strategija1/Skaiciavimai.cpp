#include "Skaiciavimai.h"

double SkVid(Mokinys2 &mok)
{
	double sum = 0, vid;					//pazymiu suma, vidurkis
	for (deque<int>::iterator vit = mok.paz.begin(); vit != mok.paz.end(); vit++)
	{
		sum += (double)*vit;
		//sum += mok[ciklas].paz[i];
	}
	vid = sum / mok.paz.size();
	mok.rez = skaiciavimas(vid, mok);
	return mok.rez;
}

double skaiciavimas(double paz, Mokinys2& mok)
{
	mok.rez = 0.4 * paz + 0.6 * mok.egz;
	return mok.rez;
}