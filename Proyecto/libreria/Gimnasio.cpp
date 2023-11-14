#include "Gimnasio.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool inscribirse(){
    int i = rand() % 2 + 1;
    return(i == 1);
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
