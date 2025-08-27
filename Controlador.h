#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Interfaz;
class Sistema;

class Controlador {
private:
    Sistema* sistema;
    Interfaz* ui;
    bool ejecutando;

public:
    Controlador();
    ~Controlador();

    void ejecutar();

    // Menús
    void gestionarSucursales();
    void gestionarClientes();
    void gestionarInstructores();
    void gestionarClasesGrupales();

    // Sucursales
    void ingresarSucursal();
    void mostrarSucursales();
    void reporteIMCPorSucursal();

    // Clientes
    void incluirCliente();
    void asignarInstructorACliente();
    void listaClientesPorSucursal();
    void detalleCliente();

    // Instructores
    void incluirInstructor();
    void listaInstructoresPorSucursal();
    void detalleInstructor();
    void instructoresPorEspecialidad();
    void clientesPorInstructor();
    void generarMedicionACliente();
    void historialMediciones();
    void ingresarEjercicioBateria();
    void generarRutina();
    void visualizacionRutina();

    // Clases grupales
    void crearClaseGrupal();
    void mostrarClasesGrupales();
    void matricularClienteEnClaseGrupal();
    void clasesMatriculadasPorCliente();

    // Auxiliar
    void sinImplementar();
};

#endif