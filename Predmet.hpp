#ifndef PREDMET_HPP_INCLUDED
#define PREDMET_HPP_INCLUDED
#include <string>
using std::string;

class Predmet{
private:
    string profesor;
public:
    Predmet(){}
    Predmet(string iime){}

    string getProfesor(){
	    return profesor;
    }
};

#endif // PREDMET_HPP_INCLUDED
