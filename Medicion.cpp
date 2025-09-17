#include "Utiles.h"
#include "Medicion.h"
#include "Cliente.h"
#include "Instructor.h"

Medicion::Medicion(string fecha, float peso, float estatura, float grasaCorp, float musculo, int metabolica, float cintura,
    float cadera, float pecho, float muslo, float grasaVis, Cliente* i) :

    fecha(fecha), peso(peso), estatura(estatura), grasaCorporal(grasaCorp), masaMuscular(musculo), edadMetabolica(metabolica),
    cintura(cintura), cadera(cadera), pecho(pecho), muslo(muslo), grasaVisceral(grasaVis), cliente(i)
{}

string Medicion::getFecha()
{
    return string();
}

float Medicion::getPeso()
{
    return peso;
}

float Medicion::getEstatura()
{
    return estatura;
}

float Medicion::getGrasaCorporal()
{
    return grasaCorporal;
}

float Medicion::getMasaMuscular()
{
    return masaMuscular;
}

int Medicion::getEdadMetabolica()
{
    return edadMetabolica;
}

float Medicion::getGrasaVisceral()
{
    return grasaVisceral;
}

float Medicion::getCintura()
{
    return cintura;
}

float Medicion::getCadera()
{
    return 0.0;
}

float Medicion::getPecho()
{
    return pecho;
}

float Medicion::getMuslo()
{
    return muslo;
}

Cliente* Medicion::getCliente()
{
    return nullptr;
}

Instructor* Medicion::getInstructor()
{
    return nullptr;
}

float Medicion::calcularIMC() {

    return peso / (estatura * estatura); 
}

string Medicion::clasificacionIMC() {

    if (calcularIMC() < 16.00) {
        return "Delgadez severa"; 
    }
    else if (calcularIMC() >= 16.01 && calcularIMC() <= 16.99){
        return "Delgadez moderada"; 
    }

    else if (calcularIMC() >= 17.00 && calcularIMC() <= 18.49) {
        return "Delgadez leve";
    }

    else if (calcularIMC() >= 18.5 && calcularIMC() <= 24.99) {
        return "Normal";
    }

    else if (calcularIMC() >= 25.00 && calcularIMC() <= 29.99) {
        return "Pre-Obesidad";
    }

    else if (calcularIMC() >= 30.00 && calcularIMC() <= 34.99) {
        return "Obesidad leve";
    }

    else if (calcularIMC() >= 35.00 && calcularIMC() <= 39.99) {
        return "Obesidad media";
    }

    else if (calcularIMC() >= 40.00) {
        return "Obesidad morbida";
    }

    return "Clasificacion invalida"; 
}

string Medicion::clasificacionPaciente() {

    if (clasificacionIMC() == "Obesidad leve" || clasificacionIMC() == "Obesidad media" || clasificacionIMC() == "Obesidad morbida") {
        return "Paciente de alto riesgo"; 
    }

    return "El paciente no es de alto riesgo"; 
}

float Medicion::calcularProteina(char sexo, bool haceEjercicio) {

    if ((sexo == 'M' || sexo == 'm') && !haceEjercicio) {
        return peso * 0.8;
    }
    else if ((sexo == 'M' || sexo == 'm') && haceEjercicio) {
        return peso * 2.5;
    }
    else if ((sexo == 'F' || sexo == 'f') && !haceEjercicio) {
        return peso * 0.8;
    }
    else if ((sexo == 'F' || sexo == 'f') && haceEjercicio) {
        return peso * 1.8; 
    }
    else {
        return 0.0; 
    }
}

float Medicion::calcularAgua() {
    return (peso / 7); 
}

string Medicion::reporteMedicion() {

    stringstream x;

    //if (cliente != nullptr) {
      //  x << "Datos del cliente: " << cliente->toString() << endl;
    //}
   // if (instructor != nullptr) {
        //x << "Datos del instructor: " << instructor->toString() << endl;
    //}
    x << "Fecha de la medicion: " << fecha << endl;

    x << "Peso: " << peso << endl;

    x << "Estatura: " << estatura << endl;

    x << "Grasa corporal: " << grasaCorporal << endl;

    x << "Masa muscular: " << masaMuscular << endl;

    x << "Edad metabolica: " << edadMetabolica << endl;

    x << "Grasa visceral: " << grasaVisceral << endl;

    x << "Cintura: " << cintura << endl;

    x << "Cadera: " << cadera << endl;

    x << "Pecho: " << pecho << endl;

    x << "Muslo: " << muslo << endl;

    x << "IMC: " << calcularIMC() << endl;

    x << "Cantidad de vasos de agua recomendados: " << calcularAgua() << endl;

    x << "Ingesta calorica recomendada: " << calcularProteina(cliente->getSexo(), cliente->getHaceEjercicio()) << endl;

    x << "Riesgo del paciente segun su IMC: " << clasificacionPaciente() << endl; 

    x << "Clasificacion del paciente segun su IMC: " << clasificacionIMC() << endl; 

    return x.str();

}

string Medicion::reporteMedicionResumen(){

    stringstream x;

    x << fecha << "|" << peso << "|" << getIMC(); 

    return x.str(); 
}

string Medicion::datosBasicosMedicion()
{
    stringstream x;

    x << "Fecha de la medicion: " << fecha << endl;

    x << "Peso: " << peso << endl;

    x << "Estatura: " << estatura << endl;

    x << "Grasa corporal: " << grasaCorporal << endl;

    x << "Masa muscular: " << masaMuscular << endl;

    x << "IMC: " << calcularIMC() << endl;

    x << "Cantidad de vasos de agua recomendados: " << calcularAgua() << endl;

    x << "Ingesta calorica recomendada: " << calcularProteina(cliente->getSexo(), cliente->getHaceEjercicio()) << endl;

    x << "Riesgo del paciente segun su IMC: " << clasificacionPaciente() << endl;

    x << "Clasificacion del paciente segun su IMC: " << clasificacionIMC() << endl;


    return x.str(); 
}

float Medicion::getIMC()
{
    return calcularIMC(); 
}
