#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Medicion;
class Rutina;
class Instructor;
class ClaseGrupal;
class Sucursal;

using std::string;

static const int MAX_MEDICIONES = 10;
static const int MAX_CLASES_INSCRITAS = 3;

class Cliente {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fecha_nacimiento;
    char sexo;
    string fecha_inscripcion;

    Medicion** historial_mediciones;
    Rutina* rutina_asignada;
    Instructor* instructor_asignado;
    Sucursal* sucursal_asignada;
    ClaseGrupal** clases_inscritas;

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
    Medicion* getMedicionPos(int pos);

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
    int getCantidadMediciones();

    Rutina* getRutinaAsignada();
    Instructor* getInstructorAsignado();
    Sucursal* getSucursalAsignada();
    Medicion** getMedicionArr();

    string mostrarClasesInscritas();
    bool puedeInscribirse();
    bool agregarClaseInscrita(ClaseGrupal* clase);
};

#endif // CLIENTE_H