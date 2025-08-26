#pragma once
#include "Ejercicio.h"
#include "Cliente.h"
#include "Instructor.h"
class Rutina{

private:

	Cliente* cliente; // Quien la recive

	Instructor* instructor;  // Quien la da 

	Ejercicio** pecho; // Arreglo dinamico para guardar ejercicios de pecho

	int cant_Pecho;
	int cap_Pecho;

	Ejercicio** tricep;// Arreglo dinamico para guardar ejercicios de pecho

	int cant_Tricep;
	int cap_Tricep;

	Ejercicio** bicep;// Arreglo dinamico para guardar ejercicios de pecho
	int cant_Bicep;
	int cap_Bicep;

	Ejercicio** piernas;// Arreglo dinamico para guardar ejercicios de pecho
	int cant_Piernas;
	int cap_Piernas;

	Ejercicio** espalda; // Arreglo dinamico para guardar ejercicios de pecho
	int cant_Espalda;
	int cap_Espalda;


public:

	Rutina(Cliente*, Instructor*);

	~Rutina();

	bool agregarEjercicio(string, Ejercicio*);

	Cliente* getCliente();

	Instructor* getInstructor(); 

	string listarRutina(); 

	string toString();
};

