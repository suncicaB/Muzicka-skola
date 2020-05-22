#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
std::string delimiter = ",";

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

void unesiUcenike(string filen, Ucenik* ucenici);

int main(){

	string u_file="ucenici.txt";
	Ucenik* ucenici;
	unesiUcenike(u_file, ucenici);
    Osoba o1, o2("Pera", "Peric", 10);
    o2.ispisiOsoba();

    Ucenik u1,u2("Suncica", "Babic", 16, RazredState::drugi);
    u1.citajFajl("ucenici.txt");
    u2.upisiUcenika(u2, 100);

    Profesor p1;
    p1.citajFajl("profesori.txt");
    return 0;
}

void unesiUcenike(string filen, Ucenik* ucenici){
	ofstream fajlO;
	
	int broj = 0;
	int brU = 0;

	string linija;
	ifstream fajlI(filen);
	if(fajlI.is_open()){
		getline(fajlI, linija);
		broj = std::atoi(linija.c_str());
		ucenici = new Ucenik[broj];
		while(getline(fajlI, linija)) {
			int pos = 0;
			string ime = linija.substr(pos, linija.find(delimiter)); 
			pos = pos + delimiter.length();
			string prezime = linija.substr(pos, linija.find(delimiter));
			pos = pos + delimiter.length();
			string godine = linija.substr(pos, linija.find(delimiter));
			int god = std::atoi(godine.c_str());
			pos = pos + delimiter.length();
			string instrument = linija.substr(pos, linija.find(delimiter));
			Ucenik u(ime, prezime, god);
			ucenici[brU] = u;
			brU++;
		}
	}		

	fajlI.close();
}

void unesiProfesore(string filen, Profesor* profesori){
        ofstream fajlO;

        int broj = 0;
        int brP = 0;

        string linija;
        ifstream fajlI(filen);
        if(fajlI.is_open()){
                getline(fajlI, linija);
                broj = std::atoi(linija.c_str());
                profesori = new Profesor[broj];
                while(getline(fajlI, linija)) {
                        int pos = 0;
                        string ime = linija.substr(pos, linija.find(delimiter));
                        pos = pos + delimiter.length();
                        string prezime = linija.substr(pos, linija.find(delimiter));
                        pos = pos + delimiter.length();
                        string godine = linija.substr(pos, linija.find(delimiter));
                        int god = std::atoi(godine.c_str());
                        pos = pos + delimiter.length();
			string struka = linija.substr(pos, linija.find(delimiter));
                        Profesor p(ime, prezime, god);
			p.setStruka(struka);
                        profesori[brP] = p;
			brP++;
                }
        }

        fajlI.close();
}

