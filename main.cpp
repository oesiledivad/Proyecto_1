#include <iostream>
#include "Controlador.h"

int main() {
	Controlador* app = new Controlador();
	app->ejecutar();
	delete app;
	return 0;
}