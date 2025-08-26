#pragma once
using namespace std;
#include <sstream>
#include "Instructor.h"
#include "Cliente.h"
class ClaseGrupal {


private:

	string codigo; // Codigo de la clase

	string salon; // Salon en que se recibe

	string horario; // Horario en que se imparte

	Instructor* ins1; // Instructor que la realiza 

	Cliente** clientes_inscritos; // Arreglo dinamico de clientes inscritos 

	int capacidad_maxima; // Capacidad maxima de alumnos

	int cantidad_matriculados; // cantidad de alumnos inscritos actualmente 




public:

	// Constructor sin parametros 
	//ClaseGrupal(); // No se ha implementado en el cpp

	// Constructor con parametros

	ClaseGrupal(string, string, string,Instructor*, int);

	// Descructor
	~ClaseGrupal();

	// Getters
	string getCodigo();

	string getSalon();

	string getHorario();

	Instructor* getInstructor(); 

	Cliente** getCliente(); // Verificar si es posible declarlo asi 

	int getCapacidad_Maxima();

	int getCupos_Disponibles();

	int getCantidad_Matriculados();

	// Metodos varios 

	bool inscribirCliente(Cliente*);

	bool retirarCliente(Cliente*);

	string listarClientes();

	string toString(); 


};

