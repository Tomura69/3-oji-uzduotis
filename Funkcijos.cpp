#include "Headers.h"

bool Patikra (std::string a){
    for (int i = 0; i < a.size(); i++){
                if (isalpha(a[i]) == 0){
                    throw "Blogai ivesti duomenys";
                    return 1;
                    break;
                }
            }
}


void Ilgiausias (int & didvar, int & didpav, std::string var, std::string pav){
    if (didvar < var.size()){
        didvar = var.size();
    }
    if (didpav < pav.size()){
        didpav = pav.size();
    }
}


void Generavimas (int test){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> range(1, 10);
    std::string s = std::to_string(test);
    std::ofstream fr("test" + s + ".md");
    if (fr.is_open()){
        for (int i = 1; i <= test; i++){
            std::string s = std::to_string(i);
            fr << "Vardas" + s << " Pavarde" + s;
            for (int y = 0; y < 10; y++){
                fr << " " << range(mt);
            }
            if (i != test)
            fr << endl;
        }
    }
    else {
        cout << "Negalima sukurti failo" << endl;
    }
    fr.close();
}

void Skaitymas (int t, int & m, std::vector<duom>& Duomenys){
    std::string s = std::to_string(t);
    std::ifstream fd("test" + s + ".md");
    bool sauga = 0;
    try {
            if (!fd.good()){
                throw "Failas neegzistuoja";
        }
        } catch (const char* msg){
            cout << msg << endl;
            sauga = 1;
        }
    int laik;
    std::string pvz;
    std::vector<int> Medv;
    while (!fd.eof()){
        if (sauga) break;
        
        int sum = 0, kas = 0;
        Duomenys.push_back(duom());
        getline(fd, pvz);
        std::istringstream in_line(pvz);
        try {
            in_line >> Duomenys[m].var;
            //Patikra (Duomenys[m].var);
            in_line >> Duomenys[m].pav;
            //Patikra (Duomenys[m].pav);
        } catch (const char* msg){
            cout << msg << endl;
        }
        while (in_line >> laik){
            if (laik == 0){
                cout << "Blogai ivesti duomenys pas studenta: " << Duomenys[m].var << ", " << t << "-ame faile" << endl;
                sum = 0;
                break;
            }
            sum = sum + laik;
            Medv.push_back(int());
            Medv[kas] = laik;
            kas++;
        }

        if (Medv.empty()){
            cout << "Blogai ivesti duomenys " << t << "-ame faile" << endl;
            continue;
        }
        int *Med = new int [kas];
        std::copy(Medv.begin(), Medv.end(), Med);
        Medv.clear();
        int egz = Med[kas-1];
        kas--;
        sum = sum - egz;
        Skaiciavimai (Duomenys, m, kas, Med, sum, egz);
        delete [] Med;
        m++;
    } 
    fd.close();
}
void Skaiciavimai (std::vector<duom>& Duomenys, int m, int kas, int Med[], int sum, int egz){
    for (int l = 0; l < kas-1; l++){
                for (int k = l+1; k < kas; k++){
                    if (Med[l] > Med[k])
                        std::swap(Med[l], Med[k]);
                }
        }
        
        bool lyginis = (kas%2 == 0);
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
}


void Rusiavimas (int & m, std::vector<duom>& Duomenys, std::vector<duom>& Minksti, std::vector<duom>& Stiprus){
    for (int i = 0; i < m; i++){
        if (Duomenys[i].galutinis > 5.0 && Duomenys[i].galmed > 5.0){
            Minksti.push_back(Duomenys[i]);
        }
        else {
            Stiprus.push_back(Duomenys[i]);
        }
    }
    m = 0;
    Duomenys.clear();
    
}

void Irasymas (std::vector<duom>& Minksti, std::vector<duom>& Stiprus){
    std::ofstream fr1("Saunuoliai.md", std::ios::app);
    std::ofstream fr2("Vargsiukai.md", std::ios::app);
    for (int i = 0; i < Minksti.size(); i++){
        fr2 << Minksti[i].var << " " << Minksti[i].pav << " " << std::setprecision(3) << Minksti[i].galutinis << " " << Minksti[i].galmed << endl;
    }
    for (int i = 0; i < Stiprus.size(); i++){
        fr1 << Stiprus[i].var << " " << Stiprus[i].pav << " " << std::setprecision(3) << Stiprus[i].galutinis << " " << Stiprus[i].galmed << endl;
    }
    fr1.close();
    fr2.close();
    Minksti.clear();
    Stiprus.clear();
}