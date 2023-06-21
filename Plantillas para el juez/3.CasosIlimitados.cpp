#include <fstream>
#include <iostream>

#include "..."

using namespace std;

Solucion resolver(Datos datos) {
    ...
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Leer los datos de la entrada

    if (!cin)  // Fin de la entrada
        return false;

    // Resolver problema y mostrar solución
    Solucion sol = resolver(datos);

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
