#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Equipo {
    string nombre;
    int problemas_resueltos;
    int tiempo;
    // Función para comparar dos equipos
    bool operator<(const Equipo& b) const {
        if (problemas_resueltos != b.problemas_resueltos)
            return problemas_resueltos > b.problemas_resueltos;
        else if (tiempo != b.tiempo)
            return tiempo < b.tiempo;
        else
            return nombre < b.nombre;
    }
};

void resuelveCaso() {
    // Declaramos las variables para los datos de entrada
    string nombre_equipo, nombre_problema, veredicto;
    int minutos;

    // Creamos dos diccionarios (unordered_map) para almacenar la información de
    // los equipos y los intentos de problemas
    unordered_map<string, Equipo> equipos;
    unordered_map<string, unordered_map<string, int>> intentos;

    // Leemos el primer nombre de equipo
    cin >> nombre_equipo;
    // Procesamos la entrada hasta encontrar la palabra "FIN"
    while (nombre_equipo != "FIN") {
        // Si el equipo no está registrado, lo agregamos al diccionario
        if (equipos.find(nombre_equipo) == equipos.end())
            equipos[nombre_equipo] = {nombre_equipo, 0, 0};

        // Leemos los datos restantes para el envío actual
        cin >> nombre_problema >> minutos >> veredicto;

        if (veredicto == "AC" &&
            intentos[nombre_equipo][nombre_problema] != -1) {
            equipos[nombre_equipo].problemas_resueltos++;
            equipos[nombre_equipo].tiempo +=
                minutos + 20 * intentos[nombre_equipo][nombre_problema];
            // Marcamos el problema como resuelto
            intentos[nombre_equipo][nombre_problema] = -1;
        } else if (intentos[nombre_equipo][nombre_problema] != -1)
            intentos[nombre_equipo][nombre_problema]++;
        cin >> nombre_equipo;
    }

    // Crear un vector de equipos para ordenarlos según las reglas
    vector<Equipo> ranking;
    for (const auto& e : equipos)
        ranking.push_back(e.second);

    // Ordenar el ranking de equipos
    sort(ranking.begin(), ranking.end());

    // Imprimir la clasificación final
    for (const auto& equipo : ranking)
        cout << equipo.nombre << " " << equipo.problemas_resueltos << " "
             << equipo.tiempo << endl;

    cout << "---" << endl;
}

int main() {
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
