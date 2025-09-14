#include "Controlador.h"
#include "Interfaz.h"
#include "Sistema.h"
#include "Cliente.h"
#include "Instructor.h"
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
        case 3:
        case 4:
            if (sistema->getCantidadSucursales() > 0) {
                if (opcion == 2) {
                    gestionarClientes();
                }
                else if (opcion == 3) {
                    gestionarInstructores();
                }
                else { // opcion == 4
                    gestionarClasesGrupales();
                }
            }
            else {
                ui->limpiarPantalla();
                ui->imprimir("Primero debe ingresar al menos una sucursal para acceder a este menu.\n");
                ui->esperaEnter();
            }
            break;
        case 0:
            ejecutando = false;
            ui->limpiarPantalla();
            cout << "Gracias por usar el sistema PowerLab" << endl;
            break;
        default:
            ui->imprimir("Opcion invalida.\n");
            ui->esperaEnter();
            break;
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
    ui->imprimir("=== INGRESAR CLIENTE ===\n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nIngresar datos del cliente:\n");
    string nombre = ui->pedirNombreCompleto();
    string cedula = ui->pedirCedula();
    string telefono = ui->pedirTelefono();
    string correo = ui->pedirEmail();
    string fechaNacimiento = ui->pedirFecha();
    string fechaInscripcion = ui->pedirFecha();
    char sexo = ui->pedirSexo();

    Instructor* instructorAsignado = nullptr;

    if (sucursalSeleccionada->getCantidadInstructores() > 0) {
        ui->imprimir("Lista de instructores existentes:\n");
        string listaInstructores = sucursalSeleccionada->listarInstructores();
        ui->imprimir(listaInstructores);
        ui->imprimir("(0) Sin instructor por el momento\n");

        string cedulaInstructor = ui->pedirCedula();

        if (cedulaInstructor != "0") {
            instructorAsignado = sucursalSeleccionada->buscarInstructorPorCedula(cedulaInstructor);
            if (instructorAsignado == nullptr) {
                ui->imprimir("Advertencia: No se encontro un instructor con esa cedula. Se asignara 'Sin instructor'.\n");
            }
        }

    }
    else {
        ui->imprimir("Advertencia: No hay instructores disponibles en esta sucursal. Se asignara 'Sin instructor' por defecto.\n");
    }

    Cliente* nuevoCliente = new Cliente(cedula, nombre, telefono, correo, fechaNacimiento, sexo, fechaInscripcion, sucursalSeleccionada);
    nuevoCliente->asignarInstructor(instructorAsignado);

    if (sucursalSeleccionada->agregarCliente(nuevoCliente)) {
        ui->imprimir("Cliente registrado correctamente!!!!!!!\n");
    }
    else {
        ui->imprimir("Error: El cliente ya existe o la sucursal ha alcanzado su capacidad maxima.\n");
        delete nuevoCliente;
    }

    ui->esperaEnter();
}

void Controlador::asignarInstructorACliente() {
    ui->limpiarPantalla();
    cout << "=== ASIGNAR INSTRUCTOR A CLIENTE ===" << endl;

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);
    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontró una sucursal con ese código.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("Error: No hay clientes registrados en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("Error: No hay instructores en esta sucursal para asignar.\n");
        ui->esperaEnter();
        return;
    }

    string cedulaCliente = ui->pedirTexto("Digite cédula del cliente: ");
    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaCliente);

    if (clienteSeleccionado == nullptr) {
        ui->imprimir("Error: No se encontró un cliente con esa cédula en la sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nLista de instructores disponibles:\n");
    string listaInstructores = sucursalSeleccionada->listarInstructores();
    ui->imprimir(listaInstructores);
    ui->imprimir("(0) Sin instructor por el momento\n");
    string cedulaInstructor = ui->pedirCedula();
    Instructor* instructorAsignado = nullptr;

    if (cedulaInstructor != "0") {
        instructorAsignado = sucursalSeleccionada->buscarInstructorPorCedula(cedulaInstructor);
        if (instructorAsignado == nullptr) {
            ui->imprimir("Advertencia: No se encontró un instructor con esa cédula. No se le asignará un instructor.\n");
        }
    }

    clienteSeleccionado->asignarInstructor(instructorAsignado);
    ui->imprimir("\nInstructor asignado al cliente con éxito.\n");

    ui->esperaEnter();
}

void Controlador::listaClientesPorSucursal() {
    ui->limpiarPantalla();
    cout << "=== LISTA CLIENTES POR SUCURSAL ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }
    else {
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    ui->esperaEnter();
}

void Controlador::detalleCliente() {
    ui->limpiarPantalla();
    cout << "=== DETALLE CLIENTE ===" << endl;

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
    }
    else {
        if (sucursalSeleccionada->getCantidadClientes() > 0) {
            ui->imprimir(sucursalSeleccionada->listarClientes());
            string cedulaBuscar = ui->pedirTexto("Digite la cédula del cliente que quiere visualizar: ");
            Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaBuscar);
            if (clienteSeleccionado != nullptr) {
                ui->imprimir("\n--- Detalle de cliente ---\n");
                ui->imprimir(clienteSeleccionado->toString());
            }
            else {
                ui->imprimir("Error: No existe el cliente con esa cédula.");
            }
        }
        else {
            ui->imprimir("Error: Esta sucursal no tiene clientes para mostrar.\n");
        }
    }

    ui->esperaEnter();
}

// INSTRUCTORES
void Controlador::incluirInstructor() {
    
    ui->limpiarPantalla();
    ui->imprimir("=== INGRESAR INSTRUCTOR ===\n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nIngresar datos del instructor:\n");
    string nombre = ui->pedirNombreCompleto();
    string cedula = ui->pedirCedula();
    string telefono = ui->pedirTelefono();
    string correo = ui->pedirEmail();
    string fechaNacimiento = ui->pedirFecha();
    int especialidades = ui->pedirEspecialidad(); 

    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento, especialidades); 

    if (sucursalSeleccionada->agregarInstructor(nuevoInstructor)) {
        ui->imprimir("Instructor registrado correctamente\n");
    }
    else {
        ui->imprimir("Error: El instructor ya existe o la sucursal ha alcanzado su capacidad maxima.\n");
        delete nuevoInstructor;
    }

    ui->esperaEnter();
}

void Controlador::listaInstructoresPorSucursal() {
    ui->limpiarPantalla();
    cout << "=== LISTA INSTRUCTORES POR SUCURSAL ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }
    else {
        ui->imprimir(sucursalSeleccionada->listarInstructores());
    }
    ui->esperaEnter();
}

void Controlador::detalleInstructor() {
    ui->limpiarPantalla();
    cout << "=== DETALLE INSTRUCTOR ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();

    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
    }
    else {
        if (sucursalSeleccionada->getCantidadInstructores() > 0) {
            ui->imprimir(sucursalSeleccionada->listarInstructores());
            string cedulaBuscar = ui->pedirTexto("Digite la cédula del instructor que quiere visualizar: ");
            Instructor* instructorSeleccionado = sucursalSeleccionada->buscarInstructorPorCedula(cedulaBuscar);
            if (instructorSeleccionado != nullptr) {
                ui->imprimir("\n--- Detalle de cliente ---\n");
                ui->imprimir(instructorSeleccionado->toString());
            }
            else {
                ui->imprimir("Error: No existe el instructor con esa cédula.");
            }
        }
        else {
            ui->imprimir("Error: Esta sucursal no tiene instructores para mostrar.\n");
        }
    }

    ui->esperaEnter();
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