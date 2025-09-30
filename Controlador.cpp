#include "Controlador.h"
#include "Interfaz.h"
#include "Sistema.h"
#include "Cliente.h"
#include "ClaseGrupal.h"
#include "Instructor.h"
#include "Medicion.h"
#include "Rutina.h"
#include "Ejercicio.h"

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
                ui->imprimir("\nERROR: Primero debe ingresar al menos una sucursal para acceder a este menu.\n");
                ui->esperaEnter();
            }
            break;
        case 0:
            ejecutando = false;
            ui->despedida();
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

Sucursal* Controlador::seleccionarSucursal() {
    ui->imprimir("Lista de sucursales existentes:\n" + sistema->listarSucursales());
    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursal = sistema->buscarSucursal(codigoSucursal);

    if (!sucursal) {
        ui->imprimir("\nERROR: No se encontró una sucursal con ese código.\n");
    }
    return sucursal;
}

Cliente* Controlador::seleccionarCliente(Sucursal* sucursal) {
    if (sucursal->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: Esta sucursal no tiene clientes.\n");
        return nullptr;
    }
    ui->imprimir(sucursal->listarClientes());
    string cedula = ui->pedirCedula();
    return sucursal->buscarClientePorCedula(cedula);
}

Instructor* Controlador::seleccionarInstructor(Sucursal* sucursal) {
    if (sucursal->getCantidadInstructores() == 0) {
        ui->imprimir("\nERROR: Esta sucursal no tiene instructores.\n");
        return nullptr;
    }
    ui->imprimir(sucursal->listarInstructores());
    string cedula = ui->pedirCedula();
    return sucursal->buscarInstructorPorCedula(cedula);
}

//  SUCURSALES
void Controlador::ingresarSucursal() {
    ui->mostrarTitulo("INGRESAR SUCURSAL");

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
            ui->imprimir("\nERROR: Ya existe una sucursal con ese codigo.\n");
        }
        else {
            ui->imprimir("\nERROR: Capacidad maxima de sucursales alcanzada.\n");
        }
        delete nueva;
    }
    ui->esperaEnter();
}

void Controlador::mostrarSucursales() {
    ui->limpiarPantalla();
    if (sistema->getCantidadSucursales() > 0) {
        Sucursal* sucursalEncontrada = seleccionarSucursal();
        if (sucursalEncontrada) {
            ui->imprimir("\n--- Detalle de la Sucursal ---\n");
            ui->imprimir(sucursalEncontrada->toString());
        }
    }
    else {
        ui->imprimir("Debe de ingresar al menos una sucursal.\n");
    }
    ui->esperaEnter();
}

void Controlador::reporteIMCPorSucursal() {
    ui->mostrarTitulo("REPORTE IMC POR SUCURSAL");

    if (sistema->getCantidadSucursales() == 0) {
        ui->imprimir("Debe de ingresar al menos una sucursal.\n");
        ui->esperaEnter();
        return; 
    }

    Sucursal* sucursalSeleccionada = seleccionarSucursal();

    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: No hay clientes en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->limpiarPantalla();
    ui->imprimir(sucursalSeleccionada->generarReporteIMC());

    ui->esperaEnter();
}

// CLIENTES
void Controlador::incluirCliente() {
    ui->mostrarTitulo("INGRESAR CLIENTE");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
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
        ui->imprimir(sucursalSeleccionada->listarInstructores());
        ui->imprimir("(0) Sin instructor por el momento\n");

        string cedulaInstructor = ui->pedirCedula();
        if (cedulaInstructor != "0") {
            instructorAsignado = sucursalSeleccionada->buscarInstructorPorCedula(cedulaInstructor);
            if (!instructorAsignado) {
                ui->imprimir("\nADVERTENCIA: No se encontró un instructor con esa cédula. Se asignará 'Sin instructor'.\n");
            }
        }
    }
    else {
        ui->imprimir("\nADVERTENCIA: No hay instructores disponibles en esta sucursal. Se asignará 'Sin instructor' por defecto.\n");
    }

    Cliente* nuevoCliente = new Cliente(cedula, nombre, telefono, correo, fechaNacimiento, sexo, fechaInscripcion, sucursalSeleccionada);

    if (sucursalSeleccionada->agregarCliente(nuevoCliente)) {
        nuevoCliente->asignarInstructor(instructorAsignado);
        ui->imprimir("\nCliente registrado correctamente!\n");
    }
    else {
        ui->imprimir("\nERROR: El cliente ya existe o la sucursal alcanzó su capacidad máxima.\n");
        delete nuevoCliente;
    }

    ui->esperaEnter();
}

