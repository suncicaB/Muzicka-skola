#ifndef PROFESOR_HPP_INCLUDED
#define PROFESOR_HPP_INCLUDED
#include <fstream>

enum ProfesorState{klavira, gitare, violine, flaute, solfedja, hora, teorije_za_muziku};

class Profesor:public Osoba{
private:
    string spisak_profesora="Profesori.txt";
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
            string zaposli=profesor.getIme()+" "+profesor.getPrezime()+" "+std::to_string(profesor.getGodine());
            fajl.open(spisak_profesora);
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
};

#endif // PROFESOR_HPP_INCLUDED
