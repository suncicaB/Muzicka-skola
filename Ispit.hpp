#ifndef ISPIT_HPP_INCLUDED
#define ISPIT_HPP_INCLUDED
#include <string>
#include<iostream>

#include "Takmicenje.hpp"

using std::string;
using std::cout;
using std::endl;

class Ispit:public Takmicenje{
private:
    string dozvola;
public:
    Ispit():Takmicenje(0), dozvola("naziv"){}
    Ispit(int uuplata, string ddozvola):Takmicenje(uuplata), dozvola(ddozvola){}

    void dajDozvolu(string imaIspit){
        dozvola=imaIspit;
    }
    void ispisi(){
        cout<<" "<<dozvola<<" "<<uplata<<endl;
    }
};


#endif // ISPIT_HPP_INCLUDED
