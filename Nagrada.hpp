#ifndef NAGRADA_HPP_INCLUDED
#define NAGRADA_HPP_INCLUDED

enum NagradaState{pohvala, treca, druga, prva};

class Nagrada{
private:
    double brojBodova;
    NagradaState mesto;
public:
    Nagrada(double bodovi){
        brojBodova = bodovi;
        if(bodovi >= 90 && bodovi <= 100) {
            mesto=prva;
        } else if(bodovi >= 80 && bodovi <= 89) {
            mesto=druga;
        } else if(bodovi >= 70 && bodovi <= 79) {
            mesto=treca;
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
};

#endif // NAGRADA_HPP_INCLUDED
