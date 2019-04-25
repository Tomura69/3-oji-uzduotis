#include "classStud.h"

Studentas::Studentas() {
}
void Studentas::skaitymas_vard (std::string var_, std::string pav_){
    var = var_;
    pav = pav_;
}
void Studentas::Vidurkis (double galutinis_, double mediana_, double galmed_){
    galutinis = galutinis_;
    mediana = mediana_;
    galmed = galmed_;
}
void Studentas::skaitymas_Nd (int nd_){
    nd.push_back(nd_);
}