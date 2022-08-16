#ifndef IMC_INTERFAZ_H_INCLUDED
#define IMC_INTERFAZ_H_INCLUDED

/* Importacion de bibliotecas */

#include <stdio.h>
#include <iostream>
#include <math.h>
using std::string;

/*Prototipo funciones*/

void imprimirMenu();
string solicitarNombre();
std::pair<float, float>  solicitarDatosIMC();
float calcularIMC(string nombre,float masa,float altura);
void clasificarIMC(string nombre,float imc);

#endif
