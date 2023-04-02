// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int nivel;
    bool coincide;
};

template <typename T>
class bintree_plus : public bintree<T> {
   public:
    tSol level(const T &valor) {
        if (left().empty() && right().empty())
            return {1, false};
    }
};

template <typename T>
inline bintree_plus<T> leerArbol_plus(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_plus(vacio);
      auto dr = leerArbol_plus(vacio);
      return {iz, raiz, dr};
   }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    char tipo;

    // Leer los datos de la entrada
    cin >> tipo;

    if (tipo == 'N') {
        int valor;
        bintree_plus<int> arbol;
        arbol = leerArbol_plus(-1);
    } else {
        char valor;
        bintree_plus<char> arbol;
        arbol = leerArbol_plus('.');
    }

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
