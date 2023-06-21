#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int resolver(queue<int>& alumnos, int k) {
    int i = 0, aux;
    while (alumnos.size() != 1) {
        aux = alumnos.front();
        alumnos.pop();
        alumnos.push(aux);
        i++;
        if (i == k) {
            alumnos.pop();
            i = 0;
        }
    }
    
    return alumnos.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_alumnos, saltos;
    queue<int> alumnos;

    // Leer los datos de la entrada
    cin >> num_alumnos >> saltos;

    if (num_alumnos == 0 && saltos == 0)
        return false;

    for (int i = 1; i <= num_alumnos; i++)
        alumnos.push(i);
    
    // Resolver problema y mostrar solución
    cout << resolver(alumnos, saltos) << endl;

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
