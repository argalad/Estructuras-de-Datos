// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include "bintree_eda.h"

using namespace std;

template <typename T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;

   public:
    bintree_plus() : bintree<T>() {}
    bintree_plus(bintree_plus<T> const& l, T const& e, bintree_plus<T> const& r)
        : bintree<T>(l, e, r) {}

    vector<T> perfilDerecho() { return perfilDerecho(this->raiz); }

   private:
    vector<T> perfilDerecho(Link r) {
        vector<T> v;

        if (r == nullptr)
            return {};

        queue<pair<int, Link>> cola;
        cola.push({1, r});
        v.push_back(r->elem);

        while (!cola.empty()) {
            auto const& par = cola.front();
            auto const& f = par.first;
            auto const& s = par.second;

            if (v.size() != f)
                v.push_back(s->elem);
            if (s->right != nullptr)
                cola.push({f + 1, s->right});
            if (s->left != nullptr)
                cola.push({f + 1, s->left});
            cola.pop();
        }

        return v;
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
    // Leer los datos de la entrada
    bintree_plus<int> arbol = leerArbol_plus(-1);
    vector<int> sol = arbol.perfilDerecho();
    for (int i : sol)
        cout << i << " ";
    cout << endl;
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
