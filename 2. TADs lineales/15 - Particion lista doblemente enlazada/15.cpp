#include <fstream>
#include <iostream>

#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;

    /* aux va recorriendo la lista, aux2 almacena el elemento siguiente cuando
     * movemos aux, y aux3 guarda un puntero al primer elemento cambiado para
     * saber cuando parar la particion */
   public:
    void particion(int pivote) {
        if (!this->empty()) {
            Nodo* aux = this->fantasma->sig;
            Nodo *aux2 = nullptr, *aux3 = nullptr;

            while (aux != this->fantasma && aux != aux3) {
                if (aux->elem <= pivote)
                    aux = aux->sig;
                else {
                    if (aux3 == nullptr)
                        aux3 = aux;
                    aux2 = aux->sig;
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
                    aux->ant = this->fantasma->ant;
                    aux->sig = this->fantasma;
                    this->fantasma->ant->sig = aux;
                    this->fantasma->ant = aux;
                    aux = aux2;
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
    int num_elem, elem, pivote;

    // Leer los datos de la entrada
    cin >> num_elem;
    if (!cin)  // Fin de la entrada
        return false;

    double_linked_list_ed_plus<int> lista;

    cin >> pivote;
    for (int i = 0; i < num_elem; i++) {
        cin >> elem;
        lista.push_back(elem);
    }

    // Resolver problema y mostrar solución
    lista.particion(pivote);
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
