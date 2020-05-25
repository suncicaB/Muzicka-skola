#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::cin;
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


void unesiUcenike(int &broj, int &brojI, string filen, vector<Ucenik> &ucenici, vector<Instrument>  &instrumenti);
void unesiProfesore(int &brojP, string filen, vector<Profesor> &profesori);
InstrumentState kreirajInstrument(string instrument);
void sacuvajPredmete(int &pred, string fn, vector<Predmet> &predmeti);
void ispisOpcija();
void upisiUcenika();
void pronadjiUcenika();
void prikaziSpisakUcenika(vector<Ucenik> &ucenici);
void zaposliProfesora();
void pronadjiProfesora();
void prikaziSpisakProfesora(vector<Profesor> &profesori);
void zakaziKoncert();
void pregledajSpisakKoncerata();

int main(){
	
	int broj = 0;
	int brojI = 0;
	int brojP = 0;
        int brU = 0;
        int brI = 0;
	int brP = 0;

	int opcija = 0;

	vector<Instrument> instrumenti;

	string u_file="ucenici.txt";
	vector<Ucenik> ucenici;
	unesiUcenike(broj, brojI, u_file, ucenici, instrumenti);

	string p_file="profesori.txt";
	vector<Profesor> profesori;
	unesiProfesore(brojP, p_file, profesori);

	vector<Predmet> predmeti;
	//kreiraj predmete
	for(int i = 0; i < brojP; i++) {
		Profesor prof = profesori[i];
		Predmet p(prof.getIme());
		predmeti.push_back(p);
	}

	ispisOpcija();
	cin >> opcija;

	while(opcija != -1) {
		if(opcija == 0) {
			ispisOpcija();			
		} else if(opcija == 1) {
			upisiUcenika();
		} else if(opcija == 2) {
			pronadjiUcenika();
		} else if(opcija == 3) {
			prikaziSpisakUcenika(ucenici);
		} else if (opcija == 4) {
			zaposliProfesora();
		} else if(opcija == 5) {
			pronadjiProfesora();
		} else if(opcija == 6) {
			prikaziSpisakProfesora(profesori);
		} else if(opcija == 7) {
			zakaziKoncert();
		} else {
			pregledajSpisakKoncerata();
		}
	}

    return 0;
}

void ispisOpcija() {
	cout << "Izaberite opciju:\n";
        cout << "1 - Upisi ucenika\n";
        cout << "2 - Pronadji ucenika\n";
        cout << "3 - Prikazi spisak ucenika\n";
        cout << "4 - Zaposli profesora\n";
        cout << "5 - Pronadji profesora\n";
        cout << "6 - Prikazi spisak profesora\n";
        cout << "7 - Zakazi koncert\n";
        cout << "8 - Pregledaj spisak koncerata \n";
        cout << "Unesite '-1' da zavrsite program \n";
}

void unesiUcenike(int &broj, int &brojI, string filen, vector<Ucenik> &ucenici, vector<Instrument>  &instrumenti){
	ofstream fajlO;
	
	int brU = 0;
	int brI = 0;

	string linija;
	ifstream fajlI(filen);
	if(fajlI.is_open()){
		getline(fajlI, linija);
		broj = std::atoi(linija.c_str());
		while(getline(fajlI, linija)) {
			int pos = 0;
			string ime = linija.substr(pos, linija.find(delimiter)); 
			linija = linija.substr(ime.size() + delimiter.length());
			string prezime = linija.substr(pos, linija.find(delimiter));
			linija = linija.substr(prezime.size() + delimiter.length());
			string godine = linija.substr(pos, linija.find(delimiter));
			linija = linija.substr(godine.size() + delimiter.length());
			int god = std::atoi(godine.c_str());
			string instrument = linija.substr(pos);
			InstrumentState instr = kreirajInstrument(instrument);
			Ucenik u(ime, prezime, god);
			u.setRazred(god);
			Instrument uInstrument (instr);
			instrumenti.push_back(uInstrument);
			u.setInstrument(&uInstrument);
			
			ucenici.push_back(u);
			brU++;
		}
	}		

	fajlI.close();
}

void unesiProfesore(int &brojP, string filen, vector<Profesor> &profesori){
        ofstream fajlO;

        int brP = 0;

        string linija;
        ifstream fajlI(filen);
        if(fajlI.is_open()){
                getline(fajlI, linija);
                brojP = std::atoi(linija.c_str());
                while(getline(fajlI, linija)) {
                        int pos = 0;
                        string ime = linija.substr(pos, linija.find(delimiter));
                        linija = linija.substr(ime.size() + delimiter.length());
			string prezime = linija.substr(pos, linija.find(delimiter));
                        linija = linija.substr(prezime.size() + delimiter.length());
                        string godine = linija.substr(pos, linija.find(delimiter));
                        linija = linija.substr(godine.size() + delimiter.length());
			int god = std::atoi(godine.c_str());
			string struka = linija.substr(pos, linija.find(delimiter));
                        Profesor p(ime, prezime, god);
			p.setStruka(struka);
                        profesori.push_back(p);
			brP++;
                }
        }

        fajlI.close();
}

InstrumentState kreirajInstrument(string instrument){
	if(instrument.compare("klavir")){
		return InstrumentState::klavir;
	}
	else if (instrument.compare("harmonika")) {
		return InstrumentState::harmonika;
	}
	else if (instrument.compare("violina")) {
		return InstrumentState::violina;
	}
	else{
		return InstrumentState::gitara;
	}
}

        
void sacuvajPredmete(int &pred, string fn, vector<Predmet> &predmeti) {
	ofstream fajl;
            fajl.open(fn);
	    for (int i = 0; i < pred; i ++) {
	   	 string upis=predmeti.front().getProfesor();
           	 fajl<<upis<<endl;

	    }
            fajl.close();

}

void upisiUcenika(){}
void pronadjiUcenika(){}
void prikaziSpisakUcenika(vector<Ucenik> &ucenici){
	for(int i = 0; i < ucenici.size(); i++) {
		Ucenik u = ucenici.front();
		u.predstaviSe();
	}
}
void zaposliProfesora(){}
void pronadjiProfesora(){}
void prikaziSpisakProfesora(vector<Profesor> &profesori){
	for(int i = 0; i < profesori.size(); i++) {
		Profesor p = profesori.front();
		p.predstaviSe();
	}
}
void zakaziKoncert(){}
void pregledajSpisakKoncerata(){}

