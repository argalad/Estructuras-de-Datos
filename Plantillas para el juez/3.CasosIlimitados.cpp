// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <...>

#include "..." // Propios o los de las estructuras de datos de clase

using namespace std;

Solucion resolver(Datos datos)
{
   ...
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
   // Leer los datos de la entrada

   if (!cin) // Fin de la entrada
      return false;

   // Resolver problema
   Solucion sol = resolver(datos);

   // Escribir sol

   return true;
}

int main()
{
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
