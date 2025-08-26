#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Utiles.h"
// #include "Sucursal.h" // Eliminado para evitar dependencia circular
class Medicion; //TODO
class Rutina; //TODO
class Instructor; //TODO
class ClaseGrupal; // Declaración adelantada agregada
class Sucursal; // Declaración adelantada agregada

using std::string;

const int MAX_MEDICIONES = 10;

const int MAX_CLASES_INSCRITAS = 3;

class Cliente {
private:
	string cedula;

	string nombre;

	string telefono;

	string correo;

	string fecha_nacimiento;

	char sexo;

	string fecha_inscripcion;

	Medicion* historial_mediciones[MAX_MEDICIONES]; // Se cuenta el historial de mediciones como un arreglo 

	Rutina* rutina_asignada;

	Instructor* instructor_asignado;

	Sucursal* sucursal;

	ClaseGrupal* clases_inscritas[MAX_CLASES_INSCRITAS];

	int cantidad_clases_inscritas;

	int cantidad_mediciones;

	bool haceEjercicio();

public:
	Cliente(string ced, string nom, string tel, string correo, string fecha_n, char sex, string fecha_i, Sucursal* suc);

	~Cliente();

	bool agregarMedicion(Medicion* medicion);

	void mostrarHistorialMediciones();

	Medicion* getUltimaMedicion();

	void asignarRutina();

	string toString();

	string getcedula();

	string getnombre();

	string gettelefono();

	string getcorreo();

	string getfecha_nacimiento();

	char getsexo();

	string getfecha_inscripcion();

	bool getHaceEjercicio();


};

#endif // !CLIENTE.H