void Controlador::asignarInstructorACliente() {
    ui->mostrarTitulo("ASIGNAR INSTRUCTOR A CLIENTE");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: No hay clientes registrados en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("\nERROR: No hay instructores para asignar en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    Cliente* cliente = seleccionarCliente(sucursalSeleccionada);
    if (!cliente) {
        ui->imprimir("\nERROR: No se encontró un cliente con esa cédula.\n");
        ui->esperaEnter();
        return;
    }

    Instructor* antiguoInstructor = cliente->getInstructorAsignado();

    ui->imprimir("\nLista de instructores disponibles:\n");
    ui->imprimir(sucursalSeleccionada->listarInstructores());
    ui->imprimir("(0) Sin instructor por el momento\n");

    string cedulaInstructor = ui->pedirCedula();
    Instructor* nuevoInstructor = nullptr;

    if (cedulaInstructor != "0") {
        nuevoInstructor = sucursalSeleccionada->buscarInstructorPorCedula(cedulaInstructor);
        if (!nuevoInstructor) {
            ui->imprimir("\nADVERTENCIA: No se encontró un instructor con esa cédula. No se le asignará un instructor.\n");
        }
    }

    if (antiguoInstructor != nullptr && antiguoInstructor != nuevoInstructor) {
        antiguoInstructor->eliminarCliente(cliente);
        ui->imprimir("El cliente ha sido removido de la lista de su instructor anterior.\n");
    }

    cliente->asignarInstructor(nuevoInstructor);

    ui->imprimir("\nInstructor asignado al cliente con éxito.\n");
    ui->esperaEnter();
}

void Controlador::listaClientesPorSucursal() {
    ui->mostrarTitulo("LISTA DE CLIENTES POR SUCURSAL");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();

    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }
    else {
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    ui->esperaEnter();
}

void Controlador::detalleCliente() {
    ui->mostrarTitulo("DETALLE CLIENTE");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();

    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }
    else {
        if (sucursalSeleccionada->getCantidadClientes() > 0) {
            Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
            if (clienteSeleccionado) {
                ui->imprimir("\n--- Detalle de cliente ---\n");
                ui->imprimir(clienteSeleccionado->toString());
            }
            else {
                ui->imprimir("\nERROR: No existe el cliente con esa cédula.");
            }
        }
        else {
            ui->imprimir("\nERROR: Esta sucursal no tiene clientes para mostrar.\n");
        }
    }
    ui->esperaEnter();
}

// INSTRUCTORES
void Controlador::incluirInstructor() {
    ui->mostrarTitulo("INGRESAR INSTRUCTOR");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nIngresar datos del instructor:\n");
    string nombre = ui->pedirNombreCompleto();
    string cedula = ui->pedirCedula();
    string telefono = ui->pedirTelefono();
    string correo = ui->pedirEmail();
    string fechaNacimiento = ui->pedirFecha("Fecha de nacimiento (DD/MM/AAAA): ");

    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento, sucursalSeleccionada);

    int numEspecialidadesDeseadas = ui->pedirEnteroRango("\nCuantas especialidades tiene el instructor: ", 1, 8);
    ui->imprimir("\nSeleccione las especialidades del instructor:\n");
    ui->imprimir(ui->mostrarEspecialidades());

    int especialidadesAgregadas = 0;
    while (especialidadesAgregadas < numEspecialidadesDeseadas) {
        int codigoEsp = ui->pedirEnteroRango("Digite especialidad #" + to_string(especialidadesAgregadas + 1) + ": ", 1, 8);

        if (nuevoInstructor->agregarEspecialidad(codigoEsp)) {
            especialidadesAgregadas++;
        }
        else {
            ui->imprimir("ADVERTENCIA: No se pudo agregar la especialidad (ya existe o es inválida). Por favor, ingrese una especialidad diferente.\n");
        }
    }

    if (sucursalSeleccionada->agregarInstructor(nuevoInstructor)) {
        ui->imprimir("\nInstructor registrado correctamente!\n");
    }
    else {
        ui->imprimir("\nERROR: El instructor ya existe o la sucursal ha alcanzado su capacidad máxima.\n");
        delete nuevoInstructor;
    }

    ui->esperaEnter();
}

