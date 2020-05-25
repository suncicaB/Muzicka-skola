#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
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

int main(){
	
	int broj = 0;
	int brojI = 0;
	int brojP = 0;
        int brU = 0;
        int brI = 0;
	int brP = 0;

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

	cout << "Izaberite opciju";
	cout << "1 - Upisi ucenika";
	cout << "2 - Pronadji ucenika";
	cout << "3 - Zaposli profesora";
	cout << "4 - Pronadji profesora";
	cout << "5 - Zakazi koncert";
	cout << "6 - Pregledaj spisak koncerata ";


    return 0;
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
			pos = pos + delimiter.length();
			string prezime = linija.substr(pos, linija.find(delimiter));
			pos = pos + delimiter.length();
			string godine = linija.substr(pos, linija.find(delimiter));
			int god = std::atoi(godine.c_str());
			pos = pos + delimiter.length();
			string instrument = linija.substr(pos, linija.find(delimiter));
			InstrumentState instr = kreirajInstrument(instrument);
			Ucenik u(ime, prezime, god);
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
                        pos = pos + delimiter.length();
                        string prezime = linija.substr(pos, linija.find(delimiter));
                        pos = pos + delimiter.length();
                        string godine = linija.substr(pos, linija.find(delimiter));
                        int god = std::atoi(godine.c_str());
                        pos = pos + delimiter.length();
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
