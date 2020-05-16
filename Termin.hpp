#ifndef TERMIN_HPP_INCLUDED
#define TERMIN_HPP_INCLUDED

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
    DanState getDan(){
        return dan;
    }
    VremeState getVreme(){
        return vreme;
    }
    bool getZauzeto(){
        return zauzeto;
    }
    void ispisiTermin(){
        cout<<dan<<endl;
        cout<<vreme<<endl;
        cout<<zauzeto<<endl;
    }
};

#endif // TERMIN_HPP_INCLUDED
