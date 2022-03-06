#include "Ivestis.h"
#include "Mokinys.h"
#include "MokiniuVidurkiuSkaiciuokle.h"
#include "Sortingas.h"
#include "Isvestis.h"

int main()
{
	int kiek=0;
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
			ivestis(Mok, ciklas, ranka, fs, kiek);
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
			ivestis(Mok, ciklas, ranka, fs, kiek);
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
	isvestis(Mok, ciklas,kiek);		//f-ja skirta isvedimui
}