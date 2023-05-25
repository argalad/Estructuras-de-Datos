// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares

#ifndef urgencias2_h
#define urgencias2_h

#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>

using namespace std;

using paciente = string;
using gravedad = int;

class urgencias {
   private:
    list<pair<gravedad, paciente>> hospital;
    map<paciente, gravedad> pacientes;
    stack<paciente> recuperados_pacientes;

   public:
    urgencias() = default;

    void nuevo_paciente(paciente const& p, gravedad const& g) {
        if (g < 1 || g > 3) // Comprobamos que la gravedad sea correcta
            throw domain_error("ERROR: Gravedad incorrecta");
        else { 
            if (pacientes.find(p) != pacientes.end()) // Comprobamos que el paciente no esté repetido
                throw domain_error("ERROR: Paciente repetido");
            else {
                hospital.push_back({g, p}); // Insertamos el paciente en la cola correspondiente. O(log n)
                pacientes[p] = g;
            }
        }
    }

    int gravedad_actual(paciente p) {
        auto itP = pacientes.find(p); // Buscamos el paciente. O(log n) o O(n) en el peor caso
        if (itP == pacientes.end())
            throw domain_error("ERROR: Paciente inexistente");
        return itP->second;
    }

    paciente siguiente() {
        if (hospital.empty())
            throw domain_error("ERROR: No hay pacientes");

        auto it = hospital.begin();
        gravedad max_gravedad = it->first;
        paciente p = it->second;
        
        // Buscar paciente mayor urgencia. O(n)
        for (auto iter = hospital.begin(); iter != hospital.end();
             ++iter) { 
            if (iter->first > max_gravedad) {
                max_gravedad = iter->first;
                p = iter->second;
                it = iter;
            }
        }

        hospital.erase(it); // Se elimina de la lista. O(1)
        pacientes.erase(p); // Se elimina del map. O(log n)
        return p;
    }

    void mejora(paciente p) {
        auto itP = pacientes.find(p); 
        if (itP == pacientes.end())
            throw domain_error("ERROR: Paciente inexistente");

        // Se busca al paciente. O(n)
        int gravedad_actual = itP->second;
        auto it = hospital.end();
        for (auto iter = hospital.begin(); iter != hospital.end(); ++iter) {
            if (iter->second == p) {
                it = iter;
                break;
            }
        }

        // Se disminuye el nivel de urgencia o se elimina.
        if (gravedad_actual > 1) {
            itP->second = gravedad_actual - 1;
            it->first = gravedad_actual - 1;
        } else {
            hospital.erase(it); // O(1)
            pacientes.erase(itP);// O(log n)

            recuperados_pacientes.push(p); // O(1)
        }
    }

    stack<paciente> recuperados() { return recuperados_pacientes; }
};

#endif