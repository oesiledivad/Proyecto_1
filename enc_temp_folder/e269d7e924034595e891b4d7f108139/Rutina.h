#ifndef RUTINA_H
#define RUTINA_H

class Ejercicio;
class Cliente;
class Instructor;

class Rutina {

private:

	Cliente* cliente; // Quien la recive

	Instructor* instructor;  // Quien la da 

	Ejercicio** ejercicios; // Arreglo dinamico para guardar ejercicios

	int cant_ejercicios;
	int cap_ejercicios;
public:

	Rutina(Cliente*, Instructor*);

	~Rutina();

	int getCantidad();

	int getCapacidad(); 


	bool agregarEjercicio(string nombre, Ejercicio* ejercicio);

	Cliente* getCliente();

	Instructor* getInstructor();

	string listarRutina();

	string toString();
};
#endif // !RUTINA_H
