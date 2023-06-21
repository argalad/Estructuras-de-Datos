#ifndef queue_eda_h
#define queue_eda_h

#include <stack>
#include <stdexcept>  // domain_error

using namespace std;

template <class T>
class queue {
   protected:
    stack<T> input;
    stack<T> output;

   public:
    // constructor: cola vacía
    queue() {}

    // añadir un elemento al final de la cola
    void push(T const& elem) { input.push(elem); }

    // consultar el primero de la cola
    T const front() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.empty() ? T() : output.top();
    }

    // eliminar el primero de la cola
    void pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty())
            output.pop();
    }

    // consultar si la cola está vacía
    bool empty() const { return input.empty() && output.empty(); }

    // consultar el tamaño de la cola
    size_t size() const {
        if (input.size() != 0)
            return input.size();
        else
            return output.size();
    }
};

#endif  // queue_eda_h

bool resuelveCaso() {
    string str;

    getline(cin, str);
    if (str == ".")
        return false;

    // lee los datos de entrada en la cola
    queue<char> cola;
    for (int i = 0; i < str.length(); ++i)
        cola.push(str[i]);
    // Rota los datos de la cola
    int n = cola.size();
    for (int i = 0; i < n; ++i) {
        cola.push(cola.front());
        cola.pop();
    }
    // Duplica los elementos de la cola
    queue<char> cola_duplicada;
    while (!cola.empty()) {
        char temp = cola.front();
        cola_duplicada.push(temp);
        cola.pop();
    }
    cola = cola_duplicada;
    // Muestra los elementos de la cola y la deshace
    while (!cola.empty()) {
        cout << cola.front();
        cola.pop();
    }
    cout << endl;
    return true;
}


int main() {
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(
        in.rdbuf());  // save old buf and redirect cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE  // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
