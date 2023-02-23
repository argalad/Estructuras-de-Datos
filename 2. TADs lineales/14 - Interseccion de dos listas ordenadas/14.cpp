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
    void interseccion(const double_linked_list_ed_plus<int>& lista) {
        Nodo* aux = this->fantasma->sig;
        Nodo* aux2 = lista.fantasma->sig;

        while (aux != this->fantasma && aux2 != lista.fantasma) {
            if (aux->elem == aux2->elem) {
                aux = aux->sig;
                aux2 = aux2->sig;
            } else if (aux->elem < aux2->elem) {
                Nodo *a_borrar = aux;
                aux->sig->ant = aux->ant;
                aux->ant->sig = aux->sig;
                aux = aux->sig;
                delete a_borrar;
            } else {
                aux2->ant->sig = aux2->sig;
                aux2->sig->ant = aux2->ant;
                aux2 = aux2->sig;
            }
        }

        if (aux != this->fantasma) { // Si quedan elementos en la primera lista, se eliminan y se actualiza el fantasma
            aux2 = aux->ant;
            while (aux != this->fantasma) {
                Nodo *a_borrar = aux;
                aux = aux->sig;
                delete a_borrar;
            }
            this->fantasma->ant = aux2;
            aux2->sig = this->fantasma;
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
void resuelveCaso() {
    int elem;
    double_linked_list_ed_plus<int> lista, lista2;

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
    lista.interseccion(lista2);
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
