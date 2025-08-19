#include "Controlador.h"

Controlador::Controlador() {
	sistema = new Sistema();
	ui = new Interfaz();
	ejecutando = true;
}

Controlador::~Controlador() {
	delete sistema;
	delete ui;
}

void Controlador::sinImplementar() {
	limpiaPantalla();
	cout << "Sin implementar\n";
	esperandoEnter();
	limpiaPantalla();
}

void Controlador::ejecutar() {
	while (ejecutando) {
		ui->mostrarMenuPrincipal();
		int opcion = ui->pedirOpcion(0, 3);
		switch (opcion) {
			case 1: 
				this->gestionarSucursales();
				break;
			case 2:
				this->sinImplementar();
				break;
			case 3:
				this->sinImplementar();
				break;
			case 0:
				ejecutando = false;
				limpiaPantalla();
				imprimeCadena("Gracias por usar el sistema PowerLab\n");
				break;
			default:
				cout << "Opcion invalida.";
		}
	}
}

void Controlador::gestionarSucursales() {
	bool volver = false;
	while (!volver) {
		ui->limpiarPantalla();
		ui->submenuSucursales();
		
		int opcion = ui->pedirOpcion(0, 4);
		switch (opcion) {
			case 1:
				sistema->crearSucursal();
				break;
			case 2:
				this->sinImplementar();
				break;
			case 3:
				sistema->listarSucursales();
				break;
			case 4:
				this->sinImplementar();
				break;
			case 0:
				volver = true;
				limpiaPantalla();
				break;
		}
	}
}