#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

class Osoba{
protected:
    string ime;
    string prezime;
    int godine;
public:
    Osoba(string iime, string pprezime, int ggodine){
        ime=iime;
        prezime=pprezime;
        godine=ggodine;
    }
    Osoba(){
        ime=" ";
        prezime=" ";
        godine=0;
    }
    Osoba(const Osoba& o){
        ime=o.ime;
        prezime=o.prezime;
        godine=o.godine;
    }
    string getIme()const{
        return ime;
    }
    string getPrezime()const{
        return prezime;
    }
    int getGodine()const{
        return godine;
    }
    void setIme(string iime){
        ime=iime;
    }
    void setPrezime(string pprezime){
        prezime=pprezime;
    }
    void setGodine(int ggodine){
        godine=ggodine;
    }
    void predstaviSe(){
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<"imam: "<<godine<<endl;
    }
};

#endif // OSOBA_HPP_INCLUDED
