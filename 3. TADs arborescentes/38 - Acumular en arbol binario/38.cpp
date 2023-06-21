#include <fstream>
#include <iostream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

bintree<int> acumula(bintree<int> const& arbol) {
    bintree<int> solucion;

    if (arbol.empty())
        return {-1, -1, -1};
    if (arbol.left().empty() && arbol.right().empty())
        return {-1, arbol.root(), -1};
    else if (arbol.left().empty()) {
        auto der = acumula(arbol.right());
        return {-1, der.root(), der};
    }
    else if (arbol.right().empty()) {
        auto iz = acumula(arbol.left());
        return {iz, iz.root(), -1};
    }
    else {
        auto iz = acumula(arbol.left());
        auto der = acumula(arbol.right());

        return {iz, iz.root() + der.root(), der};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;

    // Leer los datos de la entrada
    arbol = leerArbol(-1);

    // Resolver problema y mostrar solución
    auto solucion = acumula(arbol);
    vector<int> sol = solucion.preorder();

    for (int i : sol)
        if (i != -1)
            cout << i << " ";
    cout << endl;
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
