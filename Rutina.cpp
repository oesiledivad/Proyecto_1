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

void Rutina::listarRutina() {

    cout << "\n==================================================================\n";
    cout << "        RUTINA GENERADA \n";
    cout << "==================================================================\n";

    for (int i = 0; i < cant_ejercicios; i++) {
        cout << ejercicios[i]->getNombre() << ", series: " << ejercicios[i]->getSeries() << ", repeticiones: " << ejercicios[i]->getRepeticiones() << endl;
    };
}


string Rutina::toString() {

    stringstream s;

    if (cliente != nullptr) {
        s << "Rutina asignada a cliente: " << cliente->toString() << endl; 
    }
    else {
        s << "Rutina asignada a cliente: (sin cliente)" << endl; 
    }
    //if (instructor != nullptr) {
      //  s << "Rutina creada por el instructor: " << instructor->toString() << endl;
   // }
    //else { 
     //   s << "Rutina creada por el instructor: (sin instructor)" << endl;
    //}

    // sin uso en la interfaz

    // reutilizo listarRutina

    listarRutina(); 


    return s.str(); 
}


       