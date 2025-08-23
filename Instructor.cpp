#include "Instructor.h"
#include "Sucursal.h"


// Instructor con sus metodos basicos y un set para ingresar su especialidad y ser guardada en sistema 

Instructor::Instructor() : numeroCed(""), nombre(""), telefono(0), correo(""),

fecha_Nacimiento(""), especialidades(nullptr), numEspecialides(0), capacidad(8){

	especialidades = new string[capacidad]; 
}
Instructor::Instructor(string numCed, string nom, int tel, string gmail, string fechaN, string espInicial) :
	numeroCed(numCed), nombre(nom), telefono(tel), correo(gmail), fecha_Nacimiento(fechaN), especialidades(nullptr),
	numEspecialides(0), capacidad(8)
{
	especialidades = new string[capacidad];

	agregarEspecialidad(espInicial);

}
Instructor::~Instructor() {
	delete[] especialidades;
}

bool Instructor::agregarEspecialidad(string esp){

	if (tieneEspecialidad(esp)) {
		cout << "La especialidad ya existe"; 
		return false; // No duplicados 
	}
		else if (numEspecialides < capacidad) {
			especialidades[numEspecialides++] = esp;
			return true;  // se agrego la especialidad
		}
	else {
		cout << "El numero de especialides sobrepaso la capacidad." << endl; 
		return false;  // sobrepaso el limite
	}

}
bool Instructor::tieneEspecialidad(string esp){
	for (int i = 0; i < numEspecialides; i++) {
		if (especialidades[i] == esp) {
			return true; // Se encontro la especialidad
		}
	}
	return false; // si termino el bucle y no encontro nada
}
string Instructor::listarEspecialidades(){
	string resultado = ""; 
	for (int i = 0; i < numEspecialides; i++) {
		resultado += " - " + especialidades[i] + "" + "\n";
	}
	return resultado; 
}

// Tostring

string Instructor::toString() {

	stringstream x;


	x << "|Numero de cedula: | " << numeroCed << endl;

	x << "|Nombre del instructor: | " << nombre << endl;

	x << "|Telefono: | " << telefono << endl;

	x << "|Correo: | " << correo << endl;

	x << "|Fecha de nacimiento | " << fecha_Nacimiento << endl;

	x << "|Especialidades: | " << * especialidades << endl;

	x << "|Numero de especialidades: | " << numEspecialides << endl;


	return x.str(); 
}

// Getters 
string Instructor::getNombre() { return nombre; }

string  Instructor::getNumeroCedula() { return numeroCed; }

int  Instructor::getTelefono() { return telefono; }

string  Instructor::getCorreo() { return correo; }

string  Instructor::getfecha_Nacimiento() { return fecha_Nacimiento; }

int  Instructor::getNumEspecialidades() { return numEspecialides; }

int  Instructor::getCapacidad() { return capacidad; }

string Instructor::getEspecialidades() { return *especialidades; }