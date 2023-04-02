// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <math.h>
#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <typename T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;

   public:
    bintree_plus() : bintree<T>() {}
    bintree_plus(bintree_plus<T> const& l, T const& e, bintree_plus<T> const& r)
        : bintree<T>(l, e, r) {}

    T elementoMinimo() { return elementoMinimo(this->raiz); }

   private:
    T elementoMinimo(Link r) {
        if (r != nullptr) {  // Si no tiene hijos, devolvemos la raíz
            if (r->left == nullptr && r->right == nullptr)
                return r->elem;
            else if (r->left == nullptr)  // Si el izquierdo vacío, devolvemos
                                          // el mínimo entre hijo derecho y raíz
                return std::min(elementoMinimo(r->right), r->elem);
            else if (r->right ==
                     nullptr)  // Si el derecho vacío, devolvemos el mínimo
                               // entre el hijo izquierdo y raíz
                return std::min(elementoMinimo(r->left), r->elem);
            else {  // Si tiene ambos hijos, devolvemos el mínimo entre ellos y
                    // la raíz.
                T min =
                    std::min(elementoMinimo(r->left), elementoMinimo(r->right));
                return std::min(min, r->elem);
            }
        }
    }
};

template <typename T>
inline bintree_plus<T> leerArbol_plus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {  // es un árbol vacío
        return {};
    } else {  // leer recursivamente los hijos
        auto iz = leerArbol_plus(vacio);
        auto dr = leerArbol_plus(vacio);
        return {iz, raiz, dr};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char tipo;

    // Leer los datos de la entrada
    cin >> tipo;

    if (!cin)  // Fin de la entrada
        return false;

    if (tipo == 'N') {
        bintree_plus<int> arbol;

        arbol = leerArbol_plus(-1);

        cout << arbol.elementoMinimo() << endl;
    } else if (tipo == 'P') {
        bintree_plus<string> arbol;
        string t = "#";

        arbol = leerArbol_plus(t);

        cout << arbol.elementoMinimo() << endl;
    }

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
