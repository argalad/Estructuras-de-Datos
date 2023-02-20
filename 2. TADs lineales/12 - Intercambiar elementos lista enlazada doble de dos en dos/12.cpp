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
    void intercambiar() { // O(n) -> se recorre la lista una vez
        if (!this->empty()) {
            Nodo* act = this->fantasma->sig;
            Nodo* sig = nullptr;

            while (act != this->fantasma && act->sig != this->fantasma) {
                if (act->ant == this->fantasma) {
                    act->sig->ant = this->fantasma;
                    this->fantasma->sig = act->sig;
                } else {
                    act->ant->sig = act->sig;
                    act->sig->ant = act->ant;
                }
                sig = act->sig->sig;
                sig->ant = act;
                act->sig->sig = act;
                act->ant = act->sig;
                act->sig = sig;

                act = act->sig;
            }
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
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_elem, elem;
    double_linked_list_ed_plus<int> lista;

    // Leer los datos de la entrada
    cin >> num_elem;
    if (num_elem == 0)
        return false;

    for (int i = 0; i < num_elem; i++)
    {
        cin >> elem;
        lista.push_back(elem);
    }
    
    // Resolver problema y mostrar solución
    lista.intercambiar();
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
