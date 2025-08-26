#pragma once
#include "Cliente.h"
#include "Instructor.h"
class Medicion{


private:

    Cliente* cliente;     // quien recibe la medición

    Instructor* instructor;    // quien la realiza

    // Identificadores
    string fecha;              // fecha de la medición (ej. "2025-08-17")

    // Datos corporales básicos
    double peso;               // en kg
    double estatura;           // en metros
    double grasaCorporal;      // en %
    double masaMuscular;       // en %

    // Datos adicionales
    int edadMetabolica;        // en años
    double grasaVisceral;      // en %

    // Medidas corporales
    double cintura;            // en cm
    double cadera;             // en cm
    double pecho;              // en cm
    double muslo;              // en cm



public:
    // Constructor
    Medicion(string,double,double,double,double,int, double, double, double, double, double, Cliente*, Instructor*);

    // Getters
    string getFecha();
    double getPeso();
    double getEstatura();
    double getGrasaCorporal();
    double getMasaMuscular();
    int getEdadMetabolica();
    double getGrasaVisceral();
    double getCintura();
    double getCadera();
    double getPecho();
    double getMuslo();

    Cliente* getCliente();

    Instructor* getInstructor();

    // Método extra
    double calcularIMC();

    string clasificacionIMC();

    string clasificacionPaciente(); 

    double calcularProteina(char, bool); 

    double calcularAgua(); 

    string reporteMedicion();

};

