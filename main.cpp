#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <windows.h> 
#include "Controlador.h"
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetConsoleCP(1252);          // Para las tildes
	SetConsoleOutputCP(1252);
	Controlador* app = new Controlador();
	app->ejecutar();
	delete app;
	return 0;
}