#include "Controlador.h"
#include "Interfaz.h"
#include "Sistema.h"
#include "Cliente.h"
#include "ClaseGrupal.h"
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
            ui->imprimir("Gracias por usar el sistema PowerLab\n");
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
            ui->imprimir("--- Detalle de la Sucursal ---\n");
            ui->imprimir(sucursalEncontrada->toString());
        }
        else {
            ui->imprimir("ERROR: No se encontro una sucursal con ese código.\n");
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
    string fechaNacimiento = ui->pedirFecha("Fecha de nacimiento (DD/MM/AAAA): ");
    string fechaInscripcion = ui->pedirFecha("Fecha de inscripción (DD/MM/AAAA): ");
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
    string fechaNacimiento = ui->pedirFecha("Fecha de nacimiento (DD/MM/AAAA): ");

    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento, 8);

    // ===== Agregar múltiples especialidades =====

    ui->imprimir("\n Ingrese una o varias especialidades (digite 0 para finalizar\n");

    ui->imprimir("\nSeleccione las especialidades del instructor:\n");

    while (true) {
        int codigoEsp = ui->pedirEspecialidad();

        if (codigoEsp == 0) {
            if (ui->pedirOpcionSN("¿Desea terminar la selección de especialidades? (S/N): ")) {
                ui->esperaEnter();
                break;
            }
            else {
                continue;
            }
        }

        if (!nuevoInstructor->agregarEspecialidad(codigoEsp)) {
            ui->imprimir("Advertencia: No se pudo agregar la especialidad (ya existe o no hay espacio).\n");
        }
    }
    // ===== Registrar en sucursal =====
    if (sucursalSeleccionada->agregarInstructor(nuevoInstructor)) {
        ui->imprimir("Instructor registrado correctamente!!!!!!!\n");
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
    ui->imprimir("=== CREAR CLASE GRUPAL ===\n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("Error: No hay instructores en esta sucursal para asignar.\n");
        ui->imprimir("Debe de ingresar al menos un instructor para asignarlo a la clase.\n");
        ui->esperaEnter();
        return;
    }
    int codClase;
    do {
        ui->imprimir("\nTipo de clases disponibles:\n");
        ui->imprimir(ui->mostrarEspecialidades());
        codClase = ui->pedirEnteroRango("Digite código de clase: ", 1, 8);

        if (!sucursalSeleccionada->existenInstructoresConEspecialidad(codClase)) {
            ui->imprimir("\nError: No hay instructores en esta sucursal con la especialidad seleccionada.");
            ui->imprimir("Por favor, elija otra especialidad.\n");
        }
        else {
            break; 
        }
    } while (true);

    string especialidadValidada = validarEspecialidad(codClase);
    ui->imprimir("\nClase " + especialidadValidada + " seleccionada!\n");

    int capacidad_clases = ui->pedirCapacidad();
    string salonClase = ui->pedirSalon();
    string horarioClase = ui->pedirHorario();;
    ui->imprimir("\nLista de instructores con la especialidad " + especialidadValidada + ":\n");
    ui->imprimir(sucursalSeleccionada->mostrarInstructoresPorEspecialidad(codClase));

    string cedInstructor = ui->pedirCedula();
    Instructor* instructorAsignado = sucursalSeleccionada->buscarInstructorPorCedula(cedInstructor);

    if (instructorAsignado != nullptr) {
        if (instructorAsignado->tieneEspecialidad(codClase)) {
            ui->imprimir("\nInstructor seleccionado!\n");
            ClaseGrupal* nuevaClaseGrup = new ClaseGrupal(especialidadValidada, salonClase, horarioClase, instructorAsignado, capacidad_clases);
            if (sucursalSeleccionada->agregarClaseGrupal(nuevaClaseGrup)) {
                ui->imprimir("\nClase grupal registrada correctamente!!!\n");
            }
            else {
                ui->imprimir("\nERROR: La clase grupal ya existe o se ha alcanzado la máxima capacidad.\n");
                delete nuevaClaseGrup;
            }
        }
        else {
            ui->imprimir("\nERROR: El instructor seleccionado no tiene la especialidad requerida para esta clase.\n");
        }
    }
    else {
        ui->imprimir("\nERROR: No se encontró un instructor con esa cédula.\n");
    }
    ui->esperaEnter();
}

