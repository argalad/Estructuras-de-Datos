#include <fstream>
#include <iostream>
#include "list_eda.h"

using namespace std;

template <class T>
class list_ed_plus : public list<T> {
    using Nodo = typename deque<T>::Nodo;

   protected:
    class reverse_iterator {
        Nodo* act;
        Nodo* fan;

       public:
        reverse_iterator() : act(nullptr), fan(nullptr) {}

        reverse_iterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}

        T& operator*() const {
            if (act == fan)
                throw std::out_of_range("fuera de la lista");
            return act->elem;
        }

        T* operator->() const { return &(operator*()); }

        reverse_iterator& operator++() {  // ++ prefijo (recomendado)
            if (act == fan)
                throw std::out_of_range("fuera de la lista");
            act = act->ant;
            return *this;
        }

        reverse_iterator operator++(int) {  // ++ postfijo
            reverse_iterator ret(*this);
            operator++();
            return ret;
        }

        bool operator==(reverse_iterator const& that) const {
            return act == that.act && fan == that.fan;
        }

        bool operator!=(reverse_iterator const& that) const {
            return !(*this == that);
        }
    };

   public:
    // Devuelve un iterador al primer elemento en el recorrido inverso
    reverse_iterator rbegin() {
        return reverse_iterator(this->fantasma->ant, this->fantasma);
    }

    // Devuelve un iterador detrás del último elemento del recorrido inverso
    reverse_iterator rend() {
        return reverse_iterator(this->fantasma, this->fantasma);
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    list_ed_plus<int> lista;
    int elem;

    // Leer los datos de la entrada
    cin >> elem;
    while (elem != 0) {
        lista.push_back(elem);
        cin >> elem;
    }

    for (auto it = lista.rbegin(); it != lista.rend(); ++it)
        cout << *it << " ";

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
