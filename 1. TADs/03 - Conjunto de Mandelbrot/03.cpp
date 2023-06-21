#include <fstream>
#include <iostream>

#include "Complejo.h"  // Propios o los de las estructuras de datos de clase

bool esMandelbrot(Complejo const& c, int num_iter) {
    Complejo z = Complejo(0, 0);

    while (num_iter > 0 && z.modulo() < 2) {
        z = z * z + c;
        num_iter--;
    }

    if (num_iter == 0)
        return true;
    else
        return false;
}

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Complejo c;
    int num_iteraciones;

    // Leer los datos de la entrada
    cin >> c >> num_iteraciones;

    if (esMandelbrot(c, num_iteraciones))
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
