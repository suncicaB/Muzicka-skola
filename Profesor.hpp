#ifndef PROFESOR_HPP_INCLUDED
#define PROFESOR_HPP_INCLUDED
#include <fstream>
#include "Osoba.hpp"
using std::ofstream;
using std::ifstream;

enum ProfesorState{klavira, gitare, violine, harmonike, solfedja, hora, teorije_za_muziku};

class Profesor:public Osoba{
private:
    string spisak_profesora="profesori.txt";
    ProfesorState struka;
public:
    Profesor():Osoba(" ", " ", 0), struka(klavira){}
    Profesor(string iime, string pprezime, int ggodine, ProfesorState sstruka):Osoba(iime, pprezime, ggodine), struka(sstruka){}
    Profesor(const Osoba& o, ProfesorState sttruka):Osoba(o), struka(sttruka){}
    Profesor(const Profesor& p):Osoba(p), struka(p.struka){}
     Profesor(string iime, string pprezime, int ggodine): Osoba(iime, pprezime, ggodine), struka(klavira){}
    ProfesorState getStruka()const{
        return struka;
    }
    void setStruka(ProfesorState strukaa){
        struka=strukaa;
    }
    void predstaviSe(){
	    string struk=enum_to_string(struka);
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<" imam: "<<godine<<endl;
        cout<<"Profesor sam "<<struk<<endl;
    }
    void zaposliProf(Profesor profesor, int i){
        ofstream fajl;
        if(i>71){
            cout<<"Popunjena radna mesta"<<endl;
        }else{
            string zaposli=profesor.getIme()+","+profesor.getPrezime()+","+std::to_string(profesor.getGodine());
            fajl.open(spisak_profesora,std::ios_base::app);
            fajl<<zaposli<<endl;
            fajl.close();
        }
    }
    void citajTxt(string nazivFajla){
    string linija;
    ifstream fajl(nazivFajla);
    if(fajl.is_open()){
        while(getline(fajl, linija)){
            cout<<linija<<'\n';
        }
        fajl.close();
    }else{
        cout<<"Neuspesno otvoren fajl";
    }
}
    void citajFajl(string nazivFajla){
        cout<<"U fajlu pise: "<<endl;
        citajTxt(nazivFajla);
        cout<<endl<<endl;
    }
    void ispisiProfesor(){
        cout<<struka<<endl;
    }
   void setStruka(string struka){
            if(struka.compare("klavir") == 0){
                struka=ProfesorState::klavira;
            }
            else if(struka.compare("gitara") == 0){
                struka = ProfesorState::gitare;
            }
	    else if(struka.compare("violina") == 0){
                struka = ProfesorState::violine;
            }
		else if(struka.compare("harmonika") == 0){
                struka = ProfesorState::harmonike;
            } else {
	    	struka = ProfesorState::solfedja;
	    }


        }
string enum_to_string(ProfesorState type) {
       switch(type) {
          case klavira:
             return "klavira";
          case gitare:
             return "gitare";
          case violine:
             return "violine";
          default:
             return "harmonike";
       }
}

};

#endif // PROFESOR_HPP_INCLUDED
