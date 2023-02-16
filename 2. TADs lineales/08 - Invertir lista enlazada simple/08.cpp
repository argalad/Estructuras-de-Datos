// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>

#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    void invertir() {
        Nodo* aux = nullptr;          // Puntero auxiliar
        Nodo* act = this->prim;       // Puntero al elemento actual
        Nodo* sig = this->prim->sig;  // Puntero al elemento siguiente

        act->sig = nullptr;  // El primero pasa a ser el último, por lo tanto el
                             // siguiente apunta a nullptr

        while (sig != nullptr) {
            aux = sig->sig;
            sig->sig = act;
            act = sig;
            sig = aux;
        }

        // Actualizamos puntero prim y ult
        act = this->prim;
        this->prim = this->ult;
        this->ult = act;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int elem;

    // Leer los datos de la entrada
    cin >> elem;

    if (!cin)  // Fin de la entrada
        return false;

    linked_list_ed_plus<int> lista;

    while (elem != 0) {
        lista.push_back(elem);
        cin >> elem;
    }

    // Resolver problema y mostrar solución
    if (!lista.empty())
        lista.invertir();
    lista.mostrar();

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
