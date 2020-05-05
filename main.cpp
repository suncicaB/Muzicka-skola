#include <iostream>
#include <fstream>

using namespace std;

#include "Osoba.hpp"
#include "Ucenik.hpp"
#include "Profesor.hpp"

int main(){
    Ucenik u1,u2("Suncica", "Babic", 16, RazredState::drugi);
    u1.citajFajl("ucenici.txt");
    u2.upisiUcenika(u2, 100);

    Profesor p1;
    p1.citajFajl("profesori.txt");
    return 0;
}
