#include "Gimnasio.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

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


int anotarAclase(string clase, sClase *clase, sCliente *cliente){

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
/*
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->read((char*)clase, sizeof(sClase));

    if(!*archi){
        return eCodArchivos::ErrorEscritura;
    }

    return eCodArchivos::ExitoOperacion;
*/
        if (!archi->is_open()){
            cout<<"Error abrir archivo";
            return -1;
        }

        int N = 1;
        sClase* clase = new clase[N];
        stringstream ss;
        string auxtipo, auxsala, header, line;
        int auxcupoMax, auxhorario;
        unsigned int auxID_Clase;

        getline(archi, header);
        while (archi){
            getline(archi, line);
            ss<<line;
            getline(ss, auxID_Clase, ",");
            clase[N].ID_Clase = auxID_Clase;
            getline(ss, auxtipo, ",");
            clase[N].tipo = auxtipo;
            getline(ss, auxsala, ",");
            clase[N].sala = auxsala;
            getline(ss, auxcupoMax, ",");
            clase[N].cupoMax = auxcupoMax;
            getline(ss, auxhorario, ",");
            clase[N].horario = auxhorario;
            N++;
        }
    }

eCodArchivos escribirArchivoClase(std::fstream	*archi, sClase *clase){
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)clase, sizeof(sClase));

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos leerArchivoCliente(std::fstream *archi, sCliente *cliente){
/*
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

*/
        if (!archi->is_open()){
            cout<<"Error abrir archivo";
            return -1;
        }

        int N = 1;
        sClase* cliente = new cliente[N];
        stringstream ss;
        string auxnombre, auxapellido, auxemail, auxtelefono, header, line;
        unsigned int auxID_Cliente;
        time_t auxfechaNacimiento;
        float auxestado;

        getline(archi, header);
        while (archi){
            getline(archi, line);
            ss<<line;
            getline(ss, auxnombre, ",");
            cliente[N].nombre = auxnombre;
            getline(ss, auxapellido, ",");
            cliente[N].apellido = auxapellido;
            getline(ss, auxemail, ",");
            cliente[N].email = auxemail;
            getline(ss, auxtelefono, ",");
            cliente[N].telefono = auxtelefono;
            getline(ss, auxID_Cliente, ",");
            cliente[N].ID_Cliente = auxID_Cliente;
            getline(ss, auxfechaNacimiento, ",");
            cliente[N].fechaNacimiento = auxfechaNacimiento;
            getline(ss, auxestado, ",");
            cliente[N].estado = auxestado;
            N++;
        }
    }

CodArchivos escribirArchivoCliente(std::fstream	*archi, sCliente *cliente){

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)cliente, sizeof(sCliente));

    return eCodArchivos::ExitoOperacion;
}