void Controlador::mostrarClasesGrupales() {
    ui->limpiarPantalla();
    ui->imprimir("=== MOSTRAR CLASES GRUPALES ===\n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("\nERROR: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClasesGrupales() == 0) {
        ui->imprimir("\nERROR: No existen clases grupales a mostrar en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir(sucursalSeleccionada->listarClasesGrupales());
    int posicionClase = ui->pedirEnteroRango("Digite el numero de la clase: ", 1, sucursalSeleccionada->getCantidadClasesGrupales());

    ClaseGrupal* claseGrupalSeleccionada = sucursalSeleccionada->buscarClaseGrupalPorPosicion(posicionClase);

    if (claseGrupalSeleccionada != nullptr) {
        ui->imprimir("\n--- Detalle de la clase grupal---\n");
        ui->imprimir(claseGrupalSeleccionada->toString());
    }
    else {
        ui->imprimir("\nERROR: No se ha encontrado una clase en esa posición. Intente de nuevo.\n");
    }
    ui->esperaEnter();
}

void Controlador::matricularClienteEnClaseGrupal() {
    ui->limpiarPantalla();
    ui->imprimir("=== MATRICULAR CLIENTE EN CLASE GRUPAL === \n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("\nERROR: no se encontró una sucursal con ese código.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClasesGrupales() == 0) {
        ui->imprimir("\nERROR: no hay clases grupales en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: no existen clientes inscritos en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nClientes de la sucursal:\n");
    ui->imprimir(sucursalSeleccionada->listarClientes());

    string cedulaCliente = ui->pedirCedula();
    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaCliente);
    if (clienteSeleccionado == nullptr) {
        ui->imprimir("\nERROR: no existe un cliente con esa cédula.\n");
        ui->esperaEnter();
        return;
    }

    int auxCantClasesSucursal = sucursalSeleccionada->getCantidadClasesGrupales();
    ui->imprimir(sucursalSeleccionada->listarClasesGrupales());
    int posicionClase = ui->pedirEnteroRango("Digite el numero de la clase: ", 1, auxCantClasesSucursal);

    ClaseGrupal* claseGrupalSeleccionada = sucursalSeleccionada->buscarClaseGrupalPorPosicion(posicionClase);

    if (claseGrupalSeleccionada == nullptr) {
        ui->imprimir("\nERROR: No se ha encontrado una clase con ese código.\n");
    }
    else {
        ui->imprimir("\n--- Detalle de la clase grupal---\n");
        ui->imprimir(claseGrupalSeleccionada->toString());

        if (!clienteSeleccionado->puedeInscribirse()) {
            ui->imprimir("\nERROR: El cliente ya ha alcanzado el límite de clases a las que se puede matricular.\n");
        }
        else if (claseGrupalSeleccionada->getCupos_Disponibles() == 0) {
            ui->imprimir("\nERROR: La clase ha alcanzado su cupo máximo de matriculados.\n");
        }
        else {
            if (ui->pedirOpcionSN("\nDesea matricular al cliente? (S/N): ")) {
                if (claseGrupalSeleccionada->inscribirCliente(clienteSeleccionado)) {
                    ui->imprimir("\nCliente matriculado correctamente!!\n");
                }
                else {
                    ui->imprimir("\nERROR: el cliente ya estaba matriculado en esta clase.\n");
                }
            }
        }
    }
    ui->esperaEnter();
}

void Controlador::clasesMatriculadasPorCliente() {
    ui->limpiarPantalla();
    ui->imprimir("=== CLASES MATRICULADAS POR CLIENTE ===\n");

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    int auxCantClasesSucursal = sucursalSeleccionada->getCantidadClasesGrupales();

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("\nERROR: no existe una sucursal con ese código.");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: no existen clientes en esta sucursal.");
        ui->esperaEnter();
        return;
    }

    if (auxCantClasesSucursal == 0) {
        ui->imprimir("\nERROR: no existen clases grupales en esta sucursal.");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nClientes de la sucursal:\n");
    ui->imprimir(sucursalSeleccionada->listarClientes());
    string cedulaCliente = ui->pedirCedula();
    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaCliente);
    if (clienteSeleccionado == nullptr) {
        ui->imprimir("\nERROR: no existe un cliente con esa cédula.\n");
        ui->esperaEnter();
        return;
    }
    if (clienteSeleccionado->getCantidadClasesInscritas() == 0) {
        ui->imprimir("\nEl cliente no está inscrito a alguna clase grupal.");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nCliente encontrado: \n");
    ui->imprimir(clienteSeleccionado->getCedula() + " " + clienteSeleccionado->getNombre() + "\n");

    ui->imprimir(clienteSeleccionado->mostrarClasesInscritas());
    ui->imprimir("Total de clases matriculadas " + to_string(clienteSeleccionado->getCantidadClasesInscritas()) + "\n");

    ui->esperaEnter();
}