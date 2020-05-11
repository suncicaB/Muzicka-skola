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
    Takmicenje(string iime, string pprezime, int ggodine, RazredState rrazred,
               double bbodovi): ucesnik(iime, pprezime, ggodine, rrazred), bodovi(bbodovi){}
    void takmicenje(){
            ucesnik.ispisiUcenik();
            bodovi.ispisiNagrada();
    }
};

#endif // TAKMICENJE_HPP_INCLUDED
