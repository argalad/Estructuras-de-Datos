// Nombre del alumno: Alberto Rodr�guez - Rabad�n Manzanares
// Usuario del juez que se est� usando en la prueba: A13

#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    void print(std::ostream& o = std::cout) const {
        if (!this->empty()) {  // la lista no est� vac�a
            Nodo* aux = this->prim;
            o << aux->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                o << ' ' << aux->elem;
                aux = aux->sig;
            }
        }
        o << std::endl;
    }

    void rotar() {
        if (!this->empty() && this->prim->sig != nullptr) {
            // Dos o mas elementos
            Nodo* a_mover = this->prim;
            // Desengancha el primer nodo
            this->prim = a_mover->sig;
            a_mover->sig = nullptr;
            // Lo engancha al final de la lista
            this->ult->sig = a_mover;
            // repite el proceso para todos los dem�s nodos de la lista
            Nodo* act = a_mover;
            while (this->ult->sig != nullptr) {
                // Desengancha el primer nodo
                a_mover = this->prim;
                this->prim = a_mover->sig;
                // Lo engancha al final de la lista
                a_mover->sig = nullptr;
                act->sig = a_mover;
                act = act->sig;
            }
            this->ult = act;
        }
    }

    // Separar los elementos positivos y negativos y eliminar los ceros
    //
    void separar(linked_list_ed_plus& l) {
        Nodo *aux = this->prim, *prev = nullptr;

        while (aux != nullptr) {
            if (aux->elem == 0) {
                if (prev == nullptr) {
                    this->prim = aux->sig;
                } else {
                    prev->sig = aux->sig;
                }

                Nodo* a_borrar = aux;
                aux = aux->sig;
                delete a_borrar;
            } else {
                if (aux->elem < 0) {
                    if (prev == nullptr) {
                        this->prim = aux->sig;
                    } else {
                        prev->sig = aux->sig;
                    }

                    l.push_back(aux->elem);
                    Nodo* a_borrar = aux;
                    aux = aux->sig;
                    delete a_borrar;
                } else {
                    prev = aux;
                    aux = aux->sig;
                }
            }
        }

        this->ult = prev;
    }
};

bool resuelveCaso() {
    // Lectura de datos
    int n;
    std::cin >> n;
    if (n == -1)
        return 0;
    linked_list_ed_plus<int> l;
    linked_list_ed_plus<int> lNegativos;
    for (int i = 0; i < n; ++i) {
        int valor;
        std::cin >> valor;
        l.push_back(valor);
    }
    // llamada a la funci�n separar
    l.separar(lNegativos);
    // Para depurar
    l.rotar();
    lNegativos.rotar();
    // Mostrar resultados
    l.print();
    lNegativos.print();

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada.
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
