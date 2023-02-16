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
                    // con sort(). En los pares se ordena primero por el primer
                    // elemento y si son iguales, por el segundo

   public:
    Polinomio() {}
    Polinomio(vector<pair<int, int>> const& p) : polinomio(p) {}

    void insertarMonomio(pair<int, int> const m) {
        auto pos = lower_bound(polinomio.begin(), polinomio.end(), m);
        if (pos == polinomio.end())
            polinomio.push_back(m);
        else if (pos->first == m.first)
            pos->second += m.second;
        else { // Hay que desplazar
            polinomio.push_back(m);
            for (int i = polinomio.size() - 1; i > pos->second/* i > *pos */; i--)
                swap(polinomio[i], polinomio[i - 1]);
        }
    }

    long long int evaluar(int const& num) const { // No usar pow
        long long int sol = 0, pot = 1;
        int exp_anterior = 0;

        for (int i = 0; i < polinomio.size(); i++) {
            while (exp_anterior < polinomio[i].first) {
                pot *= num;
                exp_anterior++;
            }
            sol += polinomio[i].second*pot;
        }

        return sol;
    }
};

inline istream& operator>>(istream& in, Polinomio& p) {
    int coeficiente;
    int exponente;
    Polinomio pol = Polinomio();

    in >> coeficiente >> exponente;
    if (in) { // Porque puede fallar la lectura si se acaba la entrada y seguimos leyendo
        while (coeficiente != 0 || exponente != 0) {
            pol.insertarMonomio({exponente, coeficiente});
            in >> coeficiente >> exponente;
        }

        p = pol;
    }

    return in;
}

#endif