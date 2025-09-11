#ifndef EJERCICIO_H
#define EJERCICIO_H
#include "Utiles.h"

class Ejercicio {
private:
	string tipo;
public:

	Ejercicio(); 

	Ejercicio(string nombreEjercicio);

	~Ejercicio(); // sin utilidad

	string getTipo();

	string toString();

};

#endif // !EJERCICIO_H
