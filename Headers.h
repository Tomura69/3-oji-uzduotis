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

bool Patikra (std::string a);
void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav);
void Skaitymas (int t, std::list<duom>& Duomenys);
void Generavimas (int test);
void Rusiavimas (std::list<duom>& Duomenys, std::list<duom>& Minksti);
void Skaiciavimai (duom& duomenys, int kas, std::vector<int>& Med, int sum, int egz);
void Irasymas (std::list<duom>& Minksti, std::list<duom>& Duomenys);