// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include "bintree_eda.h"

using namespace std;

template <typename T>
bintree<T> reconstruccion(queue<T>& preorden,
                          const vector<T>& inorden,
                          int in_ini,
                          int in_fin) {
    if (in_ini > in_fin)
        return {};

    // Guardamos raíz para eliminarla de la cola
    T raiz = preorden.front();
    preorden.pop();

    if (in_ini == in_fin)
        return {raiz};
    

    // Posición para dividir el recorrido inorden
    int pos = in_ini;
    bool found = false;
    while (!found && pos <= in_fin) {
        if (inorden[pos] == raiz)
            found = true;
        else
            pos++;
    }

    // Reconstrucción de hijos
    auto iz = reconstruccion(preorden, inorden, in_ini, pos - 1);
    auto der = reconstruccion(preorden, inorden, pos + 1, in_fin);

    return {iz, raiz, der};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string line;
    int elem;

    // Leer los datos de la entrada
    getline(cin, line);
    if (!cin)  // Fin de la entrada
        return false;

    queue<int> preorden;
    vector<int> inorden;

    istringstream iss(line);
    while (iss >> elem) {
        preorden.push(elem);
    }

    getline(cin, line);
    istringstream iss2(line);
    while (iss2 >> elem) {
        inorden.push_back(elem);
    }

    // Resolver problema y mostrar solución
    auto arbol_sol = reconstruccion(preorden, inorden, 0, preorden.size() - 1);
    vector<int> vector_sol = arbol_sol.postorder();

    for (int i : vector_sol)
        cout << i << " ";
    cout << endl;

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