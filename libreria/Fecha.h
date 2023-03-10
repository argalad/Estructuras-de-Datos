#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#ifndef Fecha_H
#define Fecha_H

class Fecha {
   private:
    int dia;
    int mes;
    int anyo;

   public:
    Fecha() {
        dia = 0;
        mes = 0;
        anyo = 0;
    }
    Fecha(int d, int m, int a) : dia(d), mes(m), anyo(a){}

    int get_dia(){return dia;}
    int get_mes(){return mes;}
    int get_anyo(){return anyo;}
};


inline ostream& operator<<(ostream& out, Fecha& f) {
    out << setfill('0') << setw(2) << f.get_dia() << "/" << setfill('0') << setw(2) << f.get_mes() << "/" << f.get_anyo();

    return out;
}

inline istream& operator>>(istream& in, Fecha& f) {
    int dia, mes, anyo;
    char aux;

    in >> dia >> aux >> mes >> aux >> anyo;
    f = Fecha(dia, mes, anyo);

    return in;
}

#endif