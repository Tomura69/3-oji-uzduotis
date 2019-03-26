#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <array>

using std::cout;
using std::cin;
using std::endl;

struct duom
{
    std::string var, pav;
    double galutinis, mediana, galmed;
};

bool Patikra (std::string a);
void Skaitymas (int & m, std::vector<duom>& Duomenys, int & didvar, int & didpav);