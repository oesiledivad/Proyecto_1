#pragma once
#include "Sucursal.h"
// Punto h del instructor 
class Instructor {
private:
	string numeroCed;
	string nombre;
	int telefono;
	string correo;
	string fecha_Nacimiento;
	string *especialidades;
	int numEspecialides;
	const int capacidad;

public:
	Instructor();

	~Instructor(); 

	Instructor(string, string, int, string, string, string);

	bool agregarEspecialidad(string); 

	bool tieneEspecialidad(string);

	string listarEspecialidades(); 

	string getNombre();

	string getNumeroCedula();

	int getTelefono();
	
	string getCorreo();

	string getfecha_Nacimiento();
	
	string getEspecialidades();

	int getNumEspecialidades(); 

	int getCapacidad();

	string toString(); 
};