void Controlador::listaInstructoresPorSucursal() {
    ui->mostrarTitulo("LISTA INSTRUCTORES POR SUCURSAL");
    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    ui->imprimir(sucursalSeleccionada->listarInstructores());
    ui->esperaEnter();
}

void Controlador::detalleInstructor() {
    ui->mostrarTitulo("DETALLE INSTRUCTOR");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();

    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }
    else {
        if (sucursalSeleccionada->getCantidadInstructores() > 0) {
            Instructor* instructorSeleccionado = seleccionarInstructor(sucursalSeleccionada);
            if (instructorSeleccionado) {
                ui->imprimir("\n--- Detalle del instructor ---\n");
                ui->imprimir(instructorSeleccionado->toString());
            }
            else {
                ui->imprimir("\nERROR: No existe el instructor con esa cédula.");
            }
        }
        else {
            ui->imprimir("\nERROR: Esta sucursal no tiene instructores para mostrar.\n");
        }
    }

    ui->esperaEnter();
}

void Controlador::instructoresPorEspecialidad() {
    ui->mostrarTitulo("LISTA INSTRUCTORES POR ESPECIALIDAD");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();

    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("\nERROR: No existen instructores en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("Digite la especialidad para conocer los instructores \n");
    int especialidad = ui->pedirEspecialidad();
    ui->imprimir(sucursalSeleccionada->mostrarInstructoresPorEspecialidad(especialidad));

    ui->esperaEnter();
}

void Controlador::clientesPorInstructor() {
    ui->mostrarTitulo("CLIENTES POR INSTRUCTOR");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("\nERROR: No hay instructores en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    Instructor* instructor = seleccionarInstructor(sucursalSeleccionada);
    if (!instructor) {
        ui->imprimir("\nERROR: No se encontró un instructor con esa cédula en la sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\nClientes a cargo del instructor " + instructor->getNombre() + ":\n");
    ui->imprimir(instructor->listarClientesAsignados());

    ui->esperaEnter();
}

void Controlador::generarMedicionACliente() {
    ui->mostrarTitulo("GENERAR MEDICIÓN A CLIENTE");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: Esta sucursal no tiene clientes registrados.\n");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("No se encontró cliente.\n");
        ui->esperaEnter();
        return;
    }

    Instructor* instructorDelCliente = clienteSeleccionado->getInstructorAsignado();
    if (!instructorDelCliente) {
        ui->imprimir("\nERROR: El cliente no tiene instructor asignado.\n");
        ui->esperaEnter();
        return;
    }

    string fecha = ui->pedirFecha("Fecha de medición (DD/MM/AAAA): ");
    float peso = ui->pedirFlotante("Peso (kg): ");
    float estatura = ui->pedirFlotante("Estatura (m): ");
    float grasaCorporal = ui->pedirFlotante("% de grasa: ");
    float masaMuscular = ui->pedirFlotante("% de músculo: ");
    int edadMetabolica = ui->pedirEntero("Edad metabólica: ");
    float grasaVisceral = ui->pedirFlotante("% de grasa visceral: ");
    float cintura = ui->pedirFlotante("Circunferencia de cintura: ");
    float cadera = ui->pedirFlotante("Circunferencia de cadera: ");
    float pecho = ui->pedirFlotante("Circunferencia de pecho: ");
    float muslo = ui->pedirFlotante("Circunferencia de muslo: ");

    Medicion* medicion = instructorDelCliente->generarMedicion(clienteSeleccionado, fecha, peso, estatura, grasaCorporal, masaMuscular, edadMetabolica, grasaVisceral, cintura, cadera, pecho, muslo);

    if (medicion) {
        ui->imprimir("\nMedición registrada correctamente:\n");
        ui->imprimir(medicion->datosBasicosMedicion());
    }
    else {
        ui->imprimir("\nERROR: no se pudo registrar la medición.\n");
    }

    ui->esperaEnter();
}

void Controlador::historialMediciones() {
    ui->mostrarTitulo("HISTORIAL DE MEDICIONES");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: No existen clientes en esta sucursal\n");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("\nERROR: No se encontró un cliente con esa cédula.\n");
        ui->esperaEnter();
        return;
    }

    if (!clienteSeleccionado->getHaceEjercicio()) {
        ui->imprimir("\nERROR: El cliente no tiene mediciones para mostrar.");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Historial de mediciones ---\n");
    ui->imprimir(clienteSeleccionado->mostrarHistorialMediciones());
    int val = clienteSeleccionado->getCantidadMediciones();
    int num = ui->pedirEnteroRango("\nDigite el número de la medición a consultar: ", 1, val);

    ui->imprimir("\n--- Detalle de la medición ---\n");
    ui->imprimir(clienteSeleccionado->mostrarMedicionResumen(num));

    ui->esperaEnter();
}

void Controlador::ingresarEjercicioBateria() {
    bool continuar = true;

    while (continuar) {
        ui->mostrarTitulo("INGRESAR EJERCICIO A LA BATERÍA");

        int zona = ui->pedirZonaMuscular();
        string nombreEjercicio = ui->pedirTexto("Digite el nombre del ejercicio: ");
        string descripcion = ui->pedirTexto("Digite la descripción: ");

        Ejercicio* nuevoEjercicio = new Ejercicio(nombreEjercicio, 0, 0, zona);

        if (sistema->agregarEjercicio(nuevoEjercicio)) {
            ui->imprimir("Ejercicio agregado correctamente a la batería.\n");
        }
        else {
            ui->imprimir("\nERROR: El ejercicio ya existe o se alcanzó la capacidad máxima.\n");
            delete nuevoEjercicio;
        }

        continuar = ui->pedirOpcionSN("¿Desea agregar otro ejercicio? (S/N): ");
    }
    ui->esperaEnter();
}

void Controlador::generarRutina() {
    ui->mostrarTitulo("GENERAR RUTINA");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: Esta sucursal no tiene clientes registrados.\n");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("\nERROR: No se encontró cliente.\n");
        ui->esperaEnter();
        return;
    }

    Instructor* instructorDelCliente = clienteSeleccionado->getInstructorAsignado();
    if (!instructorDelCliente) {
        ui->imprimir("\nERROR: El cliente no tiene instructor asignado.\n");
        ui->esperaEnter();
        return;
    }

    if (clienteSeleccionado->getRutinaAsignada()) {
        ui->imprimir("\nADVERTENCIA: Esto eliminará la rutina actual del cliente y creará una nueva.\n");
        bool continuar = ui->pedirOpcionSN("¿Desea continuar? (S/N): ");
        if (!continuar) {
            return;
        }
    }

    Rutina* rutina = instructorDelCliente->generarRutina(clienteSeleccionado);

    bool continuar = true;
    bool ejerciciosAgregados = false;
    while (continuar) {
        limpiaPantalla();
        ui->mostrarTitulo("GENERANDO RUTINA PARA " + clienteSeleccionado->getNombre());
        int zona = ui->pedirZonaMuscular();
        int totalEjercicios;
        string listaEjercicios = sistema->listarEjercicios(zona, totalEjercicios);
        ui->imprimir(listaEjercicios);

        if (totalEjercicios == 0) {
            ui->imprimir("No hay ejercicios disponibles en esta zona.\n");
            ui->imprimir("Por favor, elija otra zona o ingrese 'N' para salir.\n");
            continuar = ui->pedirOpcionSN("¿Desea agregar otro ejercicio? (S/N): ");
            continue;
        }

        int elegido;
        do {
            elegido = ui->pedirEntero("Número del ejercicio: ");
            if (elegido <= 0) {
                ui->imprimir("ERROR: El número del ejercicio debe ser mayor a cero.\n");
            }
        } while (elegido <= 0);

        int series;
        do {
            series = ui->pedirEntero("Series: ");
            if (series <= 0) {
                ui->imprimir("ERROR: El número de series debe ser mayor a cero.\n");
            }
        } while (series <= 0);

        int repeticiones;
        do {
            repeticiones = ui->pedirEntero("Repeticiones: ");
            if (repeticiones <= 0) {
                ui->imprimir("ERROR: El número de repeticiones debe ser mayor a cero.\n");
            }
        } while (repeticiones <= 0);

        Ejercicio* base = sistema->buscarEjercicioPorZona(zona, elegido);
        if (!base) {
            ui->imprimir("ERROR: Ejercicio no encontrado. Por favor, asegúrese de ingresar un número de la lista.\n");
            ui->imprimir("Vuelva a intentarlo.");
            ui->esperaEnter();
            continue;
        }

        Ejercicio* nuevo = new Ejercicio(base->getNombre(), base->getZona(), series, repeticiones);
        if (rutina->agregarEjercicio(nuevo)) {
            ui->imprimir("Ejercicio agregado a la rutina.\n");
            ejerciciosAgregados = true;
        }
        else {
            ui->imprimir("Error al agregar ejercicio.\n");
            delete nuevo;
        }

        continuar = ui->pedirOpcionSN("¿Desea agregar otro ejercicio? (S/N): ");
    }

    ui->limpiarPantalla();

    if (rutina && rutina->getCantidadEjercicios() == 0) {
        ui->imprimir("\nNo se agregaron ejercicios. La rutina no fue guardada.\n");
        clienteSeleccionado->asignarRutina(nullptr);
        delete rutina;
    }
    else if (ejerciciosAgregados) {
        ui->imprimir("\nRutina generada y asignada exitosamente al cliente: " + clienteSeleccionado->getNombre() + ".\n");
    }

    ui->esperaEnter();
}

void Controlador::visualizacionRutina() {
    ui->mostrarTitulo("VISUALIZACIÓN DE RUTINA");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: esta sucursal no tiene clientes.");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("\nERROR: no se encontró al cliente.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Cliente encontrado ---\n");
    ui->imprimir(clienteSeleccionado->getNombre());

    Rutina* rutina = clienteSeleccionado->getRutinaAsignada();

    if (!rutina) {
        ui->imprimir("\nEl cliente no cuenta con una rutina asignada.\n");

        if (!clienteSeleccionado->getInstructorAsignado()) {
            ui->imprimir("ADVERTENCIA: el cliente tampoco tiene instructor asignado.\n");
        }
    }
    else {
        ui->imprimir("\n--- Rutina asignada ---\n");
        ui->imprimir(rutina->toString());

        if (!clienteSeleccionado->getInstructorAsignado()) {
            ui->imprimir("Nota: el instructor que asignó esta rutina ya no está asociado al cliente.\n");
        }
    }

    ui->esperaEnter();
}

// CLASES GRUPALES
void Controlador::crearClaseGrupal() {
    ui->mostrarTitulo("CREAR CLASE GRUPAL");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadInstructores() == 0) {
        ui->imprimir("\nERROR: No hay instructores en esta sucursal.\n");
        ui->imprimir("Debe ingresar al menos un instructor.\n");
        ui->esperaEnter();
        return;
    }

    int codClase;
    do {
        ui->imprimir("\nTipo de clases disponibles:\n");
        ui->imprimir(ui->mostrarEspecialidades());
        codClase = ui->pedirEnteroRango("Digite código de clase: ", 1, 8);

        if (!sucursalSeleccionada->existenInstructoresConEspecialidad(codClase)) {
            ui->imprimir("\nERROR: No hay instructores con esa especialidad.\n");
            ui->imprimir("Elija otra especialidad.\n");
        }
        else {
            break;
        }
    } while (true);

    string especialidadValidada = validarEspecialidad(codClase);
    ui->imprimir("\nClase " + especialidadValidada + " seleccionada!\n");

    int capacidad = ui->pedirCapacidad();
    string salon = ui->pedirSalon();
    string horario = ui->pedirHorario();

    //ui->imprimir("\nInstructores con especialidad " + especialidadValidada + ":\n");

    Instructor* instructorAsignado = seleccionarInstructor(sucursalSeleccionada);
    if (!instructorAsignado) {
        ui->imprimir("\nERROR: No se encontró al instructor.\n");
        ui->esperaEnter();
        return;
    }

    if (!instructorAsignado->tieneEspecialidad(codClase)) {
        ui->imprimir("\nERROR: El instructor no tiene la especialidad requerida.\n");
        ui->esperaEnter();
        return;
    }

    ClaseGrupal* nuevaClase = new ClaseGrupal(especialidadValidada, salon, horario, instructorAsignado, sucursalSeleccionada, capacidad);

    if (sucursalSeleccionada->agregarClaseGrupal(nuevaClase)) {
        ui->imprimir("Clase grupal registrada correctamente!!!\n");
    }
    else {
        ui->imprimir("\nERROR: La clase grupal ya existe o capacidad máxima alcanzada.\n");
        delete nuevaClase;
    }

    ui->esperaEnter();
}

