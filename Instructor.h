#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
using std::string;

class Cliente;
class Sucursal;
// Enumeración de especialidades
const int MAX_CLIENTES_ASIGNADOS = 100;

class Instructor {
private:
    // Datos básicos del instructor 
    string numeroCed;
    string nombre;
    string telefono;
    string correo;
    string fecha_Nacimiento;
    Sucursal* sucursal_asignada;

    // Especialidades en forma de códigos numéricos
    int* especialidades;
    int numEspecialidades;
    int capacidad;

    // Arreglo de punteros a Clientes
    Cliente** clientes_asignados;
    int cantidad_clientes_asignados;
    int capacidad_clientes_asignados;
public:
    // Constructor sin parámetros
    Instructor();

    // Constructor con parámetros básicos
    Instructor(string ced, string nom, string tel, string cor, string fecha, int capacidad_especialidades, Sucursal* suc);

    // Destructor
    ~Instructor();

    bool asignarCliente(Cliente* cliente);
    bool eliminarCliente(Cliente* cliente);
    string listarClientesAsignados();
    int getCantidadClientesAsignados();

    // Métodos para especialidades
    bool agregarEspecialidad(int codigo);
    bool tieneEspecialidad(int codigo);
    string listarEspecialidades();

    // Getters
    string getNombre();
    string getNumeroCedula();
    string getTelefono();
    string getCorreo();
    string getFechaNacimiento();
    int getNumEspecialidades();
    int getCapacidad();

    // Utilidad
    string toString();
};

#endif // INSTRUCTOR_H