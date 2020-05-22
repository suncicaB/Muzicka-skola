switch(godine){
case pripemni:
    cout << "7";
    break;
case prvi:
    cout << "8";
    break;
case drugi:
    cout << "9";
    break;
case treci:
    cout << "10";
    break;
case cetvrti:
    cout << "11";
    break;
case peti:
    cout << "12";
    break;
case sesti:
    cout << "13";
    break;
}
void Godinee(int i){
//i oznacava broj godina
i=godine;
for(i=7;i<=13;i++){
    razred++;
}
}

    Ucenik(string iime, string pprezime, int ggodine, RazredState rrazred){
        ime=iime;
        prezime=pprezime;
        godine=ggodine;
        razred=rrazred;
    }
    Ucenik(){
        ime=" ";
        prezime=" ";
        godine=0;
        razred=pripremni;
    }
    Ucenik(const Ucenik& u){
        ime=u.ime;
        prezime=u.prezime;
        godine=u.godine;
        razred=u.razred;
    }
    string getIme()const{
        return ime;
    }
    string getPrezime()const{
        return prezime;
    }
    int getGodine()const{
        return godine;
    }
    RazredState getRazred()const{
        return razred;
    }
    void setIme(string iime){
        ime=iime;
    }
    void setPrezime(string pprezime){
        prezime=pprezime;
    }
    void setGodine(int ggodine){
        godine=ggodine;
    }

    Profesor(string imee, string prezimee, ProfesorState sstruka){
        ime=imee;
        prezime=prezimee;
        struka=sstruka;
    }
    Profesor(){
        ime=" ";
        prezime=" ";
        struka=pijanista;
    }
    Profesor(const Profesor& p){
        ime=p.ime;
        prezime=p.prezime;
        struka=p.struka;
    }
    string getIme()const{
        return ime;
    }
    string getPrezime()const{
        return prezime;
    }
    ProfesorState getStruka()const{
        return struka;
    }
    void setIme(string imee){
        ime=imee;
    }
    void setPrezime(string prezimee){
        prezim=prezimee;
    }
    void setKlasa(ProfesorState sstruka){
        struka=sstruka;
    }

        Saradnik(string imme, string prrezima, SaradnikState vvrsta){
        ime=imee;
        prezime=prezimee;
        vrsta=vvrsta;
    }
    Saradnik(const Saradnik& s){
        ime=s.ime;
        prezime=s.prezime;
        vrsta=s.vrsta;
    }
    string getIme()const{
        return ime;
    }
    string getPrezime()const{
        return prezime;
    }
    SaradnikState getVrsta()const{
        return vrsta;
    }
    void setIme(string imme){
        ime=imme;
    }
