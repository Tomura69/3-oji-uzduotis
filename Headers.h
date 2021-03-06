#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <ctype.h>
#include <vector>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
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
#include "classStud.h"


using std::cout;
using std::cin;
using std::endl;

typedef std::vector<Studentas> TipasC;

bool Patikra (std::string a);
void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav);
void Skaitymas (int dydis, int & m, TipasC& Studentai);
void Generavimas (int dydis);
bool Skola(const Studentas & i);
TipasC Rusiavimas (TipasC& Studentai);
void Skaiciavimai (TipasC& Studentai, int m, int kas, int sum, int egz);
void Irasymas (TipasC& Minksti, TipasC& Studentai);