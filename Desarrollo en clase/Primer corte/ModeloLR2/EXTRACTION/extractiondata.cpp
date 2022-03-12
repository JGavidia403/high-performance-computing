/*
 * Autor: Jofre Oliveros
 * Fecha: 1 de marzo de 2022
 * Materia: HPC-3
 * Objetivo: Aplicación para el calculo
 * del modelo de regresión lineal.
 * Funcionalidad:
 * 1. Crear/Implementar una Interfaz para
 * la clase que manipula, extrae, explora
 * los datos, dado por un fichero CSV
 * (Valores separados por comas).
 * Argumentos de entrada:
 *          Nombre del fichero,
 *          Delimitador
 *          Cabecera
 *
*/

#include "extractiondata.h"
#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <unistd.h>

/*Se implementa la primera función miembro: lectura
 *del fichero CSV. Para ello, disponemos de un vecor
 *de vectores del tipo string, en donde se itera
 *linea por linea y se almacena el vector
 *de vectores del tipo string, cada registro o fila
 * La función retornará un vector de vectores tipo string
*/

std::vector<std::vector<std::string>> ExtractionData::Readcsv(){
    /*Se abre el fichero .csv de solo lectura*/
    std::ifstream Fichero(setDatos);
    /*Se crea el vector de vectores tipo string
      a retornar : tendrá los datos del dataset */
    std::vector<std::vector<std::string>> datosString;
    /*Se itera a traves de cada linea. Se divide el
      contenido según el delimitador provisto por el
      constructor */
    std::string linea = ""; //Variable para almacenar cada linea del dataset

    while(getline(Fichero,linea)){
        /*Cada linea de almacena en vectorFila*/
        std::vector<std::string> vectorFila;
        /*cada vector se divide segun delimitador*/
        boost::algorithm::split(vectorFila,linea, boost::is_any_of(delimitador));
        /*Cada fila se ingresa al vector de vectores*/
        datosString.push_back(vectorFila);

    }

    /*Se cierra el fichero*/
    Fichero.close();
    /*Se retorna el vector de vectores*/
    return datosString;

}

/*Segunda función miembro: Almacenar el vector de vectores
 *del tipo string en una matrix. La idea es presentar
 *el conjunto de datos similar a un objeto pandas
 * (DataFrame)*/

Eigen::MatrixXd ExtractionData::CSVtoEigen(
        std::vector<std::vector<std::string>> setDatos,
        int filas, int columnas){
        /*Identificar si tiene o no cabecera*/
        if(header==true){
            filas = filas-1;
        }
        /*Se itera sobre las filas y columnas, para almacenar
         * en la matrix de dimensión filasxcolumnas.
         * Basicamente, se le almacenará strings del vector:
         * que luego se pasa a "float" para ser manipulados
         */
        Eigen::MatrixXd dfMatriz(columnas,filas);

        int i,j;
        for(i=0; i<filas;i++){
            for(j=0; j<columnas; j++){
                dfMatriz(j,i) = atof(setDatos[i][j].c_str()); //atof casteo a fotante
            }
        }
        /*Se transpone la matriz para ser retornada*/
        return dfMatriz.transpose();
}
