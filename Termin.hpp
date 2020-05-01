#ifndef TERMIN_HPP_INCLUDED
#define TERMIN_HPP_INCLUDED

enum TerminState{jedan, dva, tri, cetiri, pet};
enum DanState{ponedeljak, utorak, sreda, cetvrtak, petak, subota};

class Termin{
protected:
    TerminState termin;
    DanState dan;
public:
    Termin(TerminState ts, DanState ds){
        termin = ts;
        dan = dan;
    }

    TerminState getTermin(){
        return termin;
    }

    DanState getDan() {
        return dan;
    }
};

#endif // TERMIN_HPP_INCLUDED
