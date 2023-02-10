// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#ifndef Polinomio_h
#define Polinomio_h

class Polinomio {
   private:
    vector<pair<int, int>>
        polinomio;  // first = exponente, second = coeficiente, para ordenarlos
                    // con sort()

   public:
    Polinomio() {}
    Polinomio(vector<pair<int, int>> const& p) : polinomio(p) {}

    void insertarMonomio(pair<int, int> const m) {
        polinomio.push_back(m);
        sort(polinomio.begin(), polinomio.end());
    }

    long int evaluar(int const& num) const {
        long int sol = 0;

        for (pair<int, int> p : polinomio)
            sol += p.second * pow(num, p.first);

        return sol;
    }
};

inline istream& operator>>(istream& in, Polinomio& p) {
    int coeficiente;
    int exponente;
    Polinomio pol = Polinomio();

    in >> coeficiente >> exponente;
    if (in) {
        while (coeficiente != 0 || exponente != 0) {
            pol.insertarMonomio({exponente, coeficiente});
            in >> coeficiente >> exponente;
        }

        p = pol;
    }

    return in;
}

#endif