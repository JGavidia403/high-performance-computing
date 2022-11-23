#include "EXTRACTION/extractiondata.h"
#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <unistd.h>
#include "regresionlineal.h"



int main(int argc, char* argv[])
{
    ExtractionData extraer(argv[1], argv[2],argv[3]);

    RegresionLineal RL;

    /*Se leen los datos del fichero, a traves
      de la función ReadCSV*/

    std::vector<std::vector<std::string>> dataSET = extraer.Readcsv();
    /*Para probar la lectura del fichero,
     se obtiene la cantidad de filas y columnas*/

    int filas = dataSET.size() + 1;
    int columnas = dataSET[0].size();

    /*Se crea una matriz dinamica double
     * de dimensión filasxcolumnas */

    Eigen::MatrixXd DataFrame = extraer.CSVtoEigen(
                dataSET,filas,columnas);
    /*
    std::cout <<DataFrame << std::endl;
    std::cout << "argv 1"<<argv[1] << std::endl;
    std::cout << "argv 2"<<argv[2] << std::endl;
    std::cout << "argv 3"<<argv[3] << std::endl;
    */
    //std::cout <<extraer.Promedio(DataFrame)<<"\n";
    //std::cout <<extraer.matrizNormal(DataFrame);
    //std::cout <<extraer.DesvStandard(DataFrame)<<"\n";

    /* El objeto CSVtoEigen (similar a un objeto DataFrame)
     * se normaliza: Se obtiene una matriz matNormal */

    Eigen::MatrixXd matNormal = extraer.matrizNormal(DataFrame);

    /* A continuación se hará el primer modulo de ML:
     * Se requiere una clase de regresión lineal (Implementación e interfaz).
     * Debe definir un constructor, importar las bibliotecas necesarias. Se debe
     * tener en cuenta que el método de regresión lineal es un método
     * estadistico que define la relaciń entre la variables independientes, con
     * la variable dependiente. La idea principal, es definir una linea recta
     * (Hiperplano), con sus correspondientes coeficientes (pendientes) y los
     * puntos de corte (y =0).
     *
     * Se tienen diferentes métodos para resolver RL: se implementará el
     * metodo de los minimos cuadrados ordinarios (OLS). El OLS
     * es un método sencill y computacionalmente económico. OLS
     * presenta una solución óptima para conjunto de datos complejos.
     * Para el Presente caso, se tiene un conjunto de datos (winedata.csv)
     * con múltiples variable independientes. Se necesita el algoritmo
     * llamado gradiente descendiente. El objetivo del GD es minimizar
     * la "función de costo" */

    /*Se crearán cuatro matrices
     * dos grupos de entrenamientos
     * dos de prueba
     */

    Eigen::MatrixXd X_train, y_train , X_test, y_test;

    /* Declaramos un obj para recibir la tupla*/

    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> empaquetado = extraer.TrainTestDiv(matNormal,0.8);
    /* Se necesita desempaquetar la tupla en cuatro grupos de datos*/
    std::tie(X_train, y_train , X_test, y_test) = empaquetado;

    /*Se imprime el total de filas, las filas para train, las filas para test
    en sus dos sabores*/
    /*std::cout<<matNormal.rows()<<"\n";
    std::cout<<X_train.rows()<<"\n";
    std::cout<<y_train.rows()<<"\n";
    std::cout<<x_test.rows()<<"\n";
    std::cout<<y_test.rows()<<"\n";*/
    /* Se necesita imprimir la cantidad de columnas por sabor*/
    /*std::cout<<matNormal.cols()<<"\n";
    std::cout<<X_train.cols()<<"\n";
    std::cout<<y_train.cols()<<"\n";
    std::cout<<x_test.cols()<<"\n";
    std::cout<<y_test.cols()<<"\n";*/

    /* Se tiene en cuenta que la regresión lineal es un método estadístico.
         * La idea principal es crear un hiperplano con tantas dimensiones
         * como variables independientes tenga el dataset (pendientes/pesos y punto de corte).
         *
         * Se hace la prueba del modelo:
         * - Se crea un vector para prueba y para entrenamiento inicializado en "unos", que
         * corresponde a los features (variables independientes). */
        Eigen::VectorXd vectorTrain = Eigen::VectorXd::Ones(X_train.rows());
        Eigen::VectorXd vectorTest = Eigen::VectorXd::Ones(X_test.rows());

        /* Se redimensiona las matrices para ser ubicadas en los vectores
         * anteriores. Similar a reshape() de numpy. */
        X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
        X_train.col(X_train.cols()-1) = vectorTrain;

        X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
        X_test.col(X_test.cols()-1) = vectorTest;

        /* Se define el vector theta, para pasar al algoritmo del GD,
         * básicamente es un vector de ceros del mismo tamaño de
         * entrenamiento. Adicional, se declara alfa y el número de
         * iteraciones. */
        Eigen::VectorXd theta = Eigen::VectorXd::Zero(X_train.cols());
        Eigen::VectorXd theta1 = Eigen::VectorXd::Zero(X_test.cols());
        float alpha = 0.01;
        int iterations = 1000;

        /* Se definen las variables de salida que representan los
         * coeficientes del vector de costo. */
        Eigen::VectorXd thetaOut;
        std::vector<float> costo;

        Eigen::VectorXd thetaOut1;
        std::vector<float> costo1;

        /* Se desempaqueta la tupla obtenida del objeto de la clase
         * Regresión Lineal */
        std::tuple<Eigen::VectorXd, std::vector<float>> salidaGD = RL.descentGradient(X_train, y_train, theta, alpha, iterations);
        std::tie(thetaOut, costo) = salidaGD;


        std::tuple<Eigen::VectorXd, std::vector<float>> salidaGD1 = RL.descentGradient(X_test, y_test, theta1, alpha, iterations);
        std::tie(thetaOut1, costo1) = salidaGD1;

        // std::cout << thetaOut << std::endl;

        /* Se quiere observar como decrece la función de costo */
        /*
        for (auto v : costo) {
            std::cout << v << std::endl;
        }<<"\n";
        */

        /* A continuación por propositos de seguridad y trsabilidad
         * se exporta el vector de costos y el vector theta a ficheros
         */

        extraer.vectorToArchivo(costo, "vectorCosto.txt");
        extraer.matrixToFile(thetaOut,"vector_theta.txt");


        extraer.vectorToArchivo(costo1, "vectorCostoTest.txt");
        extraer.matrixToFile(thetaOut1,"vector_thetaTest.txt");

        /*Con el proposito de ajustar el modelo y hacer la predicciones
         * necesarias, calculamos de nuevo el promedio y la desviación
         *estandar basadas en los datos para calcular y_hat (predicciones
         * de los valores 'y' segun el modelo)
         */

        auto muPromedio = extraer.Promedio(DataFrame);
        std::cout<<"mean : \n "<<muPromedio<<"\n";
        auto muFeatures = muPromedio(0,8);
        auto escaladaData = DataFrame.rowwise() - DataFrame.colwise().mean();
        auto muEstandar = extraer.DesvStandard(escaladaData);
        std::cout<<"std : \n "<<muEstandar<<"\n";
        auto DevFeatures = muEstandar(0,8);
        Eigen::MatrixXd y_train_hat = (X_train*thetaOut*DevFeatures).array()
                                       +muFeatures;

        Eigen::MatrixXd y_test_hat = (X_test*thetaOut1*DevFeatures).array()
                                       +muFeatures;

        Eigen::MatrixXd y = DataFrame.col(8).topRows(13600);

        Eigen::MatrixXd y1 = DataFrame.col(8).bottomRows(3400);

        /* A continuación se determina que tan bueno es nuestro modelo
         * utilizando la metrica R² */

        float comprobacionMetrica = RL.metricaR2(y,y_train_hat);
        float comprobacionMetrica1 = RL.metricaR2(y1,y_test_hat);

        extraer.matrixToFile(y_train_hat, "prediccion.txt");
        extraer.matrixToFile(y_test_hat, "prediccionTest.txt");
        // Las variables independientes presentan una relación sobre la varible dependiente apróx. 37%

        //std::cout<<comprobacionMetrica<<"\n";
        //std::cout<<comprobacionMetrica1<<"\n";






    return EXIT_SUCCESS;
}
