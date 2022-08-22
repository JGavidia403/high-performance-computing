/*
 * Autor: Jofre Oliveros
 * Fecha: 23 de agosto de 2022
 * Materia: HPC-1 para ML
 * Objetivo: Por medio del uso de
 * la biblioteca de Eigen, resolver
 * 15 problemas matriciales
*/
#include <iostream>
#include <eigen3/Eigen/Dense>
#include "Logica/logica.h"
#include <cstdlib>
using namespace std;

int main()
{
    cout << "\n\t\t\tTaller Solución de problemas matriciales con Eigen  -  H  P  C  1\n\n";
    int opcion = 0;
    while(opcion!=10){
        system("clear");
        cout<< "\n\n >>> Elija el punto que desea revisar\n\n";
        cout<<" \t1.  X = 3A - 4B\n"
              " \t2.  2X + 4A = 3BA\n"
              " \t3.  AXB^T = C\n"
              " \t4.  XA = B\n"
              " \t5.  X = 2(AB + C)\n"
              " \t6.  X = A + 3B\n"
              " \t7.  XA = B\n"
              " \t8.  AX = B\n"
              " \t9.  X = (A^T)A - 2A\n"
              "\t10. X= A³\n"
              "\t11. (A^T)XB = C\n"
              "\t12. X = A(A^T) - 2AB\n"
              "\t13. X = ABC\n"
              "\t14. (A^T)X = B\n"
              "\t15. XA = B\n"
              "\t16. AX = B\n"
              "\t17. Salir.\n\n";
        cout<<"   >>";
        cin >> opcion;

        switch(opcion){
        //system("clear");
        case 1:{
            system("clear");
            cout<<"\n\nPrimer punto.\n";
            cout<<primerPunto()<<"\n";
            cin.get();


        }
            break;
        case 2:{
            system("clear");
            cout<<"Segundo punto.\n";
            cout<<segundoPunto();
            cin.get();

        }
            break;
        case 3:{
            system("clear");
            cout<<"\nTercer Punto. \n";
            cout<<tercerPunto();
            cin.get();

        }
            break;
        case 4:{
            system("clear");
            cout<<"Cuarto punto.\n";
            cout<<cuartoPunto();
            cin.get();

        }
            break;
        case 5:{
            system("clear");
            cout<<"Quinto punto.\n";
            cout<<quintoPunto();
            cin.get();
        }
            break;
        case 6:{
            system("clear");
            cout<<"Sexto punto. \n";
            cout<<sextoPunto();
            cin.get();

        }
            break;
        case 7:{

            system("clear");
            cout<<"Septimo punto.\n";
            cout<<septimoPunto();
            cin.get();

        }
            break;
        case 8:{
            system("clear");
            cout<<"Octavo punto. \n";
            cout<<octavoPunto();
            cin.get();

        }
            break;
        case 9:{
            system("clear");
            cout<<"Noveno punto.\n";
            cout<<novenoPunto();
            cin.get();

        }
            break;
        case 10:{
            system("clear");
            cout<<"Decimo punto.\n";
            cout<<decimoPunto();
            cin.get();

        }
            break;

        case 11:{
            system("clear");
            cout<<"UnDecimo punto.\n";
            cout<<unDecimoPunto();
            cin.get();

        }
            break;
        case 12:{
            system("clear");
            cout<<"DuoDecimo punto. \n";
            cout<<duoDecimoPunto();
            cin.get();

        }
            break;
        case 13:{
            system("clear");
            cout<<"Decimo Tercer Punto. n";
            cout<<decimoTercerPunto();
            cin.get();

        }
            break;
        case 14:{
            system("clear");
            cout<<"Decimo Cuarto punto. \n";
            cout<<decimoCuartoPunto();
            cin.get();

        }
            break;
        case 15:{
            system("clear");
            cout<<"Decimo Quinto punto.\n";
            cout<<decimoQuintoPunto();
            cin.get();

        }
            break;
        case 16:{
            system("clear");
            cout<<"Decimo Sexto punto.\n";
            cout<<decimoSextoPunto();
            cin.get();

        }
            break;
            default:
            cout << "\n\nUsted ha ingresado una opción incorrecta !";
        }
        cin.get();

    }


    return 0;
}

