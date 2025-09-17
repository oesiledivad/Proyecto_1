#include "Controlador.h"
#include "Interfaz.h"
#include "Sistema.h"
#include "Cliente.h"
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
    
    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento, 8);

    // ===== Agregar múltiples especialidades =====

    ui->imprimir ("\n Ingrese una o varias especialidades (digite 0 para finalizar\n"); 

    ui->imprimir("\nSeleccione las especialidades del instructor:\n");

    while (true) {
        int codigoEsp = ui->pedirEspecialidad();

        if (codigoEsp == 0) {
            // Preguntar si realmente quiere terminar
            char opcion;
            cout << "¿Desea terminar la selección de especialidades? (S/N): ";
            cin >> opcion;
            if (opcion == 'S' || opcion == 's') {
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
                ui->imprimir("\n--- Detalle del instructor ---\n");
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
    cout << "=== LISTA INSTRUCTORES POR ESPECIALIDAD ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("Digite la especialidad para conocer los instructores \n");
    int especialidad = ui->pedirEspecialidad();
    sucursalSeleccionada->mostrarInstructoresPorEspecialidad(especialidad);

    ui->esperaEnter();
}

void Controlador::clientesPorInstructor() {
    ui->limpiarPantalla();
    cout << "=== CLIENTES POR INSTRUCTOR ===" << endl;

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

    string cedulaInstructor = ui->pedirTexto("Digite cédula del instructor: ");
    Instructor* instructorConCliente = sucursalSeleccionada->buscarInstructorPorCedula(cedulaInstructor);

    if (instructorConCliente == nullptr) {
        ui->imprimir("Error: No se encontró un instructor con esa cédula en la sucursal.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\Clientes asociados al instructor:\n");
    string listaClientes = sucursalSeleccionada->listarClientes();
    ui->imprimir(listaClientes);

    ui->esperaEnter();
}

void Controlador::generarMedicionACliente() {
    ui->limpiarPantalla();
    cout << "=== GENERAR MEDICION A CLIENTE ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() > 0) {
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    else {
        ui->imprimir("Error: Esta sucursal no tiene clientes para mostrar.\n");
    }

    string cedulaBuscar = ui->pedirTexto("Digite la cédula del cliente que quiere visualizar: ");

    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaBuscar);

        if (clienteSeleccionado != nullptr) {
            ui->imprimir("\n--- Cliente encontrado ---\n");
             ui->imprimir(sucursalSeleccionada->listarClientes());
        }
        else {
            ui->imprimir("Error: No existe el cliente con esa cédula.");
        }

    ui->imprimir("\nGeneracion de Medicion\n");

    ui->imprimir("\nIngresar datos de la Medicion:\n");


    string fecha = ui->pedirFecha();
    float peso = ui->pedirFlotante("\nDigite peso(kg)\n");
    float estatura = ui->pedirFlotante("\nDigite estatura(m)\n");
    float grasaCorporal = ui->pedirFlotante("\nDigite % de grasa\n");
    float masaMuscular = ui->pedirFlotante("\nDigite % de musculo\n");
    int edadMetabolica = ui->pedirEntero("\nDigite la edad metabolica\n");
    float grasaVisceral = ui->pedirFlotante("\nDigite % de grasa visceral\n");
    float cintura = ui->pedirFlotante("\nDigite un valor para cintura\n");
    float cadera = ui->pedirFlotante("\nDigite un valor para cadera\n");
    float pecho = ui->pedirFlotante("\nDigite un valor para pecho\n");
    float muslo = ui->pedirFlotante("\nDigite un valor para muslo\n");

    Medicion* medicion = new Medicion(fecha, peso, estatura, grasaCorporal, masaMuscular, edadMetabolica, grasaVisceral, cintura, cadera, pecho, muslo, clienteSeleccionado); 

    ui->imprimir(medicion->datosBasicosMedicion()); 

    if (clienteSeleccionado->agregarMedicion(medicion)) {
        ui->imprimir("Medicion agregada correctamente\n");
    }
    else {
        ui->imprimir("Error: la medicion ya existe o la sucursal ha alcanzado su capacidad maxima.\n");
        delete medicion;
    }

    ui->esperaEnter(); 

}

void Controlador::historialMediciones() {
    ui->limpiarPantalla();
    cout << "=== HISTORIAL DE MEDICIONES ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() > 0) {
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    else {
        ui->imprimir("Error: Esta sucursal no tiene clientes para mostrar.\n");
    }

    string cedulaBuscar = ui->pedirTexto("Digite la cédula del cliente que quiere visualizar: ");

    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaBuscar);

    if (clienteSeleccionado != nullptr) {
        ui->imprimir("\n--- Cliente encontrado ---\n");
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    else {
        ui->imprimir("Error: No existe el cliente con esa cédula.");
    }

    ui->imprimir("\n Historial de mediciones\n"); 

    ui->imprimir(clienteSeleccionado->mostrarHistorialMediciones());

    int num = ui->pedirEntero("\nDigite el numero de la medicion a consultar\n");

    ui->imprimir("\nDetalle de la medicion\n");

    ui->imprimir(clienteSeleccionado->mostrarMedicionResumen(num));

    ui->esperaEnter();
}

void Controlador::ingresarEjercicioBateria() {
    ui->limpiarPantalla();
    cout << "=== INGRESAR EJERCICIO A LA BATERÍA ===" << endl;

    char opcion = 'S';
    while (opcion == 'S' || opcion == 's') {
        ui->limpiarPantalla();
        cout << "=== NUEVO EJERCICIO ===" << endl;

        int zona = ui->pedirZonaMuscular();

        string nombreEjercicio = ui->pedirTexto("\nDigite el nombre del ejercicio: ");

        string descripcion = ui->pedirTexto("\nDigite la descripcion: ");



        Ejercicio* nuevoEjercicio = new Ejercicio(nombreEjercicio, 0, 0, zona);

        if (sistema->agregarEjercicio(nuevoEjercicio)) {
            ui->imprimir("\n Ejercicio agregado correctamente a la batería.\n");
        }
        else {
            ui->imprimir("\n Error: El ejercicio ya existe o se alcanzó la capacidad máxima.\n");
            delete nuevoEjercicio;
        }

        ui->imprimir("\n¿Desea agregar otro ejercicio? (S/N): ");
        cin >> opcion;
        cin.ignore(); 
        ui->esperaEnter();
    }
    ui->esperaEnter();
}

void Controlador::generarRutina() {
    ui->limpiarPantalla();
    cout << "=== GENERAR RUTINA ===" << endl;

    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontró una sucursal con ese código.\n");
        ui->esperaEnter();
        return;
    }

    string cedulaCliente = ui->pedirTexto("Digite cédula del cliente: ");
    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaCliente);

    if (clienteSeleccionado == nullptr) {
        ui->imprimir("Error: No se encontró un cliente con esa cédula.\n");
        ui->esperaEnter();
        return;
    }

    cout << "\nCliente encontrado: " << clienteSeleccionado->getNombre() << endl;

    cout << "Instructor asignado: " << clienteSeleccionado->getInstructorAsignado()->getNombre() << endl;

    char opcion = 'S';
    while (opcion == 'S' || opcion == 's') {
        int zona = ui->pedirZonaMuscular();

        int total = sistema->listarEjercicios(zona);
        if (total == 0) {
            ui->imprimir("\nNo hay ejercicios en esta zona.\n");
            break;
        }
        int elegido = ui->pedirEntero("\nDigite el ejercicio: ");

        int series = ui->pedirEntero("Digite las series: ");

        int repeticiones = ui->pedirEntero("Digite las repeticiones: ");

        Ejercicio* base = sistema->buscarEjercicioPorZona(zona, elegido);

        if (base == nullptr) {
            ui->imprimir("\nError: No se encontro el ejercicio indicado\n");
        }

        if (base != nullptr) {

            // creamos un nuevo ejercicio para la rutina personal
            Ejercicio* nuevo = new Ejercicio(base->getNombre(), base->getZona(),series, repeticiones);

            Rutina* rutina = clienteSeleccionado->getRutinaAsignada(); 

            if (rutina == nullptr) {
                rutina = new Rutina(clienteSeleccionado, clienteSeleccionado->getInstructorAsignado());
                clienteSeleccionado->asignarRutina(rutina); 
            }
            rutina->agregarEjercicio(nuevo); 

            ui->imprimir("\nEjercicio seleccionado!!!\n");
        }

        ui->imprimir("\n¿Desea agregar otro ejercicio? (S/N): ");
        cin >> opcion;
        cin.ignore();
    }
    ui->esperaEnter();
}

