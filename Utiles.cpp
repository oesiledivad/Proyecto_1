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
			valido = true;
		}
		else {
			cerr << "Valor incorrecto. Digite un numero entero: ";
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
			valido = true;
		} else {
			cerr << "Valor incorrecto. Digite un numero: ";
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

string leerFecha() {
	string fecha;
	bool valido = false;
	while (!valido) {
		imprimeCadena("Fecha (DD/MM/AAAA): ");
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
		especialidad = "";
	}
	return especialidad;
}