void Controlador::mostrarClasesGrupales() {
    ui->mostrarTitulo("MOSTRAR CLASES GRUPALES");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClasesGrupales() == 0) {
        ui->imprimir("\nERROR: No existen clases grupales en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir(sucursalSeleccionada->listarClasesGrupales());

    int cantidadClases = sucursalSeleccionada->getCantidadClasesGrupales();
    int posicionClase = ui->pedirEnteroRango("Digite el número de la clase: ", 1, cantidadClases);

    ClaseGrupal* claseSeleccionada = sucursalSeleccionada->buscarClaseGrupalPorPosicion(posicionClase);

    if (claseSeleccionada) {
        ui->imprimir("\n--- Detalle de la clase grupal ---\n");
        ui->imprimir(claseSeleccionada->toString());
    }
    else {
        ui->imprimir("\nERROR: No se encontró la clase en esa posición.\n");
    }

    ui->esperaEnter();
}

void Controlador::matricularClienteEnClaseGrupal() {
    ui->mostrarTitulo("MATRICULAR CLIENTE EN CLASE GRUPAL");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClasesGrupales() == 0) {
        ui->imprimir("\nERROR: No hay clases grupales en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("\nERROR: no se encontró al cliente.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir(sucursalSeleccionada->listarClasesGrupales());

    int cantidadClases = sucursalSeleccionada->getCantidadClasesGrupales();
    int posicionClase = ui->pedirEnteroRango("Digite el número de la clase: ", 1, cantidadClases);

    ClaseGrupal* claseSeleccionada = sucursalSeleccionada->buscarClaseGrupalPorPosicion(posicionClase);

    if (!claseSeleccionada) {
        ui->imprimir("\nERROR: No se encontró la clase.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Detalle de la clase grupal ---\n");
    ui->imprimir(claseSeleccionada->toString());

    if (!clienteSeleccionado->puedeInscribirse()) {
        ui->imprimir("\nERROR: El cliente alcanzó el límite de clases.\n");
        ui->esperaEnter();
        return;
    }

    if (claseSeleccionada->getCupos_Disponibles() == 0) {
        ui->imprimir("\nERROR: La clase tiene cupo completo.\n");
        ui->esperaEnter();
        return;
    }

    if (ui->pedirOpcionSN("¿Desea matricular al cliente? (S/N): ")) {
        if (claseSeleccionada->inscribirCliente(clienteSeleccionado)) {
            ui->imprimir("Cliente matriculado correctamente!\n");
        }
        else {
            ui->imprimir("\nERROR: El cliente ya estaba matriculado.\n");
        }
    }

    ui->esperaEnter();
}

void Controlador::clasesMatriculadasPorCliente() {
    ui->mostrarTitulo("CLASES MATRICULADAS POR CLIENTE");

    Sucursal* sucursalSeleccionada = seleccionarSucursal();
    if (!sucursalSeleccionada) {
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClasesGrupales() == 0) {
        ui->imprimir("\nERROR: No existen clases grupales en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }

    Cliente* clienteSeleccionado = seleccionarCliente(sucursalSeleccionada);
    if (!clienteSeleccionado) {
        ui->imprimir("\nERROR: no se encontró al cliente.");
        ui->esperaEnter();
        return;
    }

    if (clienteSeleccionado->getCantidadClasesInscritas() == 0) {
        ui->imprimir("El cliente no está inscrito en ninguna clase grupal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Cliente: " + clienteSeleccionado->getNombre() + " ---\n");
    ui->imprimir(clienteSeleccionado->mostrarClasesInscritas());
    ui->imprimir("Total de clases matriculadas: " + to_string(clienteSeleccionado->getCantidadClasesInscritas()) + "\n");

    ui->esperaEnter();
}