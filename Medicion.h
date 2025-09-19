#ifndef MEDICION_H
#define MEDICION_H

class Cliente;
class Instructor;

class Medicion {
private:

    Cliente* cliente_asignado;     // quien recibe la medición

    Instructor* instructor_asignado;    // quien la realiza

    // Identificadores
    string fecha;              // fecha de la medición (ej. "2025-08-17")

    // Datos corporales básicos
   float peso;               // en kg
   float estatura;           // en metros
   float grasaCorporal;      // en %
   float masaMuscular;       // en %

    // Datos adicionales
    int edadMetabolica;        // en años
    float grasaVisceral;      // en %

    // Medidas corporales
    float cintura;            // en cm
    float cadera;             // en cm
    float pecho;              // en cm
    float muslo;              // en cm

public:
    // Constructor
    Medicion(string, float, float, float, float, int, float, float, float, float, float, Cliente*, Instructor*);
    ~Medicion();

    // Getters
    string getFecha();
    float getPeso();
    float getEstatura();
    float getGrasaCorporal();
    float getMasaMuscular();
    int getEdadMetabolica();
    float getGrasaVisceral();
    float getCintura();
    float getCadera();
    float getPecho();
    float getMuslo();

    Cliente* getCliente();

    Instructor* getInstructor();

    // Método extra
    float calcularIMC();

    string clasificacionIMC();

    string clasificacionPaciente();

    float calcularProteina();

    float calcularAgua();

    string reporteMedicion();

    string reporteMedicionResumen(); 

    string datosBasicosMedicion(); 

    float getIMC(); 
};
#endif // !MEDICION_H
