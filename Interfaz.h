#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Utiles.h"
using namespace std;

class Interfaz {
public:
    // MENUS
    void mostrarMenuPrincipal();
    void submenuSucursales();
    void submenuClientes();
    void submenuInstructores();
    void submenuClasesGrupales();

    // ENTRADA DE DATOS
    int pedirOpcion(int min, int max);
    string pedirTexto(const string& mensaje);
    int pedirEntero(const string& mensaje);
    int pedirEnteroRango(const string& mensaje, int min, int max);
    float pedirFlotante(const string& mensaje);
    float pedirFlotanteRango(const string& mensaje, float min, float max);
    char pedirSexo();
    string pedirEmail();
    string pedirFecha(const string& mensaje);
    bool pedirOpcionSN(const string& mensaje);
    void esperaEnter();
    void limpiarPantalla();
    void imprimir(const string& mensaje);

    // AUXILIARES
    string pedirCodigoSucursal();
    string pedirCedula();
    string pedirProvincia();
    string pedirCanton();
    string pedirTelefono();
    string pedirNombreCompleto();
    int pedirEspecialidad();
    int pedirZonaMuscular();
    string pedirHorario();
    string pedirSalon();
    int pedirCapacidad();
    int pedirCantidadEspecialidades();
    string pedirDescripcionEjercicio();

    string mostrarEspecialidades();
};

#endif