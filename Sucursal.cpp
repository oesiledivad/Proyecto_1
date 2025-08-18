#include "Sucursal.h"

Sucursal::Sucursal() : codigo (""), provincia (""), canton(""), correo(""), telefono ("") {
}

Sucursal::Sucursal(string cod, string prov, string canto, string corr, string tel):
codigo(cod), provincia(prov), canton(canto), correo(corr), telefono(tel), 
cantidad_clientes(0), cantidad_instructores(0), cantidad_clases(0), 
capacidad_clientes(MAX_CLIENTES), capacidad_instructores(MAX_INSTRUCTORES), capacidad_clases(MAX_CLASES)  {
	clientes = new Cliente * [capacidad_clientes];
	instructores = new Instructor * [capacidad_instructores];
	clases_grupales = new ClaseGrupal * [capacidad_clases];

	for (int i = 0; i < capacidad_clientes; i++) {
		clientes[i] = nullptr;
	}

	for (int i = 0; i < capacidad_instructores; i++) {
		instructores[i] = nullptr;
	}

	for (int i = 0; i < capacidad_clases; i++) {
		clases_grupales[i] = nullptr;
	}

}

Sucursal::~Sucursal() {
	for (int i = 0; i < cantidad_clientes; i++) {
		if (clientes[i] != nullptr) {
			delete clientes[i];
		}
	}
	delete[] clientes;

	for (int i = 0; i < cantidad_instructores; i++) {
		if (instructores[i] != nullptr) {
			delete instructores[i];
		}
	}
	delete[] instructores;

	for (int i = 0; i < cantidad_clases; i++) {
		if (clases_grupales[i] != nullptr) {
			delete clases_grupales[i];
		}
	}
	delete[] clases_grupales;
}

void Sucursal::agregarCliente(Cliente* cliente) {
	if (cantidad_clientes < capacidad_clientes) {
		clientes[cantidad_clientes++] = cliente;
	}
}

void Sucursal::agregarInstructor(Instructor* instructor) {
	if (cantidad_instructores < capacidad_instructores) {
		instructores[cantidad_instructores++] = instructor;
	}
}

void Sucursal::agregarClaseGrupal(ClaseGrupal* clase) {
	if (cantidad_clases < capacidad_clases) {
		clases_grupales[cantidad_clases] = clase;
	}
}

string Sucursal::getCodigo() {
	return codigo;
}

string Sucursal::toString() {
	stringstream s;

	s << "Ingrese el codigo: " << codigo << endl;

	s << "Ingrese la provincia: " << provincia << endl;

	s << "Ingrese el canton: " << canton << endl;

	s << "Ingrese el correo electronico: " << endl; 

	s << "Ingrese el telefono: " << telefono << endl; 

	return s.str();
}

void Sucursal:: ingresarSucursal() { // Se crea metodo provicional para ingresar una sucursal

	system("cls"); 

	cout << "  INGRESE LOS DATOS DE LA SUCURSAL \n " << endl; 

	string codigo, provincia, canton, correo, telefono;
	cin.ignore();
	cout << "Codigo: "; getline(cin, codigo);
	cout << "Provincia: "; getline(cin, provincia);
	cout << "Canton: "; getline(cin, canton);
	cout << "Correo: "; getline(cin, correo);
	cout << "Teléfono: "; getline(cin, telefono);
	cout << "\n Sucursal registrada.\n"; system("pause");
}
