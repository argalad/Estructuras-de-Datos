#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int caudal;
    int tramos_navegables;
};

tSol tramosNavegabes(bintree<int> const& arbol) {
    if (arbol.empty())
        return {0, 0};
    else {
        if (arbol.left().empty() && arbol.right().empty() && arbol.root() == 0)
            return {1, 0};

        tSol iz = tramosNavegabes(arbol.left());
        tSol der = tramosNavegabes(arbol.right());
        int caudal = std::max(iz.caudal + der.caudal - arbol.root(), 0);

        if (iz.caudal >= 3 && der.caudal >= 3)
            return {caudal, iz.tramos_navegables + der.tramos_navegables + 2};
        else if (iz.caudal >= 3 || der.caudal >= 3)
            return {caudal, iz.tramos_navegables + der.tramos_navegables + 1};
        else
            return {caudal, iz.tramos_navegables + der.tramos_navegables};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    // Resolver problema y mostrar solución
    tSol sol = tramosNavegabes(arbol);

    cout << sol.tramos_navegables << endl;
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
