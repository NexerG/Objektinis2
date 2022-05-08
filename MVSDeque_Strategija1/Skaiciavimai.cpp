#include "Skaiciavimai.h"

double SkVid(Mokinys2& mok)
{
	double sum = 0, vid;					//pazymiu suma, vidurkis
	deque<int> dummy= mok.getpazymiai();
	for (deque<int>::iterator vit = dummy.begin(); vit != dummy.end(); vit++)
	{
		sum += (double)*vit;
		//sum += mok[ciklas].paz[i];
	}
	vid = sum / mok.getpazymiai().size();
	mok.setRez(skaiciavimas(vid, mok));
	return mok.getrezultatas();
}

double skaiciavimas(double paz, Mokinys2 mok)
{
	double dummy;
	dummy = 0.4 * paz + 0.6 * mok.getegz();
	mok.setRez(dummy);
	return mok.getrezultatas();
}