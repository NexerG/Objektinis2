#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using std::sort;

void rikiavimas(vector<Mokinys>& mok, int ciklas);
void RikVarPav(vector<Mokinys>& mok, char rus, int ciklas);
vector<Mokinys> SRSmeg(vector<Mokinys>& mok, int kiek);	//studentu su vidurkiais daugiau negu 5 isrinkimas
vector<Mokinys> SRNemk(vector<Mokinys>& mok, int kiek);	//studentu su vidurkiais maziau negu 5 isrinkimas