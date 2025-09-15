#include "ClaseGrupal.h"
#include "Instructor.h"
#include "Cliente.h"

ClaseGrupal::ClaseGrupal(string codigo, string salon, string horario,Instructor * ins,int capacidad ): 
codigo(codigo), salon(salon), horario(horario), ins1(ins), capacidad_maxima(capacidad), cantidad_matriculados(0) {

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

Instructor* ClaseGrupal::getInstructor() { return nullptr; }

Cliente** ClaseGrupal::getCliente() { return nullptr; } // Verificar metodo 

bool ClaseGrupal::inscribirCliente(Cliente* c1) {
	bool resultado = true;

	if (cantidad_matriculados >= capacidad_maxima) {
		resultado = false;
	}

	for (int i = 0; i < cantidad_matriculados && resultado; i++) {
		if (clientes_inscritos[i] != nullptr && clientes_inscritos[i]->getCedula() == c1->getCedula()) {
			resultado = false;
		}
	}

	if (resultado && !c1->puedeInscribirse()) {
		resultado = false;
	}

	if (resultado) {
		clientes_inscritos[cantidad_matriculados++] = c1;
		c1->agregarClaseInscrita(this);
	}

	return resultado;
}


bool ClaseGrupal::retirarCliente(Cliente* c1) {

	for (int i = 0; i < cantidad_matriculados; i++) {
		if (clientes_inscritos[i] != nullptr && clientes_inscritos[i]->getCedula() == c1->getCedula()) {
			
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
		x << i+1 << "- "<< clientes_inscritos[i]->getCedula() << " " << clientes_inscritos[i]->getNombre() << "\n" << endl;
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