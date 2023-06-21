#include <fstream>
#include <iostream>
#include <set>

using namespace std;

template<typename T>
class set_plus : public set<T> {
public:
    std::pair<bool, T> lower_bound(T const& e) const {
        auto it = set<T>::lower_bound(e);
        if (it == set<T>::end())
            return {false, {}};
        return {true, *it};
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;

    // Leer los datos de la entrada
    cin >> n;
    if (n == 0)  // Fin de la entrada
        return false;

    set_plus<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto sol = s.lower_bound(x);
        if (sol.first)
            cout << sol.second << endl;
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
