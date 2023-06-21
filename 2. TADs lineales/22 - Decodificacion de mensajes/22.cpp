#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool esVocal(const char& c) {
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return true;
    else
        return false;
}

string decodificar(string const& mensaje) {
    queue<char> cola;
    stack<char> pila;
    string resultado;

    for (int i = 0; i < mensaje.size(); i++) {
        if (i % 2 == 0)  // A la cola caracteres en posiciones pares
            cola.push(mensaje[i]);
        else  // A la pila caracteres en posiciones impares
            pila.push(mensaje[i]);
    }
    
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    while (!cola.empty()) {
        if (esVocal(cola.front())) {
            resultado += cola.front();
            cola.pop();
        } else {
            while (!cola.empty() && !esVocal(cola.front())) {
                pila.push(cola.front());
                cola.pop();
            }

            while (!pila.empty()) {
                resultado += pila.top();
                pila.pop();
            }
        }
    }

    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string mensaje;

    // Leer los datos de la entrada
    getline(cin, mensaje);

    if (!cin)  // Fin de la entrada
        return false;

    // Resolver problema y mostrar solución
    cout << decodificar(mensaje) << endl;

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
