#include "Instructor.h"
#include "Sucursal.h"


// Instructor con sus metodos basicos y un set para ingresar su especialidad y ser guardada en sistema 

Instructor::Instructor() : numeroCed(""), nombre(""), telefono(0), correo(""),

fecha_Nacimiento(""), especialidades(nullptr), numEspecialides(), capacidad(8){

	especialidades = new string[capacidad]; 
}
Instructor::Instructor(string numCed, string nom, int tel, string gmail, string fechaN, string espInicial) :
	numeroCed(numCed), nombre(nom), telefono(tel), correo(gmail), fecha_Nacimiento(fechaN), especialidades(nullptr),
	numEspecialides(), capacidad(8)
{
	especialidades = new string[capacidad];
	agregarEspecialidad(espInicial);

}
Instructor::~Instructor() {
	delete[] especialidades;
}

void Instructor::setTipoEspecialidad(string esp){

	tipoEspecialidad = esp; 
}

void Instructor::agregarEspecialidad(string esp){

	if (numEspecialides < capacidad) {
		especialidades[numEspecialides++] = esp;
	}
	else {
		cout << "El numero de especialides sobrepaso la capacidad." << endl; 
	}

}
bool Instructor::tieneEspecialidad(string esp){
	for (int i = 0; i < numEspecialides; i++) {
		if (especialidades[i] == esp) {
			return true; // Se encontro la especialidad
		}
			return false; // No se encontro
	}
}
void Instructor::listarEspecialidades(){
	for (int i = 0; i < numEspecialides; i++) {
		cout << "Especialida del instructor: " << especialidades[i] << "";
	}

}