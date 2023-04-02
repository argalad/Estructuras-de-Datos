// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int mul;
    int altura;
};

bool esPrimo(int const& n) {
    int divisor = 2;

    if (n == 0 || n == 1 || n == 4)
        return false;

    while (divisor <= n / 2) {
        if (n % divisor == 0)
            return false;
        else
            divisor++;
    }

    return true;
}

class multiploDe7 {
   public:
    bool operator()(int const& n) { return (n != 7) && (n % 7 == 0); }
};

inline std::ostream& operator<<(std::ostream& out, tSol const& sol) {
    if (sol.mul != -1)
        out << sol.mul << " " << sol.altura;
    else
        out << "NO HAY";
    out << endl;

    return out;
}

template <class P>
tSol resolver(bintree<int> const& arbol, P propiedad) {
    if (arbol.empty())
        return {-1, 0};
    else {
        tSol iz = resolver(arbol.left(), propiedad);
        tSol der = resolver(arbol.right(), propiedad);

        if (propiedad(arbol.root()))
            return {arbol.root(), 1};
        else {
            if (esPrimo(arbol.root()))
                return {-1, 0};
            else {
                if (der.mul != -1 && iz.mul != -1) {
                    if (iz.altura <= der.altura)
                        return {iz.mul, iz.altura + 1};
                    else
                        return {der.mul, der.altura + 1};

                } else if (der.mul != -1)
                    return {der.mul, der.altura + 1};
                else
                    return {iz.mul, iz.altura + 1};
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;

    // Leer los datos de la entrada
    arbol = leerArbol(-1);
    // Resolver problema y mostrar solución
    tSol sol = resolver(arbol, multiploDe7());
    cout << sol;
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
