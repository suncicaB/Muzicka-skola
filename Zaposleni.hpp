#ifndef ZAPOSLENI_HPP_INCLUDED
#define ZAPOSLENI_HPP_INCLUDED
//metoda za kontzrolisanje broja zaposlenih i ispisivaje poruke da moze da se zaposljavaju novi ljudi
class Zaposleni{
private:
    int broj;
public:
    Zaposleni(int bbroj){
        broj=bbroj;
    }
    Zaposleni(){
        broj=1;
    }
    Zaposleni(const Zaposleni& z){
        broj=z.broj;
    }
    int getBroj()const{
        return broj;
    }
    void setBroj(int bbroj){
        broj=bbroj;
    }
    void kontrola(int i){
        if(i>71){
            cout<<"Radna mesta su popunjena"<<endl;
        }
        else{
            cout<<"Slanje zahteva za zaposljavanje"<<endl;
        }
    }
    //void Broj
};

#endif // ZAPOSLENI_INCLUDED
