// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int max;
    int altura_pares;
};

tSol caminoPares(bintree<int> const& arbol) {
    if (arbol.empty())
        return {0, 0};
    else {
        tSol iz = caminoPares(arbol.left());
        tSol der = caminoPares(arbol.right());

        if (arbol.root() % 2 == 0) {
            return {
                std::max(iz.max, std::max(der.max, iz.altura_pares +
                                                       der.altura_pares + 1)),
                max(iz.altura_pares, der.altura_pares) + 1};
        } else
            return {std::max(iz.max, der.max), 0};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    // Resolver problema y escribir solución
    tSol sol = caminoPares(arbol);
    cout << sol.max << endl;
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
