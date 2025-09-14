#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H
using namespace std;
#include <sstream>

class Instructor;
class Cliente;

class ClaseGrupal {
private:
	string codigo; 
	string salon;
	string horario;
	Instructor* ins1;
	Cliente** clientes_inscritos;
	int capacidad_maxima;
	int cantidad_matriculados;

public:

	ClaseGrupal(string, string, string, Instructor*, int);
	~ClaseGrupal();

	string getCodigo();
	string getSalon();
	string getHorario();
	Instructor* getInstructor();
	Cliente** getCliente();
	int getCapacidad_Maxima();
	int getCupos_Disponibles();
	int getCantidad_Matriculados();

	bool inscribirCliente(Cliente*);
	bool retirarCliente(Cliente*);

	string listarClientes();
	string toString();
};

#endif // !"CLASEGRUPAL_H"