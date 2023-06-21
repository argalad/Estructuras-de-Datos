#include <fstream>
#include <iostream>

using namespace std;

int becariosPrecarios(int jefes, int num_ramas, int nivel) {
    int becarios = 0;

    for (int i = 0; i < num_ramas; i++) {
        int rama;
        cin >> rama;

        if (rama != 0)
            becarios += becariosPrecarios(jefes, rama, nivel + 1);
        else if (nivel >= jefes)
            becarios++;
    }

    return becarios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Leer los datos de la entrada
    int jefes, raiz;

    cin >> jefes >> raiz;

    if (!cin)  // Fin de la entrada
        return false;

    // Resolver problema y mostrar solución
    if (raiz == 0)
        cout << "0" << endl;
    else
        cout << becariosPrecarios(jefes, raiz, 1) << endl;

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
