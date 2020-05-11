#ifndef UCENIK_HPP_INCLUDED
#define UCENIK_HPP_INCLUDED
#include<fstream>
enum RazredState{pripremni, prvi, drugi, treci, cetvrti, peti, sesti};

class Ucenik:public Osoba{
protected:
    RazredState razred;
public:
    Ucenik():Osoba(" ", " ", 0), razred(pripremni){}
    Ucenik(string iime, string pprezime, int ggodine, RazredState rrazred):Osoba(iime, pprezime, ggodine), razred(rrazred){}
    Ucenik(const Osoba& o, RazredState razzred):Osoba(o), razred(razzred){}
    Ucenik(const Ucenik& u):Osoba(u), razred(u.razred){}
    RazredState getRazred(){
        return razred;
    }
    void setRazred(int godina){
        if(godina<7){
            cout<<"Nema dovoljno godina za upis u muzicku skolu"<<endl;
        }else if((godina>=7) && (godina<=13)){
            if(godina==7){
                razred=pripremni;
            }
            else if(godina==8){
                razred=prvi;
            }
            else if(godina==9){
                razred=drugi;
            }
            else if(godina==10){
                razred=treci;
            }
            else if(godina==11){
                razred=cetvrti;
            }
            else if(godina==12){
                razred=peti;
            }
            else if(godina==13){
                razred=sesti;
            }
        }
    }
    void predstaviSe(){
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<"imam: "<<godine<<endl;
        cout<<"I idem u: "<<razred<<endl;
    }

    string enum_to_string(RazredState type) {
       switch(type) {
          case pripremni:
             return "pripremni";
          case prvi:
             return "prvi";
          case drugi:
             return "drugi";
          case treci:
             return "treci";
          case cetvrti:
             return "cetvrti";
          case peti:
             return "peti";
          default:
             return "sesti";
       }
}
     void upisiUcenika(Ucenik ucenik, int i){
        ofstream fajl;
        string naziv=enum_to_string(ucenik.getRazred())+".txt";
        if(i>2001){
            cout<<"Popunjena mesta";
        }else{
            fajl.open(naziv);
            string upis=ucenik.getIme()+" "+ucenik.getPrezime()+" "+std::to_string(ucenik.getGodine());
            fajl<<upis<<endl;
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
    void ispisiUcenik(){
        cout<<razred<<endl;
    }
};
#endif // UCENIK_HPP_INCLUDED
