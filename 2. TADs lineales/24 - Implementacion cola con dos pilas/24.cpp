// Programa para probar la implementación de una cola

#include <fstream>
#include <iostream>

//
//  queue_eda.h
//
//  Implementación del TAD cola con dos pilas
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2018 Isabel
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stack>
#include <stdexcept>  // std::domain_error

using namespace std;

template <class T>
class queue {
   protected:
    stack<T> pila_a;
    stack<T> pila_b;

   public:
    // constructor: cola vacía
    queue() {}

    // añadir un elemento al final de la cola
    void push(T const& elem) { pila_a.push(elem); }

    // consultar el primero de la cola
    T const& front() { return pila_a.top(); }

    // eliminar el primero de la cola
    void pop() {
        if (pila_a.empty() && pila_b.empty())
            throw domain_error("Pilas vacías.");

        if (!pila_b.empty())
            pila_b.pop();
        else {
            while (!pila_a.empty()) {
                pila_b.push(pila_a.top());
                pila_a.pop();
            }
            pila_b.pop();
        }
    }

    // consultar si la cola está vacía
    bool empty() const { return pila_a.empty(); }

    // consultar el tamaño de la cola
    size_t size() const {
        if (pila_a.size() != 0)
            return pila_a.size();
        else
            return pila_b.size();
    }
};

#endif  // queue_eda_h

bool resuelveCaso() {
    std::string str;
    getline(std::cin, str);
    if (str == ".")
        return false;
    // lee los datos de entrada en la cola
    queue<char> cola;
    for (int i = 0; i < str.length(); ++i) {
        cola.push(str[i]);
    }
    // Rota los datos de la cola
    for (int i = 0; i < cola.size(); ++i) {
        cola.push(cola.front());
        cola.pop();
    }
    // Duplica los elementos de la cola
    for (int i = 0; i < cola.size(); ++i) {
        cola.push(cola.front());
        cola.push(cola.front());
        cola.pop();
    }
    // Muestra los elementos de la cola y la deshace
    for (int i = 0; i < cola.size(); i += 2) {
        std::cout << cola.front();
        cola.pop();
        cola.pop();
    }
    if (!cola.empty())
        std::cout << "ERROR\n";
    std::cout << '\n';
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(
        in.rdbuf());  // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE  // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
