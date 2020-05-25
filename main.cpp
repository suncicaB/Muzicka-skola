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
void upisiUcenika(vector<Ucenik> &ucenici);
void pronadjiUcenika(vector<Ucenik> &ucenici);
void prikaziSpisakUcenika(vector<Ucenik> &ucenici);
void zaposliProfesora(vector<Profesor> &profesori);
void pronadjiProfesora(vector<Profesor> &profesori);
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
	for(Profesor prof:profesori) {
		Predmet p(prof.getIme());
		predmeti.push_back(p);
	}

	ispisOpcija();
	cin >> opcija;

	while(opcija != -1) {
		if(opcija == 0) {
			ispisOpcija();
			break;			
		} else if(opcija == 1) {
			upisiUcenika(ucenici);
			break;
		} else if(opcija == 2) {
			pronadjiUcenika(ucenici);
			break;
		} else if(opcija == 3) {
			prikaziSpisakUcenika(ucenici);
			break;
		} else if (opcija == 4) {
			zaposliProfesora(profesori);
			break;
		} else if(opcija == 5) {
			pronadjiProfesora(profesori);
			break;
		} else if(opcija == 6) {
			prikaziSpisakProfesora(profesori);
			break;
		} else if(opcija == 7) {
			zakaziKoncert();
			break;
		} else {
			pregledajSpisakKoncerata();
			break;
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
	    for (Predmet p:predmeti) {
	   	 string upis=p.getProfesor();
           	 fajl<<upis<<endl;

	    }
            fajl.close();

}

void upisiUcenika(vector<Ucenik> &ucenici){
	string ime;
	string prezime;
	int godine;
	string instrument;
	
	cin.ignore(1000, '\n');
	cout << "Unesite ime ucenika: " << endl;
	getline(cin, ime);
	cout << "Unesite prezime ucenika: " << endl;
	getline(cin, prezime);
        cout << "Unesite godine ucenika: " << endl;
	cin >> godine;
	cin.ignore(1000, '\n');
	cout << "Unesite naziv instrumenta:" << endl;
	getline(cin,instrument);
        Ucenik u(ime, prezime, godine);
	InstrumentState instr = kreirajInstrument(instrument);
        u.setRazred(godine);
        Instrument uInstrument (instr);
        u.setInstrument(&uInstrument);

	u.upisiUcenika(u, 1);
	ucenici.push_back(u);
	
}
void pronadjiUcenika(vector<Ucenik> &ucenici){
	string ime;

	cin.ignore(1000, '\n');
        cout << "Unesite ime ucenika: " << endl;
        getline(cin, ime);
	for(Ucenik u:ucenici) {
		if(u.getIme().compare(ime) == 0) {
			u.predstaviSe();
		}
	}
	cout<<"Ne postoji ucenik sa tim imenom!"<<endl;

}
void prikaziSpisakUcenika(vector<Ucenik> &ucenici){
	for(Ucenik u:ucenici) {
		u.predstaviSe();
	}
}
void zaposliProfesora(vector<Profesor> &profesori){
	string ime;
        string prezime;
        int godine;
        string instrument;

        cin.ignore(1000, '\n');
        cout << "Unesite ime profesora: " << endl;
        getline(cin, ime);
        cout << "Unesite prezime profesora: " << endl;
        getline(cin, prezime);
        cout << "Unesite godine profesora: " << endl;
        cin >> godine;
        cin.ignore(1000, '\n');
        cout << "Unesite naziv instrumenta:" << endl;
        getline(cin,instrument);
        Profesor p(ime, prezime, godine);
        p.setStruka(instrument);

        p.zaposliProf(p, 1);
        profesori.push_back(p);

}
void pronadjiProfesora(vector<Profesor> &profesori){

}
void prikaziSpisakProfesora(vector<Profesor> &profesori){
	for(Profesor p:profesori) {
		p.predstaviSe();
	}
}
void zakaziKoncert(){}
void pregledajSpisakKoncerata(){}

