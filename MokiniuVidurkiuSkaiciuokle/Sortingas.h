#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <deque>

using std::deque;
using std::sort;

void rikiavimas(deque<Mokinys>& mok, int ciklas);
void RikVarPav(deque<Mokinys>& mok, char rus, int ciklas);
void SRSmegNemk(deque<Mokinys>& mok, int kiek, deque<Mokinys>& Smegenines, deque<Mokinys>& Nemoksos);	//studentu su vidurkiais daugiau negu 5 isrinkimas
