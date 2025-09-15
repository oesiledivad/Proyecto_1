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

Rutina::Rutina(Cliente* c, Instructor* i, int capacidad){ // con parametros 

    this->cliente = c; 

    this->instructor = i; 

    this->cant_ejercicios = 0;

    this->cap_ejercicios = capacidad; 

    ejercicios = new Ejercicio * [cap_ejercicios]; 

    for (int i = 0; i < cap_ejercicios; i++) {
        ejercicios[i] = nullptr; 
    }
}

Rutina::~Rutina(){
    
    if (ejercicios != nullptr) {
        for (int i = 0; i < cap_ejercicios; i++) {
            delete ejercicios[i];
        }
    }
    delete[]ejercicios; 
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
            if (ejercicios[i]->getTipo() == e1->getTipo()) {
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

    stringstream x;

    x << "Rutina actual del cliente: " << endl << endl;


   for (int i = 0; i < cant_ejercicios; i++) {
       x << ejercicios[i]->toString() << endl;
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


       