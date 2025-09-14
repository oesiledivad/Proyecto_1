#include "Utiles.h"
#include "Instructor.h"
#include "Sucursal.h"

// ===== Funci�n auxiliar =====
string nombreEspecialidad(int codigo) {
    switch (codigo) {
    case 1: CROSSFIT: return "CrossFit";
        break;
    case 2: HIIT: return "HIIT";
    case 3: TRX: return "TRX";
    case 4: PESAS: return "Pesas";
    case 5: SPINNING: return "Spinning";
    case 6: CARDIO: return "Cardio";
    case 7: YOGA: return "Yoga";
    case 8: ZUMBA: return "Zumba";
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
    capacidad = 8; // capacidad inicial para especialidades
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

// ===== M�todos =====
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