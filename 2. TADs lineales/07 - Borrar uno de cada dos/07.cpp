// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>

#include "Horas.h"
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    void eliminarPares() {
        int count = 1;
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            if (count % 2 != 0 && aux->sig != nullptr) {
                if (aux->sig->sig != nullptr)
                    aux->sig = aux->sig->sig;
                else
                    aux->sig = nullptr;
                count += 2;
            } else
                count++;
            aux = aux->sig;
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
    int num_casos;

    // Leer los datos de la entrada
    cin >> num_casos;

    if (num_casos == 0)
        return false;

    Horas hora;
    linked_list_ed_plus<Horas> lista;

    for (int i = 0; i < num_casos; i++) {
        cin >> hora;
        lista.push_back(hora);
    }

    // Resolver problema y mostrar solución
    lista.eliminarPares();
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
