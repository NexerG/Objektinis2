#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <deque>

using std::deque;
using std::sort;

void RikVarPav(deque<Mokinys2>& mok, char rus);
void SRSmegNemk(deque<Mokinys2>& mok, int kiek, deque<Mokinys2>& Smegenines, deque<Mokinys2>& Nemoksos);	//studentu su vidurkiais daugiau negu 5 isrinkimas
