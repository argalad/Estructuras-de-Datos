// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <fstream>
#include <iostream>

#include "urgencias2.h"

using namespace std;

bool resuelveCaso() {
    urgencias ur;
    string op, nombre;
    int gravedad;
    if (!cin)  // Fin de la entrada
        return false;
    // Leer los datos de la entrada
    cin >> op;
    while (op != "FIN") {
        try {
            if (op == "nuevo_paciente") {
                cin >> nombre >> gravedad;
                ur.nuevo_paciente(nombre, gravedad);
            } else if (op == "siguiente") {
                nombre = ur.siguiente();
                cout << "Siguiente paciente: " << nombre << endl;
            } else if (op == "mejora") {
                cin >> nombre;
                ur.mejora(nombre);
            } else if (op == "recuperados") {
                stack<string> recuperados = ur.recuperados();
                cout << "Lista de recuperados: ";
                while (!recuperados.empty()) {
                    cout << recuperados.top() << " ";
                    recuperados.pop();
                }
                cout << endl;
            } else if (op == "gravedad_actual") {
                cin >> nombre;
                cout << "La gravedad de " << nombre << " es "
                     << ur.gravedad_actual(nombre) << endl;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << '\n';
        }
        if (!cin)  // Fin de la entrada
            return false;
        cin >> op;
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
