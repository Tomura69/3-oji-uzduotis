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

void Generavimas (int stud){
    std::ofstream fr("kursiokai.cpp");
    if (fr.is_open()){
        for (int i = 1; i <= stud; i++){
            std::string s = std::to_string(i);
            fr << "Vardas" + s << " Pavarde" + s;
            for (int y = 0; y < 10; y++){
                fr << " " << 1+rand() % 10;
            }
            fr << endl;
        }
    }
    else {
        cout << "Negalima sukurti failo" << endl;
    }
    fr.close();
}

void Skaitymas (int & m, std::vector<duom>& Duomenys){
    std::ifstream fd("kursiokai.txt");
    
    int laik;
    std::string pvz;
    //std::getline(fd, pvz);
    while (!fd.eof()){
        try {
            if (!fd.good()){
                throw "Failas neegzistuoja";
        }
        } catch (const char* msg){
            cout << msg << endl;
            break;
        }
        std::vector<int> Medv;
        int sum = 0, kas = 0;
        Duomenys.push_back(duom());
        try {
            fd >> Duomenys[m].var;
            //Patikra (Duomenys[m].var);
            fd >> Duomenys[m].pav;
            //Patikra (Duomenys[m].pav);
        } catch (const char* msg){
            cout << msg << endl;
        }
        std::getline(fd, pvz);
        for (int i = 0; i < pvz.size(); i++){
            if (pvz[i] != ' '){
                laik = pvz[i] - '0';
                if (pvz[i] == '1' && pvz[i+1] == '0'){
                    laik = 10;
                    Medv.push_back(laik);
                    kas++;
                    i++;
                }
                else if (laik < 1 || laik > 10){
                }
                else {
                    Medv.push_back(laik);
                    kas++;
                }
            }
        }
        pvz = '0';
        if (Medv.empty()){
            cout << "Blogai ivesti duomenys" << endl;
            break;
        }
        int* Med = new int(kas);
        std::copy(Medv.begin(), Medv.end(), Med);
        
        for (int l = 0; l < kas-1; l++){
                for (int k = l+1; k < kas; k++){
                    if (Med[l] > Med[k])
                        std::swap(Med[l], Med[k]);
                }
        }
        int egz = Med[kas-1];
        kas--;
        for (int i = 0; i < kas; i++){
            sum = sum + Med[i];
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
        m++;
        delete [] Med;
        Medv.clear();
    } 
    fd.close();
}

void Rusiavimas (int & m, std::vector<duom>& Duomenys){
    for (int i = 0; i < m; i++){
        if (Duomenys[m].galutinis > 5.0 && Duomenys[m].galmed > 5.0){
            std::ofstream fr1("Saunuoliai.txt", std::ios::app);
            fr1 << Duomenys[m].var << " " << Duomenys[m].pav << " " << Duomenys[m].galutinis << " " << Duomenys[m].galmed << endl;
        }
        else {
            std::ofstream fr2("Vargsiukai.txt", std::ios::app);
            fr2 << Duomenys[m].var << " " << Duomenys[m].pav << " " << Duomenys[m].galutinis << " " << Duomenys[m].galmed << endl;
        }
    }
}