// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int num_elem;
    bool zurdo;
};

tSol zurdo(bintree<char> arbol) {
    if (arbol.empty())
        return {0, true};
    else if (arbol.left().empty() && arbol.right().empty()) {
        return {1, true};
    }
    else {
        tSol iz = zurdo(arbol.left());
        tSol der = zurdo(arbol.right());

        if (iz.zurdo && der.zurdo && iz.num_elem > der.num_elem)
            return {iz.num_elem + der.num_elem + 1, true};
        else
            return {iz.num_elem + der.num_elem + 1, false};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');

    // Resolver problema y mostrar solución
    if (zurdo(arbol).zurdo)
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
