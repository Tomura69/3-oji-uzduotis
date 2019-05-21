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
Pridėta "rule of three". Pridėta daug funkcijų.
### :computer:[v1.5](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v1.5)
Sukurta bas klasė Human.
### :computer:[v2](https://github.com/Tomura69/3-oji-uzduotis/releases/tag/v2)
Pridėtas doxygen ir unit testas.
