// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Horas.h"

using namespace std;

#ifndef Pelicula_h
#define Pelicula_h

class Pelicula {
   private:
    string nombre;
    Horas hora_inicio;
    Horas duracion;
    Horas hora_fin;

   public:
    Pelicula(){};

    Pelicula(string s, Horas h, Horas d)
        : nombre(s), hora_inicio(h), duracion(d), hora_fin(h + d){};

    string get_nombre() const { return this->nombre; }
    Horas get_hora_inicio() const { return this->hora_inicio; }
    Horas get_duracion() const { return this->duracion; }
    Horas get_hora_fin() const { return this->hora_fin; }

    bool operator<(Pelicula const& p) const {
        if (hora_fin < p.hora_fin)
            return true;
        else if (hora_fin == p.hora_fin)
            return nombre < p.nombre;
        else
            return false;
    }
};

inline istream& operator>>(istream& in, Pelicula& p) {
    string nombre;
    Horas hora_inicio;
    Horas duracion;

    in >> hora_inicio >> duracion;
    getline(in, nombre);
    p = Pelicula(nombre, hora_inicio, duracion);

    return in;
}

inline ostream& operator<<(ostream& out, Pelicula const& p) {
    out << setfill('0') << setw(2) << p.get_hora_fin().get_hora() << ":"
        << setfill('0') << setw(2) << p.get_hora_fin().get_minutos() << ":"
        << setfill('0') << setw(2) << p.get_hora_fin().get_segundos() << " "
        << p.get_nombre() << endl;
    return out;
}

#endif