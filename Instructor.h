#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {
private:

	//Datos basicos del instructor 
	string numeroCed;
	string nombre;
	int telefono;
	string correo;
	string fecha_Nacimiento;
    // Especialidades en forma de c�digos num�ricos
    int* especialidades;
    int numEspecialidades;
    int capacidad;

	string* especialidades;
    // Constructor sin par�metros
    Instructor();
	int numEspecialides;
    // Constructor con par�metros b�sicos
    Instructor(string ced, string nom, string tel, string cor, string fecha, int capacidad);
	string* especialidades;
	int numEspecialides;
	const int capacidad;

    // M�todos para especialidades
    bool agregarEspecialidad(int codigo);
    bool tieneEspecialidad(int codigo);
    string listarEspecialidades();
	Instructor(string, string, int, string, string, string);

	// Metodos varios
	bool agregarEspecialidad(string);

	bool tieneEspecialidad(string);

	string listarEspecialidades();

    // Getters
    string getNombre();
    string getNumeroCedula();
    string getTelefono();
    string getCorreo();
// Funci�n auxiliar global para traducir c�digo a texto
string nombreEspecialidad(int codigo);
    string getFechaNacimiento();
#endif // INSTRUCTOR_H    int getCapacidad();

    // Utilidad
    string toString();
};


#endif // !INSTRUCTOR_H