#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Medicion;
class Rutina;
class Instructor;
class ClaseGrupal;
class Sucursal;

using std::string;

const int MAX_MEDICIONES = 10;
const int MAX_CLASES_INSCRITAS = 3;

class Cliente {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fecha_nacimiento;
    char sexo;
    string fecha_inscripcion;

    Medicion* historial_mediciones[MAX_MEDICIONES];
    Rutina* rutina_asignada;
    Instructor* instructor_asignado;
    Sucursal* sucursal;
    ClaseGrupal* clases_inscritas[MAX_CLASES_INSCRITAS];

    int cantidad_clases_inscritas;
    int cantidad_mediciones;
    bool haceEjercicio();

public:
    Cliente(string ced, string nom, string tel, string corr, string fecha_n, char sex, string fecha_i, Sucursal* suc);
    ~Cliente();

    bool agregarMedicion(Medicion* medicion);
    string mostrarHistorialMediciones();
    string mostrarMedicionResumen(int num);
    Medicion* getUltimaMedicion();

    void asignarInstructor(Instructor* instructor);
    void asignarRutina(Rutina* rutina);


    string toString();
    string getCedula();
    string getNombre();
    string getTelefono();
    string getCorreo();
    string getFecha_nacimiento();
    char getSexo();
    string getFecha_inscripcion();
    bool getHaceEjercicio();
    int getCantidadClasesInscritas();
    void matriculado();

    Rutina* getRutinaAsignada();
    Instructor* getInstructorAsignado();

    string mostrarClasesInscritas();
    bool puedeInscribirse();
    bool agregarClaseInscrita(ClaseGrupal* clase);
};

#endif // CLIENTE_H