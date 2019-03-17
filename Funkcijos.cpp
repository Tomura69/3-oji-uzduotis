#include "Headers.h"

bool Patikra (std::string a){
    for (int i = 0; i < a.size(); i++){
        if (isalpha(a[i]) == 0){
            throw "Blogai ivesti duomenys, bandykite dar karta";
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

void Skaitymas (int t, std::list<duom>& Duomenys){
    std::string s = std::to_string(t);
    std::ifstream fd("test" + s + ".md");
    duom duomenys;
    bool sauga = 0;
    if (!fd.good()){
        throw "Failai neegzistuoja";
    }
    int laik;
    std::string pvz;
    std::vector<int> Medv;
    while (!fd.eof()){
        int sum = 0, kas = 0;
        getline(fd, pvz);
        std::istringstream in_line(pvz);
        try {
            in_line >> duomenys.var;
            //Patikra (duomenys.var);
            in_line >> duomenys.pav;
            //Patikra (duomenys.pav);
        } catch (const char* msg){
            cout << msg << endl;
        }
        while (in_line >> laik){
            if (laik == 0){
                cout << "Blogai ivesti duomenys pas studenta: " << duomenys.var << ", " << t << "-ame faile" << endl;
                sum = 0;
                break;
            }
            sum = sum + laik;
            Medv.push_back(laik);
            kas++;
        }

        if (Medv.empty()){
            cout << "Blogai ivesti duomenys " << t << "-ame faile" << endl;
            break;
        }
        int egz = Medv[kas-1];
        kas--;
        sum = sum - egz;
        Skaiciavimai (duomenys, kas, Medv, sum, egz);
        Duomenys.push_back(duomenys);
    } 
    fd.close();
}
void Skaiciavimai (duom& duomenys, int kas, std::vector<int>& Medv, int sum, int egz){
    std::sort(Medv.begin(), Medv.end());
        
    bool lyginis = (kas%2 == 0);
    if (lyginis){
        double tarp2 = (Medv[kas/2-1] + Medv[kas/2]) / 2.0;
        duomenys.mediana = tarp2;
    }
    else {
        duomenys.mediana = Medv[(kas/2)];
    }
    double tarp = 0.4*((double)sum / kas)+0.6*egz;
    duomenys.galutinis = tarp;
    duomenys.galmed = 0.4*duomenys.mediana+0.6*egz;
    Medv.clear();
}


void Rusiavimas (std::list<duom>& Duomenys, std::list<duom>& Minksti){
    std::list<duom>::iterator itr = Duomenys.begin();
    duom laik;
    for (itr; itr != Duomenys.end(); itr++){
        if (itr -> galutinis < 5.0 && itr -> galmed < 5.0){
            laik.var = itr -> var;
            laik.pav = itr -> pav;
            laik.galutinis = itr -> galutinis;
            laik.galmed = itr -> galmed;
            Minksti.push_back(laik);
            Duomenys.erase(itr);
            itr--;
        }
    }
    
}

void Irasymas (std::list<duom>& Minksti, std::list<duom>& Duomenys){
    std::ofstream fr2("Vargsiukai.md");
    std::ofstream fr1("Saunuoliai.md");
    std::list<duom>::iterator it2 = Minksti.begin();
    std::list<duom>::iterator it1 = Duomenys.begin();
    for (it2; it2 != Minksti.end(); it2++){
        fr2 << it2 -> var << " " << it2 -> pav << " " << std::setprecision(3) << it2 -> galutinis << " " << it2 -> galmed << endl;
    }
    for (it1; it1 != Duomenys.end(); it1++){
        fr1 << it1 -> var << " " << it1 -> pav << " " << std::setprecision(3) << it1 -> galutinis << " " << it1 -> galmed << endl;
    }
    fr2.close();
    fr1.close();
    Minksti.clear();
    Duomenys.clear();
}