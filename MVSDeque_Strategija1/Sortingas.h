#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <deque>

using std::deque;
using std::sort;

void RikVarPav(deque<Mokinys>& mok, char rus);
void SRSmegNemk(deque<Mokinys>& mok, int kiek, deque<Mokinys>& Smegenines, deque<Mokinys>& Nemoksos);	//studentu su vidurkiais daugiau negu 5 isrinkimas
