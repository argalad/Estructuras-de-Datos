#include <fstream>
#include <iostream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int nodos_acumuladores;
    int suma;
};

tSol numAcumuladores(bintree<int> const& arbol) {
    if (arbol.empty())
        return {0, 0};
    if (arbol.left().empty() && arbol.right().empty())
        return {arbol.root() == 0 ? 1 : 0, arbol.root()};
    else if (arbol.left().empty()) {
        auto der = numAcumuladores(arbol.right());

        if (der.suma == arbol.root())
            return {der.nodos_acumuladores + 1, der.suma + arbol.root()};
        else
            return {der.nodos_acumuladores, der.suma + arbol.root()};
    } else if (arbol.right().empty()) {
        auto iz = numAcumuladores(arbol.left());

        if (iz.suma == arbol.root())
            return {iz.nodos_acumuladores + 1, iz.suma + arbol.root()};
        else
            return {iz.nodos_acumuladores, iz.suma + arbol.root()};
    } else {
        auto iz = numAcumuladores(arbol.left());
        auto der = numAcumuladores(arbol.right());
        int acumulados = iz.nodos_acumuladores + der.nodos_acumuladores;

        if (iz.suma + der.suma == arbol.root())
            return {acumulados + 1,
                    iz.suma + der.suma + arbol.root()};
        else
            return {acumulados,
                    iz.suma + der.suma + arbol.root()};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;

    // Leer los datos de la entrada
    arbol = leerArbol(-1);

    // Resolver problema y mostrar solución
    auto solucion = numAcumuladores(arbol);
    cout << solucion.nodos_acumuladores << endl;
}

int main() {
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
