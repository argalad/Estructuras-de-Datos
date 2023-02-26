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
    void sumar(const linked_list_ed_plus<int> &l) {
        if (!this->empty()) {
            Nodo* act = this->prim;
            Nodo* prev = this->prim;
            Nodo* aux = l.prim;

            while (act != nullptr) {
                act->elem += aux->elem;

                if (act->elem == 0) {
                    Nodo* a_borrar = act;
                    if (act == this->prim)
                        this->prim = act->sig;
                    act = act->sig;
                    if (act == nullptr)
                        this->ult = prev;
                    if (prev->elem == 0)
                        prev = act;
                    else
                        prev->sig = act;
                    aux = aux->sig;
                    delete a_borrar;
                } else {
                    prev = act;
                    act = act->sig;
                    aux = aux->sig;
                }
            }
            this->ult = prev;
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_elems, elem;
    linked_list_ed_plus<int> lista, lista2;

    // Leer los datos de la entrada
    cin >> num_elems;
    if (num_elems == -1)
        return false;

    for (int i = 0; i < num_elems; i++)
    {
        cin >> elem;
        lista.push_back(elem);
    }

    for (int i = 0; i < num_elems; i++)
    {
        cin >> elem;
        lista2.push_back(elem);
    }
    
    // Resolver problema y mostrar solución
    lista.sumar(lista2);
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
