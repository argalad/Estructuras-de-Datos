#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Horas.h"
#include "Pelicula.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_peliculas;

    // Leer los datos de la entrada
    cin >> num_peliculas;

    if (num_peliculas == 0)
        return false;

    try {
        vector<Pelicula> peliculas(num_peliculas);
        for (Pelicula& p : peliculas)
            cin >> p;

        sort(peliculas.begin(), peliculas.end());

        for (Pelicula& p : peliculas)
            cout << p;
    } catch (overflow_error& e) {
        cout << e.what() << endl;
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
