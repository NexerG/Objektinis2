#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <deque>

using std::deque;
using std::sort;

void RikVarPav(vector<Mokinys>& mok, char rus);
void SRSmegNemk(vector<Mokinys>& mok, int kiek, vector<Mokinys>& Smegenines, vector<Mokinys>& Nemoksos);	//studentu su vidurkiais daugiau negu 5 isrinkimas
