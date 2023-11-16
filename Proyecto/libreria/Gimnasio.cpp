#include "Gimnasio.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

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


int anotarAclase(const string& clase, sClase *clase, sCliente*cliente){
    switch (clase){
    case "Spinning":
    case "Yoga":
    case "Pilates":
    case "Stretching":
    case  "Zumba":
    case "Boxeo":
    case "Musculacion":
    default: return -1;
    }
    return 0;
}

eCodArchivos leerArchivoClase(std::fstream	*archi, sClase *clase){}
eCodArchivos escribirArchivoClase(std::fstream	*archi, sClase *clase){}
eCodArchivos leerArchivoCliente(std::fstream *archi, sCliente *cliente){}
eCodArchivos escribirArchivoCliente(std::fstream	*archi, sCliente *cliente){}
