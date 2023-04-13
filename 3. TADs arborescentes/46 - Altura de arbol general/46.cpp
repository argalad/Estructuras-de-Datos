// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>

using namespace std;

int alturaArbolGeneral(int num_ramas) {
    int altura = 1;
    int rama;

    if (num_ramas != 0) {
        for (int i = 0; i < num_ramas; i++) {
            cin >> rama;
            if (rama > 0)
                altura = std::max(altura, 1 + alturaArbolGeneral(rama));
        }
    }

    return altura;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int raiz, altura = 1;
    // Leer los datos de la entrada
    cin >> raiz;

    // Resolver problema y mostrar solución
    if (raiz != 0) {
        altura += alturaArbolGeneral(raiz);
    }

    cout << altura << endl;
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