#include "Ivestis.h"
#include "Mokinys.h"
#include "MokiniuVidurkiuSkaiciuokle.h"
#include "Sortingas.h"
#include "Isvestis.h"
#include <chrono>

using namespace std::chrono;

int main()
{
	int gener,ranka;
	cout << "ar generuoti failus? (0/1)";
	cin >> gener;
	cout << "rusiuoti mokinius pagal pavardes? ar pagal vardus? (p/v)";
	char rus = 'n';		//rusiavimo kintamasis
	cin >> rus;
	cout << "ar norite imti generuotus mokinius (1) ar norite juos paimti is failo (2)?";
	cin >> ranka;
	if (gener == 1)
	{
		int StudSkc = 100;
		for (int i = 0; i < 5; i++)
		{
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
					Israsymas << (rand() % 10) + 1 << " ";
				}
				Israsymas << endl;
				generacija << Israsymas.str();
			}
			generacija.close();
		}
	}
	deque<Mokinys> Smegenines;	//Geruciu vektorius
	deque<Mokinys> Nemoksos;	//nemoksu vektorius
	clock_t ProgStart, ProgEnd;	//programos laiko matavimo kintamieji
	clock_t start, end;
	//clock_t start, end;			//segmentu laiko matavimo kintamieji
	int kiek = 0;
	char Status = 't';			//Statuso kintamasis skirtas suziureti kiek bus mokiniu
	int ciklas = 0;				//kintamasis kuris nusako kurioje vietoje vektoriaus esame
	deque<Mokinys> Mok;
	ifstream fs("kursiokai.txt", ifstream::in);

	ProgStart = clock();
	if (ranka == 1)
	{
		start = clock();
		int dummy = 1;
		//failu generacija
		for (int i = 0; i < 5; i++)
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
			if (rus == 'p')
			{
				RikVarPav(Mok, rus, ciklas);
			}
			else if (rus == 'v')
			{
				RikVarPav(Mok, rus, ciklas);
			}
			start = clock();
			SRSmegNemk(Mok, kiek, Smegenines, Nemoksos);
			end = clock();
			cout << "Failo su " << Smegenines.size() + Nemoksos.size() << " irasu dalijimo i dvi dalis laikas, panaikinant pradini vektoriu: "
				<< ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;

			stringstream Isved;
			Isved << "Smegenines" << i << ".txt";
			ofstream ofsGeri(Isved.str());
			Isved.str("");
			Isved << "Nemoksos" << i << ".txt";
			ofstream ofsBlogi(Isved.str());

			isvestis(Smegenines, Nemoksos, ciklas, kiek, ofsGeri, ofsBlogi);		//f-ja skirta isvedimui
			ciklas = 0;
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
		if (rus == 'p')
		{
			RikVarPav(Mok, rus, ciklas);
		}
		else if (rus == 'v')
		{
			RikVarPav(Mok, rus, ciklas);
		}
		start = clock();
		SRSmegNemk(Mok, kiek, Smegenines, Nemoksos);
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
	cout << "Programos veikimo laikas: " << ((float)ProgEnd - ProgStart) / CLOCKS_PER_SEC << "s" << endl;
}