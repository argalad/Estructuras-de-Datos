#include <fstream>
#include <iostream>
#include <string>
#include "Horas.h"
#include "list_eda.h"

using namespace std;

void eliminar_pares(list<Horas>& lista) {
    list<Horas>::iterator it = lista.begin();
    int pos = 0;
    while (it != lista.end()) {
        pos++;
        if (pos % 2 == 0)
            it = lista.erase(it);
        else
            it++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;

    // Leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;

    list<Horas> lista;
    for (int i = 0; i < n; i++) {
        Horas h;
        cin >> h;
        lista.push_back(h);
    }

    // Resolver problema y mostrar solución
    eliminar_pares(lista);

    for (auto hora : lista)
        cout << hora << " ";
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
