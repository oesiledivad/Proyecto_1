#include "Ejercicio.h"
#include "Instructor.h"

Ejercicio::Ejercicio(string nom, string tip, string grupo):
nombre(nom), tipo(tip), grupo_muscular(grupo) {}

Ejercicio::~Ejercicio() {}

string Ejercicio::getNombre() {
	return nombre;
}

string Ejercicio::getTipo() {
	return tipo;
}

string Ejercicio::getGrupoMuscular() {
	return grupo_muscular;
}

string Ejercicio::toString() {
	stringstream s;
	s << "Sin implementacion" << endl;
	return s.str();
}