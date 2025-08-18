#include "Cliente.h"

Cliente::Cliente(string ced, string nom, string tel, string correo, string fecha_n, char sex,
	string fecha_i, Sucursal* suc) : cedula(ced), nombre(nom), 
	telefono(tel), correo(correo), fecha_nacimiento(fecha_n),
	sexo(sex), fecha_inscripcion(fecha_i), rutina_asignada(nullptr), instructor_asignado(nullptr), 
	sucursal(suc), cantidad_clases_inscritas(0), cantidad_mediciones(0) {
	// TODO

	for (int i = 0; i < MAX_MEDICIONES; i++) { // Se inicializa MAX_MEDICIONES como un arreglo 
		historial_mediciones[i] = nullptr; 
	}

	for (int i = 0; i < MAX_CLASES_INSCRITAS; i++) { // Se evita basura con nullptr
		clases_inscritas[i] = nullptr;
	}
}

Cliente::~Cliente() {
	for (int i = 0; i < MAX_MEDICIONES; i++) {
		if (historial_mediciones [i] != nullptr) { // Se implementa el destructor del historial de mediciones del cliente
			delete historial_mediciones[i];
		}
	}

	for (int i = 0; i < MAX_CLASES_INSCRITAS; i++) { // El cliente no puede destruir las "clases grupales" puesto que no son suyas, se dejan en nullptr
		clases_inscritas[i] = nullptr;
	}
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

