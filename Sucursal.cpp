#include "Utiles.h"
#include "Sucursal.h"
#include "ClaseGrupal.h"
#include "Instructor.h"
#include "Cliente.h"

//Sucursal::Sucursal() : codigo (""), provincia (""), canton(""), correo(""), telefono ("") {
//}

Sucursal::Sucursal(string cod, string prov, string canto, string corr, string tel):
codigo(cod), provincia(prov), canton(canto), correo(corr), telefono(tel), 
cantidad_clientes(0), cantidad_instructores(0), cantidad_clases(0), 
capacidad_clientes(MAX_CLIENTES), capacidad_instructores(MAX_INSTRUCTORES), capacidad_clases(MAX_CLASES)  {
	clientes = new Cliente * [capacidad_clientes];
	instructores = new Instructor * [capacidad_instructores];
	clases_grupales = new ClaseGrupal * [capacidad_clases];

	for (int i = 0; i < capacidad_clientes; i++) {
		clientes[i] = nullptr;
	}

	for (int i = 0; i < capacidad_instructores; i++) {
		instructores[i] = nullptr;
	}

	for (int i = 0; i < capacidad_clases; i++) {
		clases_grupales[i] = nullptr;
	}

}

Sucursal::~Sucursal() {
	for (int i = 0; i < cantidad_clientes; i++) {
		if (clientes[i] != nullptr) {
			delete clientes[i];
		}
	}
	delete[] clientes;

	for (int i = 0; i < cantidad_instructores; i++) {
		if (instructores[i] != nullptr) {
			delete instructores[i];
		}
	}
	delete[] instructores;

	for (int i = 0; i < cantidad_clases; i++) {
		if (clases_grupales[i] != nullptr) {
			delete clases_grupales[i];
		}
	}
	delete[] clases_grupales;
}

bool Sucursal::agregarCliente(Cliente* cliente) {
	for (int i = 0; i < cantidad_clientes; i++) {
		if (clientes[i] != nullptr && clientes[i]->getCedula() == cliente->getCedula()) {
			return false;
		}
	}

	if (cantidad_clientes < capacidad_clientes) {
		clientes[cantidad_clientes++] = cliente;
		return true;
	}

	return false;
}

bool Sucursal::agregarInstructor(Instructor* instructor) {
	for (int i = 0; i < cantidad_instructores; i++) {
		if (instructores[i] != nullptr && instructores[i]->getNumeroCedula() == instructor->getNumeroCedula()) {
			return false;
		}
	}

	if (cantidad_instructores < capacidad_instructores) {
		instructores[cantidad_instructores++] = instructor;
		return true;
	}
	else {
		return false;
	}
}

bool Sucursal::agregarClaseGrupal(ClaseGrupal* clase) {
    if (cantidad_clases < capacidad_clases) {
        clases_grupales[cantidad_clases++] = clase;
        return true;
    } else {
        return false;
    }
}


Cliente* Sucursal::buscarClientePorCedula(string cedu) {

	for (int i = 0; i < cantidad_clientes; i++) {
		if (clientes[i]!= nullptr && clientes[i]->getCedula() == cedu) {
			return clientes[i]; 
		}
	}
	return nullptr; 
}


Instructor* Sucursal::buscarInstructorPorCedula(string cedu) {
	for (int i = 0; i < cantidad_instructores; i++) {
		if (instructores[i] != nullptr && instructores[i]->getNumeroCedula() == cedu) {
			return instructores[i];
		}
	}
	return nullptr;
}

void Sucursal::mostrarInstructoresPorEspecialidad(int especialidad) {
	bool encontrado = false;

	cout << "\n--- Instructores con la especialidad: "
		<< nombreEspecialidad(especialidad) << " ---\n";

	for (int i = 0; i < cantidad_instructores; i++) {
		if (instructores[i] != nullptr && instructores[i]->tieneEspecialidad(especialidad)) {
			cout << "Cedula: " << instructores[i]->getNumeroCedula() << " | Nombre: " << instructores[i]->getNombre() << "\n";
			encontrado = true;
		}
	}

	if (!encontrado) {
		cout << "No existen instructores con esta especialidad en la sucursal.\n";
	}
}


string Sucursal::listarClientes() {
	stringstream s;
	if (cantidad_clientes == 0) {
		s << "No hay clientes registrados en esta sucursal.\n";
	}
	else {
		s << "=== LISTADO DE CLIENTES ===\n";
		for (int i = 0; i < cantidad_clientes; i++) {
			if (clientes[i] != nullptr) {
				s << "Cedula: " << clientes[i]->getCedula() << " | Nombre: " << clientes[i]->getNombre() << "\n";
			}
		}
	}
	return s.str();
}

string Sucursal::listarInstructores() {
	stringstream s;
	if (cantidad_instructores == 0) {
		s << "No hay instructores en esta sucursal. Puedes seleccionar la opcion de 'Sin instructor'.\n";
	}
	else {
		s << "=== LISTADO DE INSTRUCTORES ===\n";
		for (int i = 0; i < cantidad_instructores; i++) {
			if (instructores[i] != nullptr) {
				s << "Cedula: " << instructores[i]->getNumeroCedula() << " | Nombre: " << instructores[i]->getNombre() << "\n";
			}
		}
	}
	return s.str();
}

string Sucursal::getCodigo() {
	return codigo;
}

string Sucursal::getProvincia() {
	return provincia;
}

string Sucursal::getCanton() {
	return canton;
}

string Sucursal::getCorreo() {
	return correo;
}

string Sucursal::getTelefono() {
	return telefono;
}

int Sucursal::getCantidadInstructores() {
	return cantidad_instructores;
}

int Sucursal::getCantidadClientes() {
	return cantidad_clientes;
}

int Sucursal::getCantidadClasesGrupales() {
	return cantidad_clases;
}

string Sucursal::toString() {
	stringstream s;

	s << "Codigo: " << getCodigo() << endl;

	s << "Provincia: " << getProvincia() << endl;

	s << "Canton: " << getCanton() << endl;

	s << "Correo: " << getCorreo() <<endl; 

	s << "Telefono: " << getTelefono() << endl; 

	return s.str();
}