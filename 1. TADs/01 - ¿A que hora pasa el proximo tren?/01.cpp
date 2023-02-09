// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Horas.h" // Propios o los de las estructuras de datos de clase

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int num_trenes, num_consultas;

    // Leer los datos de la entrada
    cin >> num_trenes >> num_consultas;

    if (num_trenes == 0 && num_consultas == 0)
        return false;

    vector<Horas> trenes(num_trenes);
    for(Horas &hora : trenes)
        cin >> hora;

    vector<Horas> consultas(num_consultas);
    for(Horas &hora : consultas) {
        try {
            cin >> hora;

            auto i = lower_bound(trenes.begin(), trenes.end(), hora);

            if (i == trenes.end())
                cout << "NO" << endl;
            else
                cout << *i;
        }
        catch(domain_error &e) {
            cout << e.what() << endl;
        }
    }

    cout << "---" << endl;

    return true;
}

int main()
{
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
