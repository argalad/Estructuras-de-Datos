// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool parentesisEquilibrados(const string& s) {
    stack<char> pila;
    char cima;
    bool equilibrado = true;

    int i = 0;
    while (s[i] != '\n' && s[i] != '\r' && s[i] != '\0' && equilibrado) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            pila.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (pila.empty())
                equilibrado = false;
            else {
                cima = pila.top();
                if ((cima == '(' && s[i] == ')') ||
                    (cima == '[' && s[i] == ']') ||
                    (cima == '{' && s[i] == '}'))
                    pila.pop();
                else
                    equilibrado = false;
            }
        }
        i++;
    }

    if (!pila.empty())
        equilibrado = false;

    return equilibrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    bool sol;
    string linea;

    // Leer los datos de la entrada
    getline(cin, linea);
    if (!cin)  // Fin de la entrada
        return false;

    // Resolver problema y mostrar solución
    sol = parentesisEquilibrados(linea);
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

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
