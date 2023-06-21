#include <fstream>
#include <iostream>
#include <climits>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    bool de_busqueda;
    int max;
    int min;
};

tSol esArbolBinarioBusqueda(const bintree<int>& arbol,
                            int max_left,
                            int min_right) {
    if (arbol.empty())
        return {true, INT_MIN, INT_MAX};

    tSol left = esArbolBinarioBusqueda(arbol.left(), max_left, min_right);
    tSol right = esArbolBinarioBusqueda(arbol.right(), max_left, min_right);

    bool de_busqueda = left.de_busqueda && right.de_busqueda &&
                       arbol.root() > left.max && arbol.root() < right.min;

    int max = std::max(arbol.root(), std::max(left.max, right.max));
    int min = std::min(arbol.root(), std::min(left.min, right.min));

    if (arbol.left().empty())
        max_left = std::max(max_left, arbol.root());

    if (arbol.right().empty())
        min_right = std::min(min_right, arbol.root());

    return {de_busqueda, max, min};
}

void resuelveCaso() {
    bintree<int> arbol;

    // Leer los datos de la entrada
    arbol = leerArbol(-1);

    // Resolver problema y mostrar solución
    tSol sol = esArbolBinarioBusqueda(arbol, INT_MIN, INT_MAX);

    if (sol.de_busqueda)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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