#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct Clase {
    unsigned int ID_Clase;
    string tipo;
    string sala;
    int cupoMax;
    int horario;
};typedef struct Clase sClase;

struct Cliente {
    unsigned int ID_Cliente;
    string nombre;
    string apellido;
    string email;
    string telefono;
    time_t fechaNacimiento;
    float estado;
};typedef struct Cliente sCliente;

//FUNCIONES:
bool inscribirse();
string determinarClase(int eleccion);
int determinarHora();
int anotarAclase(string clase, sClase *clase, sCliente* cliente);

typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;

eCodArchivos leerArchivoClase(std::fstream	*archi, sClase *clase);
eCodArchivos escribirArchivoClase(std::fstream	*archi, sClase *clase);
eCodArchivos leerArchivoCliente(std::fstream *archi, sCliente *cliente);
eCodArchivos escribirArchivoCliente(std::fstream	*archi, sCliente *cliente);

#endif // GIMNASIO_H
