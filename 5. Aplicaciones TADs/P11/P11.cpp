// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "urgencias.h" // Propios o los de las estructuras de datos de clase

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
   urgencias ur;
   string op, nombre;
   int gravedad;

   if (!cin) // Fin de la entrada
      return false;
   // Leer los datos de la entrada
   cin >> op;
   while (op != "FIN")
   {
      try
      {
         if (op == "nuevo_paciente")
         {
            cin >> nombre >> gravedad;
            ur.nuevo_paciente(nombre, gravedad);
         }
         if (op == "siguiente")
         {
            nombre = ur.siguiente();
            cout << "Siguiente paciente: " << nombre << endl;
         }
         else if (op == "mejora")
         {
            cin >> nombre;
            ur.mejora(nombre);
         }
         else if (op == "recuperados")
         {
            set<string> recuperados = ur.recuperados();
            cout << "Lista de recuperados: ";
            for (auto const &i : recuperados)
               cout << i << " ";
            cout << endl;
         }
         else if (op == "gravedad_actual")
         {
            cin >> nombre;
            gravedad = ur.gravedad_actual(nombre);
            cout << "La gravedad de " << nombre << " es " << gravedad << endl;
         }
      }
      catch (const std::exception &e)
      {
         std::cout << e.what() << '\n';
      }
      if (!cin) // Fin de la entrada
      return false;

      cin >> op;
   }

   cout << "---" << endl;

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
