# 3-oji-uzduotis
3rd task of obprog
### Paleidimas

Paleidimas: atsisiuntus bet kurio relyso source code failą, reikia atsidaryti konsolę (veikia tik ant mac ir unix os) ir parašyti žodį `make`.Tokiu būdu bus paleista programa. Norint nutraukti programą reikia paspausti `Ctrl` + `C`.

### Versijos:
### :computer:[v1.1](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v1.1)
- Struct
```
10-ies dydzio failo skaitymas uztruko: 0.0004767 sekundziu
100-ies dydzio failo skaitymas uztruko: 0.0004909 sekundziu
1000-ies dydzio failo skaitymas uztruko: 0.003636 sekundziu
10000-ies dydzio failo skaitymas uztruko: 0.0413341 sekundziu
100000-ies dydzio failo skaitymas uztruko: 0.412476 sekundziu
Duomenu isrusiavimas uztruko: 0.0456263 sekundziu
Duomenu isvedimas uztruko: 1.33192 sekundziu
```
- Class
```
10-ies dydzio failo skaitymas uztruko: 0.0004892 sekundziu
100-ies dydzio failo skaitymas uztruko: 0.0008056 sekundziu
1000-ies dydzio failo skaitymas uztruko: 0.0059247 sekundziu
10000-ies dydzio failo skaitymas uztruko: 0.0553212 sekundziu
100000-ies dydzio failo skaitymas uztruko: 0.562614 sekundziu
Duomenu isrusiavimas uztruko: 0.09818 sekundziu
Duomenu isvedimas uztruko: 1.02057 sekundziu
```
Matome, jog su klase failų nuskaitymas ir išrūšiavimas vyksta šiek tiek lėčiau, negu struktūroje, tačiau clasė pranašesnė failų išvedime.
- Struct (02 optimization)
```
10-ies dydzio failo skaitymas uztruko: 0.0004066 sekundziu
100-ies dydzio failo skaitymas uztruko: 0.0004727 sekundziu
1000-ies dydzio failo skaitymas uztruko: 0.0023184 sekundziu
10000-ies dydzio failo skaitymas uztruko: 0.0194655 sekundziu
100000-ies dydzio failo skaitymas uztruko: 0.189917 sekundziu
Duomenu isrusiavimas uztruko: 0.028143 sekundziu
Duomenu isvedimas uztruko: 0.963156 sekundziu
```
Optimizavus struktūrą rezultatai stipriai pasikeitė į gerąją pusę, programa tapo spartesnė.
- Class (02 optimization)
```
```
Klase, su optimizavimu neveikė, nebenuskaitė duomenų.
- Struct (03 optimization)
```
10-ies dydzio failo skaitymas uztruko: 0.0004408 sekundziu
100-ies dydzio failo skaitymas uztruko: 0.0004157 sekundziu
1000-ies dydzio failo skaitymas uztruko: 0.0022738 sekundziu
10000-ies dydzio failo skaitymas uztruko: 0.0195726 sekundziu
100000-ies dydzio failo skaitymas uztruko: 0.179976 sekundziu
Duomenu isrusiavimas uztruko: 0.0284092 sekundziu
Duomenu isvedimas uztruko: 0.95613 sekundziu
```
Naudojant 3 optimizavimo lygį programos veikimas beveik nepasikeitė
- Class (03 optimization)
```
```
Klase, su optimizavimu neveikė, nebenuskaitė duomenų.

### :computer:[v1.2](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v1.2)
Pridėta daug funkcijų:
```cpp
friend std::ostream& operator << (std::ostream& out, const Studentas& Tomas){
  out << Tomas.Vardas() << " " << Tomas.Pavarde() << " " << std::setprecision(3) << Tomas.Vidurkis() << " " << Tomas.MedVid();
  return out;
}
friend bool operator == (const Studentas& Tomas, const Studentas& Tomas1){
  if (Tomas.Vardas() == Tomas1.Vardas() && Tomas.Pavarde() == Tomas1.Pavarde()){
    return 1;
  }
  else{
    return 0;
  }
}
friend bool operator <= (const Studentas& Tomas, int n){
  if (Tomas.Vidurkis() <= n || Tomas.MedVid() <= n){
    return 1;
  }
  else{
    return 0;
  }
}
friend bool operator >= (const Studentas& Tomas, int n){
  if (Tomas.Vidurkis() >= n || Tomas.MedVid() >= n){
    return 1;
  }
  else{
    return 0;
  }
}
friend bool operator > (const Studentas& Tomas, int n){
  if (Tomas.Vidurkis() > n && Tomas.MedVid() > n){
    return 1;
  }
  else{
    return 0;
  }
}
friend bool operator < (const Studentas& Tomas, int n){
  if (Tomas.Vidurkis() < n && Tomas.MedVid() < n){
    return 1;
  }
  else{
    return 0;
  }
}
friend bool operator != (const Studentas& Tomas, int n){
  if (Tomas.Vidurkis() != n && Tomas.MedVid() != n){
    return 1;
  }
  else{
    return 0;
  }
}
```
Ne visos funkcijos yra naudojamos, tačiau kitiem naudotojam gali jų prireikti.

### :computer:[v1.5](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v1.5)
Sukurta base klasė Human:
```cpp
class Human{
    protected:
        std::string var, pav;
        Human () {};
        Human (std::string v, std::string p) : var(v), pav(p) {}
    public:
        void skaitymas_vard (std::string var_, std::string pav_);
        virtual inline std::string Vardas () const {return var;}
        virtual inline std::string Pavarde () const {return pav;}
};
```
Ši bazinė klasė mums leidžia kurti kitas klases, ir jos jau turės minimalų interfeisą.
Taip pat šios bazinės klasės obiektų negalima kurti programoje.

### :computer:[v2](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v2)
Norint paleisti testą, koncolėje reikia suvesti:
`$ sudo apt-get install libcppunit-dev`
Tada programa veiks be problemų ir atliks unit testą.

Pridėtas doxygen ir unit testas:
```cpp
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
    cout << endl;
```
Rezultatas:
```cpp
TestBasicMath::testVidurkis : assertion
TestBasicMath::testMediana : OK
v1.cpp:31:Assertion
Test name: TestBasicMath::testVidurkis
assertion failed
- Expression: 5 < mTestObj->Vidurkis()

Failures !!!
Run: 2   Failure total: 1   Failures: 1   Errors: 0
```
