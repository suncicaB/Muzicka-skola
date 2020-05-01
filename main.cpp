#include <iostream>

using namespace std;

#include "Osoba.hpp"
#include "Ucenik.hpp"
#include "Profesor.hpp"

int main(){
    Osoba o1, o2("Pera", "Peric", 10);
    Osoba predstaviSe(o2);

    Ucenik u1, u2("Mitar", "Mitrovic", 8);

    Profesor p1, p2("Nikola", "Nikolic", 35)
    return 0;
}
