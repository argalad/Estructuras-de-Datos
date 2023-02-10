// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef Horas_h
#define Horas_h

class Horas {
   private:
    int hora, minutos, segundos;

   public:
    Horas(){};

    Horas(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            throw domain_error("ERROR");

        else {
            this->hora = h;
            this->minutos = m;
            this->segundos = s;
        }
    }

    int get_hora() const { return this->hora; }

    int get_minutos() const { return this->minutos; }

    int get_segundos() const { return this->segundos; }

    bool operator<(Horas const& h) const {
        if (hora < h.hora)
            return true;
        else if (hora == h.hora) {
            if (minutos < h.minutos)
                return true;
            else if (minutos == h.minutos) {
                if (segundos < h.segundos)
                    return true;
                else
                    return false;
            } else
                return false;
        } else
            return false;
    }

    bool operator==(Horas const& h) const {
        return (this->hora == h.hora && this->minutos == h.minutos &&
                this->segundos == h.segundos);
    }

    Horas operator+(Horas const& h) const {
        Horas hora;

        hora.hora = this->hora + h.hora;
        hora.minutos = this->minutos + h.minutos;
        hora.segundos = this->segundos + h.segundos;

        if (hora.segundos > 59) {
            hora.segundos -= 60;
            hora.minutos++;
        }

        if (hora.minutos > 59) {
            hora.minutos -= 60;
            hora.hora++;
        }

        if (hora.hora > 23)
            throw overflow_error("Hoy no");

        return hora;
    }
};

inline istream& operator>>(istream& in, Horas& h) {
    int hor, min, sec;
    char aux;

    in >> hor >> aux >> min >> aux >> sec;
    h = Horas(hor, min, sec);

    return in;
}

inline ostream& operator<<(ostream& out, Horas& h) {
    out << setfill('0') << setw(2) << h.get_hora() << ":" << setfill('0')
        << setw(2) << h.get_minutos() << ":" << setfill('0') << setw(2)
        << h.get_segundos() << endl;

    return out;
}

#endif