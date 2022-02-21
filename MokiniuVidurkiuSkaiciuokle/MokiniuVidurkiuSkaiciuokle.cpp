#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

struct Mokinys
{
	string vardas[30], pavarde[30];
	int** paz;
	int egz[30], kiek[30];
	double rezult = 0;
};

void ivestis(Mokinys& mok, int amount);
void isvestis(Mokinys& mok, int amount);
double skaiciavimas(double a, Mokinys& mok, int amount);
double skaiciavimasVid(Mokinys& mok, int amount);
void rikiavimas(Mokinys& mok, int amount);
double skaiciavimasMed(Mokinys& mok, int amount);
void NDpazymiuIvestis(Mokinys& mok, int amout);

int main()
{
	char Status='y';
	int amount = 0;
	Mokinys Mok;

	while (Status == 't')
	{
		ivestis(Mok, amount);
		rikiavimas(Mok, amount);
		cout << "Dar vieno mokinio vidurkis?[t/n]";
		cin >> Status;
		amount++;
	}
	isvestis(Mok,amount);
}

void ivestis(Mokinys& mok, int amount)
{
	const int c = 30;
	cout << "Iveskite mokinio varda\n";
	cin >> mok.vardas[amount];
	cout << "Iveskite mokinio pavarde\n";
	cin >> mok.pavarde[amount];
	cout << "Iveskite pazymiu kieki\n";
	cin >> mok.kiek[amount];

	if (amount == 0)
		mok.paz = new int* [(mok.kiek[amount] * 2)];
	mok.paz[amount] = new int[mok.kiek[amount]];

	srand(std::time(NULL));

	for (int i = 0; i < mok.kiek[amount]; i++)
	{
		mok.paz[amount][i] = rand() % 10 + 1;
		if (mok.paz[amount][i] > 10 || mok.paz[amount][i]<1)
		{
			cout << "Blogas pazymys, veskite is naujo [1;10]\n";
			i--;
		}
	}
	NDpazymiuIvestis(mok,amount);

	cout << "Iveskite egzamino pazymi [1;10]\n";
	while (mok.egz[amount] < 0 || mok.egz[amount] > 10)
	{
		cin >> mok.egz[amount];
	}
}

void isvestis(Mokinys& mok, int amount)
{
	cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << mok.vardas[i] << setw(10) << mok.pavarde[i] << setw(15) << fixed << setprecision(2) << skaiciavimasVid(mok,i) << setw(15) << fixed << setprecision(2) << skaiciavimasMed(mok, i) << endl;
	}
}

void rikiavimas(Mokinys& mok, int amount)
{
	int temp;
	for (int i = 0; i < mok.kiek[amount]; i++)
		for (int j = i + 1; j < mok.kiek[amount]; j++)
		{
			if (mok.paz[i] > mok.paz[j])
			{
				temp = mok.paz[i][amount];
				mok.paz[i][amount] = mok.paz[j][amount];
				mok.paz[j][amount] = temp;
			}
		}
}

double skaiciavimasVid(Mokinys& mok, int amount)
{
	double sum = 0, vid;					//pazymiu suma, vidurkis
	for (int i = 0; i < mok.kiek[amount]; i++)
	{
		sum += mok.paz[amount][i];
	}
	vid = sum / mok.kiek[amount];
	mok.rezult = skaiciavimas(vid, mok, amount);
	return mok.rezult;
}

double skaiciavimas(double paz, Mokinys& mok, int amount)
{
	mok.rezult = 0.4 * paz + 0.6 * mok.egz[amount];
	return mok.rezult;
}

double skaiciavimasMed(Mokinys& mok, int amount)
{
	if (mok.kiek[amount] % 2 == 0)
	{
		double laikMed;
		laikMed = ((mok.paz[amount][mok.kiek[amount] / 2] + mok.paz[amount][mok.kiek[amount] / 2 - 1]) / 2.0);
		mok.rezult = skaiciavimas(laikMed, mok, amount);
		return mok.rezult;
	}
	else
	{
		mok.rezult = skaiciavimas(mok.paz[amount][mok.kiek[amount] / 2], mok, amount);
		return mok.rezult;
	}
}

void NDpazymiuIvestis(Mokinys& mok,int amount)
{
	char status;
	int ciklas = mok.kiek[amount];
	while (ciklas<(mok.kiek[amount])*2)
	{
		cout << "Ar norite ivesti namu darbu pazymi? (t/n)\n";
		cin >> status;
		if (status == 't')
		{
			cin >> mok.paz[amount][ciklas];
			ciklas++;
			mok.kiek[amount] = ciklas;
		}
		else
			break;
	}
}