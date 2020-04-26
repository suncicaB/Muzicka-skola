#ifndef PREDMET_HPP_INCLUDED
#define PREDMET_HPP_INCLUDED

#include "Profesor.hpp"
#include "Ucenik.hpp"

class Predmet{
private:
    Profesor profesori;
    Ucenik ucenici;
public:
    Predmet():profesori(), ucenici(){}
};

#endif // PREDMET_HPP_INCLUDED
