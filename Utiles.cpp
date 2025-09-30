#include "Utiles.h"

void imprimeCadena(string cadena) {
	cout << cadena;
}

void limpiaPantalla() {
	system("cls");
}

string leerCadena() {
	string s;
	do {
		getline(cin, s);
	} while (s.find_first_not_of("") == string::npos);
	return s;
}

int leerEntero() {
	int n = 0;
	bool valido = false;
	while (!valido) {
		if (cin >> n) {
			if (n >= 0) {
				valido = true;
			}
			else {
				cerr << "Valor incorrecto. Digite un numero entero positivo o cero: ";
			}
		}
		else {
			cerr << "Valor incorrecto. Digite un numero entero positivo o cero: ";
			cin.clear(); 
		}
		cin.ignore(1024, '\n');
	}
	return n;
}

void esperandoEnter() {
	imprimeCadena("Presione ENTER para continuar...\n");
	cin.ignore(1024, '\n');
}

int leerEnteroRango(int min, int max) {
	int n = 0;
	bool valido = false;
	while (!valido) {
		n = leerEntero();
		if (n >= min && n <= max) {
			valido = true;
		}
		else {
			cerr << "El valor debe estar entre " << min << " y " << max << ". Intente de nuevo: ";
		}
	}
	return n;
}

float leerFlotante() {
	float ff = 0.0f;
	bool valido = false;
	while (!valido) {
		if (cin >> ff) {
			if (ff > 0.0f) {
				valido = true;
			}
			else {
				cerr << "Valor incorrecto. Digite un numero mayor a 0: ";
			}
		}
		else {
			cerr << "Valor incorrecto. Digite un numero mayor a 0: ";
			cin.clear();
		}

		cin.ignore(1024, '\n');
	}
	return ff;
}

float leerFlotanteRango(float min, float max) {
	float ff = 0.0f;
	bool valido = false;
	while (!valido) {
		ff = leerFlotante();
		if (ff >= min && ff <= max) {
			valido = true;
		}
		else {
			cerr << "El valor debe estar entre " << min << " y " << max << ". Intente de nuevo: ";
		}
	}
	return ff;
}

char leerSexo() {
	char sexo = ' ';
	bool valido = false;
	while (!valido) {
		imprimeCadena("Sexo (M/F): ");
		string entrada = leerCadena();
		if (entrada.length() == 1) {
			sexo = entrada[0];
			if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
				if (sexo >= 'a' && sexo <= 'z') {
					sexo = sexo - 'a' + 'A';
				}
				valido = true;
			}
		}
		if (!valido) {
			cerr << "Ingrese 'M' para masculino o 'F' para femenino." << endl;
		}
	}
	return sexo;
}

string leerEmail() {
	string email;
	bool valido = false;
	while (!valido) {
		imprimeCadena("Email: ");
		email = leerCadena();
		bool conArroba = false;
		bool conPunto = false;
		
		for (int i = 0; i < email.length(); i++) {
			if (email[i] == '@') conArroba = true;
			if (email[i] == '.') conPunto = true;
		}
		
		valido = (conArroba && conPunto);
		if (!valido) {
			cerr << "Error: Formato de email no valido." << endl;
		}
	}
	return email;
}

string leerFecha(const string& mensaje) {
	string fecha;
	bool valido = false;
	while (!valido) {
		imprimeCadena(mensaje);
		fecha = leerCadena();
		valido = true;

		if (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/') {
			valido = false;
		}

		if (valido) {
			for (int i = 0; i < 10 && valido; i++) {
				if (i != 2 && i != 5) {
					if (fecha[i] <= '0' && fecha[i] > '9') {
						valido = false;
					}
				}
			}
		}
		else {
			cerr << "Formato de fecha invalido. Por favor use DD/MM/AAAA." << endl;
		}
	}
	return fecha;
}

string leerCedula(const string& mensaje) {
	string cedula;
	bool valido = false;

	while (!valido) {
		imprimeCadena(mensaje);
		cedula = leerCadena();

		valido = true;

		if (cedula.length() > 9 || cedula.empty()) {
			valido = false;
		}

		for (char c : cedula) {
			if (!isdigit(c)) {
				valido = false;
				break;
			}
		}

		if (!valido) {
			cerr << "Cedula invalida. Debe contener solo digitos (max 9).\n";
		}
	}

	return cedula;
}

string leerNumeroTelefono(const string& mensaje) {
	string numero;
	bool valido = false;

	while (!valido) {
		imprimeCadena(mensaje);
		numero = leerCadena();

		valido = true;

		if (numero.length() > 11 || numero.empty()) {
			valido = false;
		}

		for (char c : numero) {
			if (!isdigit(c)) {
				valido = false;
				break;
			}
		}

		if (!valido) {
			cerr << "Numero invalido. Debe contener solo digitos (max 11).\n";
		}
	}

	return numero;
}

bool leerOpcionSN(const string& mensaje) {
	string entrada;
	bool valido = false;
	char opcion;

	while (!valido) {
		imprimeCadena(mensaje);
		entrada = leerCadena();

		if (entrada.length() == 1) {
			opcion = toupper(entrada[0]);
			if (opcion == 'S' || opcion == 'N') {
				valido = true;
			}
		}

		if (!valido) {
			cerr << "Entrada invalida. Solo se acepta 'S' o 'N'.\n";
		}
	}

	return opcion == 'S';
}

string validarEspecialidad(int codigo) {
	string especialidad = "";
	switch (codigo) {
	case 1:
		especialidad = "CrossFit";
		break;
	case 2:
		especialidad = "HIIT";
		break;
	case 3:
		especialidad = "TRX";
		break;
	case 4:
		especialidad = "Pesas";
		break;
	case 5:
		especialidad = "Spinning";
		break;
	case 6:
		especialidad = "Cardio";
		break;
	case 7:
		especialidad = "Yoga";
		break;
	case 8:
		especialidad = "Zumba";
		break;
	default:
		especialidad = "Sin Definir";
	}
	return especialidad;
}

string validarZonaMuscular(int zona) {
	string resultado;
	switch (zona) {
	case 1:
		resultado = "Pecho";
		break;
	case 2:
		resultado = "Tríceps";
		break;
	case 3:
		resultado = "Bíceps";
		break;
	case 4:
		resultado = "Piernas";
		break;
	case 5:
		resultado = "Espalda";
		break;
	default:
		resultado = "Zona desconocida";
	}
	return resultado;
}

int convertirFechaAEntero(const string& fecha) {
	int dia = (fecha[0] - '0') * 10 + (fecha[1] - '0');
	int mes = (fecha[3] - '0') * 10 + (fecha[4] - '0');
	int anio = (fecha[6] - '0') * 1000 + (fecha[7] - '0') * 100 + (fecha[8] - '0') * 10 + (fecha[9] - '0');

	return anio * 10000 + mes * 100 + dia;
}