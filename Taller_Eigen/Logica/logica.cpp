/*
 * Autor: Jofre Oliveros
 * Fecha: 20 de agosto de 2022
 * Materia: HPC-1
 * Objetivo: Aplicación para el calculo
 * de resolución de problemas matriciales
 *
*/

#include "logica.h"
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<float,2,2> Matriz2x2f;
typedef Eigen::Matrix<float,2,3> Matriz2x3f;
typedef Eigen::Matrix<float,3,2> Matriz3x2f;
typedef Eigen::Matrix<float,3,3> Matriz3x3f;
typedef Eigen::Matrix<float,4,4> Matriz4x4f;
typedef Eigen::Matrix<float,1,3> Vector1x3f;
typedef Eigen::Matrix<float,2,1> Vector2x1f;

/* Función que multiplica y resta dos matrices*/

Matriz2x2f primerPunto(){

    Matriz2x2f mA,mB,mC;

    mA<<4,-2,
        1,-7;

    mB<<-1,2,
        6,-5;
    mC = (3*mA).array() - (4*mB).array();

    return mC;

}

/* Función que multiplica,resta y divide dos matrices*/

Matriz2x2f segundoPunto(){

    Matriz2x2f mA,mB,mC;

    mA<<0,-1,
        2,1;

    mB<<1,2,
        3,4;
    mC = ((3*mB*mA).array() - (4*mA).array()) / 2;

    return mC;

}

/* Función que multiplica,resta y divide dos matrices
 * Teniendo en cuenta que se debe tener un orden determinado
 * en el producto de matrices al momento de despejar
 * */

Matriz2x2f tercerPunto(){

    Matriz2x2f mA,mB,mC,mD;

    mA<<-3,-2,
         3,3;

    mB<<5,3,
        9,4;

    mC<<1,1,
        0,0;
    mD = ((mA).inverse())*mC*(mB.transpose()).inverse();

    return mD;

}

/*Multiplicación de una matriz A con la matriz inversa de B
lo cual es equivalente a la división en números reales*/
Matriz2x2f cuartoPunto(){

    Matriz2x2f mA,mB,mC;

    mA<<2,1,
       -4,-3;

    mB<<2,2,
        6,4;

    mC = mB * mA.inverse();

    return mC;

}

/*Operaciones basicas entre matrices*/

Matriz2x2f quintoPunto(){

    Matriz2x2f mC,mD;
    Matriz3x2f mB;
    Matriz2x3f mA;



    mA<<3,0,-1,
         0,2,1;

    mB<<1,2,
        1,0,
        0,6;

    mC<<-2,0,
        -2,-5;

    mD = 2*(mA*mB+mC);

    return mD;


}

/*Operaciones basicas entre matrices*/

Matriz3x3f sextoPunto(){

    Matriz3x3f mA,mB,mC;

    mA<<1,5,-1,
        -1,2,2,
        0,-3,3;

    mB<<-1,-1,3,
         1,-2,-2,
         -3,3,-5;

    mC = mA+3*mB;
    return mC;
}

/*División entre matrices*/

Matriz3x3f septimoPunto(){

    Matriz3x3f mA,mB,mC;

    mA<<2,7,3,
        3,9,4,
        1,5,3;

    mB<<1,0,2,
        0,1,0,
        0,0,1;

    mC = mB*mA.inverse();
    return mC;
}
/*División entre matrices*/
Matriz3x3f octavoPunto(){

    Matriz3x3f mA,mB,mC;

    mA<<1,1,1,
        6,5,4,
        13,10,8;

    mB<<0,1,2,
        1,0,2,
        1,2,0;

    mC = mA.inverse()*mB;
    return mC;
}

/*Operaciones Básicas entre matrices*/
Matriz2x2f novenoPunto(){

    Matriz2x2f mA,mB;

    mA<<3,-1,
        0,2;

    mB = mA.transpose()*mA - 2*mA;
    return mB;
}

/*Potencia 3 de una matriz A = A³*/
Matriz2x2f decimoPunto(){

    Matriz2x2f mA,mB;

    mA<<4,2,
       -1,0;

    mB = mA*mA*mA;
    return mB;
}

Matriz2x2f unDecimoPunto(){

    Matriz2x2f mA,mB,mC,mD;

    mA<<2,4,
        3,2;

    mB<<1,0,
        2,1;

    mC<<7,5,
        6,1;

    mD = (mA.transpose()).inverse()*mC*mB.inverse();
    return mD;
}


Matriz2x2f duoDecimoPunto(){

    Matriz2x3f mA;
    Matriz3x2f mB;
    Matriz2x2f mC;

    mA<<1,0,-2,
        2,-1,3;

    mB<<2,-3,
        -2,0,
        -1,-2;


    mC = mA*mA.transpose() - 2*mA*mB;
    return mC;
}

float decimoTercerPunto(){

    //Vector3f mA;
    Vector1x3f mA;
    Matriz3x2f mB;
    Vector2x1f mC,mD;

    mA<<4,8,12;

    mB<<3,2,
        0,1,
       -1,0;

    mC<<3,
       -1;

    mD = mA*mB;
    return mD.dot(mC);
}

Matriz3x3f decimoCuartoPunto(){

    Matriz3x3f mA,mB,mC;
    mA<< 3,4,1,
        -1,-3,3,
         2,3,0;

    mB<<3,9,7,
        1,11,7,
        7,5,7;

    mC = ((mA.transpose()).inverse()) * mB;

    return mC;
}

Matriz3x3f decimoQuintoPunto(){

    Matriz3x3f mA,mB,mC;
    mA<< 2,5,7,
         6,3,4,
         5,-2,-3;

    mB<<-1,1,0,
        0,1,1,
        1,0,-1;

    mC = mB *mA.inverse() ;

    return mC;
}


Matriz4x4f decimoSextoPunto(){

    Matriz4x4f mA,mB,mC;
    mA<< 1,1,1,1,
         1,1,-1,-1,
         1,-1,1,-1,
         1,-1,-1,1;

    mB<<1,1,0,0,
        1,0,1,0,
        1,0,0,1,
        1,0,1,1;

    mC = mA.inverse() * mB;

    return mC;
}




