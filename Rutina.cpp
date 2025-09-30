#include "Utiles.h"
#include "Rutina.h"
#include "Ejercicio.h"
#include "Cliente.h"
#include "Instructor.h"

Rutina::Rutina(){ // sin parametros 

    this->cliente = nullptr;

    this->instructor = nullptr; 

    this->ejercicios = nullptr;

    this->cant_ejercicios = 0; 

    this->cap_ejercicios = 0; 
   
}

Rutina::Rutina(Cliente* c, Instructor* i){ // con parametros 

    this->cliente = c; 

    this->instructor = i; 

    this->cant_ejercicios = 0;

    this->cap_ejercicios = 100; 

    ejercicios = new Ejercicio * [cap_ejercicios]; 

    for (int i = 0; i < cap_ejercicios; i++) {
        ejercicios[i] = nullptr; 
    }
}

Rutina::~Rutina(){
    if (ejercicios != nullptr) {
        for (int i = 0; i < cap_ejercicios; i++) {
            if (ejercicios[i] != nullptr) {
                delete ejercicios[i];
            }
        }
    }
    delete[]ejercicios;
    cliente = nullptr;
    instructor = nullptr;
}

int Rutina::getCantidadEjercicios() {
    return cant_ejercicios; 
}

int Rutina::getCapacidadEjercicios() {
    return cap_ejercicios; 
}

bool Rutina::agregarEjercicio( Ejercicio * e1) {
  
    if (cant_ejercicios < cap_ejercicios) {
        for (int i = 0; i < cant_ejercicios; i++) {
            if (ejercicios[i]->getNombre() == e1->getNombre()) {
                return false; // encontro el mismo tipo de ejercicio
            }
        }
        ejercicios[cant_ejercicios++] = e1; 
        return true; 
    } 
    return false;
}

Cliente* Rutina::getCliente() {
    return cliente; 
}

Instructor* Rutina :: getInstructor() {
    return instructor; 
}

string Rutina::listarRutina() {
    stringstream s;
    s << "\n==================================================================\n";
    s << "\tRUTINA GENERADA \n";
    s << "==================================================================\n";

    for (int i = 0; i < cant_ejercicios; i++) {
        s << ejercicios[i]->getNombre() << ", series: " << ejercicios[i]->getSeries() << ", repeticiones: " << ejercicios[i]->getRepeticiones() << endl;
    };
    return s.str();
}

string Rutina::toString() {

    stringstream s;
    if (!cliente->getRutinaAsignada()) {
        s << "\nEl cliente no tiene rutina asignada\n";
    }
    else if (cliente != nullptr) {
        s << "Rutina generada por el instructor: " << instructor->getNombre() << endl;
        s << "Rutina asignada a cliente: " << cliente->getNombre() << endl;
        s << listarRutina();
    }
    else {
        s << "Rutina asignada a cliente: (sin cliente)" << endl; 
    }

    return s.str(); 
}


       