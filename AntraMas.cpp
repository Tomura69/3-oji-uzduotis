#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;

struct duom
{
    std::string var, pav;
    double galutinis, mediana, galmed;
};


int main (){
    const std::string eroras = "Blogai ivesti duomenys";
    int m, n = 0, sum = 0, j = 1, generuoti;
    double tarp, egz, tarp2;
    bool lyginis;
    srand(time(NULL));
    cout << "Ivesk kiek studentu?" << endl;
    cin >> m;
    duom *A = new duom[m];
    for (int y = 0; y < m; y++){
        sum = 0;
        bool break1 = 0;
        cout << "Ivesk varda ir pavarde" << endl;
        cin >> A[y].var;
        for (int i = 0; i < A[y].var.size(); i++){
                if (isalpha(A[y].var[i]) == 0){
                    cout << eroras << endl;
                    break1 = 1;
                    break;
                }
            }
        if (break1) break;
        cin >> A[y].pav;
        for (int i = 0; i < A[y].pav.size(); i++){
                if (isalpha(A[y].pav[i]) == 0){
                    cout << eroras << endl;
                    break1 = 1;
                    break;
                }
            }
        if (break1) break;

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
                A[y].mediana = tarp2;
            }
            else {
                A[y].mediana = Med[(n/2)];
            }
            egz = 1+rand() % 10;
            tarp = 0.4*((double)sum / n)+0.6*egz;
            A[y].galutinis = tarp;
            A[y].galmed = 0.4*A[y].mediana+0.6*egz;
        }
        else {
            cout << "Ivesk namu darbu rezultatus, baige iveskite 0" << endl;
            std::string simboliai;
            char a;
            while (true){
                cin >> a;
                int o = a - '0';
                if (a==  '0' && simboliai[n-1] != '1') break;
                else if (o > 10 || a <= 0){
                    cout << "Veskite skaicius, o ne simblius" << endl;
                }
                simboliai = simboliai + a;
                n++;
            }
            int* Med = new int[n];
            int x = 0;
            for (int h = 0; h < n; h++){
                int p = simboliai[h] - '0';
                if (p == 1 && simboliai[h+1] == '0'){
                    Med[h] = 10;
                    x++;
                }
                else if (p == 0 && simboliai[h-1] == '1');
                else Med[h] = p;
            }
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
                A[y].mediana = tarp2;
            }
            else {
                A[y].mediana = Med[(n/2)];
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
            A[y].galutinis = tarp;
            A[y].galmed = 0.4*A[y].mediana+0.6*egz;
        }
        cout << "Pavarde" << std::setw(15) << "Vardas" << std::setw(21) << "VidGalutinis" << std::setw(21) << "MedGalutinis" << endl;
        cout << std::string(60, '-') << endl;
        for (int i = 0; i < j; i++){
            cout << A[i].var << std::setw(15) << A[i].pav << std::setw(21) << std::setprecision(2) << A[i].galutinis << std::setw(21) << std::setprecision(2) << A[i].galmed << endl;
        }
        j++;
    }
    
    return 0;
}