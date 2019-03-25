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

void Skaitymas (int & m, std::vector<duom>& Duomenys){
    std::ifstream fd("kursiokai.txt");
    int laik;
    bool failas = 0;
    if (!fd.good()){
        failas = 1;
    }
    std::vector<int> Medv;
    std::string pvz;
    std::getline(fd, pvz);
    while (!fd.eof()){
        if (failas) {
            cout << "Failas neegzistuoja" << endl;
            break;
        }
        int sum =0, kas = 0;
        Duomenys.push_back(duom());
        fd >> Duomenys[m].var;
        fd >> Duomenys[m].pav;
        std::getline(fd, pvz);
        for (int i = 0; i < pvz.size(); i++){
            if (pvz[i] != ' '){
                if (pvz[i] == '1' && pvz[i+1] == '0'){
                    laik = 10;
                    Medv.push_back(laik);
                    kas++;
                    i++;
                }
                else {
                    laik = pvz[i] - '0';
                    Medv.push_back(laik);
                    kas++;
                }
            }   
        }
        int* Med = new int(kas);
        std::copy(Medv.begin(), Medv.end(), Med);
        for (int i = 0; i < kas; i++){
            if (Med[i] == -35) {
            kas--;
            }
        }
        int egz = Med[kas-1];
        kas--;
        for (int i = 0; i < kas; i++){
            sum = sum + Med[i];
        }
        bool lyginis = (kas%2 == 0);
        for (int l = 0; l < kas-1; l++){
                for (int k = l+1; k < kas; k++){
                    if (Med[l] > Med[k])
                        std::swap(Med[l], Med[k]);
                }
            }
            if (lyginis){
                double tarp2 = (Med[kas/2-1] + Med[kas/2]) / 2.0;
                Duomenys[m].mediana = tarp2;
            }
            else {
                Duomenys[m].mediana = Med[(kas/2)];
            }
            double tarp = 0.4*((double)sum / kas)+0.6*egz;
            Duomenys[m].galutinis = tarp;
            Duomenys[m].galmed = 0.4*Duomenys[m].mediana+0.6*egz;
        delete [] Med;
        Medv.clear();
        m++;
    }
    fd.close();
}

