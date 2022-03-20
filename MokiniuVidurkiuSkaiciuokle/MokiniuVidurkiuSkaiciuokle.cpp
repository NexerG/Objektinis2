#include "Ivestis.h"
#include "Mokinys.h"
#include "MokiniuVidurkiuSkaiciuokle.h"
#include "Sortingas.h"
#include "Isvestis.h"
#include <chrono>

int main()
{
	clock_t ProgStart,ProgEnd;	//programos laiko matavimo kintamieji
	ProgStart = clock();
	clock_t start, end;			//segmentu laiko matavimo kintamieji
	int kiek=0;
	int ranka = 0;
	char Status = 't';			//Statuso kintamasis skirtas suziureti kiek bus mokiniu
	int ciklas = -1;				//kintamasis kuris nusako kurioje vietoje vektoriaus esame
	vector<Mokinys> Mok;
	cout << "ar norite ivesti mokinius ranka (1) ar norite juos paimti is failo (2)?";
	ifstream fs("kursiokai.txt", ifstream::in);
	cin >> ranka;
	if (ranka == 1)
	{
		while (Status == 't')		//ciklas skirtas mokiniu funkcijoms atlikti
		{
			ivestis(Mok, ciklas, ranka, fs, kiek);
			rikiavimas(Mok, ciklas);
			cout << "Dar vieno mokinio vidurkis?[t/n]";
			cin >> Status;
			ciklas++;
		}
	}
	if (ranka == 2)
	{
		start = clock();
		ivestis(Mok, ciklas, ranka, fs, kiek);
		end = clock();
		cout << "Failo su "<< Mok.size()<<" elementu nuskaitymo laikas: "<<((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
		for (int i = 0; i < ciklas; i++)
			rikiavimas(Mok, i);
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
	start = clock();
	vector<Mokinys> Smegenines = SRSmeg(Mok,kiek);
	vector<Mokinys> Nemoksos = SRNemk(Mok, kiek);
	end = clock();
	cout << "Failo su " << Smegenines.size() + Nemoksos.size() << " irasu dalijimo i dvi dalis laikas, panaikinant pradini vektoriu: " 
		<< ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
	isvestis(Smegenines,Nemoksos, ciklas, kiek);		//f-ja skirta isvedimui
	ProgEnd = clock();
	cout << "Programos veikimo laikas: " << ((float)end - start) / CLOCKS_PER_SEC << "s" << endl;
}