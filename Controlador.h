#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Interfaz.h"
#include "Sistema.h"

class Controlador {
private:
	Sistema* sistema;
	Interfaz* ui;
	bool ejecutando;
public:
	Controlador();
	~Controlador();

	void ejecutar();

	void gestionarSucursales();
	//void gestionarClientes();


	// Para no estar copiando lo mismo
	void sinImplementar();
};
#endif // !CONTROLADOR_H
