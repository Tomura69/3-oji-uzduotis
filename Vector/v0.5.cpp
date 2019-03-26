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

    cout << "Darbas su vektor:" << endl;
    int t = 10;
    for (int i = 0; i < 5; i++){
        auto startas = std::chrono::system_clock::now();
        Generavimas (t);
        Skaitymas (t, m, Duomenys);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << t << "-ies dydzio failo " /*generavimas ir */"skaitymas uztruko: " << uztruko << " sekundziu" << endl;
        t = t * 10;
    }

    {auto startas = std::chrono::system_clock::now();
    Rusiavimas (m, Duomenys, Minksti, Stiprus);
    auto pabaiga = std::chrono::system_clock::now();
    auto uztruko = std::chrono::duration_cast<
    std::chrono::duration<double> >(pabaiga - startas).count();
    cout << "Duomenu isrusiavimas uztruko: " << uztruko << " sekundziu" << endl;}
        
    {auto startas = std::chrono::system_clock::now();
    Irasymas (Minksti, Stiprus);
    auto pabaiga = std::chrono::system_clock::now();
    auto uztruko = std::chrono::duration_cast<
    std::chrono::duration<double> >(pabaiga - startas).count();
    cout << "Duomenu isvedimas uztruko: " << uztruko << " sekundziu" << endl;}
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
            continue;
        }
        Ilgiausias (didvar, didpav, Duomenys[m].var, Duomenys[m].pav);
        char d;
        cout << "Jei norite, kad pazymiai butu generuojami atsitiktinai veskite 1, kitu atveju veskite 0" << endl;
        cin >> d;
        generuoti = d - '0';
        if (generuoti < 0 || generuoti > 1){
            cout << eroras << endl;
            continue;
        }
        if (generuoti){
            int n = 0;
            cout << "Kiek generuoti skaiciu" << endl;
            cin >> n;
            std::vector<int> Medv;
            Medv.reserve(n);
            for (int i = 0; i < n; i++){
                Medv.push_back(range(mt));
                sum = sum + Medv[i];
            }
            egz = range(mt);
            Skaiciavimai (Duomenys, m, n, Medv, sum, egz);
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
                continue;
            }
            int kas = 0;
            for (int i = 0; i < n; i++){
                if (Medv[i] == 1 && Medv[i+1] == 0){
                    Medv[i] = 10;
                    kas++;
                }
            }
            std::sort(Medv.begin(), Medv.end());
            
            for (int i = 0; i < kas; i++){
                for (int y = 0; y < n; y++){
                    Medv[y] = Medv[y+1];
                }
                n--;
            }
            int l = n;
            for (int p = 0; p < l; p++){
                if (Medv[p] > 10 || Medv[p] <= 0){
                    n--;
                }
            }
            for (int i = 0; i < n; i++){
                sum = sum + Medv[i];  
            }
            
            cout << "Ivesk egzamino rezultatus" << endl;
            std::string g;
            cin >> g;
            if (g.size() == 2 && g[0] == '1' && g[1] == '0') egz = 10;
            else if (g.size() == 1) egz = g[0] - '0';
            if (egz > 10 || egz <= 0){
                cout << eroras << endl;
                continue;
            }
            Skaiciavimai (Duomenys, m, n, Medv, sum, egz);
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
            cout << std::left << std::setw(didvar+1) << Duomenys[i].var << std::left << std::setw(didpav+1) << Duomenys[i].pav << std::left << std::setw(14) << std::setprecision(3) << Duomenys[i].galutinis << std::left << std::setprecision(3) << Duomenys[i].galmed << endl;
        }
        m++;
        cout << endl;
    }
    return 0;
}