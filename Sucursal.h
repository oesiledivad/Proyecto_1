#ifndef SUCURSAL_H
#define SUCURSAL_H

class Cliente;
class Instructor;
class ClaseGrupal;

const int MAX_CLIENTES = 100;
const int MAX_INSTRUCTORES = 20;
const int MAX_CLASES = 8;

class Sucursal {
private:
	string codigo;
	string provincia;
	string canton;
	string correo;
	string telefono;

	Cliente** clientes;
	Instructor** instructores;
	ClaseGrupal** clases_grupales;

	int cantidad_clientes;
	int cantidad_instructores;
	int cantidad_clases;
	int capacidad_clientes;
	int capacidad_instructores;
	int capacidad_clases;
public:
	Sucursal(string cod, string prov, string canto, string corr, string tel);
	//Sucursal(); 
	~Sucursal();

	string getCodigo();
	string getProvincia();
	string getCanton();
	string getCorreo();
	string getTelefono();
	string toString();

	int getCantidadClientes();
	int getCantidadInstructores();
	int getCantidadClasesGrupales();

	bool agregarCliente(Cliente* cliente);
	bool agregarInstructor(Instructor* instructor);
	bool agregarClaseGrupal(ClaseGrupal* clase);
	bool existenInstructoresConEspecialidad(int codigoEspecialidad);

	Cliente* buscarClientePorCedula(string cedu);
	Instructor* buscarInstructorPorCedula(string cedu);
	ClaseGrupal* buscarClaseGrupalPorCodigo(string codigo);
	ClaseGrupal* buscarClaseGrupalPorPosicion(int pos);

	string listarClientes();
	string listarInstructores();
	string listarClasesGrupales();

	string mostrarInstructoresPorEspecialidad(int especialidad);
};

#endif // !SUCURSAL_H
