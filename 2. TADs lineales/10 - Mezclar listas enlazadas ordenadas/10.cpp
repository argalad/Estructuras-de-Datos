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
    void mezclar(linked_list_ed_plus<T>& lista) {
        Nodo *aux = this->prim, *aux2 = lista.prim, *aux3 = nullptr;

        while (aux != nullptr && aux2 != nullptr) {
            if (aux->elem <= aux2->elem) {
                if (aux->elem + 1 < aux2->elem)
                    aux = aux->sig;
                else {
                    aux3 = aux2->sig;
                    aux2->sig = aux->sig;
                    if (aux == this->ult)
                        this->ult = aux2;
                    aux->sig = aux2;
                    aux2 = aux3;
                    aux = aux->sig->sig;
                }
            } else {
                if (aux == this->prim)
                    this->prim = aux2;
                aux3 = aux2->sig;
                aux2->sig = aux;
                aux2 = aux3;
            }
        }
        if (aux2 != nullptr) {
            if (this->empty()) {
                this->prim = lista.prim;
                this->ult = lista.ult;
            } else {
                aux = this->ult;
                aux->sig = aux2;
                this->ult = lista.ult;
            }
        }
        lista.prim = nullptr;
        lista.ult = nullptr;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int elem;

    linked_list_ed_plus<int> lista;
    linked_list_ed_plus<int> lista2;

    // Leer los datos de la entrada
    cin >> elem;
    while (elem != 0) {
        lista.push_back(elem);
        cin >> elem;
    }

    cin >> elem;
    while (elem != 0) {
        lista2.push_back(elem);
        cin >> elem;
    }

    // Resolver problema y mostrar solución
    lista.mezclar(lista2);
    lista.mostrar();
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
