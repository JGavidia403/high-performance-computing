/*
 * Autor: Jofre Oliveros
 * Fecha: 20 de agosto de 2022
 * Materia: HPC-1
 * Objetivo: Aplicación para la
 * resolución de problemas matrciales.
 * Funcionalidad:
 * 1. Crear/Implementar una Interfaz para
 * la clase que Resuelve los 15
 * problemas matriciales
 *
*/
#ifndef LOGICA_H
#define LOGICA_H
#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>

typedef Eigen::Matrix<float,2,2> Matriz2x2f;
typedef Eigen::Matrix<float,2,3> Matriz2x3f;
typedef Eigen::Matrix<float,3,2> Matriz3x2f;
typedef Eigen::Matrix<float,3,3> Matriz3x3f;
typedef Eigen::Matrix<float,4,4> Matriz4x4f;
typedef Eigen::Vector3f Vector3f;
typedef Eigen::Vector2f Vector2f;

Matriz2x2f primerPunto();
Matriz2x2f segundoPunto();
Matriz2x2f tercerPunto();
Matriz2x2f cuartoPunto();
Matriz2x2f quintoPunto();
Matriz3x3f sextoPunto();
Matriz3x3f septimoPunto();
Matriz3x3f octavoPunto();
Matriz2x2f novenoPunto();
Matriz2x2f decimoPunto();
Matriz2x2f unDecimoPunto();
Matriz2x2f duoDecimoPunto();
float decimoTercerPunto();
Matriz3x3f decimoCuartoPunto();
Matriz3x3f decimoQuintoPunto();
Matriz4x4f decimoSextoPunto();


#endif // LOGICA_H
