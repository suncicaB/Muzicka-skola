#ifndef ISPIT_HPP_INCLUDED
#define ISPIT_HPP_INCLUDED
#include "Profesor.hpp"
#include "Termin.hpp"

class Ispit{
private:
    Termin termin;
    Profesor ispitivac;
public:
    Ispit(TerminState ts, DanState ds,
          string iime,
          string pprezime,
          int ggodine,
          ProfesorState sstruka):termin(ts, ds), ispitivac(iime, pprezime, ggodine, sstruka){}

    Ispit():termin(TerminState.jedan, DanState.ponedeljak), ispitivac("", "", 0, ProfesorState.klavira){}

    Termin getTermin() {
        return termin;
    }

    Profesor getIspitivac() {
        return ispitivac;
    }

    DanState getDanIspita() {
        return termin.getDan();
    }
};


#endif // ISPIT_HPP_INCLUDED
