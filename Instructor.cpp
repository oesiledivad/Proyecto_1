#include "Instructor.h"
#include "Cliente.h"
#include "Sucursal.h"
#include "Utiles.h"
#include "Rutina.h"
#include "Medicion.h"

// ===== Constructores =====
Instructor::Instructor() {
    numeroCed = "";
    nombre = "";
    telefono = "";
    correo = "";
    fecha_Nacimiento = "";
    capacidad_especialidades = MAX_ESPECIALIDADES; // capacidad inicial para especialidades
    numEspecialidades = 0;
    especialidades = new int*[capacidad_especialidades];
    sucursal_asignada = nullptr;
    cantidad_clientes_asignados = 0;
    capacidad_clientes_asignados = MAX_CLIENTES_ASIGNADOS;
    clientes_asignados = new Cliente * [capacidad_clientes_asignados];

    for (int i = 0; i < capacidad_clientes_asignados; i++) {
        clientes_asignados[i] = nullptr;
    }
    for (int i = 0; i < capacidad_especialidades; i++) {
        especialidades[i] = nullptr;
    }
}

Instructor::Instructor(string ced, string nom, string tel, string cor, string fecha, Sucursal* suc) {
    numeroCed = ced;
    nombre = nom;
    telefono = tel;
    correo = cor;
    fecha_Nacimiento = fecha;
    capacidad_especialidades = MAX_ESPECIALIDADES;
    numEspecialidades = 0;
    especialidades = new int*[capacidad_especialidades];
    sucursal_asignada = suc;

    cantidad_clientes_asignados = 0;
    capacidad_clientes_asignados = MAX_CLIENTES_ASIGNADOS;
    clientes_asignados = new Cliente * [capacidad_clientes_asignados];

    for (int i = 0; i < capacidad_clientes_asignados; i++) {
        clientes_asignados[i] = nullptr;
    }

    for (int i = 0; i < capacidad_especialidades; i++) {
        especialidades[i] = nullptr;
    }
}

// ===== Destructor =====
Instructor::~Instructor() {
    for (int i = 0; i < capacidad_clientes_asignados; i++) {
        // Elimina las Mediciones y las Rutinas, no al Cliente
        if (clientes_asignados[i] != nullptr) {
            for (int j = 0; j < clientes_asignados[i]->getCantidadMediciones(); j++) {
                delete clientes_asignados[i]->getMedicionPos(j);
            }
            delete clientes_asignados[i]->getRutinaAsignada();
        }
    }

    for (int i = 0; i < capacidad_especialidades; i++) {
        if (especialidades[i] != nullptr) {
            delete especialidades[i];
        }
    }

    delete[] clientes_asignados;
    delete[] especialidades;
    sucursal_asignada = nullptr;
}

// ===== Métodos para Clientes =====
bool Instructor::asignarCliente(Cliente* cliente) {
    if (cantidad_clientes_asignados < capacidad_clientes_asignados) {
        clientes_asignados[cantidad_clientes_asignados++] = cliente;
        return true;
    }
    return false; // No hay espacio
}

bool Instructor::eliminarCliente(Cliente* cliente) {
    for (int i = 0; i < cantidad_clientes_asignados; i++) {
        if (clientes_asignados[i] == cliente) {
            for (int j = i; j < cantidad_clientes_asignados - 1; j++) {
                clientes_asignados[j] = clientes_asignados[j + 1];
            }
            clientes_asignados[cantidad_clientes_asignados - 1] = nullptr;
            cantidad_clientes_asignados--;
            return true;
        }
    }
    return false;
}

string Instructor::listarClientesAsignados() {
    stringstream s;
    if (cantidad_clientes_asignados == 0) {
        s << "No hay clientes asignados." << endl;
    }
    else {
        for (int i = 0; i < cantidad_clientes_asignados; i++) {
            if (clientes_asignados[i] != nullptr) {
                s << clientes_asignados[i]->getCedula();
                s << " - ";
                s << clientes_asignados[i]->getNombre() << endl;
            }
        }
    }
    return s.str();
}

int Instructor::getCantidadClientesAsignados() {
    return cantidad_clientes_asignados;
}

// ===== Métodos para especialidades =====
bool Instructor::agregarEspecialidad(int codigo) {
    // Verificar si ya existe
    for (int i = 0; i < numEspecialidades; i++) {
        if (*especialidades[i] == codigo) {
            return false; // ya la tiene
        }
    }
    // Agregar si hay espacio
    if (numEspecialidades < capacidad_especialidades) {
        especialidades[numEspecialidades++] = new int(codigo);
        return true;
    }
    return false; // no hay espacio
}

bool Instructor::tieneEspecialidad(int codigo) {
    for (int i = 0; i < numEspecialidades; i++) {
        if (*especialidades[i] == codigo) {
            return true;
        }
    }
    return false;
}

string Instructor::listarEspecialidades() {
    stringstream x;
    for (int i = 0; i < numEspecialidades; i++) {
        x << "- " << validarEspecialidad(*especialidades[i]) << "\n";
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
int Instructor::getCapacidad() { return capacidad_especialidades; }


Medicion* Instructor::generarMedicion(Cliente* cliente, const string& fecha, float peso, float estatura, float grasaCorporal, float masaMuscular, int edadMetabolica, float grasaVisceral, float cintura, float cadera, float pecho, float muslo) {
    Medicion* resultado = nullptr;
    if (cliente) {
        Medicion* nueva = new Medicion(fecha, peso, estatura, grasaCorporal, masaMuscular, edadMetabolica, cintura, cadera, pecho, muslo,grasaVisceral, cliente, this);

        if (cliente->agregarMedicion(nueva)) {
            resultado = nueva;
        }
        else {
            delete nueva;
            resultado = nullptr;
        }
    }
    return resultado;
}

Rutina* Instructor::generarRutina(Cliente* cliente) {
    Rutina* resultado = nullptr;
    if (cliente) {
        Rutina* rutinaAnterior = cliente->getRutinaAsignada();

        if (rutinaAnterior) {
            cliente->asignarRutina(nullptr);
            delete rutinaAnterior;
        }

        Rutina* nueva = new Rutina(cliente, this);
        cliente->asignarRutina(nueva);
        resultado = nueva;
    }
    return resultado;
}

// ===== toString =====
string Instructor::toString() {
    stringstream s;
    s << "Instructor: " << nombre << " (" << numeroCed << ")\n";
    s << "Tel: " << telefono << " | Correo: " << correo << "\n";
    s << "Fecha de nacimiento: " << fecha_Nacimiento << "\n";
    s << "Especialidades: \n" << listarEspecialidades();
    s << "Sucursal: " << sucursal_asignada->getProvincia() << " - " << sucursal_asignada->getCanton() << endl;
    return s.str();
}