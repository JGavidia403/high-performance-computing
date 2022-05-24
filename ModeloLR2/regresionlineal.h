#ifndef REGRESIONLINEAL_H
#define REGRESIONLINEAL_H
#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>


class RegresionLineal
{
public:
    RegresionLineal(){}

    /*A continuación se implementa la función de
     * minimos cuadrados ordinarios como función
     * de costos */

    float OLS_costo(Eigen::MatrixXd X,
                                     Eigen::MatrixXd y,
                                     Eigen::MatrixXd theta);
    std::tuple<Eigen::VectorXd, std::vector<float>> descentGradient(Eigen::MatrixXd X, Eigen::MatrixXd y,
                                                                    Eigen::VectorXd theta, float alpha,
                                                                    int iterator);

    float metricaR2(Eigen::MatrixXd y, Eigen::MatrixXd y_hat);
};

#endif // REGRESIONLINEAL_H
