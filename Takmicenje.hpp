#ifndef TAKMICENJE_HPP_INCLUDED
#define TAKMICENJE_HPP_INCLUDED
//da bi se ucestvovalo na takmicenju treba da se uplati ucesce
#include "Koncert.hpp"

class Takmicenje{
protected:
    int uplata;
public:
    Takmicenje(){
        uplata=0;
    }
    Takmnicenje(int uplataa){
        uplata=uplataa;
    }
    virtual void ispisUplate()=0;
};

#endif // TAKMICENJE_HPP_INCLUDED
