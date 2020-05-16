#ifndef KONCERT_HPP_INCLUDED
#define KONCERT_HPP_INCLUDED
#include <vector>

#include"Ucenik.hpp"
#include"Termin.hpp"

ostream& operator<<(ostream& out, const Termin& t){
        out<<"Termin"<<endl;
        out<<"Dan:"<<t.getDan()<<endl;
        out<<"Vreme:"<<t.getVreme()<<endl;
        if(t.getZauzeto()==1){
            out<<"Termin zauzet"<<endl;
        }
        else{
            out<<"Termin nije zauzet"<<endl;
        }
        out<<endl;
        return out;
}

class Koncert:private Ucenik{
private:
    int ks;
    std::vector <Termin> ter;
public:
    Koncert():Ucenik(" ", " ", 0, pripremni), ks(0){}
    Koncert(string iime, string pprezime, int ggodine, RazredState rrazred, int kks):
        Ucenik(iime, pprezime, ggodine, rrazred), ks(kks){}

    friend ostream& operator<<(ostream& out, const Termin& t);

    void dodajT(const Termin& t){
        ter.push_back(t);
    }

    bool izbaciT(const Termin& t){
        for(auto it=ter.begin(); it<ter.end();it++){
            if(t.getZauzeto()==true){
                cout<<"Termin "<<t.getDan()<<" u "<<t.getVreme()<<"je zauzet"<<endl;
                ter.erase(it);
                cout<<"Izbrisano"<<endl;
                return true;
                }
            }
            return false;
        }


    void pregledT(){
        cout<<endl;
        cout<<"Pregled: "<<endl;
        cout<<endl;
        for(auto it=ter.begin(); it<ter.end();it++){
            cout<<*it<<endl;
        }
    }

    bool pretragaT(const Termin& t){
        for(auto it=ter.begin(); it<ter.end();it++){
            if((t.getDan().uporediDan(it->getDan())==true) && (t.getVreme().uporediVreme(it->getVreme())==true)){
               return true;
            }
        }
        return false;
    }
};

#endif // KONCERT_HPP_INCLUDED
