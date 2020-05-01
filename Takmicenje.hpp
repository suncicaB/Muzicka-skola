#ifndef TAKMICENJE_HPP_INCLUDED
#define TAKMICENJE_HPP_INCLUDED
//metoda da dodeluje uceniku nagradu
#include "Ucenik.hpp"
#include "Nagrada.hpp"

class Takmicenje{
private:
    Ucenik ucesnik;
    Nagrada bodovi;
public:
    Takmicenje( string iime=" ",
               string pprezime = " ",
               int ggodine=0,
               RazredState rrazred=pripremni,
               double bbodovi=0): ucesnik(iime, pprezime, ggodine, rrazred), bodovi(bbodovi){}
    Takmicenje( string iime,
               string pprezime,
               int ggodine,
               RazredState rrazred,
               double bbodovi): ucesnik(iime, pprezime, ggodine, rrazred), bodovi(bbodovi){}

    Ucenik getUcesnik(){
        return ucesnik;
    }

    Nagrada getNagrad(){
        return bodovi;
    }

    string getIme() {
        return ucesnik.getIme();
    }

    string getPrezime() {
        return ucesnik.getPrezime();
    }

    NagradaState getNagrada() {
        return bodovi.getNagrada();
    }

    double getOsvojeniBodovi() {
        return bodovi.getBrojBodova();
    }
};

#endif // TAKMICENJE_HPP_INCLUDED
