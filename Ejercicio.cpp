#include "Ejercicio.h"
#include "Instructor.h"

Ejercicio::Ejercicio(string nom, int series, int repeticiones, double peso): nombre(nom), series(series), repeticiones(repeticiones), peso(peso) {}

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

double Ejercicio::getPeso() {
	return peso; 
}
string Ejercicio::toString() {

	stringstream s;

	s << nombre << " - " << endl;

	s << series << "x" << repeticiones <<endl;

	if (peso > 0) {
		s << " (" << peso << "kg)" << endl;
	}
	return s.str();
}