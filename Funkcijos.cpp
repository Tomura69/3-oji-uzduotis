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

void Skaitymas (int & m, std::vector<duom>& Duomenys, int & didvar, int & didpav){
    std::ifstream fd("kursiokai.txt");
    
    int laik;
    std::string pvz;
    std::getline(fd, pvz);
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
            Patikra (Duomenys[m].var);
            if (didvar < Duomenys[m].var.size()){
                didvar = Duomenys[m].var.size();
            }
            fd >> Duomenys[m].pav;
            Patikra (Duomenys[m].pav);
            if (didpav < Duomenys[m].pav.size()){
                didpav = Duomenys[m].pav.size();
            }
        } catch (const char* msg){
            cout << msg << endl;
            break;
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