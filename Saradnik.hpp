#ifndef SARADNIK_HPP_INCLUDED
#define SARADNIK_HPP_INCLUDED

enum SaradnikState{direktor, zamenik direktora, sekretar, pedagog, sef racunovodstva};

class Saradnik{
private:
    SaradnikState vrsta;
public:
    Saradnik():Osoba(" ", " ", 0), vrsta(direktor){}
    Saradnik(string iime, string pprezime, int ggodine, SaradnikState vvrsta):Osoba(iime, pprezime, ggodine), vrsta(vvrsta){}
    Saradnik(const Osoba& o, SaradnikState vrrsta):Osoba(o), vrsta(vrrsta){}
    Saradnik(const Saradnik& s):Osoba(s), vrsta(u.vrsta){}
    SaradnikState getVrsta()const{
        return vrsta;
    }
    void setVrsta(SaradnikState vvrsta){
        vrsta=vvrsta;
    }
    void predstaviSe(){
        cout<<"Dobar dan ja sam: "<<ime<<" "<<prezime<<"imam: "<<godine<<endl;
        cout<<"I u ovoj skoli sam:  "<<vrsta<<endl;
    }
};

#endif // SARADNIK_HPP_INCLUDED
