// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>

#include "linked_list_ed.h"

using namespace std;

template<typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

    public:

    void eliminarRepetidos() {
        Nodo *aux = this->prim;

        while(aux->sig != nullptr) {
            if (aux->elem == aux->sig->elem)
                aux->sig = aux->sig->sig;
            else
                aux = aux->sig;
        }

        this->ult = aux;
        aux->sig = nullptr;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_elem;
    char elem;

    // Leer los datos de la entrada
    cin >> num_elem;

    if (num_elem == -1)
        return false;

    linked_list_ed_plus<char> lista;

    for (int i = 0; i < num_elem; i++)
    {
        cin >> elem;
        lista.push_back(elem);
    }
    
    // Resolver problema y mostrar solución
    lista.eliminarRepetidos();
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
