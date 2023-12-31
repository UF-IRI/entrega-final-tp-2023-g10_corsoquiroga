/*
 ../Users/Pili/Downloads/entrega-final-tp-2023-g10_corsoquiroga-main/entrega-final-tp-2023-g10_corsoquiroga-main/Proyecto/"iriClasesGYM";
../Users/Pili/Downloads/entrega-final-tp-2023-g10_corsoquiroga-main/entrega-final-tp-2023-g10_corsoquiroga-main/Proyecto/"iriClientesGYM";
../Users/Pili/Downloads/entrega-final-tp-2023-g10_corsoquiroga-main/entrega-final-tp-2023-g10_corsoquiroga-main/Proyecto/"asistencias_1697673600000";
 */
#include <iostream>
#include <Gimnasio.h>
#include <fstream>
#include <string>

#include "Gimnasio.cpp"

using namespace std;
int main(int argc, char *argv[]) {
    //"../gngng/

    bool inscribir = true;
    int eleccion = 0;
    string Clase;

    cout<<"BIENVENIDO AL GIMNASIO MUSCULITO"<<endl;

    ifstream inClase;
    ofstream outClase;
    ifstream inCliente;
    ofstream outCliente;
    ofstream outAsistencias("asistencias_1697673600000.dat", std::ios::binary);
    inClase.open("iriClasesGYM");
    outClase.open("iriClasesGYM");
    outCliente.open ("iriClientesGYM");
    inCliente.open("iriClientesGYM");

    sClase * clase= new sClase();
    sCliente * cliente= new sCliente();

    //clase->agregarContacto();
    //prueba....

    while(inscribir){
        cout<<"¿A qué clase desea inscribirse?: "<<endl;
        cout<<"1. Spinning"<<endl;
        cout<<"2. Yoga"<<endl;
        cout<<"3. Pilates"<<endl;
        cout<<"4. Stretching"<<endl;
        cout<<"5. Zumba"<<endl;
        cout<<"6. Boxeo"<<endl;
        cout<<"7. Musculación"<<endl;
        eleccion = rand%(1,7);
        clase = determinarClase(elección);
        int exitoso = anotarAclase(clase, clase, cliente);
        if(exitoso == -1)
            cout<<"No pudimos anotar al cliente en la clase"<<endl;
        else
            cout<<"Registro exitoso"<<endl;
        inscribir = inscribirse();
    }

    cout<<"Gracias por elegirnos"<<endl;



    inClase.close();
    outClase.close();
    inCliente.close();
    outCliente.close();

    delete clase;
    delete cliente;

    return 0;
}
