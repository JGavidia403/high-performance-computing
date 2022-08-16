#include <iostream>
#include <stdio.h>
#include <math.h>
#include "IMC_interfaz.h"

int main(){
    float masa,altura,imc;
    string nombre;
    imprimirMenu();
    nombre = solicitarNombre();
    auto datos = solicitarDatosIMC();
    masa = datos.first;
    altura = datos.second;
    imc = calcularIMC(nombre,masa,altura);
    clasificarIMC(nombre,imc);

}
