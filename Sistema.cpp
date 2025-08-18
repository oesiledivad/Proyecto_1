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

void Sistema::agregarSucursal(Sucursal* sucursal) {
	if (cantidad_sucursales < capacidad_sucursales) {
		sucursales[cantidad_sucursales++] = sucursal;
	}
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

void Sistema::listarSucursales() {
	//TODO
}

void Sistema::listarEjercicios() {
	//TODO
}

void Sistema::iniciarAplicacion() { // Pantalla basica para ingresar los datos del sistema
	//TODO
	cout << "V 0.01" << endl;

	int opcion = 0;

	Sucursal e1;

	do {
		system("cls");

		cout << "===========================================================================================\n";

		cout << "   BIENVENIDO AL SISTEMA POWERLAB  \n";

		cout << "===========================================================================================\n";

		cout << "[1] -> Ingresar nueva Sucursal: \n "; 

		cout << "[0] -> Salir \n ";

		cout << "------------------------------------------------------------------------------------------- \n";

		cout << "Seleccione una opcion: ";


		cin >> opcion; 


		switch (opcion) {

		case 1:
			e1.ingresarSucursal();

			break;

		case 0:
			cout << "Gracias por usar POWERLAB \n";
			break;

		default: cout << "Opcion invalida \n"; 
		}

	} while (opcion != 0);

}
