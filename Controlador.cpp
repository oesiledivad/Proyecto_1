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
        int opcion = ui->pedirOpcion(0, 5);

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
        case 5:
            ui->limpiarPantalla();
            rellenarDatosPrueba();
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

void Controlador::rellenarDatosPrueba() {
    ui->mostrarTitulo("LLENANDO DATOS DE PRUEBA");

    Sucursal* sucursal1 = new Sucursal("SJ01", "San José", "Aserrí", "sanjose.01@powerlab.com", "2222-2222");
    Sucursal* sucursal2 = new Sucursal("HE01", "Heredia", "Heredia", "heredia.01@powerlab.com", "2442-2222");

    sistema->agregarSucursal(sucursal1);
    sistema->agregarSucursal(sucursal2);

    ui->imprimir("Sucursales creadas\n");

    Instructor* instructor1 = new Instructor("101110111", "Juan Pérez", "8888-8888", "juan@powerlab.com", "15/05/1985", 8, sucursal1);
    instructor1->agregarEspecialidad(1); // CrossFit
    instructor1->agregarEspecialidad(7); // Yoga

    Instructor* instructor2 = new Instructor("202220222", "María López", "8777-7777", "maria@powerlab.com", "20/08/1990", 8, sucursal1);
    instructor2->agregarEspecialidad(2); // HIIT
    instructor2->agregarEspecialidad(8); // Zumba

    Instructor* instructor3 = new Instructor("303330333", "Carlos Rojas", "8666-6666", "carlos@powerlab.com", "10/12/1988", 8, sucursal1);
    instructor3->agregarEspecialidad(5); // Spinning
    instructor3->agregarEspecialidad(6); // Cardio

    Instructor* instructor4 = new Instructor("404440444", "Lucía García", "8555-5555", "lucia@powerlab.com", "22/02/1982", 8, sucursal2);
    instructor4->agregarEspecialidad(3); // TRX
    instructor4->agregarEspecialidad(4); // Pesas

    Instructor* instructor5 = new Instructor("505550555", "Roberto Martínez", "8444-4444", "roberto@powerlab.com", "03/07/1987", 8, sucursal2);
    instructor5->agregarEspecialidad(1); // CrossFit
    instructor5->agregarEspecialidad(3); // TRX

    Instructor* instructor6 = new Instructor("606660666", "Ana Torres", "8333-3333", "ana2@powerlab.com", "11/09/1992", 8, sucursal2);
    instructor6->agregarEspecialidad(2); // HIIT
    instructor6->agregarEspecialidad(8); // Zumba

    sucursal1->agregarInstructor(instructor1);
    sucursal1->agregarInstructor(instructor2);
    sucursal1->agregarInstructor(instructor3);
    sucursal2->agregarInstructor(instructor4);
    sucursal2->agregarInstructor(instructor5);
    sucursal2->agregarInstructor(instructor6);

    ui->imprimir("Instructores creados\n");

    Cliente* cliente1 = new Cliente("111111111", "Ana Mendoza", "8111-1111", "ana@email.com", "05/03/1990", 'F', "01/01/2024", sucursal1);
    Cliente* cliente2 = new Cliente("222222222", "Luis Chaves", "8222-2222", "luis@email.com", "12/07/1985", 'M', "15/01/2024", sucursal1);
    Cliente* cliente3 = new Cliente("333333333", "Sofía Vega", "8333-3333", "sofia@email.com", "25/11/1995", 'F', "20/01/2024", sucursal2);
    Cliente* cliente4 = new Cliente("444444444", "Carlos Jiménez", "8444-4444", "carlos2@email.com", "18/02/1992", 'M', "05/03/2024", sucursal1);
    Cliente* cliente5 = new Cliente("555555555", "María Pérez", "8555-5555", "maria2@email.com", "07/09/1987", 'F', "10/02/2024", sucursal1);
    Cliente* cliente6 = new Cliente("666666666", "José González", "8666-6666", "jose@email.com", "15/01/1994", 'M', "20/03/2024", sucursal2);

    // --- NUEVOS CLIENTES PARA PRUEBAS ADICIONALES ---
    Cliente* cliente7 = new Cliente("777777777", "Prueba Capacidad", "8777-7777", "capacidad@email.com", "01/01/2000", 'M', "01/04/2024", sucursal1);
    Cliente* cliente8 = new Cliente("888888888", "Prueba Clases", "8888-8888", "clases@email.com", "01/01/2000", 'F', "01/04/2024", sucursal1);

    // Cliente para probar matriculación en otra sucursal
    Cliente* cliente9_otraSucursal = new Cliente("999999999", "Marta Soto", "8999-9999", "marta@email.com", "01/01/1995", 'F', "01/05/2024", sucursal2);

    cliente1->asignarInstructor(instructor1);
    cliente2->asignarInstructor(instructor2);
    cliente3->asignarInstructor(instructor3);
    cliente4->asignarInstructor(instructor1);
    cliente5->asignarInstructor(instructor2);
    cliente6->asignarInstructor(instructor4);
    cliente7->asignarInstructor(instructor1);
    cliente8->asignarInstructor(instructor2);
    cliente9_otraSucursal->asignarInstructor(instructor4);

    sucursal1->agregarCliente(cliente1);
    sucursal1->agregarCliente(cliente2);
    sucursal1->agregarCliente(cliente4);
    sucursal1->agregarCliente(cliente5);
    sucursal2->agregarCliente(cliente3);
    sucursal2->agregarCliente(cliente6);
    sucursal1->agregarCliente(cliente7);
    sucursal1->agregarCliente(cliente8);
    sucursal2->agregarCliente(cliente9_otraSucursal);

    ui->imprimir("Clientes creados\n");

    Medicion* med1 = new Medicion("01/02/2024", 65.0f, 1.75f, 0, 0, 0, 0, 0, 0, 0, 0, cliente1, instructor1);
    Medicion* med2 = new Medicion("15/02/2024", 50.0f, 1.75f, 0, 0, 0, 0, 0, 0, 0, 0, cliente2, instructor2);
    Medicion* med3 = new Medicion("20/02/2024", 80.0f, 1.75f, 0, 0, 0, 0, 0, 0, 0, 0, cliente3, instructor3);
    Medicion* med4 = new Medicion("01/03/2024", 70.0f, 1.80f, 0, 0, 0, 0, 0, 0, 0, 0, cliente4, instructor4);
    Medicion* med5 = new Medicion("20/03/2024", 140.0f, 1.70f, 0, 0, 0, 0, 0, 0, 0, 0, cliente6, instructor5);

    cliente1->agregarMedicion(med1);
    cliente2->agregarMedicion(med2);
    cliente3->agregarMedicion(med3);
    cliente4->agregarMedicion(med4);
    cliente6->agregarMedicion(med5);

    ui->imprimir("Mediciones creadas\n");

    ui->imprimir("\n--- Probando la reasignación de instructor ---\n");
    ui->imprimir("Cliente Ana Mendoza está asignada a Juan Pérez.\n");
    ui->imprimir("Reasignando Ana Mendoza a Carlos Rojas...\n");
    cliente1->asignarInstructor(instructor3);
    ui->imprimir("Verificando... Carlos Rojas ahora tiene " + to_string(instructor3->getCantidadClientesAsignados()) + " clientes.\n");
    ui->imprimir("Verificando... Juan Pérez ahora tiene " + to_string(instructor1->getCantidadClientesAsignados()) + " clientes.\n");
    ui->imprimir("Asignación y reasignación de instructores probada\n");

    Ejercicio* ej1 = new Ejercicio("Flexiones de pecho", 1, 3, 12);
    Ejercicio* ej2 = new Ejercicio("Sentadillas", 2, 4, 15);
    Ejercicio* ej3 = new Ejercicio("Curl de bíceps", 3, 3, 10);
    Ejercicio* ej4 = new Ejercicio("Dominadas", 1, 4, 8);
    Ejercicio* ej5 = new Ejercicio("Prensa de pierna", 2, 4, 12);

    sistema->agregarEjercicio(ej1);
    sistema->agregarEjercicio(ej2);
    sistema->agregarEjercicio(ej3);
    sistema->agregarEjercicio(ej4);
    sistema->agregarEjercicio(ej5);

    ui->imprimir("Ejercicios creados\n");

    Rutina* rutina1 = new Rutina(cliente1, instructor3);
    rutina1->agregarEjercicio(new Ejercicio("Flexiones de pecho", 1, 3, 12));
    rutina1->agregarEjercicio(new Ejercicio("Sentadillas", 2, 4, 15));
    cliente1->asignarRutina(rutina1);

    Rutina* rutina2 = new Rutina(cliente2, instructor2);
    rutina2->agregarEjercicio(new Ejercicio("Curl de bíceps", 3, 3, 10));
    rutina2->agregarEjercicio(new Ejercicio("Prensa de pierna", 2, 4, 12));
    cliente2->asignarRutina(rutina2);

    ui->imprimir("Rutinas creadas\n");

    // --- CLASES GRUPALES ---

    ClaseGrupal* clase1 = new ClaseGrupal("Yoga", "Salón A", "Lunes 9:00 AM", instructor1, sucursal1, 15);
    ClaseGrupal* clase2 = new ClaseGrupal("Pilates", "Salón B", "Martes 10:00 AM", instructor2, sucursal1, 12);
    ClaseGrupal* clase3 = new ClaseGrupal("CrossFit", "Salón C", "Miércoles 5:00 PM", instructor3, sucursal1, 10);
    ClaseGrupal* clase4 = new ClaseGrupal("Zumba", "Salón D", "Jueves 7:00 PM", instructor6, sucursal2, 10);

    // NUEVO: Clase con solo 2 cupos para probar capacidad
    ClaseGrupal* clase_llena = new ClaseGrupal("TRX", "Salón G", "Martes 5:00 PM", instructor5, sucursal2, 2);

    sucursal1->agregarClaseGrupal(clase1);
    sucursal1->agregarClaseGrupal(clase2);
    sucursal1->agregarClaseGrupal(clase3);
    sucursal2->agregarClaseGrupal(clase4);
    sucursal2->agregarClaseGrupal(clase_llena);

    ui->imprimir("Clases grupales creadas\n");

    // --- MATRICULACIONES DE PRUEBA ---
    ui->imprimir("\n--- Probando matriculaciones ---\n");
    ui->imprimir("\n--- Prueba de matriculación entre sucursales ---\n");
    // Cliente de SJ01 (cliente1) intenta matricularse en clase de HE01 (clase4)
    ui->imprimir("Intentando matricular a " + cliente1->getNombre() + " (San José) en la clase de Zumba (Heredia)...\n");
    if (clase4->inscribirCliente(cliente1)) {
        ui->imprimir("Error: El cliente se matriculó en una sucursal diferente.\n");
    }
    else {
        ui->imprimir("**Cliente " + cliente1->getNombre() + " NO pudo matricularse. (Correcto)\n");
    }

    // Cliente de HE01 (cliente9_otraSucursal) intenta matricularse en clase de SJ01 (clase1)
    ui->imprimir("Intentando matricular a " + cliente9_otraSucursal->getNombre() + " (Heredia) en la clase de Yoga (San José)...\n");
    if (clase1->inscribirCliente(cliente9_otraSucursal)) {
        ui->imprimir("Error: El cliente se matriculó en una sucursal diferente.\n");
    }
    else {
        ui->imprimir("**Cliente " + cliente9_otraSucursal->getNombre() + " NO pudo matricularse. (Correcto)\n");
    }

    ui->imprimir("\n--- Prueba de capacidad de clase ---\n");
    // Inscribiendo clientes en la clase de 2 cupos
    clase_llena->inscribirCliente(cliente1);
    ui->imprimir("Cliente " + cliente1->getNombre() + " se matriculó en " + clase_llena->getCodigo() + "\n");
    clase_llena->inscribirCliente(cliente2);
    ui->imprimir("Cliente " + cliente2->getNombre() + " se matriculó en " + clase_llena->getCodigo() + "\n");

    // Intentando inscribir a un tercer cliente en la clase llena
    ui->imprimir("Intentando matricular al cliente " + cliente7->getNombre() + " en la clase llena...\n");
    if (clase_llena->inscribirCliente(cliente7)) {
        ui->imprimir("Error: Cliente " + cliente7->getNombre() + " se matriculó en clase llena.\n");
    }
    else {
        ui->imprimir("**" + cliente7->getNombre() + " NO pudo matricularse, la clase está llena. (Correcto)\n");
    }

    ui->imprimir("\n--- Prueba de límite de clases por cliente ---\n");
    // Matricular a un cliente en 3 clases
    clase1->inscribirCliente(cliente8);
    ui->imprimir("Cliente " + cliente8->getNombre() + " matriculado en " + clase1->getCodigo() + "\n");
    clase2->inscribirCliente(cliente8);
    ui->imprimir("Cliente " + cliente8->getNombre() + " matriculado en " + clase2->getCodigo() + "\n");
    clase3->inscribirCliente(cliente8);
    ui->imprimir("Cliente " + cliente8->getNombre() + " matriculado en " + clase3->getCodigo() + "\n");

    // Intentando matricular al cliente en una cuarta clase
    ui->imprimir("Intentando matricular a " + cliente8->getNombre() + " en una cuarta clase...\n");
    if (clase4->inscribirCliente(cliente8)) {
        ui->imprimir("Error: Cliente " + cliente8->getNombre() + " se matriculó en más de 3 clases.\n");
    }
    else {
        ui->imprimir("**" + cliente8->getNombre() + " NO pudo matricularse, ya alcanzó el límite de 3 clases. (Correcto)\n");
    }

    ui->imprimir("\nPruebas de capacidad y límite de clases completadas.\n");

    ui->imprimir("\nDATOS DE PRUEBA CARGADOS EXITOSAMENTE!\n");
    ui->imprimir("* 2 Sucursales\n");
    ui->imprimir("* 6 Instructores\n");
    ui->imprimir("* 9 Clientes\n");
    ui->imprimir("* 5 Mediciones\n");
    ui->imprimir("* 5 Ejercicios\n");
    ui->imprimir("* 2 Rutinas\n");
    ui->imprimir("* 5 Clases grupales\n");

    ui->esperaEnter();
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

    Sucursal* sucursal = seleccionarSucursal();

    if (!sucursal) {
        ui->esperaEnter();
        return;
    }

    if (sucursal->getCantidadClientes() == 0) {
        ui->imprimir("\nERROR: No hay clientes en esta sucursal.\n");
        ui->esperaEnter();
        return;
    }
    ui->limpiarPantalla();
    ui->imprimir(sucursal->generarReporteIMC());

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
                ui->imprimir("\nAdvertencia: No se encontró un instructor con esa cédula. Se asignará 'Sin instructor'.\n");
            }
        }
    }
    else {
        ui->imprimir("\nAdvertencia: No hay instructores disponibles en esta sucursal. Se asignará 'Sin instructor' por defecto.\n");
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
        ui->imprimir("ERROR: No hay clientes registrados en esta sucursal.\n");
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
            ui->imprimir("\nAdvertencia: No se encontró un instructor con esa cédula. No se le asignará un instructor.\n");
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

    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento, 8, sucursalSeleccionada);

    ui->imprimir("\nSeleccione las especialidades del instructor (digite 0 para finalizar):\n");
    ui->imprimir(ui->mostrarEspecialidades());
    bool terminar = false;

    while (!terminar) {
        int codigoEsp = ui->pedirEnteroRango("Digite la especialidad deseada: ", 0, 8);

        if (codigoEsp == 0) {
            if (ui->pedirOpcionSN("¿Desea terminar la selección de especialidades? (S/N): ")) {
                terminar = true;
            }
            continue;
        }

        if (!nuevoInstructor->agregarEspecialidad(codigoEsp)) {
            ui->imprimir("Advertencia: No se pudo agregar la especialidad (ya existe o no hay espacio).\n");
        }
    }

    if (sucursalSeleccionada->agregarInstructor(nuevoInstructor)) {
        ui->imprimir("Instructor registrado correctamente!\n");
    }
    else {
        ui->imprimir("Error: El instructor ya existe o la sucursal ha alcanzado su capacidad máxima.\n");
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
        ui->imprimir("ERROR: El cliente no tiene instructor asignado.\n");
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

    int num = ui->pedirEntero("\nDigite el número de la medición a consultar: ");

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

    Rutina* rutina = instructorDelCliente->generarRutina(clienteSeleccionado);

    bool continuar = true;

    while (continuar) {
        limpiaPantalla();
        ui->mostrarTitulo("GENERANDO RUTINA");
        int zona = ui->pedirZonaMuscular();
        int total = sistema->listarEjercicios(zona);
        if (total == 0) {
            ui->imprimir("No hay ejercicios en esta zona.\n");
            break;
        }

        int elegido = ui->pedirEntero("Número del ejercicio: ");
        int series = ui->pedirEntero("Series: ");
        int repeticiones = ui->pedirEntero("Repeticiones: ");

        Ejercicio* base = sistema->buscarEjercicioPorZona(zona, elegido);
        if (!base) { 
            ui->imprimir("Ejercicio no encontrado.\n"); 
            continue; 
        }

        Ejercicio* nuevo = new Ejercicio(base->getNombre(), base->getZona(), series, repeticiones);
        if (rutina->agregarEjercicio(nuevo)) {
            ui->imprimir("Ejercicio agregado a la rutina.\n");
        }
        else {
            ui->imprimir("Error al agregar ejercicio.\n");
            delete nuevo;
        }

        continuar = ui->pedirOpcionSN("¿Desea agregar otro ejercicio? (S/N): ");
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

    if (!clienteSeleccionado->getInstructorAsignado()) {
        ui->imprimir("\nERROR: el cliente no tiene instructor asignado.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Cliente encontrado ---\n");
    ui->imprimir(clienteSeleccionado->getNombre());

    Rutina* rutina = clienteSeleccionado->getRutinaAsignada();
    if (!rutina) {
        ui->imprimir("\nEl cliente no cuenta con una rutina asignada\n");
    }
    else {
        ui->imprimir("\n--- Rutina asignada ---\n");
        ui->imprimir(rutina->toString());
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
        ui->imprimir("Error: No hay instructores en esta sucursal.\n");
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
            ui->imprimir("Error: No hay instructores con esa especialidad.\n");
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

    ui->imprimir("\nInstructores con especialidad " + especialidadValidada + ":\n");

    Instructor* instructorAsignado = seleccionarInstructor(sucursalSeleccionada);
    if (!instructorAsignado) {
        ui->esperaEnter();
        return;
    }

    if (!instructorAsignado->tieneEspecialidad(codClase)) {
        ui->imprimir("ERROR: El instructor no tiene la especialidad requerida.\n");
        ui->esperaEnter();
        return;
    }

    ClaseGrupal* nuevaClase = new ClaseGrupal(especialidadValidada, salon, horario, instructorAsignado, sucursalSeleccionada, capacidad);

    if (sucursalSeleccionada->agregarClaseGrupal(nuevaClase)) {
        ui->imprimir("Clase grupal registrada correctamente!!!\n");
    }
    else {
        ui->imprimir("ERROR: La clase grupal ya existe o capacidad máxima alcanzada.\n");
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
        ui->imprimir("ERROR: No existen clases grupales en esta sucursal.\n");
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
        ui->imprimir("ERROR: No se encontró la clase en esa posición.\n");
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
        ui->imprimir("ERROR: No hay clases grupales en esta sucursal.\n");
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
        ui->imprimir("ERROR: No se encontró la clase.\n");
        ui->esperaEnter();
        return;
    }

    ui->imprimir("\n--- Detalle de la clase grupal ---\n");
    ui->imprimir(claseSeleccionada->toString());

    if (!clienteSeleccionado->puedeInscribirse()) {
        ui->imprimir("ERROR: El cliente alcanzó el límite de clases.\n");
        ui->esperaEnter();
        return;
    }

    if (claseSeleccionada->getCupos_Disponibles() == 0) {
        ui->imprimir("ERROR: La clase tiene cupo completo.\n");
        ui->esperaEnter();
        return;
    }

    if (ui->pedirOpcionSN("¿Desea matricular al cliente? (S/N): ")) {
        if (claseSeleccionada->inscribirCliente(clienteSeleccionado)) {
            ui->imprimir("Cliente matriculado correctamente!\n");
        }
        else {
            ui->imprimir("ERROR: El cliente ya estaba matriculado.\n");
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
        ui->imprimir("ERROR: No existen clases grupales en esta sucursal.\n");
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