#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <ctype.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <chrono>
#include <iterator>
#include <stdlib.h>
#include <array>
#include <random>
#include <list>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <deque>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

struct duom
{
    std::string var, pav;
    double galutinis, mediana, galmed;
};

typedef std::list<duom> Tipas;

bool Patikra (std::string a);
void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav);
void Skaitymas (int t, Tipas& Duomenys);
void Generavimas (int test);
void Rusiavimas (Tipas& Duomenys, Tipas& Minksti);
void Skaiciavimai (duom& duomenys, int kas, std::vector<int>& Med, int sum, int egz);
void Irasymas (Tipas& Minksti, Tipas& Duomenys);