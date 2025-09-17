#ifndef SISTEMA_H
#define SISTEMA_H
#include "Utiles.h"
#include "Sucursal.h"
#include "Ejercicio.h"

const int MAX_SUCURSALES = 30;
const int MAX_EJERCICIOS = 100;

class Sistema {
private:
	Sucursal** sucursales;
	Ejercicio** ejercicios;
	int cantidad_sucursales;
	int cantidad_ejercicios;
	int capacidad_sucursales;
	int capacidad_ejercicios;
public:
	Sistema();
	~Sistema();

	int getCantidadSucursales();
	int getCantidadEjercicios();

	bool agregarSucursal(Sucursal*);
	Sucursal* buscarSucursal(string codigo);
	string listarSucursales();
	bool agregarEjercicio(Ejercicio*);
	Ejercicio* buscarEjercicio(string nombre);
	int listarEjercicios(int zona);
	string zonaMuscularNombre(int zona); 

	Ejercicio* buscarEjercicioPorZona(int zona, int indice);
};
#endif 