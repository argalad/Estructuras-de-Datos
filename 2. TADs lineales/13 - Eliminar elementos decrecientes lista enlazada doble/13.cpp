#include <fstream>
#include <iostream>

#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;

   public:
    void eliminarDecrecientes() {
        if (!this->empty()) {
            Nodo* act = this->fantasma->sig;
            Nodo* sig = act->sig;

            while (act != this->fantasma && sig != this->fantasma) {
                if (act->elem > sig->elem) {
                    sig = sig->sig;
                    sig->ant = act;
                    act->sig = sig;
                } else {
                    act = act->sig;
                    sig = sig->sig;
                }
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

    // Leer los datos de la entrada
    cin >> num_elem;
    if (num_elem == 0)
        return false;

    double_linked_list_ed_plus<int> lista;
    for (int i = 0; i < num_elem; i++) {
        cin >> elem;
        lista.push_back(elem);
    }

    // Resolver problema y mostrar solución
    lista.eliminarDecrecientes();
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
