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
	bool exitoso = false;
	if (cantidad_sucursales < capacidad_sucursales) {
		sucursales[cantidad_sucursales++] = sucursal;
		exitoso = true;
	}
	return exitoso;
}

void Sistema::agregarEjercicio(Ejercicio* ejercicio) {
	if (cantidad_ejercicios < capacidad_ejercicios) {
		ejercicios[cantidad_ejercicios++] = ejercicio;
	}
}


Sucursal* Sistema::buscarSucursal(string codigo) {
	//TODO
	return nullptr;
}

Ejercicio* Sistema::buscarEjercicio(string nombre) {
	//TODO
	return nullptr;
}

// Esto podría ser un de tipo string
// con stringstream
void Sistema::listarSucursales() {
	limpiaPantalla();
	if (cantidad_sucursales == 0) {
		imprimeCadena("No hay sucursales que mostrar.\n");
	}
	else {
		imprimeCadena("Listando las sucursales...\n");
		for (int i = 0; i < cantidad_sucursales; i++) {
			if (sucursales[i] != nullptr) {
				cout << "Sucursal " << (i + 1) << "\n";
				cout << "Codigo: " << sucursales[i]->getCodigo() << "\n";
			}
		}
	}
	esperandoEnter();
}

void Sistema::listarEjercicios() {
	//TODO
}

void Sistema::crearSucursal() {
	// Esto de aca deberia de ir en Interfaz
	// Por el momento se queda aca
	limpiaPantalla();
	imprimeCadena("Agregando sucursal...\n");
	imprimeCadena("Ingrese el codigo: ");
	string codigo = leerCadena();
	imprimeCadena("Ingrese la provincia: ");
	string provincia = leerCadena();
	imprimeCadena("Ingrese el canton: ");
	string canton = leerCadena();
	imprimeCadena("Ingrese el correo: ");
	string correo = leerEmail();
	imprimeCadena("Ingrese el telefono: ");
	string telefono = leerCadena();
	
	Sucursal* nueva = new Sucursal(codigo, provincia, canton, correo, telefono);

	if (agregarSucursal(nueva)) {
		imprimeCadena("Sucursal agregada con exito!\n");
	}
	else {
		imprimeCadena("Error: capacidad de maxima de sucursales alcanzada.\n");
		delete nueva;
	}
	esperandoEnter();
}
