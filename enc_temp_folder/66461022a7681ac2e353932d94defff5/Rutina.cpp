#include "Utiles.h"
#include "Rutina.h"
#include "Ejercicio.h"
#include "Cliente.h"
#include "Instructor.h"

Rutina::Rutina(Cliente* c, Instructor* i){

    ejercicios = new Ejercicio * [cap_ejercios]; 

    for(int i = 0; i < cap)


}

Rutina::~Rutina(){
    

}

bool Rutina::agregarEjercicio(string tipo, Ejercicio* e1) {
  
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

       