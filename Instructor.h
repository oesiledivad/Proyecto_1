#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
using namespace std;

// Enumeración de especialidades
enum Especialidad {
    CROSSFIT = 1,
    HIIT,
    TRX,
    PESAS,
    SPINNING,
    CARDIO,
    YOGA,
    ZUMBA
};

class Instructor {
private:
    // Datos básicos del instructor 
    string numeroCed;
    string nombre;
    string telefono;
    string correo;
    string fecha_Nacimiento;

    // Especialidades en forma de códigos numéricos
    int* especialidades;
    int numEspecialidades;
    int capacidad;

public:
    // Constructor sin parámetros
    Instructor();

    // Constructor con parámetros básicos
    Instructor(string ced, string nom, string tel, string cor, string fecha, int capacidad);

    // Destructor
    ~Instructor();

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

// Función auxiliar global para traducir código a texto
string nombreEspecialidad(int codigo);

#endif // INSTRUCTOR_