#include "Interfaz.h"
#include <iostream>
using namespace std;

void Interfaz::mostrarMenuPrincipal() {
    limpiarPantalla();
    cout << "==================================================" << endl;
    cout << "        GESTIÓN DE GIMNASIOS POWERLAB" << endl;
    cout << "==================================================" << endl;
    cout << "(1) Submenú de Sucursales" << endl;
    cout << "(2) Submenú de Clientes" << endl;
    cout << "(3) Submenú de Instructores" << endl;
    cout << "(4) Submenú de Clases Grupales" << endl;
    cout << "(0) Salir" << endl;
    cout << "==================================================" << endl;
}

void Interfaz::submenuSucursales() {
    limpiarPantalla();
    cout << "==================================================" << endl;
    cout << "               SUBMENÚ SUCURSALES" << endl;
    cout << "==================================================" << endl;
    cout << "(1) Ingresar Sucursal" << endl;
    cout << "(2) Mostrar Sucursales" << endl;
    cout << "(3) Reporte de IMC por sucursal" << endl;
    cout << "(0) Regresar Menú Principal" << endl;
    cout << "==================================================" << endl;
}

void Interfaz::submenuClientes() {
    limpiarPantalla();
    cout << "==================================================" << endl;
    cout << "               SUBMENÚ CLIENTES" << endl;
    cout << "==================================================" << endl;
    cout << "(1) Incluir Cliente" << endl;
    cout << "(2) Asignar Instructor a Cliente" << endl;
    cout << "(3) Lista de Clientes por Sucursal" << endl;
    cout << "(4) Detalle de Cliente" << endl;
    cout << "(0) Regresar al Menú Principal" << endl;
    cout << "==================================================" << endl;
}

void Interfaz::submenuInstructores() {
    limpiarPantalla();
    cout << "==================================================" << endl;
    cout << "              SUBMENÚ INSTRUCTORES" << endl;
    cout << "==================================================" << endl;
    cout << "(1) Incluir Instructor" << endl;
    cout << "(2) Lista de Instructores por Sucursal" << endl;
    cout << "(3) Detalle de Instructor" << endl;
    cout << "(4) Instructores por Especialidad" << endl;
    cout << "(5) Clientes por Instructor" << endl;
    cout << "(6) Generar Medición a Cliente" << endl;
    cout << "(7) Historial de Mediciones" << endl;
    cout << "(8) Ingresar Ejercicio a la Batería" << endl;
    cout << "(9) Generar rutina" << endl;
    cout << "(10) Visualización de Rutina" << endl;
    cout << "(0) Regresar al Menú Principal" << endl;
    cout << "==================================================" << endl;
}

void Interfaz::submenuClasesGrupales() {
    limpiarPantalla();
    cout << "==================================================" << endl;
    cout << "            SUBMENÚ CLASES GRUPALES" << endl;
    cout << "==================================================" << endl;
    cout << "(1) Crear Clase Grupal" << endl;
    cout << "(2) Mostrar Clases Grupales" << endl;
    cout << "(3) Matricular Cliente en Clase Grupal" << endl;
    cout << "(4) Clases Matriculadas por Cliente" << endl;
    cout << "(0) Regresar al Menú Principal" << endl;
    cout << "==================================================" << endl;
}

// ENTRADA Y SALIDA DE DATOS

void Interfaz::imprimir(const string& mensaje) {
    imprimeCadena(mensaje);
}

int Interfaz::pedirOpcion(int min, int max) {
    cout << "Digite la opción deseada: ";
    return leerEnteroRango(min, max);
}

string Interfaz::pedirTexto(const string& mensaje) {
    cout << mensaje;
    return leerCadena();
}

int Interfaz::pedirEntero(const string& mensaje) {
    cout << mensaje;
    return leerEntero();
}

int Interfaz::pedirEnteroRango(const string& mensaje, int min, int max) {
    cout << mensaje;
    return leerEnteroRango(min, max);
}

float Interfaz::pedirFlotante(const string& mensaje) {
    cout << mensaje;
    return leerFlotante();
}

float Interfaz::pedirFlotanteRango(const string& mensaje, float min, float max) {
    cout << mensaje;
    return leerFlotanteRango(min, max);
}

char Interfaz::pedirSexo() {
    return leerSexo();
}

string Interfaz::pedirEmail() {
    return leerEmail();
}

string Interfaz::pedirFecha() {
    return leerFecha();
}

void Interfaz::esperaEnter() {
    esperandoEnter();
}

void Interfaz::limpiarPantalla() {
    limpiaPantalla();
}

// AUXILIARES
string Interfaz::pedirCodigoSucursal() {
    return pedirTexto("Digite Código: ");
}

string Interfaz::pedirCedula() {
    return pedirTexto("Digite cédula: ");
}

string Interfaz::pedirProvincia() {
    return pedirTexto("Digite provincia: ");
}

string Interfaz::pedirCanton() {
    return pedirTexto("Digite cantón: ");
}

string Interfaz::pedirTelefono() {
    return pedirTexto("Digite teléfono: ");
}

string Interfaz::pedirNombreCompleto() {
    return pedirTexto("Digite nombre completo: ");
}

int Interfaz::pedirEspecialidad() { 
    cout << "\n=== LISTA DE ESPECIALIDADES ===" << endl;
    cout << "1. CrossFit" << endl;
    cout << "2. HIIT" << endl;
    cout << "3. TRX" << endl;
    cout << "4. Pesas" << endl;
    cout << "5. Spinning" << endl;
    cout << "6. Cardio" << endl;
    cout << "7. Yoga" << endl;
    cout << "8. Zumba" << endl;
    cout << "0. Terminar seleccion" << endl;
    cout << "Seleccione una opcion: ";

    int opcion;
    cin >> opcion;
    return opcion; // el usuario ingresa un número (0..8)
}



int Interfaz::pedirZonaMuscular() { 
    cout << "Zonas musculares disponibles:" << endl;
    cout << "1. Pecho" << endl; 
    cout << "2. Tríceps" << endl; 
    cout << "3. Bíceps" << endl;
    cout << "4. Piernas" << endl; 
    cout << "5. Espalda" << endl; 
    return pedirEnteroRango("Digite zona muscular: ", 1, 5); 
}

string Interfaz::pedirHorario() {
    return pedirTexto("Digite horario: _");
}

string Interfaz::pedirSalon() {
    return pedirTexto("Digite salón: _");
}

int Interfaz::pedirCapacidad() {
    return pedirEntero("Digite capacidad máxima: ");
}

int Interfaz::pedirCantidadEspecialidades() {
    return pedirEntero("Cuantas especialidades tiene el instructor: ");
}

string Interfaz::pedirDescripcionEjercicio() {
    return pedirTexto("Digite la descripción: ");
}