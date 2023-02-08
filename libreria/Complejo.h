// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#ifndef Complejo_h
#define Complejo_h

class Complejo {
    
private:

    float real;
    float imaginario;

public:

    Complejo() {};

    Complejo(float r, float i) : real(r), imaginario(i) {};

    Complejo operator+ (Complejo const &c) const {
        return {real + c.real, imaginario + c.imaginario};
    }

    Complejo operator* (Complejo const &c) const {
        return {real * c.real - imaginario * c.imaginario, real * c.imaginario + c.real * imaginario};
    }

    float modulo() const {
        return sqrt(pow(real, 2) + pow(imaginario, 2));
    }

};

inline istream& operator>> (istream& in, Complejo &c) {
	float real;
    float imaginario;

	in >> real >> imaginario;
	c = Complejo(real, imaginario);

	return in;
}

#endif