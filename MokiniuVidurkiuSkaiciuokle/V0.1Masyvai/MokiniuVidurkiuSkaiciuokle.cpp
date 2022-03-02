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
	string* vardas;
	string* pavarde;
	int** paz;
	int* egz;
	int* kiek;
	double rezult = 0;
};

void ivestis(Mokinys& mok, int amount);
void isvestis(Mokinys& mok, int amount);
double skaiciavimas(double a, Mokinys& mok, int amount);
double SkVid(Mokinys& mok, int amount);
void rikiavimas(Mokinys& mok, int amount);
double SkMed(Mokinys& mok, int amount);
void NDpazymiuIvestis(Mokinys& mok, int amout);
Mokinys Dinam(Mokinys& mok, int amount);

int main()
{
	char Status='t';
	int amount = 0;
	Mokinys Mok;

	while (Status == 't')
	{
		//Dinam(Mok, amount);
		ivestis(Mok, amount);
		rikiavimas(Mok, amount);
		cout << "Dar vieno mokinio vidurkis?[t/n]";
		cin >> Status;
		amount++;
	}
	isvestis(Mok,amount);
}

Mokinys Dinam(Mokinys& mok, int amount)
{
	Mokinys mk;
	amount++;
	mk.paz = new int* [amount+1];
	mk.vardas = new string[amount+1];
	mk.pavarde = new string[amount+1];
	mk.kiek = new int[amount+1];
	mk.egz = new int[amount+1];

	for (int i = 0; i < amount; i++)
	{
		mk.vardas[i] = mok.vardas[i];
		mk.pavarde[i] = mok.pavarde[i];
		mk.paz[i] = mok.paz[i];
		mk.egz[i] = mok.egz[i];
		mk.kiek[i] = mok.kiek[i];
	}
	return mk;
}

void ivestis(Mokinys& mok, int amount)
{
	if (amount == 0)
	{
		mok.paz = new int* [amount+1];
		mok.vardas = new string[amount+1];
		mok.pavarde = new string[amount+1];
		mok.kiek = new int[amount+1];
		mok.egz = new int[amount+1];
	}
	cout << "Iveskite mokinio varda\n";
	cin >> mok.vardas[amount];
	cout << "Iveskite mokinio pavarde\n";
	cin >> mok.pavarde[amount];
	cout << "Iveskite pazymiu kieki\n";
	cin >> mok.kiek[amount];

	mok=Dinam(mok, amount);
	mok.paz[amount] = new int[mok.kiek[amount]];

	srand(std::time(NULL));
	//namu darbu pazimiu generavimas
	for (int i = 0; i < mok.kiek[amount]; i++)
	{
		mok.paz[amount][i] = rand() % 10 + 1;
		//cin >> mok.paz[amount][i]<<endl;
		//if (mok.paz[amount][i] > 10 || mok.paz[amount][i]<1)
		//{
		//	cout << "Blogas pazymys, veskite is naujo [1;10]\n";
		//	i--;
		//}
		//cout<<mok.paz[amount][i]= rand() %10 + 1; //debug
	}

	//cout << "Iveskite egzamino pazymi [1;10]\n";
	while (mok.egz[amount] < 0 || mok.egz[amount] > 10)
	{
		mok.egz[amount] = rand() % 10 + 1;
		//cout << mok.egz[amount]<<endl; //debug
	}
}

void isvestis(Mokinys& mok, int amount)
{
	cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << mok.vardas[i] << setw(10) << mok.pavarde[i] << setw(15) << fixed << setprecision(2) << SkVid(mok,i) << setw(15) << fixed << setprecision(2) << SkMed(mok, i) << endl;
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
				temp = mok.paz[amount][i];
				mok.paz[amount][i] = mok.paz[amount][j];
				mok.paz[amount][j] = temp;
			}
		}
}

double SkVid(Mokinys& mok, int amount)
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

double SkMed(Mokinys& mok, int amount)
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