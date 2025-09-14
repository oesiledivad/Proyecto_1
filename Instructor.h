#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
using namespace std;

// Enumeraci�n de especialidades
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
    // Datos b�sicos del instructor 
    string numeroCed;
    string nombre;
    string telefono;
    string correo;
    string fecha_Nacimiento;

    // Especialidades en forma de c�digos num�ricos
    int* especialidades;
    int numEspecialidades;
    int capacidad;

public:
    // Constructor sin par�metros
    Instructor();

    // Constructor con par�metros b�sicos
    Instructor(string ced, string nom, string tel, string cor, string fecha, int capacidad);

    // Destructor
    ~Instructor();

    // M�todos para especialidades
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

// Funci�n auxiliar global para traducir c�digo a texto
string nombreEspecialidad(int codigo);

#endif // INSTRUCTOR_H