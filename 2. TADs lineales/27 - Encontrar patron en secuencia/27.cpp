#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

template <class T>
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
    T it1 = ini1;
    while (it1 != fin1) {
        T it2 = ini2;
        T temp = it1;
        while (temp != fin1 && it2 != fin2 && *temp == *it2) {
            temp++;
            it2++;
        }
        if (it2 == fin2) {
            return it1;
        }
        it1++;
    }
    return fin1;
}

bool resuelveCaso() {
    int N1, N2;

    // Leer los datos de la entrad
    cin >> N1 >> N2;

    if (N1 == 0 && N2 == 0)
        return false;

    list<int> lista1, lista2;
    int num;

    for (int i = 0; i < N1; i++) {
        cin >> num;
        lista1.push_back(num);
    }

    for (int i = 0; i < N2; i++) {
        cin >> num;
        lista2.push_back(num);
    }
    
    // Resolver problema y mostrar solución
    auto it = Mysearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());

    while (it != lista1.end()) {
        it = lista1.erase(it, next(it, distance(lista2.begin(), lista2.end())));
        it = Mysearch(it, lista1.end(), lista2.begin(), lista2.end());
    }

    for (int num : lista1)
        cout << num << " ";

    cout << endl;

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
