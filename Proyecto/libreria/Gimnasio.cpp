#include "Gimnasio.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

bool inscribirse(){
    int i = rand() % 2 + 1;
    if (i == 1)
        return true;
    else
        return false;
}

string determinarClase(int eleccion){
    switch (eleccion){
    case 1: return "Spinning";
    case 2: return "Yoga";
    case 3: return "Pilates";
    case 4: return "Stretching";
    case 5: return "Zumba";
    case 6: return "Boxeo";
    case 7: return "Musculacion";
    default: return "";
    }
}
int determinarHora() {
    return rand() % 14 + 7; // Rango de 7 a 21
}


int anotarAclase(const string& clase, sClase *clase, sCliente *cliente){

    switch (clase){
    case "Spinning":
        if(clase->tipo == clase && clase->cupoMax<45){

            clase->cupoMax++;
        }
    case "Yoga":
        if(clase->tipo == clase && clase->cupoMax<25){
            clase->cupoMax++;
        }
    case "Pilates":
        if(clase->tipo == clase && clase->cupoMax<15){
            clase->cupoMax++;
        }
    case "Stretching":
        if(clase->tipo == clase && clase->cupoMax<40){
            clase->cupoMax++;
        }
    case  "Zumba":
        if(clase->tipo == clase && clase->cupoMax<50){
            clase->cupoMax++;
        }
    case "Boxeo":
        if(clase->tipo == clase && clase->cupoMax<30){
            clase->cupoMax++;
        }
    case "Musculacion":
        if(clase->tipo == clase && clase->cupoMax<30){
            clase->cupoMax++;
        }
    default: return -1;
    }
    return 0;
}

//ARCHIVOS
eCodArchivos leerArchivoClase(std::fstream	*archi, sClase *clase){

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->read((char*)clase, sizeof(sClase));

    if(!*archi){
        return eCodArchivos::ErrorEscritura;
    }

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos escribirArchivoClase(std::fstream	*archi, sClase *clase){
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)clase, sizeof(sClase));

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos leerArchivoCliente(std::fstream *archi, sCliente *cliente){

    unsigned int auxId;
    string auxNombre, auxApellido, auxEmail, auxTelefono;
    float auxEstado;
    time_t auxFecha;
    char coma;
    int i=0;

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    while(*archi>>auxId>>coma>>auxNombre>>coma>>auxApellido>>coma>>auxEmail>>coma>>auxTelefono>>coma>>auxFecha>>coma>>auxEstado){
        (cliente+i)->ID_Cliente=auxId;
        (cliente+i)->nombre=auxNombre;
        (cliente+i)->apellido=auxApellido;
        (cliente+i)->email=auxEmail;
        (cliente+i)->telefono=auxTelefono;
        (cliente+i)->fechaNacimiento=auxFecha;
        (cliente+i)->estado=auxEstado;
        i++;
    }

    return eCodArchivos::ExitoOperacion;
}

CodArchivos escribirArchivoCliente(std::fstream	*archi, sCliente *cliente){

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)cliente, sizeof(sCliente));

    return eCodArchivos::ExitoOperacion;
}
