#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Sucursal.h"
// Punto h del instructor 
class Sucursal;

class Instructor {
private:

	//Datos basicos del instructor 
	string numeroCed;
	string nombre;
	int telefono;
	string correo;
	string fecha_Nacimiento;
	string* especialidades;
	int numEspecialides;
	const int capacidad;

public:

	// Constructor sin parametros
	Instructor();

	//Desctructor
	~Instructor();


	// Constructor con parametros 
	Instructor(string, string, int, string, string, string);

	// Metodos varios
	bool agregarEspecialidad(string);

	bool tieneEspecialidad(string);

	string listarEspecialidades();

	// Getters y toString

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


#endif // !INSTRUCTOR_H