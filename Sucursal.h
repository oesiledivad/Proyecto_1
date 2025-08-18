#ifndef SUCURSAL_H
#define SUCURSAL_H
#include "Utiles.h"

class Cliente;
class Instructor;
class ClaseGrupal;

const int MAX_CLIENTES = 100;
const int MAX_INSTRUCTORES = 20;
const int MAX_CLASES = 8;

class Sucursal {
private:
	string codigo;
	string provincia;
	string canton;
	string correo;
	string telefono;

	Cliente** clientes;
	Instructor** instructores;
	ClaseGrupal** clases_grupales;

	int cantidad_clientes;
	int cantidad_instructores;
	int cantidad_clases;
	int capacidad_clientes;
	int capacidad_instructores;
	int capacidad_clases;
public:
	Sucursal(string cod, string prov, string canto, string corr, string tel);
	Sucursal(); 
	void ingresarSucursal(); // Metodo para ingresar la sucursal
	~Sucursal();

	string getCodigo();
	string toString();

	void agregarCliente(Cliente* cliente);
	void agregarInstructor(Instructor* instructor);
	void agregarClaseGrupal(ClaseGrupal* clase);
};

#endif // !SUCURSAL_H
