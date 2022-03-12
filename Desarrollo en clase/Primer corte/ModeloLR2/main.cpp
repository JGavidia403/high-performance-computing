#include "EXTRACTION/extractiondata.h"
#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <unistd.h>



int main(int argc, char* argv[])
{
    ExtractionData extraer(argv[1], argv[2],argv[3]);

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
    std::cout <<DataFrame << std::endl;
    std::cout << "argv 1"<<argv[1] << std::endl;
    std::cout << "argv 2"<<argv[1] << std::endl;
    std::cout << "argv 3"<<argv[1] << std::endl;
    return 0;
}
