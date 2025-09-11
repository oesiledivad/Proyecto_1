#include "Ejercicio.h"
#include "Instructor.h"

Ejercicio::Ejercicio(){
	this->tipo = "SIN DEFINIR"; 
}

Ejercicio::Ejercicio(string nombreEjercicio) {
	this->tipo = nombreEjercicio; 
}

Ejercicio::~Ejercicio() {}

string Ejercicio::getTipo() {
	return tipo;
}
string Ejercicio::toString() {

	stringstream s;

	s << "Tipo ejercicio: " << tipo << " - " << endl;

	return s.str();
}