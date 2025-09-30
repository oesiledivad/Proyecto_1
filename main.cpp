#include <iostream>
#include <windows.h> 
#include "Controlador.h"
int main() {
	SetConsoleCP(1252);          // Para las tildes
	SetConsoleOutputCP(1252);
	Controlador* app = new Controlador();
	app->ejecutar();
	delete app;
	return 0;
}