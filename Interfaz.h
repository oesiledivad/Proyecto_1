#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Utiles.h"
class Interfaz {
public:
	// Menus principales
	void mostrarMenuPrincipal();
	void submenuSucursales();

	int pedirOpcion(int min, int max);
	string pedirTexto(const string& mensaje);
	int pedirEntero(const string& mensaje);
	int pedirEnteroRango(const string& mensaje, int min, int max);
	float pedirFlotante(const string& mensaje);
	float pedirFlotanteRango(const string& mensaje, float min, float max);
	char pedirSexo();
	string pedirEmail();
	string pedirFecha();
	void esperaEnter();
	void limpiarPantalla();

};
#endif // !INTERFAZ_H
