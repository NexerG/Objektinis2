#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::noskipws;
using std::sort;

//constanta nusakanti po kiek pazimiu turi mokiniai
int kiek=0;

struct Mokinys
{
	string vardas, pavarde;
	vector<int> paz;
	int egz;				//kintamasis skirtas medianai ir vidurkiui laikyti
	double rez = 0;
};

void ivestis(std::vector<Mokinys>& mok, int ciklas, int ranka, ifstream &fs);			//duomenu ivedimas
void isvestis(std::vector<Mokinys>& mok, int ciklas);					//isvedimas
double skaiciavimas(double a, std::vector<Mokinys>& mok, int ciklas);	//galutinio pazimio radimas
double SkVid(std::vector<Mokinys>& mok, int ciklas);					//vidurkio skaiciavimas
void rikiavimas(std::vector<Mokinys>& mok, int ciklas);					//rikiavimas
double SkMed(std::vector<Mokinys>& mok, int ciklas);					//medianos skaiciavimas
void RikVarPav(std::vector<Mokinys>& mok, char rus, int ciklas);
bool Var(Mokinys mok1, Mokinys mok2) { return (mok1.vardas < mok2.vardas); };
bool Pav(Mokinys mok1, Mokinys mok2) { return (mok1.pavarde < mok2.pavarde); };


int main()
{
	int ranka = 0;
	char Status = 't';			//Statuso kintamasis skirtas suziureti kiek bus mokiniu
	int ciklas = 0;				//kintamasis kuris nusako kurioje vietoje vektoriaus esame
	vector<Mokinys> Mok;
	cout << "ar norite ivesti mokinius ranka (1) ar norite juos paimti is failo (2)?";
	ifstream fs("kursiokai.txt", ifstream::in);
	cin >> ranka;
	if (ranka == 1)
	{
		while (Status == 't')		//ciklas skirtas mokiniu funkcijoms atlikti
		{
			ivestis(Mok, ciklas, ranka, fs);
			rikiavimas(Mok, ciklas);
			cout << "Dar vieno mokinio vidurkis?[t/n]";
			cin >> Status;
			ciklas++;
		}
	}
	if (ranka == 2)
	{
		while (!fs.eof())
		{
			ivestis(Mok, ciklas, ranka, fs);
			rikiavimas(Mok, ciklas);
			ciklas++;
		}
		fs.close();
	}

	cout << "rusiuoti mokinius pagal pavardes? ar pagal vardus? (p/v)";
	char rus = 'n';		//rusiavimo kintamasis
	cin >> rus;
	if (rus == 'p')
	{
		RikVarPav(Mok,rus,ciklas);
	}
	else if (rus == 'v')
	{
		RikVarPav(Mok, rus,ciklas);
	}
	//else cout << "ivedete ne toki simboli, veskite is naujo";
	isvestis(Mok, ciklas);		//f-ja skirta isvedimui
}

void ivestis(std::vector<Mokinys>& mok, int ciklas, int ranka, ifstream& fs)
{
	mok.push_back(Mokinys());
	if (ranka == 1)											//ivestis ranka
	{
		cout << "Iveskite mokinio varda\n";
		mok.push_back(Mokinys());
		cin >> mok[ciklas].vardas;
		cout << "Iveskite mokinio pavarde\n";
		cin >> mok[ciklas].pavarde;
	}

	if (ranka == 2)											//ivestis is failo
	{
		if (ciklas == 0)
		{
			fs.ignore(999, '\n');
		}
		fs >> mok[ciklas].vardas >> mok[ciklas].pavarde;
	}

	srand(std::time(NULL));

	//namu darbu pazimiu generavimas
	char status;
	int vieta = 0;
	mok[ciklas].paz.push_back(vieta);
	while (fs >> status)
	{
		//cout << status << endl;
		if (status != '\n' && status != ' ' && status <= 57)
		{
			if (status != '0')
			{
				mok[ciklas].paz.push_back(vieta);
				mok[ciklas].paz[vieta] = std::stoi(&status);
				//cout << mok[ciklas].paz[vieta]<<endl;
				vieta++;
			}
			else
			{
				mok[ciklas].paz[vieta-1] = mok[ciklas].paz[vieta-1] * 10;
			}
		}
		else if (status > 57) break;
	}
	kiek = vieta-1;
	//cout << endl << vieta;
	mok[ciklas].egz = mok[ciklas].paz[vieta-1];
}

void isvestis(std::vector<Mokinys>& mok, int ciklas)
{
	std::stringstream X;		//kintamasis isvedimui
	cout << "Vardas" << setw(10) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < ciklas; i++)
	{
		cout << mok[i].vardas << setw(20) << right << mok[i].pavarde << setw(20) << right << fixed << setprecision(2) << SkVid(mok, i) << setw(15) << right << fixed << setprecision(2) << SkMed(mok, i) << endl;
		//cout << X;
	}
}

void rikiavimas(std::vector<Mokinys>& mok, int ciklas)
{
	int temp;
	sort(mok[ciklas].paz.begin(), mok[ciklas].paz.end());
}

void RikVarPav(std::vector<Mokinys>& mok, char rus, int ciklas)
{
	if (rus == 'p')
		sort(mok.begin(), mok.end(),Pav);
	if (rus == 'v')
		sort(mok.begin(), mok.end(), Var);
}

double SkVid(std::vector<Mokinys>& mok, int ciklas)
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