#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> resolver(int n) {
    map<string, int> scores;
    cin.ignore();  // descartar salto de línea

    for (int i = 0; i < n; i++) {
        string name;
        string status;

        getline(cin, name);
        getline(cin, status);

        if (status == "CORRECTO")
            scores[name]++;
        else
            scores[name]--;
    }

    return scores;
}

void mostrar_sol(const map<string, int>& scores) {
    bool first = true;

    for (auto& p : scores) {
        if (p.second != 0) {
            if (!first)
                cout << endl;
            else
                first = false;
            cout << p.first << ", " << p.second;
        }
    }
    cout << endl << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    // Leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;

    // Resolver problema y mostrar solución
    auto sol = resolver(n);
    mostrar_sol(sol);

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
