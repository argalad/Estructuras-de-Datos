// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "bintree_eda.h"

using namespace std;

template <typename T>
bintree<T> buildTree(vector<T>& preorder) {
    if (preorder.empty()) {
        return bintree<T>();
    }
    auto root = std::make_shared<typename bintree<T>::TreeNode>(nullptr, preorder[0], nullptr);
    std::vector<T> left_subtree, right_subtree;
    for (size_t i = 1; i < preorder.size(); ++i) {
        if (preorder[i] < preorder[0]) {
            left_subtree.push_back(preorder[i]);
        } else {
            right_subtree.push_back(preorder[i]);
        }
    }
    root->left = buildTree(left_subtree).root;
    root->right = buildTree(right_subtree).root;
    return bintree<T>(root);
}



bool resuelveCaso() {
    string line;
    int elem;

    // Leer los datos de la entrada
    getline(cin, line);
    if (!cin)  // Fin de la entrada
        return false;

    queue<int> preorden;

    istringstream iss(line);
    while (iss >> elem) {
        preorden.push(elem);
    }

    // Resolver problema y mostrar solución
    auto arbol = esArbolBinarioBusqueda(preorden);

    for (int i : arbol.postorder())
        cout << i << " ";
    cout << endl;
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