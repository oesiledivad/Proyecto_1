#include "Cliente.h"

Cliente::Cliente(string ced, string nom, string tel, string correo, string fecha_n, char sex,
	string fecha_i, Sucursal* suc) : cedula(ced), nombre(nom), 
	telefono(tel), correo(correo), fecha_nacimiento(fecha_n),
	sexo(sex), fecha_inscripcion(fecha_i),
	historial_mediciones(nullptr), rutina_asignada(nullptr), instructor_asignado(nullptr), 
	sucursal(suc), cantidad_clases_inscritas(0), cantidad_mediciones(0) {
	// TODO
	for (int i = 0; i < MAX_CLASES_INSCRITAS; i++) {
		clases_inscritas[i] = nullptr;
	}
}

Cliente::~Cliente() {
	delete[] historial_mediciones;
}

bool Cliente::agregarMedicion(Medicion* medicion) {
	/* TODO
		if (cantidad_mediciones < MAX_MEDICIONES) {
		historial_mediciones[cantidad_mediciones++] = *medicion;
	} 
	*/
	return false;
}

void Cliente::mostrarHistorialMediciones() {
	//TODO
}

Medicion* Cliente::getUltimaMedicion() {
	return nullptr;
}

void Cliente::asignarRutina() {
	//TODO
}

