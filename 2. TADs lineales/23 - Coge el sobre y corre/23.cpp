#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, k, elem;
    queue<int> cola;

    // Leer los datos de la entrada
    cin >> n >> k;

    if (n == 0 && k == 0)
        return false;

    deque<int> sobres, mayores;

    for (int i = 0; i < k; i++) {
        cin >> elem;
        sobres.push_back(elem);

        while (!mayores.empty() && mayores.back() < elem)
            mayores.pop_back();

        mayores.push_back(elem);
    }

    for (int i = k; i < n; i++) {
        cout << mayores.front() << " ";
        cin >> elem;
        sobres.push_back(elem);
        
        if (mayores.front() == sobres.front())
            mayores.pop_front();
        sobres.pop_front();

        while (!mayores.empty() && mayores.back() < elem)
            mayores.pop_back();

        mayores.push_back(elem);
    }
    cout << mayores.front() << endl;

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
