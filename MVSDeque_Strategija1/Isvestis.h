#pragma once
#include "Mokinys.h"
#include "Skaiciavimai.h"
#include <fstream>
#include "Mok.h"

using std::ofstream;
using std::cout;
using std::setw;
using std::right;
using std::left;
using std::setprecision;
using std::fixed;
using std::endl;
using std::stringstream;

void isvestis(deque<Mokinys2>& Smegenines, deque<Mokinys2>& Nemoksos, int ciklas, int kiek, ofstream& ofsGeri, ofstream& ofsBlogi);