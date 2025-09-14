#include "Utiles.h"
#include "Instructor.h"
#include "Sucursal.h"

// ===== Función auxiliar =====
string nombreEspecialidad(int codigo) {
    switch (codigo) {
    case CROSSFIT: return "CrossFit";
    case HIIT: return "HIIT";
    case TRX: return "TRX";
    case PESAS: return "Pesas";
    case SPINNING: return "Spinning";
    case CARDIO: return "Cardio";
    case YOGA: return "Yoga";
    case ZUMBA: return "Zumba";
    default: return "Desconocido";
    }
}

// ===== Constructores =====
Instructor::Instructor() {
    numeroCed = "";
    nombre = "";
    telefono = "";
    correo = "";
    fecha_Nacimiento = "";
    capacidad = 5; // capacidad inicial para especialidades
    numEspecialidades = 0;
    especialidades = new int[capacidad];
}

Instructor::Instructor(string ced, string nom, string tel, string cor, string fecha, int cap) {
    numeroCed = ced;
    nombre = nom;
    telefono = tel;
    correo = cor;
    fecha_Nacimiento = fecha;
    capacidad = cap;
    numEspecialidades = 0;
    especialidades = new int[capacidad];
}

// ===== Destructor =====
Instructor::~Instructor() {
    delete[] especialidades;
}

// ===== Métodos =====
bool Instructor::agregarEspecialidad(int codigo) {
    // Verificar si ya existe
    for (int i = 0; i < numEspecialidades; i++) {
        if (especialidades[i] == codigo) {
            return false; // ya la tiene
        }
    }
    // Agregar si hay espacio
    if (numEspecialidades < capacidad) {
        especialidades[numEspecialidades++] = codigo;
        return true;
    }
    return false; // no hay espacio
}

bool Instructor::tieneEspecialidad(int codigo) {
    for (int i = 0; i < numEspecialidades; i++) {
        if (especialidades[i] == codigo) {
            return true;
        }
    }
    return false;
}

string Instructor::listarEspecialidades() {
    stringstream x;

    for (int i = 0; i < numEspecialidades; i++) {
            x << "- " << nombreEspecialidad(especialidades[i]) << "\n";
        }
    return x.str(); 
}

// ===== Getters =====
string Instructor::getNombre() { return nombre; }
string Instructor::getNumeroCedula() { return numeroCed; }
string Instructor::getTelefono() { return telefono; }
string Instructor::getCorreo() { return correo; }
string Instructor::getFechaNacimiento() { return fecha_Nacimiento; }
int Instructor::getNumEspecialidades() { return numEspecialidades; }
int Instructor::getCapacidad() { return capacidad; }

// ===== toString =====
string Instructor::toString() {
    stringstream ss;
    ss << "Instructor: " << nombre << " (" << numeroCed << ")\n";
    ss << "Tel: " << telefono << " | Correo: " << correo << "\n";
    ss << "Fecha de nacimiento: " << fecha_Nacimiento << "\n";
    ss << "Especialidades: " << listarEspecialidades();
    return ss.str();
}