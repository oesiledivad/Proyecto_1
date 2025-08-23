#pragma once
using namespace std;
#include <sstream>
#include "Instructor.h"
#include "Cliente.h"
class ClaseGrupal {


private:

	string codigo;

	string salon;

	string horario;

	Instructor* ins1;

	Cliente** clientes_inscritos;

	int capacidad_maxima; // Capacidad maxima de alumnos

	int cantidad_matriculados; // cantidad de alumnos inscritos actualmente 




public:

	//ClaseGrupal();

	ClaseGrupal(string, string, string,Instructor*, int);

	~ClaseGrupal();

	string getCodigo();

	string getSalon();

	string getHorario();

	int getCapacidad_Maxima();

	int getCupos_Disponibles();

	int getCantidad_Matriculados();

	bool inscribirCliente(Cliente*);

	bool retirarCliente(Cliente*);

	string listarClientes();

	string toString(); 


};

