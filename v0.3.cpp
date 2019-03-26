#include "Headers.h"


int main (int argc, char *argv[]){
    const std::string eroras = "Blogai ivesti duomenys, bandykite dar karta";
    int m = 0, n, sum = 0, generuoti, didvar = 5, didpav = 6;
    double tarp, egz, tarp2;
    bool lyginis;
    std::vector<duom> Duomenys;
    
    srand(time(NULL));
    Skaitymas (m, Duomenys, didvar, didpav);
    while (true){
        n = 0;
        sum = 0;
        cout << "Ivesk varda ir pavarde" << endl;
        Duomenys.push_back(duom());
        try{
            cin >> Duomenys[m].var;
            Patikra (Duomenys[m].var);
            if (didvar < Duomenys[m].var.size()){
                didvar = Duomenys[m].var.size();
            }
            cin >> Duomenys[m].pav;
            Patikra (Duomenys[m].pav);
            if (didpav < Duomenys[m].pav.size()){
                didpav = Duomenys[m].pav.size();
            }
            } catch (const char* msg){
                cout << msg << endl;
                continue;
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
                if (n == 0 && a == '0') break;
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
            int* Med = new int[n];
            int kas = 0;
            std::copy(Medv.begin(), Medv.end(), Med);
            Medv.clear();
            for (int i = 0; i < n; i++){
                if (Med[i] == 1 && Med[i+1] == 0){
                    Med[i] = 10;
                    kas++;
                }
            }
            for (int t = 0; t < n - 1; t++){
                for (int o = t; o < n; o++){
                    if (Med[t] > Med[o] || Med[t] < 0){
                        std::swap(Med[t], Med[o]);
                    }
                }
            }
            for (int i = 0; i < kas; i++){
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
        for (int i = 0; i <= m; i++) {
		    for (int j = 0; j <= m; j++) {
			    if (Duomenys[i].var < Duomenys[j].var){
                    std::swap(Duomenys[i], Duomenys[j]);
                }
            }
        }
        cout << endl;
        cout << std::left << std::setw(didvar + 1) << "Vardas" << std::left << std::setw(didpav + 1) << "Pavarde" << "VidGalutinis  " << "MedGalutinis" << endl;
        cout << std::string(didvar+didpav+27, '-') << endl;
        //cout << std::left << std::setw(didvar+1) << Duomenys[m].var << std::left << std::setw(didpav+1) << Duomenys[m].pav << std::left << std::setw(14) << std::setprecision(3) << Duomenys[m].galutinis << std::left << std::setprecision(3) << Duomenys[m].galmed << endl;
        
        for (int i = 0; i <= m; i++){
            cout << std::left << std::setw(didvar+1) << Duomenys[i].var << std::left << std::setw(didpav+1) << Duomenys[i].pav << std::left << std::setw(14) << std::setprecision(3) << Duomenys[i].galutinis << std::left << std::setprecision(3) << Duomenys[i].galmed << endl;
        }
        m++;
    }
    
    return 0;
}