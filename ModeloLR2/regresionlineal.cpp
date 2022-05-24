













#include "regresionlineal.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <cmath>

/*Se necesita entrenar el modelo, lo que implica
 * minimizar la función de costo. De esta forma
 * se puede medir la función de hipotesis. Una
 * función de costo es la forma de penalizar al
 * modelo por cometer un error.
 * Se implementa una función de tipo flotante
 * que toma como entrada los valores (X,y) */


float RegresionLineal::OLS_costo(Eigen::MatrixXd X,
                                 Eigen::MatrixXd y,
                                 Eigen::MatrixXd theta){
    Eigen::MatrixXd diferencia = pow((X*theta - y).array(),2);
    return diferencia.sum()/(2*X.rows());
}

/* Se provee al programa una función para dar al algoritmo un valor inicial para theta
 * el cual cambiara iterativamente hasta que converga al valor minimo de la
 * función de costo. Basicamente describe el Gradiente Descendiente: La ide es calcular
 * el gradiente para la función de costo, dado por la derivada parcial de la función
 * La función debe tener un Alfa que representa el salto del gradiente.
 * Las entradas para la función son X, y, theta, Alfa y e lnúmero de iteraciones
 */
std::tuple<Eigen::VectorXd, std::vector<float>> RegresionLineal::descentGradient(Eigen::MatrixXd X,
                                                                                 Eigen::MatrixXd y,
                                                                                 Eigen::VectorXd theta,
                                                                                 float alpha,
                                                                                 int iterator) {
    /* Se almacenan parámetros de theta */
    Eigen::MatrixXd temp = theta;
    /* Se captura el número de variables independientes */
    int parameters = theta.rows();
    /* Se ubica el costo inicial, que se actualiza cada vez con
     * los nuevos */
    std::vector<float> costo;
    costo.push_back(OLS_costo(X, y, theta));
    /* Por cada iteración se calcula la función de error de cada
     * features (variables independientes), para ser almacenado en
     * la variable temporal (tempTheta) basada en el nuevo valor de theta*/
    for (int i=0; i<iterator; ++i) {
        Eigen::MatrixXd error = X*theta - y;
        for (int j=0; j<parameters; ++j) {
            Eigen::MatrixXd X_i = X.col(j);
            Eigen::MatrixXd tempTheta = error.cwiseProduct(X_i);
            temp(j, 0) = theta(j, 0) - ((alpha/X.rows())*tempTheta.sum());
        }
        theta = temp;
        costo.push_back(OLS_costo(X, y, theta));
    }
    /* Se empaqueta la tupla y se retorna */
    return std::make_tuple(theta, costo);

}

/* Para determinar que tan bueno es nuestro modelo es necesario
 * recurrir a una metrica de rendimiento. Para ello se escoge al
 * R² el cual representa que tan bueno es nuestro modelo
 */

float RegresionLineal::metricaR2(Eigen::MatrixXd y, Eigen::MatrixXd y_hat){

    auto numerador = pow((y-y_hat).array(), 2).sum();
    auto denominador = pow(y.array()-y.mean(), 2).sum();
    return 1-(numerador/denominador);

}



