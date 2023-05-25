// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Persona {
public:
    Persona(int edad, const string &nombre) : edad_(edad), nombre_(nombre) {}

    int edad() const {
        return edad_;
    }

    const string &nombre() const {
        return nombre_;
    }

private:
    int edad_;
    string nombre_;
};

template <class T, class Predicate>
void remove_if(list<T>& lista, Predicate pred) {
    for (auto it = lista.begin(); it != lista.end();) {
        if (pred(*it))
            it = lista.erase(it);
        else
            it++;
    }
}

bool resuelveCaso() {
    int num_personas, edad_min, edad_max;

    // Leer los datos de la entrad
    cin >> num_personas >> edad_min >> edad_max;

    if (num_personas == 0 && edad_min == 0 && edad_max == 0)
        return false;

    list<Persona> personas;
    for (int i = 0; i < num_personas; ++i) {
        int edad;
        string nombre;
        cin >> edad;
        cin.ignore();
        getline(cin, nombre);
        personas.emplace_back(edad, nombre);
    }

    // Resolver problema y mostrar solución
    remove_if(personas, [edad_min, edad_max](const Persona& p) {
        return p.edad() < edad_min || p.edad() > edad_max;
    });

    for (const auto& persona : personas)
        cout << persona.nombre() << endl;

    cout << "---" << endl;

    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
