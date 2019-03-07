#include "Headers.h"

int main (int argc, char *argv[]){
    const std::string eroras = "Blogai ivesti duomenys";
    int m = 0, sum = 0, generuoti, didvar = 6, didpav = 7, stud;
    double tarp, egz, tarp2;
    bool lyginis;
    std::vector<duom> Duomenys, Minksti, Stiprus;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> range(1, 10);
        int t = 10;
        for (int i = 0; i < 5; i++){
            auto startas = std::chrono::system_clock::now();
            Generavimas (t);
            Skaitymas (t, m, Duomenys);
            auto pabaiga = std::chrono::system_clock::now();
            auto uztruko = std::chrono::duration_cast<
            std::chrono::duration<double> >(pabaiga - startas).count();
            cout << t << "-ies dydzio failo generavimas ir skaitymas uztruko: " << uztruko << " sekundziu" << endl;
            t = t * 10;
        }

        {auto startas = std::chrono::system_clock::now();
        Rusiavimas (m, Duomenys, Minksti, Stiprus);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << "Duomenu isrusiavimas uztruko: " << uztruko << " sekundziu" << endl;}
        
        auto startas = std::chrono::system_clock::now();
        Irasymas (Minksti, Stiprus);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << "Duomenu isvedimas uztruko: " << uztruko << " sekundziu" << endl;
        cout << endl;

        
        while (true){
            sum = 0;
            cout << "Ivesk varda ir pavarde" << endl;
            Duomenys.push_back(duom());
            try {
                cin >> Duomenys[m].var;
                Patikra (Duomenys[m].var);
                cin >> Duomenys[m].pav;
                Patikra (Duomenys[m].pav);
            } catch (const char* msg){
                cout << msg << endl;
                break;
            }
            Ilgiausias (didvar, didpav, Duomenys[m].var, Duomenys[m].pav);
            char d;
            cout << "Jei norite, kad pazymiai butu generuojami atsitiktinai veskite 1, kitu atveju veskite 0" << endl;
            cin >> d;
            generuoti = d - '0';
            if (generuoti < 0 || generuoti > 1){
                cout << eroras << endl;
                break;
            }
            if (generuoti){
                int n = 0;
                cout << "Kiek generuoti skaiciu" << endl;
                cin >> n;
                lyginis = (n%2 == 0);
                int *Med = new int[n];
                for (int i = 0; i < n; i++){
                    Med[i] = range(mt);
                    sum = sum + Med[i];
                }
                egz = range(mt);
                Skaiciavimai (Duomenys, m, n, Med, sum, egz);
                delete [] Med;
            }
            else {
                cout << "Ivesk namu darbu rezultatus, baige iveskite 0" << endl;
                char a;
                int n = 0;
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
                    break;
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
                int l = n;
                for (int p = 0; p < l; p++){
                    if (Med[p] > 10 || Med[p] <= 0){
                        n--;
                    }
                }
                for (int i = 0; i < n; i++){
                    sum = sum + Med[i];  
                }
            
                cout << "Ivesk egzamino rezultatus" << endl;
                std::string g;
                cin >> g;
                if (g.size() == 2 && g[0] == '1' && g[1] == '0') egz = 10;
                else if (g.size() == 1) egz = g[0] - '0';
                if (egz > 10 || egz <= 0){
                    cout << eroras << endl;
                    break;
                }
                Skaiciavimai (Duomenys, m, n, Med, sum, egz);
                delete [] Med;
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
            for (int i = 0; i <= m; i++){
                cout << std::left << std::setw(didvar+1) << Duomenys[i].var << std::left << std::setw(didpav+1) << Duomenys[i].pav << std::left << std::setw(14) << std::setprecision(2) << Duomenys[i].galutinis << std::left << std::setprecision(2) << Duomenys[i].galmed << endl;
            }
            m++;
            cout << endl;
    }
    return 0;
}