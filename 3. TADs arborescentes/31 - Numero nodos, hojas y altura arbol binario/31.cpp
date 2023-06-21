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

    void propiedades() {
        cout << num_nodos(this->raiz) << " " << num_hojas(this->raiz) << " "
             << altura(this->raiz) << endl;
    }

   private:
    int num_nodos(Link r) {
        if (r == nullptr)
            return 0;
        else
            return num_nodos(r->left) + num_nodos(r->right) + 1;
    }

    int num_hojas(Link r) {
        if (r == nullptr)
            return 0;
        else if (r->left == nullptr && r->right == nullptr)
            return 1;
        else
            return num_hojas(r->left) + num_hojas(r->right);
    }

    int altura(Link r) {
        if (r == nullptr)
            return 0;
        else
            return std::max(altura(r->left), altura(r->right)) + 1;
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
void resuelveCaso() {
    bintree_plus<char> arbol;

    // Leer los datos de la entrada
    arbol = leerArbol_plus('.');

    // Escribir solución
    arbol.propiedades();
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
