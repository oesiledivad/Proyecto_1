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
	//string tipoEspecialidad;
	const int capacidad;

public:
	Instructor();

	~Instructor(); 

	Instructor(string, string, int, string, string, string);

	void agregarEspecialidad(string); 

	bool tieneEspecialidad(string);

	void listarEspecialidades(); 

	//void setTipoEspecialidad(string); 
	
	//string getTipoEspecialidad(string); 
};

