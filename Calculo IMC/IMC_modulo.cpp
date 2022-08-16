/*
 * Fecha : 15/08/20221
 * Autor : Jofre Eduardo Oliveros Gavidia
 * Materia : HPC para IA 1
 * Tema : Compilacion separada en c++
 */

#include "IMC_interfaz.h"
#include <string>
using std::string;

void imprimirMenu(){
    std::cout<<"//// Bienvenido al programa de calculo del IMC ////"<<std::endl;
    std::cout<<"Ingrese los siguiente datos :  "<<std::endl;


}

string solicitarNombre(){
    std::string nombre;
    std::cout<<"---> Nombre "<<std::endl;
    std::cin>>nombre;
    return nombre;
}

std::pair<float, float> solicitarDatosIMC(){

    float masa, altura;

    std::pair<float, float> ret;

    std::cout<<"---> Masa corporal en kg "<<std::endl;
    std::cin>>masa;
    std::cout<<"---> Altura en cm "<<std::endl;
    std::cin>>altura;

    ret.first = masa;
    ret.second = altura;

    return ret;
}

float calcularIMC(string nombre,float masa,float altura){
    float imc;
    imc = masa/(pow(altura/100,2));
    std::cout << "Paciente: " << nombre << ", su BMI es de: " << imc ;
    std::cout << std::endl;
    return imc;
}

void clasificarIMC(string nombre,float imc){

    if (imc<=18.5)
            std::cout << "Paciente: " << nombre << " tiene 'Delgadez Extrema'" << std::endl;
        else if (imc<=24.9)
            std::cout << "Paciente: " << nombre << " tiene 'un rango de peso Saludable'" << std::endl;
        else if (imc<=29.9)
            std::cout << "Paciente: " << nombre << " tiene 'Sobre Peso'" << std::endl;
        else if (imc<=34.9)
            std::cout << "Paciente: " << nombre << " tiene 'Obesidad Clase I'" << std::endl;
        else if (imc<=39.9)
            std::cout << "Paciente: " << nombre << " tiene 'Obesidad Clase II'" << std::endl;
        else
            std::cout << "Paciente: " << nombre << " tiene 'Obesidad Clase III'" << std::endl;
}
