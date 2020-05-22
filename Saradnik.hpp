#ifndef SARADNIK_HPP_INCLUDED
#define SARADNIK_HPP_INCLUDED
#include <fstream>
#include "Osoba.hpp"

enum SaradnikState{direktor, zamenik_direktora, sekretar, pedagog, sef_racunovodstva};

class Saradnik:public Osoba{
private:
    SaradnikState vrsta;
public:
    Saradnik():Osoba(" ", " ", 0), vrsta(direktor){}
    Saradnik(string iime, string pprezime, int ggodine, SaradnikState vvrsta):Osoba(iime, pprezime, ggodine), vrsta(vvrsta){}
    Saradnik(const Osoba& o, SaradnikState vrrsta):Osoba(o), vrsta(vrrsta){}
    Saradnik(const Saradnik& s):Osoba(s), vrsta(s.vrsta){}
    SaradnikState getVrsta()const{
        return vrsta;
    }
    void setVrsta(SaradnikState vvrsta){
        vrsta=vvrsta;
    }
    void predstaviSe(){
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<"imam: "<<godine<<endl;
        cout<<"I u ovoj skoli sam:  "<<vrsta<<endl;
    }
    void ispisiSaradnik(){
        cout<<vrsta<<endl;
    }
};

#endif // SARADNIK_HPP_INCLUDED
