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

void Sistema::agregarEjercicio(Ejercicio* ejercicio) {
	if (cantidad_ejercicios < capacidad_ejercicios) {
		ejercicios[cantidad_ejercicios++] = ejercicio;
	}
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

Ejercicio* Sistema::buscarEjercicio(string nombre) {
	//TODO
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

void Sistema::listarEjercicios() {
	//TODO
}

