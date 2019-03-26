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
#include <stdlib.h>
#include <array>
#include <random>
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

typedef std::deque<duom> Tipas;

bool Patikra (std::string a);
void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav);
void Skaitymas (int t, int & m, Tipas& Duomenys);
void Generavimas (int test);
bool Skola(const duom & i);
Tipas Rusiavimas (Tipas& Duomenys);
void Skaiciavimai (Tipas& Duomenys, int m, int kas, std::vector<int>& Med, int sum, int egz);
void Irasymas (Tipas& Minksti, Tipas& Duomenys);