void Controlador::visualizacionRutina() {
    ui->limpiarPantalla();
    cout << "=== VISUALIZACIÓN DE RUTINA ===" << endl;
    string listaSucursales = sistema->listarSucursales();
    ui->imprimir("Lista de sucursales existentes:\n" + listaSucursales);

    string codigoSucursal = ui->pedirCodigoSucursal();
    Sucursal* sucursalSeleccionada = sistema->buscarSucursal(codigoSucursal);

    if (sucursalSeleccionada == nullptr) {
        ui->imprimir("Error: No se encontro una sucursal con ese codigo.\n");
        ui->esperaEnter();
        return;
    }

    if (sucursalSeleccionada->getCantidadClientes() > 0) {
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    else {
        ui->imprimir("Error: Esta sucursal no tiene clientes para mostrar.\n");
    }

    string cedulaBuscar = ui->pedirTexto("Digite la cédula del cliente que quiere visualizar: ");

    Cliente* clienteSeleccionado = sucursalSeleccionada->buscarClientePorCedula(cedulaBuscar);

    if (clienteSeleccionado != nullptr) {
        ui->imprimir("\n--- Cliente encontrado ---\n");
        ui->imprimir(sucursalSeleccionada->listarClientes());
    }
    else {
        ui->imprimir("Error: No existe el cliente con esa cédula.");
    }
    Rutina* rutina = clienteSeleccionado->getRutinaAsignada();

    if (rutina == nullptr) {
        ui->imprimir("El cliente no cuenta con una rutina asignada\n");
    }
    else {
        ui->imprimir(rutina->toString());
    }
    ui->esperaEnter(); 
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