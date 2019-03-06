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
#include <algorithm>
#include <cmath>
#include <stdio.h>
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
void Skaitymas (int t, int & m, std::vector<duom>& Duomenys);
void Generavimas (int test);
void Rusiavimas (int & m, std::vector<duom>& Duomenys);
void Skaiciavimai (std::vector<duom>& Duomenys, int m, int kas, int Med[], int sum, int egz);