#include "Ivestis.h"
#include "Mokinys.h"
#include "MokiniuVidurkiuSkaiciuokle.h"
#include "Sortingas.h"
#include "Isvestis.h"
#include <chrono>

int main()
{
	vector<Mokinys> Smegenines;	//Geruciu vektorius
	vector<Mokinys> Nemoksos;	//nemoksu vektorius
	clock_t ProgStart, ProgEnd;	//programos laiko matavimo kintamieji
	ProgStart = clock();
	clock_t start, end;			//segmentu laiko matavimo kintamieji
	int kiek = 0;
	int ranka = 0;
	char Status = 't';			//Statuso kintamasis skirtas suziureti kiek bus mokiniu
	int ciklas = -1;				//kintamasis kuris nusako kurioje vietoje vektoriaus esame
	vector<Mokinys> Mok;
	cout << "ar norite generuoti (prasideda nuo 1000) mokinius (1) ar norite juos paimti is failo (2)?";
	ifstream fs("kursiokai.txt", ifstream::in);
	cin >> ranka;
	if (ranka == 1)
	{
		start = clock();
		int StudSkc = 100;
		int dummy = 1;
		int KFailu = 0;		//kintamasis skirtas laikyti kiek failu sukurta
		//failu generacija
		for (int i = 0; i < i + 2; i++)
		{
			KFailu++;
			StudSkc = StudSkc * 10;
			stringstream KursSaras;//kursioku sarasas
			KursSaras << "kursiokai" << i << ".txt";
			ofstream generacija(KursSaras.str());
			for (int j = 0; j < StudSkc; j++)
			{
				stringstream Vardas, Pavard, Israsymas;
				Vardas << "Vardas" << j << " ";
				Pavard << "Pavarde" << j << " ";
				Israsymas << Vardas.str() << Pavard.str();
				for (int z = 0; z < 15; z++)
				{
					srand(time(NULL));
					Israsymas << rand() % 10 + 1 << " ";
				}
				Israsymas << endl;
				generacija << Israsymas.str();
			}
			generacija.close();
			end = clock();
			cout << "Failu generavimas su " << StudSkc << " studentais uztruko: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
			cout << "Ar generuoti " << StudSkc * 10 << " studentu informacija? (0/1)" << endl;
			cin >> dummy;
			if (!dummy)
				break;
		}
		for (int i = 0; i < KFailu; i++)
		{
			stringstream KursSaras;//bus naudojamas kursioku sarasas
			KursSaras << "kursiokai" << i << ".txt";
			ifstream fsb(KursSaras.str());
			start = clock();
			ivestis(Mok, ciklas, ranka, fsb, kiek);
			end = clock();
			cout << "Failo su " << Mok.size() << " elementu nuskaitymo laikas: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
			for (int j = 0; j < ciklas; j++)
				rikiavimas(Mok, j);
			fsb.close();

			cout << "rusiuoti mokinius pagal pavardes? ar pagal vardus? (p/v)";
			char rus = 'n';		//rusiavimo kintamasis
			cin >> rus;
			if (rus == 'p')
			{
				RikVarPav(Mok, rus, ciklas);
			}
			else if (rus == 'v')
			{
				RikVarPav(Mok, rus, ciklas);
			}

			stringstream Isved;
			Isved << "Smegenines" << i << ".txt";
			ofstream ofsGeri(Isved.str());
			Isved.str("");
			Isved << "Nemoksos" << i << ".txt";
			ofstream ofsBlogi(Isved.str());
			Smegenines = SRSmeg(Mok, kiek);
			Nemoksos = SRNemk(Mok, kiek);
			isvestis(Smegenines, Nemoksos, ciklas, kiek, ofsGeri, ofsBlogi);		//f-ja skirta isvedimui
			ciklas = -1;
			Smegenines.clear();
			Nemoksos.clear();
			ofsGeri.close();
			ofsBlogi.close();
		}
	}
	if (ranka == 2)
	{
		start = clock();
		ivestis(Mok, ciklas, ranka, fs, kiek);
		end = clock();
		cout << "Failo su " << Mok.size() << " elementu nuskaitymo laikas: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
		for (int i = 0; i < ciklas; i++)
			rikiavimas(Mok, i);
		fs.close();

		cout << "rusiuoti mokinius pagal pavardes? ar pagal vardus? (p/v)";
		char rus = 'n';		//rusiavimo kintamasis
		cin >> rus;
		if (rus == 'p')
		{
			RikVarPav(Mok, rus, ciklas);
		}
		else if (rus == 'v')
		{
			RikVarPav(Mok, rus, ciklas);
		}

		start = clock();
		Smegenines = SRSmeg(Mok, kiek);		//geruciu ir bloguciu atskyrimas nuskaitant faila
		Nemoksos = SRNemk(Mok, kiek);		//geruciu ir bloguciu atskyrimas nuskaitant faila
		end = clock();
		cout << "Failo su " << Smegenines.size() + Nemoksos.size() << " irasu dalijimo i dvi dalis laikas, panaikinant pradini vektoriu: "
			<< ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;

		ofstream ofsGeri("Smegenines.txt");
		ofstream ofsBlogi("Nemoksos.txt");
		isvestis(Smegenines, Nemoksos, ciklas, kiek, ofsGeri, ofsBlogi);		//f-ja skirta isvedimui
		ofsBlogi.close();
		ofsGeri.close();
	}
	ProgEnd = clock();
	cout << "Programos veikimo laikas: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
}