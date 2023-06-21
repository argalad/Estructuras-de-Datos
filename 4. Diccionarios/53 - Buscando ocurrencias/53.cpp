#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Resuelve un caso de prueba
bool resuelveCaso() {
    int n, m;

    cin >> n;
    if (!cin)
        return false;
    cin >> m;

    unordered_map<int, vector<int>> ocurrencias;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ocurrencias[num].push_back(i + 1);
    }

    for (int i = 0; i < m; i++) {
        int k, v;
        cin >> k >> v;

        if (ocurrencias[v].size() >= k)
            cout << ocurrencias[v][k - 1] << endl;
        else
            cout << "NO HAY" << endl;
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
