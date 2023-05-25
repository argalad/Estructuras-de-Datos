// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n;
    cin >> n;

    unordered_map<int, int> capitulos;
    int maxPeriodo = 0, periodoActual = 0;

    for (int i = 0; i < n; i++) {
        int capitulo;
        cin >> capitulo;

        if (capitulos.find(capitulo) != capitulos.end())
            periodoActual = min(i - capitulos[capitulo], periodoActual + 1);
        else
            periodoActual++;

        capitulos[capitulo] = i;
        maxPeriodo = max(maxPeriodo, periodoActual);
    }

    cout << maxPeriodo << endl;
}

int main() {
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
