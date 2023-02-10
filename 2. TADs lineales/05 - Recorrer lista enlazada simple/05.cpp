// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "linked_list_ed.h"  // Propios o los de las estructuras de datos de clase

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    template <typename Predicate>
    void mostrarPropiedad(Predicate pred, ostream& o = cout) {
        Nodo* aux = this->prim;
        while (aux != nullptr && !pred(aux->elem[0]))
            aux = aux->sig;
        if (aux != nullptr) {
            o << aux->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                if (pred(aux->elem[0]))
                    o << ' ' << aux->elem;
                aux = aux->sig;
            }
        }
        o << endl;
    }
};

class empieza {
   private:
    char c;

   public:
    empieza(char ch) : c(ch) {}
    bool operator()(char valor) { return valor == c; }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char c;

    // Leer los datos de la entrada
    cin >> c;

    if (!cin)  // Fin de la entrada
        return false;

    linked_list_ed_plus<string> lista;
    string str;

    getline(cin, str);     // Saltar el final de linea
    getline(cin, str);     // Leer la linea del caso
    stringstream ss(str);  // Construye el objeto ss de tipo stringstream
    while (ss) {
        string aux;
        ss >> aux;
        lista.push_back(aux);
    }

    // Resolver problema y mostrar solucion
    lista.mostrarPropiedad(empieza(c));

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
