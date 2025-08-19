#include <iostream>
#include "Controlador.h"
using namespace std;

int main() {
	Controlador* app = new Controlador();
	app->ejecutar();
	delete app;
	return 0;
}  