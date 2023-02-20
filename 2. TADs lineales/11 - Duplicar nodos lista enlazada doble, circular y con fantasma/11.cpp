// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>

#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;

   public:
    void duplicar() {
        Nodo* aux = this->fantasma->sig;

        while (aux != this->fantasma) {
            Nodo* nuevo = new Nodo(aux->elem, aux->ant, aux->sig);
            aux->sig->ant = nuevo;
            aux->sig = nuevo;
            nuevo->ant = aux;
            aux = nuevo->sig;
        }
    }

    void mostrar(std::ostream& o = std::cout) const {
        Nodo* aux = this->fantasma->sig;
        while (aux != this->fantasma) {
            o << aux->elem << ' ';
            aux = aux->sig;
        }
        o << std::endl;
    }

    void mostrarInverso(std::ostream& o = std::cout) const {
        Nodo* aux = this->fantasma->ant;
        while (aux != this->fantasma) {
            o << aux->elem << ' ';
            aux = aux->ant;
        }
        o << std::endl;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int elem;
    double_linked_list_ed_plus<int> lista;

    // Leer los datos de la entrada
    cin >> elem;
    if (!cin)  // Fin de la entrada
        return false;

    while (elem != 0) {
        lista.push_back(elem);
        cin >> elem;
    }

    // Resolver problema y mostrar solución
    lista.duplicar();
    lista.mostrar();
    lista.mostrarInverso();

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
