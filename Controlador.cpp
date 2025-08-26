#include "Controlador.h"

Controlador::Controlador() {
    sistema = new Sistema();
    ui = new Interfaz();
    ejecutando = true;
}

Controlador::~Controlador() {
    delete sistema;
    delete ui;
}

void Controlador::ejecutar() {
    while (ejecutando) {
        ui->mostrarMenuPrincipal();
        int opcion = ui->pedirOpcion(0, 4);
        switch (opcion) {
        case 1:
            gestionarSucursales();
            break;
        case 2:
            gestionarClientes();
            break;
        case 3:
            gestionarInstructores();
            break;
        case 4:
            gestionarClasesGrupales();
            break;
        case 0:
            ejecutando = false;
            ui->limpiarPantalla();
            cout << "Gracias por usar el sistema PowerLab" << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    }
}

void Controlador::gestionarSucursales() {
    bool volver = false;
    while (!volver) {
        ui->submenuSucursales();
        int opcion = ui->pedirOpcion(0, 3);

        switch (opcion) {
        case 1:
            ingresarSucursal();
            break;
        case 2:
            mostrarSucursales();
            break;
        case 3:
            reporteIMCPorSucursal();
            break;
        case 0:
            volver = true;
            break;
        }
    }
}

void Controlador::gestionarClientes() {
    bool volver = false;
    while (!volver) {
        ui->submenuClientes();
        int opcion = ui->pedirOpcion(0, 4);

        switch (opcion) {
        case 1:
            incluirCliente();
            break;
        case 2:
            asignarInstructorACliente();
            break;
        case 3:
            listaClientesPorSucursal();
            break;
        case 4:
            detalleCliente();
            break;
        case 0:
            volver = true;
            break;
        }
    }
}

void Controlador::gestionarInstructores() {
    bool volver = false;
    while (!volver) {
        ui->submenuInstructores();
        int opcion = ui->pedirOpcion(0, 10);

        switch (opcion) {
        case 1:
            incluirInstructor();
            break;
        case 2:
            listaInstructoresPorSucursal();
            break;
        case 3:
            detalleInstructor();
            break;
        case 4:
            instructoresPorEspecialidad();
            break;
        case 5:
            clientesPorInstructor();
            break;
        case 6:
            generarMedicionACliente();
            break;
        case 7:
            historialMediciones();
            break;
        case 8:
            ingresarEjercicioBateria();
            break;
        case 9:
            generarRutina();
            break;
        case 10:
            visualizacionRutina();
            break;
        case 0:
            volver = true;
            break;
        }
    }
}

void Controlador::gestionarClasesGrupales() {
    bool volver = false;
    while (!volver) {
        ui->submenuClasesGrupales();
        int opcion = ui->pedirOpcion(0, 4);

        switch (opcion) {
        case 1:
            crearClaseGrupal();
            break;
        case 2:
            mostrarClasesGrupales();
            break;
        case 3:
            matricularClienteEnClaseGrupal();
            break;
        case 4:
            clasesMatriculadasPorCliente();
            break;
        case 0:
            volver = true;
            break;
        }
    }
}

void Controlador::sinImplementar() {
    ui->limpiarPantalla();
    cout << "Funcionalidad sin implementar" << endl;
    ui->esperaEnter();
}

//  SUCURSALES
void Controlador::ingresarSucursal() {
    ui->limpiarPantalla();
    ui->imprimir("=== INGRESAR SUCURSAL ===\n");

    string codigo = ui->pedirCodigoSucursal();
    string provincia = ui->pedirProvincia();
    string canton = ui->pedirCanton();
    string correo = ui->pedirEmail();
    string telefono = ui->pedirTelefono();

    Sucursal* nueva = new Sucursal(codigo, provincia, canton, correo, telefono);

    if (sistema->agregarSucursal(nueva)) {
        ui->imprimir("Sucursal agregada con exito!\n");
    }
    else {
        if (sistema->buscarSucursal(nueva->getCodigo()) != nullptr) {
            ui->imprimir("Error: Ya existe una sucursal con ese codigo.\n");
        }
        else {
            ui->imprimir("Error: Capacidad maxima de sucursales alcanzada.\n");
        }
        delete nueva;
    }
    ui->esperaEnter();
}

void Controlador::mostrarSucursales() {
    ui->limpiarPantalla();
    ui->imprimir(sistema->listarSucursales());
    if (sistema->getCantidadSucursales() > 0) {
        string codigo_buscar = ui->pedirTexto("Digite el código de la sucursal a consultar: ");
        Sucursal* sucursalEncontrada = sistema->buscarSucursal(codigo_buscar);
        if (sucursalEncontrada != nullptr) {
            cout << "--- Detalle de la Sucursal ---" << endl;
            cout << sucursalEncontrada->toString();
        }
        else {
            cout << "Error: No se encontro una sucursal con ese codigo.\n" << endl;
        }
    }

    ui->esperaEnter();
}

void Controlador::reporteIMCPorSucursal() {
    ui->limpiarPantalla();
    cout << "=== REPORTE IMC POR SUCURSAL ===" << endl;
    // TODO
    sinImplementar();
}

// CLIENTES
void Controlador::incluirCliente() {
    ui->limpiarPantalla();
    cout << "=== INCLUIR CLIENTE ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::asignarInstructorACliente() {
    ui->limpiarPantalla();
    cout << "=== ASIGNAR INSTRUCTOR A CLIENTE ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::listaClientesPorSucursal() {
    ui->limpiarPantalla();
    cout << "=== LISTA CLIENTES POR SUCURSAL ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::detalleCliente() {
    ui->limpiarPantalla();
    cout << "=== DETALLE CLIENTE ===" << endl;
    // TODO
    sinImplementar();
}

// INSTRUCTORES
void Controlador::incluirInstructor() {
    ui->limpiarPantalla();
    cout << "=== INCLUIR INSTRUCTOR ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::listaInstructoresPorSucursal() {
    ui->limpiarPantalla();
    cout << "=== LISTA INSTRUCTORES POR SUCURSAL ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::detalleInstructor() {
    ui->limpiarPantalla();
    cout << "=== DETALLE INSTRUCTOR ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::instructoresPorEspecialidad() {
    ui->limpiarPantalla();
    cout << "=== INSTRUCTORES POR ESPECIALIDAD ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::clientesPorInstructor() {
    ui->limpiarPantalla();
    cout << "=== CLIENTES POR INSTRUCTOR ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::generarMedicionACliente() {
    ui->limpiarPantalla();
    cout << "=== GENERAR MEDICIÓN A CLIENTE ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::historialMediciones() {
    ui->limpiarPantalla();
    cout << "=== HISTORIAL DE MEDICIONES ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::ingresarEjercicioBateria() {
    ui->limpiarPantalla();
    cout << "=== INGRESAR EJERCICIO A LA BATERÍA ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::generarRutina() {
    ui->limpiarPantalla();
    cout << "=== GENERAR RUTINA ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::visualizacionRutina() {
    ui->limpiarPantalla();
    cout << "=== VISUALIZACIÓN DE RUTINA ===" << endl;
    // TODO
    sinImplementar();
}

// CLASES GRUPALES
void Controlador::crearClaseGrupal() {
    ui->limpiarPantalla();
    cout << "=== CREAR CLASE GRUPAL ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::mostrarClasesGrupales() {
    ui->limpiarPantalla();
    cout << "=== MOSTRAR CLASES GRUPALES ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::matricularClienteEnClaseGrupal() {
    ui->limpiarPantalla();
    cout << "=== MATRICULAR CLIENTE EN CLASE GRUPAL ===" << endl;
    // TODO
    sinImplementar();
}

void Controlador::clasesMatriculadasPorCliente() {
    ui->limpiarPantalla();
    cout << "=== CLASES MATRICULADAS POR CLIENTE ===" << endl;
    // TODO
    sinImplementar();
}