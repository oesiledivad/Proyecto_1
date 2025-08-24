#include "Cliente.h"
#include "Medicion.h" // Agregado para evitar warnings de tipo incompleto

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
		delete[]historial_mediciones; 
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

string Cliente::getcedula()
{
	return cedula;
}

string Cliente::getnombre()
{
	return nombre;
}

string Cliente::gettelefono()
{
	return telefono;
}

string Cliente::getcorreo()
{
	return correo;
}

string Cliente::getfecha_nacimiento()
{
	return fecha_nacimiento;
}

char Cliente::getsexo()
{
	return sexo;
}

string Cliente::getfecha_inscripcion()
{
	return fecha_inscripcion;
}
bool Cliente::getHaceEjercicio() {
	return haceEjercicio(); 
}

bool Cliente::haceEjercicio() {
    // Implementación provisional, puedes cambiar la lógica después
    return false;
}

string Cliente :: toString(){

	stringstream x;


	x << "Cedula: " << cedula << endl;

	x << "Nombre: " << nombre << endl;

	x << "Telefono: " << telefono << endl;

	x << "Correo: " << correo << endl;

	x << "Fecha de nacimiento: " << fecha_nacimiento << endl;

	x << "Sexo: " << sexo << endl;

	x << "Fecha de inscripcion: " << fecha_inscripcion << endl;

	return x.str(); 

}