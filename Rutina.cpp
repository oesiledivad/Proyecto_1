#include "Rutina.h"

Rutina::Rutina(Cliente* c, Instructor* i): cliente(c), instructor(i), 
cant_Pecho(0),cap_Pecho(10), cant_Tricep(0), cap_Tricep(10), cant_Bicep(0), cap_Bicep(10),
cant_Piernas(0), cap_Piernas(10), cant_Espalda(0), cap_Espalda(10) {

    pecho = new Ejercicio * [cap_Pecho];

    tricep = new Ejercicio * [cap_Tricep];

    bicep = new Ejercicio * [cap_Bicep];

    piernas = new Ejercicio * [cap_Piernas];

    espalda = new Ejercicio * [cap_Espalda];


    for (int i = 0; i < cap_Pecho; i++) {
        pecho[i] = nullptr;
    }
    for (int i = 0; i < cap_Tricep; i++) {
        tricep[i] = nullptr;
    }
    for (int i = 0; i < cap_Bicep; i++) {
        bicep[i] = nullptr;
    }
    for (int i = 0; i < cap_Piernas; i++) {
        piernas[i] = nullptr;
    }
    for (int i = 0; i < cap_Espalda; i++) {
        espalda[i] = nullptr;
    }
}

Rutina::~Rutina(){
    delete[] pecho; 
    delete[] tricep;
    delete[] bicep;
    delete[] piernas;
    delete[] espalda;

}

bool Rutina::agregarEjercicio(string tipo, Ejercicio* e1) {
    if (tipo == "Pecho" || tipo == "pecho") {
        if (cant_Pecho < cap_Pecho) {
            pecho[cant_Pecho++] = e1;
            return true;
        }
    }
    else if (tipo == "Triceps" || tipo == "triceps") {
        if (cant_Tricep < cap_Tricep) {
            tricep[cant_Tricep++] = e1;
            return true;
        }
    }
    else if (tipo == "Biceps" || tipo == "biceps") {
        if (cant_Bicep < cap_Bicep) {
            bicep[cant_Bicep++] = e1;
            return true;
        }
    }
    else if (tipo == "Piernas" || tipo == "piernas") {
        if (cant_Piernas < cap_Piernas) {
            piernas[cant_Piernas++] = e1;
            return true;
        }
    }
    else if (tipo == "Espalda" || tipo == "espalda") {
        if (cant_Espalda < cap_Espalda) {
            espalda[cant_Espalda++] = e1;
            return true;
        }
    }

    // Si no coincidió el tipo o no había espacio
    return false;
}


string Rutina::listarRutina() {

    stringstream x;

    x << "Rutina actual del cliente: " << endl << endl;


    x << "\n --- Pecho ---" << endl; 

    for (int i = 0; i < cant_Pecho; i++) {
        if (pecho[i] != nullptr) {
            x << " * " << pecho[i]->toString() << endl;
        }
    }

         x << "\n --- Triceps ---" << endl; 

         for (int i = 0; i < cant_Tricep; i++) {
             if (tricep[i] != nullptr) {
                 x << " * " << tricep[i]->toString() << endl;
             }
         }

         x << "\n --- Biceps ---" << endl; 

         for (int i = 0; i < cant_Bicep; i++) {
             if (bicep[i] != nullptr) {
                 x << " * " << bicep[i]->toString() << endl;
             }
         }

             x << "\n --- Piernas ---" << endl;

             for (int i = 0; i < cant_Piernas; i++) {
                 if (piernas[i] != nullptr) {
                     x << " * " << piernas[i]->toString() << endl;
                 }
             }
                 x << "\n --- Espalda ---" << endl;

                 for (int i = 0; i < cant_Espalda; i++) {
                     if (espalda[i] != nullptr) {
                         x << " * " << espalda[i]->toString() << endl;
                     }
                 }
                     return x.str();


                 }


string Rutina::toString() {

    stringstream s;

    if (cliente != nullptr) {
        s << "Rutina asignada a cliente: " << cliente->toString() << endl; 
    }
    else {
        s << "Rutina asignada a cliente: (sin cliente)" << endl; 
    }
    if (instructor != nullptr) {
        s << "Rutina creada por el instructor: " << instructor->toString() << endl;
    }
    else {
        s << "Rutina creada por el instructor: (sin instructor)" << endl;
    }

    // reutilizo listarRutina

    s << listarRutina() << endl; 


    return s.str(); 



}

       