int main (int argc, char *argv[]){
    const std::string eroras = "Blogai ivesti duomenys, bandykite dar karta";
    int m = 0, n = 0, sum = 0, generuoti, skaityti, didvar = 5, didpav = 6;
    double tarp, egz, tarp2;
    bool lyginis, break1 = 0;
    std::vector<duom> Duomenys;
    
    cout << "Veskite 1, jei norite nuskaityti is failo, kitu atveju betkoki kita simboli" << endl;
    cin >> skaityti;
    if (skaityti == 1){
        Skaitymas (m, Duomenys);
    }
    else {
        srand(time(NULL));
        while (true){
            sum = 0;
            break1 = 0;
            n = 0;
            cout << "Ivesk varda ir pavarde" << endl;
            Duomenys.push_back(duom());
            cin >> Duomenys[m].var;
            for (int i = 0; i < Duomenys[m].var.size(); i++){
                if (isalpha(Duomenys[m].var[i]) == 0){
                    cout << eroras << endl;
                    break1 = 1;
                    break;
                }
            }
            if (break1) continue;
            if (didvar < Duomenys[m].var.size()){
                didvar = Duomenys[m].var.size();
            }
            cin >> Duomenys[m].pav;
            for (int i = 0; i < Duomenys[m].pav.size(); i++){
                if (isalpha(Duomenys[m].pav[i]) == 0){
                    cout << eroras << endl;
                    break1 = 1;
                    break;
                }
            }
            if (break1) continue;
            if (didpav < Duomenys[m].pav.size()){
                didpav = Duomenys[m].pav.size();
            }

            char d;
            cout << "Jei norite, kad pazymiai butu generuojami atsitiktinai veskite 1, kitu atveju veskite 0" << endl;
            cin >> d;
            generuoti = d - '0';
            if (generuoti < 0 || generuoti > 1){
                cout << eroras << endl;
                continue;
            }
            if (generuoti){
                cout << "Kiek generuoti skaiciu" << endl;
                cin >> n;
                lyginis = (n%2 == 0);
                int *Med = new int[n];
                for (int i = 0; i < n; i++){
                    Med[i] = 1+rand() % 10;
                    sum = sum + Med[i];
                }
                for (int l = 0; l < n-1; l++){
                    for (int k = l+1; k < n; k++){
                        if (Med[l] > Med[k])
                            std::swap(Med[l], Med[k]);
                    }
                }
                if (lyginis){
                    tarp2 = (Med[n/2-1] + Med[n/2]) / 2.0;
                    Duomenys[m].mediana = tarp2;
                }
                else {
                    Duomenys[m].mediana = Med[(n/2)];
                }
                egz = 1+rand() % 10;
                tarp = 0.4*((double)sum / n)+0.6*egz;
                Duomenys[m].galutinis = tarp;
                Duomenys[m].galmed = 0.4*Duomenys[m].mediana+0.6*egz;
            }
            else {
                cout << "Ivesk namu darbu rezultatus, baige iveskite 0" << endl;
                char a;
                std::vector<int> Medv;
                while (true){
                    cin >> a;
                    int o = a - '0';
                    if (a == '0' && Medv[n-1] != 1) break;
                    else if (o > 10 || a <= 0){
                        cout << "Veskite skaicius, o ne simblius" << endl;
                    }
                    Medv.push_back(o);
                    n++;
                }
                if (Medv.empty()){
                    cout << eroras << endl;
                    continue;
                }
                int x = 0;
                for (int h = 0; h < n; h++){
                    if (Medv[h] == 1 && Medv[h+1] == 0){
                        Medv[h] = 10;
                        x++;
                    }
                    else if (Medv[h] == 0 && Medv[h-1] == 1);
                    else Medv[h] = Medv[h];
                }
                int* Med = new int[n];
                std::copy(Medv.begin(), Medv.end(), Med);
                Medv.clear();
                for (int t = 0; t < n - 1; t++){
                    for (int o = t; o < n; o++){
                        if (Med[t] > Med[o] || Med[t] < 0){
                            std::swap(Med[t], Med[o]);
                        }
                    }
                }
                for (int i = 0; i < x; i++){
                    for (int y = 0; y < n; y++){
                        Med[y] = Med[y+1];
                    }
                    n--;
                }
                lyginis = (n%2 == 0);
                for (int l = 0; l < n - 1; l++){
                    for (int k = l+1; k < n; k++){
                        if (Med[l] > Med[k]){
                            std::swap(Med[l], Med[k]);}
                    }
                    sum = sum + Med[l];
                }
                sum = sum + Med[n-1];
                if (lyginis){
                    tarp2 = (Med[n/2-1] + Med[n/2]) / 2.0;
                    Duomenys[m].mediana = tarp2;
                }
                else {
                    Duomenys[m].mediana = Med[(n/2)];
                }
                cout << "Ivesk egzamino rezultatus" << endl;
                char g;
                cin >> g;
                egz = g - '0';
                if (egz > 10 || egz <= 0){
                    cout << eroras << endl;
                    continue;
                }
                delete [] Med;
                tarp = 0.4*((double)sum / n)+0.6*egz;
                Duomenys[m].galutinis = tarp;
                Duomenys[m].galmed = 0.4*Duomenys[m].mediana+0.6*egz;
            }
            cout << endl;
            cout << std::left << std::setw(didvar + 1) << "Vardas" << std::left << std::setw(didpav + 1) << "Pavarde" << "VidGalutinis  " << "MedGalutinis" << endl;
            cout << std::string(didvar+didpav+27, '-') << endl;
            cout << std::left << std::setw(didvar+1) << Duomenys[m].var << std::left << std::setw(didpav+1) << Duomenys[m].pav << std::left << std::setw(14) << std::setprecision(3) << Duomenys[m].galutinis << std::left << std::setprecision(3) << Duomenys[m].galmed << endl;
        
            for (int i = 0; i < m; i++){
                cout << std::left << std::setw(didvar+1) << Duomenys[i].var << std::left << std::setw(didpav+1) << Duomenys[i].pav << std::left << std::setw(14) << std::setprecision(3) << Duomenys[i].galutinis << std::left << std::setprecision(3) << Duomenys[i].galmed << endl;
            }
            m++;
            cout << endl;
        }
    }
    return 0;
}