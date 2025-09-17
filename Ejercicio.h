#ifndef EJERCICIO_H
#define EJERCICIO_H
#include "Utiles.h"

class Ejercicio {
private:
	string nombre;
	int series;
	int repeticiones;
	int zona; // 1, 2, 3, 4, 5 
public:
	Ejercicio(string nom, int, int, int);

	Ejercicio(string nom);

	~Ejercicio();

	string getNombre();

	string toString();

	int getSeries();

	int getRepeticiones();

	int getZona(); 

};

#endif // !EJERCICIO_H