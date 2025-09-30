#include "Sistema.h"

Sistema::Sistema() :
	cantidad_sucursales(0), cantidad_ejercicios(0),
	capacidad_sucursales(MAX_SUCURSALES), capacidad_ejercicios(MAX_EJERCICIOS) {
	
	sucursales = new Sucursal * [capacidad_sucursales];
	ejercicios = new Ejercicio * [capacidad_ejercicios];
	
	for (int i = 0; i < capacidad_sucursales; i++) {
		sucursales[i] = nullptr;
	}

	for (int i = 0; i < capacidad_ejercicios; i++) {
		ejercicios[i] = nullptr;
	}
}

Sistema::~Sistema() {
	for (int i = 0; i < cantidad_sucursales; i++) {
		if (sucursales[i] != nullptr) {
			delete sucursales[i];
		}
	}
	delete[] sucursales;

	for (int i = 0; i < cantidad_ejercicios; i++) {
		if (ejercicios[i] != nullptr) {
			delete ejercicios[i];
		}
	}
	delete[] ejercicios;
}

bool Sistema::agregarSucursal(Sucursal* sucursal) {
	if (buscarSucursal(sucursal->getCodigo()) != nullptr) {
		return false;
	}

	if (cantidad_sucursales < capacidad_sucursales) {
		sucursales[cantidad_sucursales++] = sucursal;
		return true;
	}

	return false;
}

bool Sistema::agregarEjercicio(Ejercicio* ejercicio) {
	if (cantidad_ejercicios < capacidad_ejercicios) {
		// Verificar si ya existe
		for (int i = 0; i < cantidad_ejercicios; i++) {
			if (ejercicios[i]->getNombre() == ejercicio->getNombre()) {
				return false; // ya existe, no agregar
			}
		}

		// Si no existe, lo agregamos
		ejercicios[cantidad_ejercicios++] = ejercicio;
		return true;
	}
	return false; // no hay espacio
}
int Sistema::getCantidadSucursales() {
	return cantidad_sucursales;
}

int Sistema::getCantidadEjercicios() {
	return cantidad_ejercicios;
}

Sucursal* Sistema::buscarSucursal(string codigo) {
	if (cantidad_sucursales == 0) {
		return nullptr;
	}

	for (int i = 0; i < cantidad_sucursales; i++) {
		if (sucursales[i] != nullptr && sucursales[i]->getCodigo() == codigo) {
			return sucursales[i];
		}
	}

	return nullptr;
}

string Sistema::listarSucursales() {
	stringstream s;
	if (cantidad_sucursales == 0) {
		s << "No hay sucursales que mostrar.\n";
	}
	else {
		s << "=== LISTADO DE SUCURSALES ===\n";
		for (int i = 0; i < cantidad_sucursales; i++) {
			if (sucursales[i] != nullptr) {
				s << sucursales[i]->getCodigo() << " ";
				s << sucursales[i]->getProvincia() << " - " << sucursales[i]->getCanton() << "\n";
			}
		}
	}
	return s.str();
}

string Sistema::listarEjercicios(int zona, int& contador) {
	stringstream s;
	contador = 0;

	s << "\nBATERÍA DE EJERCICIOS DISPONIBLES PARA ZONA: " << validarZonaMuscular(zona) << endl;
	s << "===========================================\n";

	for (int i = 0; i < cantidad_ejercicios; i++) {
		if (ejercicios[i] != nullptr && ejercicios[i]->getZona() == zona) {
			s << ++contador << ". " << ejercicios[i]->getNombre() << endl;
		}
	}
	return s.str();
}

Ejercicio* Sistema::buscarEjercicioPorZona(int zona, int indiceUsuario) {
	int contador = 0;
	for (int i = 0; i < cantidad_ejercicios; i++) {
		if (ejercicios[i] != nullptr && ejercicios[i]->getZona() == zona) {
			contador++;
			if (contador == indiceUsuario) {
				return ejercicios[i];
			}
		}
	}
	return nullptr;
}