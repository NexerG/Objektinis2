#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;


//constanta nusakanti po kiek pazimiu turi mokiniai
const int kiek=8;

struct Mokinys
{
	string vardas, pavarde;
	int paz[kiek];
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};

void ivestis(std::vector<Mokinys>& mok, int ciklas);					//duomenu ivedimas
void isvestis(std::vector<Mokinys>& mok, int ciklas);					//isvedimas
double skaiciavimas(double a, std::vector<Mokinys>& mok, int ciklas);	//galutinio pazimio radimas
double SkVid(std::vector<Mokinys>& mok, int ciklas);					//vidurkio skaiciavimas
void rikiavimas(std::vector<Mokinys>& mok, int ciklas);					//rikiavimas
double SkMed(std::vector<Mokinys>& mok, int ciklas);					//medianos skaiciavimas

int main()
{
	char Status = 't';			//Statuso kintamasis skirtas suziureti kiek bus mokiniu
	int ciklas = 0;				//kintamasis kuris nusako kurioje vietoje vektoriaus esame
	std::vector<Mokinys> Mok;
	while (Status == 't')		//ciklas skirtas mokiniu funkcijoms atlikti
	{
		ivestis(Mok,ciklas);
		rikiavimas(Mok, ciklas);
		cout << "Dar vieno mokinio vidurkis?[t/n]";
		cin >> Status;
		ciklas++;
	}
	isvestis(Mok, ciklas);		//f-ja skirta isvedimui
}

void ivestis(std::vector<Mokinys>& mok, int ciklas)
{
	cout << "Iveskite mokinio varda\n";
	mok.push_back(Mokinys());
	cin >> mok[ciklas].vardas;
	cout << "Iveskite mokinio pavarde\n";
	cin >> mok[ciklas].pavarde;

	srand(std::time(NULL));

	//namu darbu pazimiu generavimas
	char status;
	cout << "Ar norite ivesti namu darbu pazimi? (t/n)\n";
	int vieta = 0;
	while(vieta<kiek)
	{
		//cout << "Iveskite namu darbu pazimi\n";
		mok[ciklas].paz[vieta] = rand() % 10 + 1;
		//cout << mok[ciklas].paz[vieta] << endl;//debug
		vieta++;
	}

	//egzamino pazymio generavimas
	//cout << "Iveskite egzamino pazimi [1;10]\n";
	mok[ciklas].egz = rand() % 10 + 1;
	//cout << mok[ciklas].egz << endl;//debug
}

void isvestis(std::vector<Mokinys>& mok, int ciklas)
{
	cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < ciklas; i++)
	{
		cout << mok[i].vardas << setw(10) << mok[i].pavarde << setw(15) << fixed << setprecision(2) << SkVid(mok,i) << setw(15) << fixed << setprecision(2) << SkMed(mok, i) << endl;
	}
}

void rikiavimas(std::vector<Mokinys>& mok, int ciklas)
{
	int temp;
	for (int i = 0; i < kiek; i++)
		for (int j = i + 1; j < kiek; j++)
		{
			if (mok[ciklas].paz[i] > mok[ciklas].paz[j])
			{
				temp = mok[ciklas].paz[i];
				mok[ciklas].paz[i] = mok[ciklas].paz[j];
				mok[ciklas].paz[j] = temp;
			}
		}
}

double SkVid(std::vector<Mokinys>& mok, int ciklas)
{
	double sum = 0, vid;					//pazymiu suma, vidurkis
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

double SkMed(std::vector<Mokinys>& mok, int ciklas)
{
	if (kiek % 2 == 0)
	{
		double Med; //kintamasis skirtas laikyti apskaiciuota mediana
		Med = ((mok[ciklas].paz[kiek/ 2] + mok[ciklas].paz[kiek / 2 - 1]) / 2.0);
		mok[ciklas].rez = skaiciavimas(Med, mok, ciklas);
		return mok[ciklas].rez;
	}
	else
	{
		mok[ciklas].rez = skaiciavimas(mok[ciklas].paz[kiek / 2], mok, ciklas);
		return mok[ciklas].rez;
	}
}