// IMPORTANTE

// Nombre del alumno: Alberto Rodr�guez - Rabad�n Manzanares
// Usuario del juez que se est� usando en la prueba: A13

#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//
//  linked_list_ed.h
//
//  Implementaci�n del TAD linked_list con nodos enlazados
//  y punteros al primer y  �ltimo nodo
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita
//  Adaptada de la implementaci�n del queue realizada por Alberto Verdejo

#ifndef linked_list_ed_h
#define linked_list_ed_h

#include <stdexcept>  // std::domain_error

template <typename T>
class linked_list_ed {
   protected:
    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el �ltimo de la lista enlazada.
     */
    struct Nodo {
        Nodo() : sig(nullptr) {}
        Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
        T elem;
        Nodo* sig;
    };

    // punteros al primer y �ltimo elemento
    Nodo* prim;
    Nodo* ult;

   public:
    // constructor: lista enlazada vacia
    linked_list_ed() : prim(nullptr), ult(nullptr) {}

    // destructor
    ~linked_list_ed() { libera(); }

    // constructor por copia
    linked_list_ed(linked_list_ed<T> const& other) { copia(other); }

    // operador de asignaci�n
    linked_list_ed<T>& operator=(linked_list_ed<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // a�adir un elemento al final de la lista enlazada
    void push_back(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr)  // la lista estaba vac�a
            prim = nuevo;
    }

    // a�adir un elemento al principio de la lista enlazada
    void push_front(T const& elem) {
        Nodo* nuevo = new Nodo(elem, prim);
        prim = nuevo;
        if (ult == nullptr)  // la lista estaba vac�a
            ult = nuevo;
    }

    // eliminar el primero de la lista enlazada
    void pop_front() {
        if (empty())
            throw std::domain_error("eliminando de una lista enlazada vacia");
        Nodo* a_borrar = prim;
        prim = prim->sig;
        if (prim == nullptr)  // la lista enlazada se ha quedado vac�a
            ult = nullptr;
        delete a_borrar;
    }

    // consultar si la lista enlazada est� vac�a
    bool empty() const { return this->prim == nullptr; }

   protected:
    void libera() {
        while (prim != nullptr) {
            Nodo* a_borrar = prim;
            prim = prim->sig;
            delete a_borrar;
        }
        ult = nullptr;
    }

    // this est� sin inicializar
    void copia(linked_list_ed const& other) {
        if (other.empty()) {
            prim = ult = nullptr;
        } else {
            Nodo* act = other.prim;     // recorre la cola original
            ult = new Nodo(act->elem);  // �ltimo nodo copiado
            prim = ult;
            while (act->sig != nullptr) {
                act = act->sig;
                ult->sig = new Nodo(act->elem);
                ult = ult->sig;
            }
        }
    }
};

#endif  // linked_list_ed_h

//*******************************************************
//
// AQUI LA CLASE A IMPLEMENTAR POR EL ALUMNO
//
//*******************************************************

template <class T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

   public:
    void print(std::ostream& o = std::cout) const {
        if (!this->empty()) {  // la lista no est� vac�a
            Nodo* aux = this->prim;
            o << aux->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                o << ' ' << aux->elem;
                aux = aux->sig;
            }
        }
        o << std::endl;
    }

    void rotar() {
        if (!this->empty() && this->prim->sig != nullptr) {
            // Dos o mas elementos
            Nodo* a_mover = this->prim;
            // Desengancha el primer nodo
            this->prim = a_mover->sig;
            a_mover->sig = nullptr;
            // Lo engancha al final de la lista
            this->ult->sig = a_mover;
            // repite el proceso para todos los dem�s nodos de la lista
            Nodo* act = a_mover;
            while (this->ult->sig != nullptr) {
                // Desengancha el primer nodo
                a_mover = this->prim;
                this->prim = a_mover->sig;
                // Lo engancha al final de la lista
                a_mover->sig = nullptr;
                act->sig = a_mover;
                act = act->sig;
            }
            this->ult = act;
        }
    }

    // Separar los elementos positivos y negativos y eliminar los ceros
    //
    void separar(linked_list_ed_plus& l) {
        Nodo *aux = this->prim, *aux2 = nullptr, *aux3 = nullptr;

        if (!this->empty()) {
            while (aux != nullptr) {
                if (aux->elem == 0) {
                    Nodo* a_borrar = aux;
                    if (aux == this->prim) {
                        this->prim = aux->sig;
                        aux = aux->sig;
                    } else {
                        aux = aux->sig;
                        if (aux2 != nullptr)
                            aux2->sig = aux;
                    }
                    delete a_borrar;
                } else if (aux->elem < 0) {
                    if (aux == this->prim) {
                        if (l.empty()) {
                            aux3 = aux;
                            l.prim = aux3;
                            l.ult = aux3;
                            aux = aux->sig;
                        } else {
                            aux3->sig = aux;
                            aux3 = aux3->sig;
                            aux = aux->sig;
                            if (aux2 != nullptr)
                                aux2->sig = aux;
                        }

                        this->prim = aux;
                    } else {
                        aux3->sig = aux;
                        aux3 = aux3->sig;
                        aux = aux->sig;
                        if (aux2 != nullptr)
                            aux2->sig = aux;
                    }

                    aux3->sig = nullptr;
                    l.ult = aux3;
                } else {
                    aux2 = aux;
                    aux = aux->sig;
                }
            }
        }
        if (aux == nullptr) {
            this->ult = aux2;
        }
    }
};

bool resuelveCaso() {
    // Lectura de datos
    int n;
    std::cin >> n;
    if (n == -1)
        return 0;
    linked_list_ed_plus<int> l;
    linked_list_ed_plus<int> lNegativos;
    for (int i = 0; i < n; ++i) {
        int valor;
        std::cin >> valor;
        l.push_back(valor);
    }
    // llamada a la funci�n separar
    l.separar(lNegativos);
    // Para depurar
    l.rotar();
    lNegativos.rotar();
    // Mostrar resultados
    l.print();
    lNegativos.print();

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada.
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
