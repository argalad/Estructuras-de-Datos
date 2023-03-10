// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <stack>

#include "Fecha.h"

using namespace std;

typedef struct {
    Fecha f;
    int fallecidos;
} Accidente;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_casos;
    stack<Accidente> pila;
    Accidente acc;

    // Leer los datos de la entrada
    cin >> num_casos;
    if (!cin)
        return false;
    
    for (int i = 0; i < num_casos; i++)
    {
        cin >> acc.f >> acc.fallecidos;
        while (!pila.empty() && pila.top().fallecidos <= acc.fallecidos)
            pila.pop();
        if (pila.empty())
            cout << "NO HAY" << endl;
        else
            cout << pila.top().f << endl;
        pila.push(acc);
    }
    cout << "---" << endl;

    return true;
}

int main() {
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
