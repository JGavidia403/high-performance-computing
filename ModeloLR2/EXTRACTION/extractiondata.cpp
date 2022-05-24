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

/* Se requiere implementar una función que calcule
 * el promedio de los datos (xcolumnas). La función
 * debe ser verificada con python usando cualquier
 * biblioteca (pandas, sklearn, seaborn...)
 *
 * En c++, existe el tipo de dato "auto" => "decltype".
 * En muchos casos, la herencia del tipo de dato no es
 * evidente. El tipo de dato "auto" => "decltype"
 * especifica el tipo de variable (deduce el tipo de
 * compilación) que va a heredarla función. Es decir,
 * en la función, si el tipo de retorno es "auto", se
 * evaluará mediante la expresión para la deducción
 * del tipo de dato a retornar */

auto ExtractionData::Promedio(Eigen::MatrixXd datos) ->
decltype (datos.colwise().mean()){
    return datos.colwise().mean();
}

/* Para implementar la función de Desviación Estandar
 * datos = xi - x.promedio()
 * En esta función */

auto ExtractionData::DesvStandard(Eigen::MatrixXd datos)->
decltype((datos.array().square().colwise().sum()
            /(datos.rows()-1)).sqrt()){

    return((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt();
}

/*Se implementa la función que calcule la normalización
 * de los datos. Lo anterior para regular la escala
 * o magnitud de los datos.Por lo tanto, adegurar la precisión
 * de los modelos de Machine Learning */

Eigen::MatrixXd ExtractionData::matrizNormal (Eigen::MatrixXd datos){

    Eigen::MatrixXd datosEsc = datos.rowwise() - Promedio(datos);

    Eigen::MatrixXd NormMatriz = datosEsc.array().rowwise()/DesvStandard(datosEsc);

    return NormMatriz;
}

/* A continuación se implementa la función para hacer la
 * división de datos en dos grupos. El primer grupo es para
 * entrenamiento, por lo genral se usa del 70% al 80% del
 * total de los datos. El segundo grupo de los datos, es para
 * pruebas. Se requiere crear una función que vuelva dos
 * grupos de datos, seleccionados de forma aleatoria */

std::tuple<Eigen::MatrixXd, Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> ExtractionData::TrainTestDiv(Eigen::MatrixXd datos, float sizeTrain){
    int filas = datos.rows();
    int filasTrain = round(sizeTrain*filas);
    int filasTest = filas - filasTrain;

    /*Con Eigen, se puede especificar un bloque de una matriz,
     * seleccionando las filas superiores para el conjunto de
     * entrenamiento, y las demás para el conjunto de pruebas
     */
    Eigen::MatrixXd trainMatriz = datos.topRows(filasTrain);

    /* Una vez seleccionadas las filas superiores para entrenamient.
     * Se seleccionan las columnas a la izquierda *** (para este conjunto
     * de datos) correspondientes a las "features" o variables dependientes
     * Entonces se seleccionan la cantidad de columnas - 1
     */

    Eigen::MatrixXd X_train = trainMatriz.leftCols(datos.cols()-1);
    /* Se selecciona la variable dependiente, en los datos de
     * entrenamiento */
    Eigen::MatrixXd y_train = trainMatriz.rightCols(1);

    /* Se realiza el mismo procedimiento para el conjunto de datos
     * de prueba, recordando que se tiene los datos de la parte
     * inferior de la matriz de entrada */

    Eigen::MatrixXd testMatriz = datos.bottomRows(filasTest);

    Eigen::MatrixXd X_test = testMatriz.leftCols(datos.cols()-1);
    /* Se selecciona la variable dependiente, en los datos de
     * entrenamiento */
    Eigen::MatrixXd y_test = testMatriz.rightCols(1);


    /*Finalmentese retorna la tupla, que contiene
     * los subconjuntos de prueba y de entrenamiento.
     * Atención con la tupla enviada, dado que al ser usada
     * es necesario desempaquetarla
     */

    return std::make_tuple(X_train, y_train,X_test,y_test);
}

/* A continuación se implementa una función para exportar
 * los valores de vector a archivo */

void ExtractionData::vectorToArchivo(std::vector<float> vectorData,
                                     std::string nameFile){
    /*Se crea la salida de datos stream o flujo de datos del fichero de entrada*/
    std::ofstream salidaData(nameFile);
    //Itera por linea
    /* Se escribe cada objeto del tipo float sobre cada vector, condicionado
     * por el cambio de linea */
    std::ostream_iterator<float> dataVector(salidaData,"\n");
    /*Se hace una copia de los objetos escritos sobre el vector data*/
    std::copy(vectorData.begin(), vectorData.end(),dataVector);
}

/* A continuación se implementa una función para exportar una amtriz
 * dinamica double a fichero.
 * Las exportaciones a ficheros son criticas o significativas
 * en tanto se tiene seguridad, trasabilidad y control sobre los
 * resultados parciales obtenidos.*/

void ExtractionData::matrixToFile(Eigen::MatrixXd DataMatriz,
                                  std::string nameFile){
    std::ofstream salidaData(nameFile);
    /* Si el fichero está abierto, y no ha llegado al final
     * copie los datos de la matriz*/

    if(salidaData.is_open()){
        salidaData<< "\n" << DataMatriz <<"\n";
    }


}

/*              ********WARNING********
 *
 *      Se ha de estudiar los datos para saber la posiciones
 *      sobre las columnas: variable dependiente, variables independientes
 */
