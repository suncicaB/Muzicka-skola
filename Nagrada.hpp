#ifndef NAGRADA_HPP_INCLUDED
#define NAGRADA_HPP_INCLUDED
#include<iostream>

enum NagradaState{pohvala, trecaa, drugaa, prvaa};
using std::cout;
using std::endl;

class Nagrada{
private:
    double brojBodova;
    NagradaState mesto;
public:
    Nagrada(double bodovi){
        brojBodova = bodovi;
        if(bodovi >= 90 && bodovi <= 100) {
            mesto=prvaa;
        } else if(bodovi >= 80 && bodovi <= 89) {
            mesto=drugaa;
        } else if(bodovi >= 70 && bodovi <= 79) {
            mesto=trecaa;
        } else {
            mesto=pohvala;
        }
    }
    double getBrojBodova(){
        return brojBodova;
    }
    NagradaState getNagrada() {
        return mesto;
    }
    void ispisiNagrada(){
        cout<<brojBodova<<endl;
        cout<<mesto<<endl;
    }
};

#endif // NAGRADA_HPP_INCLUDED
