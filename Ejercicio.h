#ifndef EJERCICIO_H
#define EJERCICIO_H
#include "Utiles.h"

class Ejercicio {
private:
	string nombre;
	int series;
	int repeticiones;
	double peso;
public:
	Ejercicio(string nom, int, int, double);
	~Ejercicio();

	string getNombre();
	string getTipo();
	string getGrupoMuscular();

	string toString();

	int getSeries(); 

	int getRepeticiones();

	double getPeso();
};

#endif // !EJERCICIO_H
