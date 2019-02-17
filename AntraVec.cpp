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
    std::vector<int> Medv;
    std::string pvz;
    std::getline(fd, pvz);
    while (!fd.eof()){
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
    const std::string eroras = "Blogai ivesti duomenys";
    int m = 0, n = 0, sum = 0, generuoti;
    double tarp, egz, tarp2;
    bool lyginis;
    std::vector<duom> Duomenys;
    
    srand(time(NULL));
    Skaitymas (m, Duomenys);
    while (true){
        sum = 0;
        cout << "Ivesk varda ir pavarde" << endl;
        Duomenys.push_back(duom());
        cin >> Duomenys[m].var;
        cin >> Duomenys[m].pav;
        /*if (isdigit(Duomenys[n].var[0])||isdigit(Duomenys[n].pav[0])){
            cout << eroras << endl;
            break;
        }*/
        char d;
        cout << "Jei norite, kad pazymiai butu generuojami atsitiktinai veskite 1, kitu atveju veskite 0" << endl;
        cin >> d;
        generuoti = d - '0';
        if (generuoti < 0 || generuoti > 1){
            cout << eroras << endl;
            break;
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
                /*if (a == '0' && simboliai[n] == 1){
                    cout << "gal 10?" << endl;
                }*/
                if (a == '0') break;
                else if (o > 10 || a <= 0){
                    cout << "Veskite skaicius, o ne simblius" << endl;
                }
                Medv.push_back(0);
                n++;
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
            for (int i = 0; i < n; i++){
                if (Med[i] > 10 || Med[i] <= 0){
                    n--;
                }
            }
            int l = n;
            for (int p = 0; p < l; p++){
                if (Med[p] >= 10 || Med[p] <= 0){
                    n--;
                }
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
                break;
            }
            delete [] Med;
            tarp = 0.4*((double)sum / n)+0.6*egz;
            Duomenys[m].galutinis = tarp;
            Duomenys[m].galmed = 0.4*Duomenys[m].mediana+0.6*egz;
        }
        cout << "Pavarde" << std::setw(15) << "Vardas" << std::setw(21) << "VidGalutinis" << std::setw(21) << "MedGalutinis" << endl;
        cout << std::string(60, '-') << endl;
        cout << Duomenys[m].var << std::setw(15) << Duomenys[m].pav << std::setw(21) << std::setprecision(2) << Duomenys[m].galutinis << std::setw(21) << std::setprecision(2) << Duomenys[m].galmed << endl;
        for (int i = 0; i < m; i++){
            cout << Duomenys[i].var << std::setw(15) << Duomenys[i].pav << std::setw(21) << std::setprecision(2) << Duomenys[i].galutinis << std::setw(21) << std::setprecision(2) << Duomenys[i].galmed << endl;
        }
        m++;
    }
    
    return 0;
}