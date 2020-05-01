#ifndef PROFESOR_HPP_INCLUDED
#define PROFESOR_HPP_INCLUDED
#include <fstream>

enum ProfesorState{klavira, gitare, violine, flaute, solfedja, hora, teorije za muziku};

class Profesor:public Osoba{
private:
    final string spisak_profesora="Profesori.txt";
    ProfesorState struka;
public:
    Profesor():Osoba(" ", " ", 0), struka(klavira){}
    Profesor(string iime, string pprezime, int ggodine, ProfesorState sstruka):Osoba(iime, pprezime, ggodine), struka(sstruka){}
    Profesor(const Osoba& o, ProfesorState sttruka):Osoba(o), struka(sttruka){}
    Profesor(const Profesor& p):Osoba(p), struka(p.struka){}
    ProfesorState getStruka()const{
        return struka;
    }
    void setStruka(ProfesorState strukaa){
        struka=strukaa;
    }
    void predstaviSe(){
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<"imam: "<<godine<<endl;
        cout<<"I predajem: "<<struka<<endl;
    }
    void zaposliProf(Profesor profesor, int i){
        ofstream fajl;
        if(i>71){
            cout<<"Popunjena radna mesta"<<endl;
        }else{
            string zaposli=Profesor.getIme()<<" "<<Profesor.getPrezime()<<" "<<Profesor.getGodine()<<endl
            fajl.open(spisak_profesora);
            fajl<<zaposli<<endl;
            fajl.close();
        }
    }
};

#endif // PROFESOR_HPP_INCLUDED
