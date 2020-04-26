#ifndef PROFESOR_HPP_INCLUDED
#define PROFESOR_HPP_INCLUDED

enum ProfesorState{klavira, gitare, violine, flaute, solfedja, hora, teorije za muziku};

class Profesor:public Osoba{
private:
    ProfesorState struka;
public:
    Profesor():Osoba(" ", " ", 0), struka(klavira){}
    Profesor(string iime, string pprezime, int ggodine, ProfesorState sstruka):Osoba(iime, pprezime, ggodine), struka(sstruka){}
    Profesor(const Osoba& o, ProfesorState sttruka):Osoba(o), struka(sttruka){}
    Profesor(const Profesor& u):Osoba(u), struka(u.struka){}
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
};

#endif // PROFESOR_HPP_INCLUDED
