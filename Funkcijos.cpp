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

void Generavimas (int test){
    std::string s = std::to_string(test);
    std::ofstream fr("test" + s + ".md");
    if (fr.is_open()){
        for (int i = 1; i <= test; i++){
            std::string s = std::to_string(i);
            fr << "Vardas" + s << " Pavarde" + s;
            for (int y = 0; y < 10; y++){
                fr << " " << 1+rand() % 10;
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
    std::ofstream fr("visi.md", std::ios::app);
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
            fr << Duomenys[m].var << " ";
            //Patikra (Duomenys[m].var);
            in_line >> Duomenys[m].pav;
            fr << Duomenys[m].pav << " ";
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
            break;
        }
        int *Med = new int [kas];
        std::copy(Medv.begin(), Medv.end(), Med);
        Medv.clear();
        int egz = Med[kas-1];
        kas--;
        sum = sum - egz;

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
        delete [] Med;
        double tarp = 0.4*((double)sum / kas)+0.6*egz;
        Duomenys[m].galutinis = tarp;
        Duomenys[m].galmed = 0.4*Duomenys[m].mediana+0.6*egz;
        fr << Duomenys[m].galutinis << " " << Duomenys[m].galmed << endl;
        m++;
    } 
    fd.close();
}

void Rusiavimas (int & m, std::vector<duom>& Duomenys){
    cout << m << endl;
    for (int i = 0; i < m; i++){
        if (Duomenys[i].galutinis > 5.0 && Duomenys[i].galmed > 5.0){
            std::ofstream fr1("Saunuoliai.md", std::ios::app);
            fr1 << Duomenys[i].var << " " << Duomenys[i].pav << " " << Duomenys[i].galutinis << " " << Duomenys[i].galmed << endl;
        }
        else {
            std::ofstream fr2("Vargsiukai.md", std::ios::app);
            fr2 << Duomenys[i].var << " " << Duomenys[i].pav << " " << Duomenys[i].galutinis << " " << Duomenys[i].galmed << endl;
        }
    }
}