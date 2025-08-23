#include "ClaseGrupal.h"

ClaseGrupal::ClaseGrupal(string codigo, string salon, string horario,Instructor * ins,int capacidad ): 
codigo(codigo), salon(salon), horario(horario), capacidad_maxima(capacidad), cantidad_matriculados(0)  {

	clientes_inscritos = new Cliente * [capacidad_maxima]; 

	for (int i = 0; i < capacidad_maxima; i++) {
		clientes_inscritos[i] = nullptr;
	}

}

ClaseGrupal::~ClaseGrupal() {
	
	delete[] clientes_inscritos; 

}

string ClaseGrupal::getCodigo() { return codigo; }

string  ClaseGrupal::getSalon() { return salon; }

string ClaseGrupal::getHorario() { return horario; }

int ClaseGrupal::getCapacidad_Maxima() { return capacidad_maxima; }

int ClaseGrupal::getCantidad_Matriculados() { return cantidad_matriculados; }

int ClaseGrupal::getCupos_Disponibles() { return capacidad_maxima - cantidad_matriculados; }

bool ClaseGrupal :: inscribirCliente(Cliente* c1) {

	if (cantidad_matriculados >= capacidad_maxima) {
		return false; // NO hay cupos 
	}
	else {
		clientes_inscritos[cantidad_matriculados++] = c1;
		return true; // hay espacio 
	}
}

bool ClaseGrupal::retirarCliente(Cliente* c1) {

	for (int i = 0; i < cantidad_matriculados; i++) {
		if (clientes_inscritos[i] != nullptr && clientes_inscritos[i]->getcedula() == c1->getcedula()) {
			
			// retroceder una posicion atras a los clientes 
			for (int j = i; j < cantidad_matriculados - 1; j++) {
				clientes_inscritos[j] = clientes_inscritos[j - 1]; 
			}
			clientes_inscritos[cantidad_matriculados -1] = nullptr; // limpiar el ultimo
			cantidad_matriculados--;
			return true; // cliente retirado
		}
	}
	return false; // No se retiro el cliente 
}

string ClaseGrupal::listarClientes() {
	
	stringstream x;

	for (int i = 0; i < cantidad_matriculados; i++) {
		x << i+1 << ") "<< clientes_inscritos[i]->toString() << "\n" << endl;
	}
	return x.str(); 
}

string ClaseGrupal::toString() {

	stringstream s;

	s << "Clase: " << codigo << endl;

	s << "| Horario: " << horario << endl;

	s << "| Salon: " << salon << endl; 

	s << "| Cupos: " << (capacidad_maxima - cantidad_matriculados) << "/" << capacidad_maxima << "\n";

	if (ins1 != nullptr) {
		s << "Instructor: " << ins1->toString() << endl;
	}

	if (cantidad_matriculados > 0) {
		s << "Clientes inscritos:\n " << listarClientes(); 
	}
	else {
		s << "Sin clientes inscritos actualmente \n"; 
	}

	return s.str(); 


}