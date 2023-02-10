// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "linked_list_ed.h"  // Propios o los de las estructuras de datos de clase

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    void duplicar() {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            Nodo* nuevo = new Nodo();
            nuevo->elem = aux->elem;
            nuevo->sig = aux->sig;
            if (aux->sig == nullptr)
                this->ult = nuevo;
            aux->sig = nuevo;
            aux = nuevo->sig;
        }
    }

    void mostrar(ostream& o = cout) {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            o << aux->elem << ' ';
            aux = aux->sig;
        }
        o << endl;
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

    // Resolver problema y mostrar solucion
    lista.duplicar();
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
