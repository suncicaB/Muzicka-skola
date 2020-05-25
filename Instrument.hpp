#ifndef INSTRUMENT_HPP_INCLUDED
#define INSTRUMENT_HPP_INCLUDED
#include<iostream>

using std::cout;
using std::endl;


enum InstrumentState{klavir, gitara, violina, harmonika};

class Instrument{
private:
    InstrumentState instr;
public:
    Instrument(InstrumentState instrr){
        instr=instrr;
    }
    Instrument(const Instrument& i){
        instr=i.instr;
    }
    InstrumentState getInstr()const{
        return instr;
    }
    InstrumentState setInstrument(InstrumentState instrr){
        return instr=instrr;
    }
    InstrumentState getIst()const{
        return getInstr();
    }

    void naziv() {
	switch(instr) {
          case klavir:
             cout << "klavir" << endl;
	     break;
          case gitara:
             cout << "gitara" << endl;
	     break;
          case violina:
             cout << "violina" << endl;
	     break;
          default:
             cout << "harmonika" << endl;
       }

    }
};

#endif // INSTRUMENT_HPP_INCLUDED
