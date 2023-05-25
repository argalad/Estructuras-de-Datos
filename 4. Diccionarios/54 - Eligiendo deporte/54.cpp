// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<pair<string, int>> eligiendoDeporte(
    const unordered_map<string, unordered_set<string>>& deportes) {
    vector<pair<string, int>> v;
    for (const auto& it : deportes)
        v.push_back({it.first, it.second.size()});

    sort(v.begin(), v.end(), [](const auto& d1, const auto& d2) {
        return (d1.second > d2.second) ||
               d1.second == d2.second && d1.first < d2.first;
    });

    return v;
}

bool resuelveCaso() {
    string cadena, deporte;
    cin >> cadena;

    if (!cin)
        return false;

    // clave : nombre deporte  , valor : nombre de estudiantes
    unordered_map<string, unordered_set<string>> deportes;
    // clave : nombre estudiante : , valor : primer deporte
    unordered_map<string, string> estudiantes;

    while (cadena != "_FIN_") {
        if (cadena[0] >= 'A' && cadena[0] <= 'Z') {
            deporte = cadena;
            deportes[deporte] = {};
        } else {
            auto it = estudiantes.find(cadena);

            if (it == estudiantes.end()) {
                estudiantes.insert({cadena, deporte});
                deportes[deporte].insert(cadena);
            } else if (it->second != deporte)
                deportes[it->second].erase(cadena);
        }

        cin >> cadena;
    }

    vector<pair<string, int>> sol = eligiendoDeporte(deportes);

    for (const auto& it : sol)
        cout << it.first << " " << it.second << endl;

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