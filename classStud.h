#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Studentas{
    private:
        std::string var, pav;
        double galutinis, mediana, galmed;
        std::vector<int> nd;
    public:
        Studentas();
        void skaitymas_vard (std::string var_, std::string pav_);
        void Vidurkis (double galutinis_, double mediana_, double galmed_);
        void skaitymas_Nd (int nd_);
        inline void popBack() {nd.pop_back();}
        inline void Rikiuoti() {std::sort(nd.begin(), nd.end());}
        inline std::string Vardas () const {return var;}
        inline std::string Pavarde () const {return pav;}
        inline int Nd (int i) const {return nd[i];}
        inline bool Empty () const {if (nd.empty()) return 1;}
        inline double Vidurkis () const {return galutinis;}
        inline double Mediana () const {return mediana;}
        inline double MedVid () const {return galmed;}
};