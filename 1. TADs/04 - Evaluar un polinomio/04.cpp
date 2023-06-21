#include <algorithm>
#include <fstream>
#include <iostream>

#include "Polinomio.h"  // Propios o los de las estructuras de datos de clase

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Polinomio p;
    int num_evaluaciones, num;

    // Leer los datos de la entrada
    cin >> p;
    if (!cin)  // Fin de la entrada
        return false;

    cin >> num_evaluaciones;
    for (int i = 0; i < num_evaluaciones; i++) {
        cin >> num;
        cout << p.evaluar(num) << " ";
    }

    cout << endl;

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
