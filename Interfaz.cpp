#include "Interfaz.h"

int Interfaz::pedirOpcion(int min, int max) {
	cout << "Seleccione una opcion: ";
	return leerEnteroRango(min, max);
}

string Interfaz::pedirTexto(const string& mensaje) {
	cout << mensaje;
	return leerCadena();
}

int Interfaz::pedirEntero(const string &mensaje) {
	cout << mensaje;
	return leerEntero();
}

int Interfaz::pedirEnteroRango(const string &mensaje,int min, int max) {
	cout << mensaje;

	return leerEnteroRango(min, max);
}

float Interfaz::pedirFlotante(const string &mensaje) {
	cout << mensaje;
	return leerFlotante();
}

float Interfaz::pedirFlotanteRango(const string& mensaje, float min, float max) {
	cout << mensaje;
	return leerFlotanteRango(min, max);
}

char Interfaz::pedirSexo() {
	return leerSexo();
}

string Interfaz::pedirEmail() {
	return leerEmail();
}

string Interfaz::pedirFecha() {
	return leerFecha();
}

void Interfaz::esperaEnter() {
	esperandoEnter();
}

void Interfaz::limpiarPantalla() {
	limpiaPantalla();
}

void Interfaz::mostrarMenuPrincipal() {
	cout << "===========================================================================================\n";

	cout << "   BIENVENIDO AL SISTEMA POWERLAB  \n";

	cout << "===========================================================================================\n";

	cout << "[1] -> Gestionar sucursales.\n";
	cout << "[2] -> Gestionar clientes.\n";
	cout << "[3] -> Gestionar instructores.\n";
	cout << "[0] -> Salir.\n";
}

void Interfaz::submenuSucursales() {
	cout << "===========================================================================================\n";

	cout << "   Gestion de sucursales  \n";

	cout << "===========================================================================================\n";

	cout << "[1] -> Agregar nueva sucursal.\n";
	cout << "[2] -> Modificar sucursal existente.\n";
	cout << "[3] -> Listar todas las sucursales.\n";
	cout << "[4] -> Buscar sucursal por codigo.\n";
	cout << "[0] -> Volver al menu principal.\n";
}

