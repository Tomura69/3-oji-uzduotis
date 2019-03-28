# Atsiskaitymai
Obiektinio programavimo 2 užduotis
### Paleidimas

Paleidimas: atsisiuntus bet kurio relyso source code failą, reikia atsidaryti konsolę (veikia tik ant mac ir unix os) ir parašyti žodį `make`.Tokiu būdu bus paleista programa. 

- Versijose nuo v0.1 galima rašyti `make Run1`, norint paleisti programą su masyvais. Parašius `make Run2`, bus paleista programa, kuri naudoja tik vektorius. 
- Versijose nuo v0.4 ir toliau, galima rašyti `make Clear`, taip bus ištrinti visi .md failai.
- Konsolėje parašius `make Clean`, bus ištrinti buildinimo failai ir `test` failai.
- Versijose v0.5 ir v1 yra po tris failus, kurie daro tą pačią užduotį, tik su skirtingais konteineriais ir matuoja jų veikimo greitį.
- Norint nutraukti programą reikia paspausti `Ctrl` + `C`.
  
## Toliau sekite instrukcijas konsolėje.
  

### Versijos:
### [v0.1](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v0.1)


Pirma programos versija turi nuskaityti duomenis, kuriuos vartotojas įvedinėja konsolėje. Taip pat su tais duomenymis atliekami kai kurie skaičiavimai. Atlikus skaičiavimus, rezultatai, išlygiuoti, išvedami konsolėje. Labai sunku buvo realizuoti su masyvais, tačiau pavyko. Taip pat buvo sunku susidoroti su saugikliais, kad nebūtų erorų.


### [v0.2](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v.0.2)

Antra versija naudoja tik vektorius. Prie programos prisideda skaitymas iš failo, kas nebuvo labai sunku, nes skaitymas iš konsolės ir failo yra labai panašūs veiksmai. Su nuskaitytais duomenymis taip pat buvo atliekami skaičiavimai ir gauti rezultatai išvedami konsolėje.

### [v0.3](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v.0.3)

Trečia versija reikalauja naudoti `try`, `throw` ir `catch` taip pat reikia programą išskirstyti į header failus ir funkcijų failus. Programa veikia paprastai, išskirsčius programą į failus kodas atrodo tvarkingesnis. Taip pat programoje yra realizuotos `try`, `throw` ir `catch` funkcijos, kurios palengvina erorų tvarkymą. Taip pat programoje atsirado įvestų duomenų išrūšiavimas.

### [v0.4](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v.0.4)

Ketvirta versija generuoja ir nuskaito 5 failus su skirtingu duomenų kiekiu. Laiko matavimui naudota `<chrono>` biblioteka, kuri yra labai tiksli. Skaičių generavimui buvo pasitelktas `std::random_device`, jis yra kur kas tikslesnis ir pranašesnis už `std::rand`, tiek dydžio, tiek skaičių atsitiktinumu. Programoje vis dar galima įrašyti duomenis konsolėje. Apačioje parodytas programos rezultatų pateikimas.
Skirtingų dydžių failų skirstymo laiko matavimai:
```
Failo generavimas ir skaitymas uztruko: 0.0177919 sekundziu
Failo generavimas ir skaitymas uztruko: 0.029366 sekundziu
Failo generavimas ir skaitymas uztruko: 0.10484 sekundziu
Failo generavimas ir skaitymas uztruko: 0.80917 sekundziu
Failo generavimas ir skaitymas uztruko: 7.41021 sekundziu
```

### [v0.5](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v.0.5)

Penkta versija rūšiuoja v0.4 - oje versijoje sugeneruotus ir nuskaitytus duomenis. Duomenys yra rūšiuojami taip: minkštus studentus perkeliant į vieną konteinerį, o stiprius studentus perkeliant į kitą konteinerį, o pirminis konteineris yra ištrinamas. 
Laikai, naudojant pirmą rūšiavimo būdą:
Vector:
```
Darbas su vektor:
Duomenu isrusiavimas uztruko: 0.0466158 sekundziu
```
Deque:
```
Darbas su deque:
Duomenu isrusiavimas uztruko: 0.0615744 sekundziu
```
List:
```
Darbas su list:
Duomenu isrusiavimas uztruko: 0.0639257 sekundziu
```

### [v1](https://github.com/Tomura69/Atsiskaitymai/releases/tag/v.1)

Pirma versija rūšiuoja duomenis tokiu būdu: radus minkštą studentą, jis yra perkeliamas į naują konteinerį, o pirminiame konteineryje ji yra ištrinamas. Taip nereikia kurti dar vieno konteinerio, tačiau šis rūšiavimo būdas yra labai nepalankus vektoriams ir deque. Norint paspartinti vektoriaus ir deque veikimą, buvo naudojama `std::stable_partition` funkcija, kuri drastiškai sumažino vektorių ir deque veikimo trukmę. Taip pat programoje atsirado `typedef`, kas labai padidino programos universalumą.
Laikai, naudojant antrą rūšiavimo būdą:
Vector:
```
Darbas su vector:
Duomenu isrusiavimas uztruko: 108.979 sekundziu
```
Vector, naudojant papildomus algoritmus:
```
Darbas su vector:
Duomenu isrusiavimas uztruko: 0.0449798 sekundziu
```
Deque:
```
Darbas su deque:
Duomenu isrusiavimas uztruko: 98.4181 sekundziu
```
Deque, naudojant papildomus algoritmus:
```
Darbas su deque:
Duomenu isrusiavimas uztruko: 0.0486952 sekundziu
```
List:
```
Darbas su list:
Duomenu isrusiavimas uztruko: 0.02027 sekundziu
```

### [Papildoma užduotis](https://github.com/Tomura69/Atsiskaitymai/releases/tag/Papildoma)

Papildoma užduotis skirta patikrinti rūšiavimo būdą, kada naudoti `std::deque` yra palankiausia. T.y. Norint išrūšiuoti studentus minkšti studentai dedami į naują vektorių, o stiprūs studentai įdedami į pirminio vektoriaus pradžią ir paskui nukertamas tame taške, kur baigiasi stiprūs studentai. Naudojant vektorių buvo naudojama `insert` funkcija, o naudojant deque pasitelkta `push_front` funkcija. Apačioje pateikiami programos veikimo laikai.

Vector:
```
Darbas su vector:
Duomenu isrusiavimas uztruko: 437.567 sekundziu
```
Deque:
```
Darbas su deque:
Duomenu isrusiavimas uztruko: 0.038717 sekundziu
```

### Išvados:
Laikas priklauso nuo to, kokiu būdu mum reikia apdoroti duomenis. Jei mums reikia tiesiog įrašyti duomenis ir su jais nieko daug nedaryt, tinkamiausia yra `std::vector`. Jei mums reikia Duomenis ištrinti, perkelti ir panašiai, patogiausia naudoti `std::list`. Įrašant duomenis ir į pradžią ir į pabaigą, patogiausia yra naudoti `std::deque`. Tačiau naudojant papildomus algoritmus, su visomis užduotimis `std::vector` gali susidoroti labai greitai. Taigi, nesvarbu ką naudoti, svarbu gerai optimizuoti ir pritaikyti tinkamą sprendimą uždaviniui.


# Testavimui naudoju tokį pat failų skaičių ir tuos pačius failus.
