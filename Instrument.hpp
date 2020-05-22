#ifndef INSTRUMENT_HPP_INCLUDED
#define INSTRUMENT_HPP_INCLUDED
//treba povezati sa drugim klasama
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
};

#endif // INSTRUMENT_HPP_INCLUDED
