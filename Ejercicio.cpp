#include "Ejercicio.h"
#include "Instructor.h"

Ejercicio::Ejercicio(string nom, int series, int repeticiones, int zona) : nombre(nom), series(series), repeticiones(repeticiones), zona(zona) {}

Ejercicio::Ejercicio(string nom){
	this->nombre = nom; 
	series = 0;
	repeticiones = 0;
	zona = 0; 
}

Ejercicio::~Ejercicio() {}

string Ejercicio::getNombre() {
	return nombre;
}

int Ejercicio::getSeries() {
	return series;
}

int Ejercicio::getRepeticiones() {
	return repeticiones;
}
int Ejercicio::getZona()
{
	return zona; 
}
string Ejercicio::toString() {

	stringstream s;

	s << nombre << " - " << endl;

	s << series << "x" << repeticiones << endl;

	return s.str();
}