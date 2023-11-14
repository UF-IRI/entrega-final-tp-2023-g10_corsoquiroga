#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <iostream>
#include <string>

using namespace std;

struct Clase {
    unsigned int ID_Clase;
    string tipo;
    string sala;
    int cupoMax;
    int horario;
};

struct Cliente {
    unsigned int ID_Cliente;
    string nombre;
    string apellido;
    string email;
    string telefono;
};

//FUNCIONES:
bool inscribirse();
string determinarClase(int eleccion);
int determinarHora();
bool anotarAclase(const string& clase);

#endif // GIMNASIO_H
