#ifndef TERMIN_HPP_INCLUDED
#define TERMIN_HPP_INCLUDED
#include<iostream>

using std::cout;
using std::endl;

enum DanState{ponedeljak, utorak, sreda, cetvrtak, petak, subota};
enum VremeState{sest, pola_sest, sedam, pola_sedam, osam, pola_osam, devet};//uvece

class Termin{
protected:
    DanState dan;
    VremeState vreme;
    bool zauzeto;
public:
    Termin(DanState dann, VremeState vremee, bool zauzetoo){
        dan=dann;
        vreme=vremee;
        zauzeto=zauzetoo;
    }
    DanState getDan() const{
        return dan;
    }
    VremeState getVreme() const{
        return vreme;
    }
    bool getZauzeto() const{
        return zauzeto;
    }
    void ispisiTermin() const{
        cout<<dan<<endl;
        cout<<vreme<<endl;
        cout<<zauzeto<<endl;
    }
};

#endif // TERMIN_HPP_INCLUDED
