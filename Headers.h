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

bool Patikra (std::string a);
void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav);
void Skaitymas (int t, int & m, std::deque<duom>& Duomenys);
void Generavimas (int test);
void Rusiavimas (int & m, std::deque<duom>& Duomenys, std::deque<duom>& Minksti, std::deque<duom>& Stiprus);
void Skaiciavimai (std::deque<duom>& Duomenys, int m, int kas, std::deque<int>& Med, int sum, int egz);
void Irasymas (std::deque<duom>& Minksti, std::deque<duom>& Stiprus);