#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <deque>

using std::deque;
using std::sort;

void RikVarPav(list<Mokinys>& mok, char rus);
void SRSmegNemk(list<Mokinys>& mok, list<Mokinys>& Smegenines, list<Mokinys>& Nemoksos);	//studentu su vidurkiais daugiau negu 5 isrinkimas
