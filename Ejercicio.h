#ifndef EJERCICIO_H
#define EJERCICIO_H
#include "Utiles.h"

class Ejercicio {
private:
	string nombre;
	string tipo;
	string grupo_muscular;
public:
	Ejercicio(string nom, string tip, string grupo);
	~Ejercicio();

	string getNombre();
	string getTipo();
	string getGrupoMuscular();

	string toString();
};

#endif // !EJERCICIO_H
