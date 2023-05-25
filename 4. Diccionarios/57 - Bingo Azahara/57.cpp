// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

set<string> bingo(int num_jugadores) {
    // Leer los cartones
    unordered_map<string, set<int>> cartones;
    for (int i = 0; i < num_jugadores; i++) {
        string nombre;
        cin >> nombre;

        set<int> numeros_carton;
        int numero;
        cin >> numero;
        while (numero != 0) {
            numeros_carton.insert(numero);
        }
        cartones[nombre] = numeros_carton;
    }

    // Simular la extracción de bolas y comprobar los ganadores
    set<string> ganadores;
    int bola;
    cin >> bola;
    while (!ganadores.size()) {
        for (const auto& carton : cartones) {
            if (carton.second.count(bola) != 0) {
                cartones[carton.first].erase(bola);

                if (cartones[carton.first].size() == 0) {
                    ganadores.insert(carton.first);
                    if (ganadores.size() == num_jugadores) {
                        break;
                    }
                }
            }
        }
    }

    return ganadores;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_jugadores;

    // Leer los datos de la entrada
    cin >> num_jugadores;
    if (num_jugadores == 0)
        return false;

    // Resolver problema y mostrar solución
    auto ganadores = bingo(num_jugadores);

    for (const auto& ganador : ganadores) {
        cout << ganador;
        if (&ganador != &*ganadores.rbegin()) {
            cout << " ";
        }
    }
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
