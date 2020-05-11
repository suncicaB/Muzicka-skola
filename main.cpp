#include <iostream>
#include <fstream>

using namespace std;

#include "Osoba.hpp"
#include "Ucenik.hpp"
#include "Profesor.hpp"
#include "Saradnik.hpp"
#include "Zaposleni.hpp"
#include "Predmet.hpp"
#include "Instrument.hpp"
#include "Ispit.hpp"
#include "Koncert.hpp"
#include "Takmicenje.hpp"
#include "Nagrada.hpp"
#include "Termin.hpp"

int Osoba::godine=7;

int main(){
    Osoba o1, o2("Pera", "Peric", 10);
    o2.ispisiOsoba();

    Ucenik u1,u2("Suncica", "Babic", 16, RazredState::drugi);
    u1.citajFajl("ucenici.txt");
    u2.upisiUcenika(u2, 100);

    Profesor p1;
    p1.citajFajl("profesori.txt");
    return 0;
}
