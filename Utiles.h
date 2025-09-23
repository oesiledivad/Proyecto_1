#ifndef UTILES_H
#define UTILES_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void imprimeCadena(string cadena);
void limpiaPantalla();
string leerCadena();
int leerEntero(); // Marcado
void esperandoEnter();

int leerEnteroRango(int min, int max); // Marcado
float leerFlotante(); // Marcado
float leerFlotanteRango(float min, float max); // Marcado
char leerSexo();
string leerEmail();
string leerFecha(const string& mensaje);
string leerCedula(const string& mensaje);            
string leerNumeroTelefono(const string& mensaje);
bool leerOpcionSN(const string& mensaje);


string validarEspecialidad(int codigo);
string validarZonaMuscular(int zona);
int convertirFechaAEntero(const string& fecha);

#endif