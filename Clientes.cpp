#include "Utiles.h"
#include "Cliente.h"
#include "Medicion.h"
#include "Rutina.h"
#include "Instructor.h"
#include "Sucursal.h"
#include "ClaseGrupal.h"

Cliente::Cliente(string ced, string nom, string tel, string corr, string fecha_n, char sex,
    string fecha_i, Sucursal* suc) : cedula(ced), nombre(nom),
    telefono(tel), correo(corr), fecha_nacimiento(fecha_n),
    sexo(sex), fecha_inscripcion(fecha_i),rutina_asignada(nullptr), instructor_asignado(nullptr),
    sucursal(suc), cantidad_clases_inscritas(0), cantidad_mediciones(0){

    rutina_asignada = new Rutina(this, instructor_asignado); 

    for (int i = 0; i < MAX_MEDICIONES; i++) {
        historial_mediciones[i] = nullptr;
    }
    for (int i = 0; i < MAX_CLASES_INSCRITAS; i++) {
        clases_inscritas[i] = nullptr;
    }
}

Cliente::~Cliente() {
    for (int i = 0; i < cantidad_mediciones; i++) {
        if (historial_mediciones[i] != nullptr) {
            delete historial_mediciones[i];
            historial_mediciones[i] = nullptr;
        }
    }

    rutina_asignada = nullptr;
    instructor_asignado = nullptr;
    sucursal = nullptr;
}

bool Cliente::agregarMedicion(Medicion* medicion) {
    if (cantidad_mediciones < MAX_MEDICIONES) {
        historial_mediciones[cantidad_mediciones++] = medicion;
        return true;
    }
    return false;
}

string Cliente::mostrarHistorialMediciones() {
    stringstream x;

    for (int i = 0; i < cantidad_mediciones; i++) {
        x << (i+1) << "-" << historial_mediciones[i]->reporteMedicionResumen() << endl;
    }
    return x.str(); 
}

string Cliente::mostrarMedicionResumen(int num){
    stringstream x;

    if (num < 1 || num > cantidad_mediciones) {
        x << "Error: numero de medicion invalido." << endl;
        return x.str();
    }

    // Acceder directamente a la medicion correspondiente
    Medicion* m = historial_mediciones[num - 1];


    x << m->datosBasicosMedicion() << endl;
    

    return x.str();
}


Medicion* Cliente::getUltimaMedicion() {
    if (cantidad_mediciones > 0) {
        return historial_mediciones[cantidad_mediciones - 1];
    }
    return nullptr;
}

void Cliente::asignarInstructor(Instructor* instructor) {
    instructor_asignado = instructor;
}

void Cliente::asignarRutina(Rutina* rutina) {
    rutina_asignada = rutina;
}

string Cliente::getCedula() { 
    return cedula; 
}
string Cliente::getNombre() { 
    return nombre; 
}
string Cliente::getTelefono() { 
    return telefono; 
}
string Cliente::getCorreo() { 
    return correo; 
}
string Cliente::getFecha_nacimiento() { 
    return fecha_nacimiento; 
}
char Cliente::getSexo() { 
    return sexo; 
}
string Cliente::getFecha_inscripcion() { 
    return fecha_inscripcion; 
}
bool Cliente::getHaceEjercicio() { 
    return haceEjercicio(); 
}
Rutina* Cliente::getRutinaAsignada() { 
    return rutina_asignada; 
}
Instructor* Cliente::getInstructorAsignado() { 
    return instructor_asignado; 
}

string Cliente::mostrarClasesInscritas() {
    stringstream s;
    if (cantidad_clases_inscritas == 0) {
        s << "El cliente no está inscrito en ninguna clase grupal." << endl;
    }
    else {
        s << "Clases matriculadas por cliente: " << endl;
        for (int i = 0; i < cantidad_clases_inscritas; i++) {
            s << i + 1 << "- " << clases_inscritas[i]->getCodigo() << endl;
        }
    }
    return s.str();
}

bool Cliente::puedeInscribirse() {
    return cantidad_clases_inscritas < MAX_CLASES_INSCRITAS;
}

bool Cliente::agregarClaseInscrita(ClaseGrupal* clase) {
    bool inscrito = false;
    for (int i = 0; i < cantidad_clases_inscritas && !inscrito; i++) {
        if (clases_inscritas[i] == clase) {
            inscrito = true;
        }
    }
    clases_inscritas[cantidad_clases_inscritas] = clase;
    cantidad_clases_inscritas++;
    return inscrito;
}

int Cliente::getCantidadClasesInscritas() {
    return cantidad_clases_inscritas;
}

bool Cliente::haceEjercicio() {
    return cantidad_mediciones > 0;
}

void Cliente::matriculado() {
    if (cantidad_clases_inscritas < MAX_CLASES_INSCRITAS) {
        cantidad_clases_inscritas++;
    }
}

string Cliente::toString() {
    stringstream x;
    x << "Cedula: " << cedula << endl;
    x << "Nombre: " << nombre << endl;
    x << "Telefono: " << telefono << endl;
    x << "Correo: " << correo << endl;
    x << "Fecha de nacimiento: " << fecha_nacimiento << endl;
    x << "Sexo: " << sexo << endl;
    x << "Fecha de inscripcion: " << fecha_inscripcion << endl;

    if (instructor_asignado) {
        x << "Instructor asignado: " << instructor_asignado->getNombre() << endl;
    }
    else {
        x << "Instructor asignado: No tiene" << endl;
    }

    if (rutina_asignada) {
        x << "Rutina asignada: Si" << endl;
    }
    else {
        x << "Rutina asignada: No tiene" << endl;
    }

    x << "Cantidad de Mediciones: " << cantidad_mediciones << endl;

    return x.str();
}