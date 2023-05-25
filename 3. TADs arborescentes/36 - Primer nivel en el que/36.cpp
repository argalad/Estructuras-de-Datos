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

    pair<int, bool> level(T const& valor) {
        return find_level(this->raiz, valor);
    }

   private:
    vector<int> count_level(Link r, T const& valor, int nivel) {
        if (r == nullptr)
            return vector<int>(nivel + 1, 0);

        vector<int> iz_count = count_level(r->left, valor, nivel + 1);
        vector<int> der_count = count_level(r->right, valor, nivel + 1);

        if (iz_count.size() < der_count.size())
            iz_count.resize(der_count.size());

        for (int i = 0; i < (int)der_count.size(); ++i)
            iz_count[i] += der_count[i];

        if (r->elem == valor)
            iz_count[nivel]++;

        return iz_count;
    }

    pair<int, bool> find_level(Link r, T const& valor) {
        vector<int> counts = count_level(r, valor, 1);

        for (int i = 0; i < (int)counts.size(); i++)
            if (counts[i] >= 2)
                return {i, true};

        return {0, false};
    }
};

template <typename T>
inline bintree_plus<T> leerArbol_plus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
        return {};
    else {
        auto iz = leerArbol_plus(vacio);
        auto dr = leerArbol_plus(vacio);
        return {iz, raiz, dr};
    }
}

void resuelveCaso() {
    char tipo;
    cin >> tipo;
    pair<int, int> sol;

    if (tipo == 'N') {
        int valor;
        cin >> valor;
        bintree_plus<int> arbol;
        arbol = leerArbol_plus(-1);
        sol = arbol.level(valor);
    } else {
        char valor;
        cin >> valor;
        bintree_plus<char> arbol;
        arbol = leerArbol_plus('.');
        sol = arbol.level(valor);
    }

    if (!sol.second)
        cout << "NO EXISTE" << endl;
    else
        cout << sol.first << endl;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
