// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares

#ifndef urgencias_h
#define urgencias_h

#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

#define clave first
#define valor second


using paciente = string;
using gravedad = int;

class urgencias {
private:
    vector<list<paciente>> hospital;
    using info_paciente = pair<gravedad, list<paciente>::iterator>;
    unordered_map<paciente, info_paciente> pacientes;
    set<paciente> lista_recuperados;

public:
    urgencias () : hospital(3) {}

    void nuevo_paciente(paciente const &p, gravedad const& g)
    {
        if (g < 1 || g > 3) // Comprobamos que la gravedad sea correcta
            throw domain_error("ERROR: Gravedad incorrecta");
        else
        {
            if (pacientes.find(p) != pacientes.end()) // Comprobamos que el paciente no esté repetido
                throw domain_error("ERROR: Paciente repetido");
            else
            {
                hospital[g-1].push_back(p); // Insertamos el paciente en la cola correspondiente. O(1)
                pacientes.insert({p, {g, --hospital[g-1].end()}}); // Insertamos el paciente en nuestro unordered_map. O(1)
            }
        }
    }

    int gravedad_actual(paciente p)
    {
        auto itP = pacientes.find(p); // Buscamos el paciente. O(1)
        if (itP == pacientes.end())
            throw domain_error("ERROR: Paciente inexistente");
        return itP->valor.first;
    }

    paciente siguiente()
    {
        paciente p;
        int i = 2;
        bool ok = false;

        while(i >= 0 && !ok) // Buscamos en las colas de urgencia, desde la grave hasta la leve
        {
            if (!hospital[i].empty())
            {
                p = hospital[i].front();
                hospital[i].pop_front();
                ok = true;
            }
            else
                if (i == 0)
                    throw domain_error("ERROR: No hay pacientes");
            i--;
        }
        
        pacientes.erase(p);
        return p;
    }

    void mejora(paciente p)
    {
        auto itP = pacientes.find(p); // Buscamos el paciente. O(1)
        if (itP == pacientes.end())
            throw domain_error("ERROR: Paciente inexistente");
        auto u = itP->valor.first; // Sacamos la gravedad
        hospital[u-1].erase(itP->valor.second); // Eliminamos al paciente de la cola de urgencias actual. O(1)
        if (u != 1)
        {
            hospital[(--u)-1].push_front(p); // Lo metemos en la cola anterior, en primera posicion. O(1)
            itP->valor.first = u;
            itP->valor.second = hospital[u-1].begin();
        }
        else
        {
            pacientes.erase(p); // Si era leve, lo sacamos de la lista de pacientes. O(1)
            lista_recuperados.insert(p); // Lo insertamos en la lista de recuperados.
        }

    }

    set<paciente> recuperados () 
    {
        return lista_recuperados;
    }
    
};

#endif