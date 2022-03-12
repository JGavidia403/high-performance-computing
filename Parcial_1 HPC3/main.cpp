/*
 * Autor: Jofre Oliveros
 * Fecha: 10 de marzo de 2022
 * Materia: HPC-3
 * Objetivo: Por medio del uso de
 * la biblioteca de Eigen, resolver
 * problemas de :
 * 1. Operaciones basicas entre matrices
 * 2. Inversa de una Matriz
 * 3. Matriz a la n
 * 4. Calcular rango de una matriz
 * 5. Solución de sistemas de
 * ecuaciones matricialmente
 * 6. otros.
*/

#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;

typedef Eigen::Matrix<float, 3, 1> MiVector3f;
typedef Eigen::Matrix<float, 2,2> Matriz2x2f;
typedef Eigen::Matrix<float, 2,3> Matriz2x3f;
typedef Eigen::Matrix<float, 3,3> Matriz3x3f;
typedef Eigen::Matrix<float,3,4> Matriz3x4f;
typedef Eigen::Matrix <float,Eigen::Dynamic,Eigen::Dynamic> MatrizDinamica;

int main()
{
    cout << "\n\t\t\tP    A    R    C    I    A    L  -  H  P  C  3\n\n";
    int opcion = 0;
    while(opcion!=10){

        cout<< "\n\n\n >>> Elija el punto que desea revisar\n\n";
        cout<<"\t1. Operaciones basicas entre matrices\n"
              "\t2. Demostrar A² - A - 2I = 0\n"
              "\t3. Hallar A^n / n pertenece a los naturales\n"
              "\t4. Hallar la inversa de una matriz\n"
              "\t5. Resolver sistema de ecuaciones\n"
              "\t6. Análisis y solución de problema usando matrices\n"
              "\t7. Calcular rango de una matriz\n"
              "\t8. Calcular el valor de X para cinco ecuaciones\n"
              "\t9. Resolver de forma matricial el sistema de ecuaciones\n"
              "\t10 Salir.\n\n";
        cout<<"   >>";
        cin >> opcion;

        switch(opcion){
        system("clear");
        case 1:{
            system("clear");
            cout<<"Primer punto. Operaciones basicas entre matrice\n";

            // Se Declara el tipo de dato para mA, mB, mC
            Matriz3x3f mA,mB,mC;

            // Se llenan las matrices manualmente
            mA<<2,0,1,
                3,0,0,
                5,1,1;

            mB<<1,0,1,
                1,2,1,
                1,1,0;
            mC = Matriz3x3f::Zero();
            cout<<"\n\nDeclaración de matrices\n\n";
            cout<<"\nMatriz A : \n\n"<<mA<<"\n";
            cout<<"\nMatriz B : \n\n"<<mB<<"\n";
            cout<<"\nMatriz C : \n\n"<<mC<<"\n";

            cout<<"\n1. Suma de matrices (A + B)\n\n";
            mC = mA.array() + mB.array();
            cout<<mC<<"\n";

            cout<<"\n2. Resta de matrices (A - B)\n\n";
            mC = mA.array() - mB.array();
            cout<<mC<<"\n";

            cout<<"\n3. Multiplicación de matrices (A * B)\n\n";
            mC = mA* mB;
            cout<<mC<<"\n";

            cout<<"\n3. Multiplicación de matrices (B * A)\n\n";
            mC = mB* mA;
            cout<<mC<<"\n";

            cout<<"\n3. Multiplicación de matrices (B * A)\n\n";
            mC = mB* mA;
            cout<<mC<<"\n";

            cout<<"\n4. Transposición matriz A\n\n";
            mC = mA.transpose();
            cout<<mC<<"\n";
        }
            break;
        case 2:{
            system("clear");
            cout<<"Segundo punto. Demostrar A² - A - 2I = 0 \n";
            // Se Declara el tipo de dato para mA y mC
            //mA es la matriz con valores que da el ejercicio
            //mB es mA * mA (A²)
            //mC es la matriz identidad multiplicada por 2 (2I)
            //mD es el resultado de A² - A - 2I
            Matriz3x3f mA,mB,mC,mD;

            // Se llena las matriz manualmente
            mA<<0,1,1,
                1,0,1,
                1,1,0;
            mB = Matriz3x3f::Zero();
            mC = Matriz3x3f::Zero();
            mD = Matriz3x3f::Zero();

            cout<<"\n1.Matriz A\n\n";
            cout<<mA<<"\n";

            cout<<"\n2.Matriz A al cuadrado A²\n\n";
            mB = mA * mA;
            cout<<mB<<"\n";

            cout<<"\n3.Producto escalar de I con 2 2I\n\n";
            mC = Matriz3x3f::Identity() * 2;
            cout<<mC<<"\n";


            cout<<"\n4.A² - A - 2I = 0\n\n";
            mD = mB - mA - mC;
            cout<<mD<<"\n";
        }
            break;
        case 3:{
            system("clear");
            int n=0;
            Matriz3x3f mA,mB;
            mA<<1,0,1,
                0,1,0,
                0,0,1;
            mB = mA;
            cout<<"\nTercer Punto. Hallar A^n / n pertenece a los naturales\n";
            cout<<"\n\n A = \n\n"<<mA<<"\n";
            cout<<"\nDigite el número n \n\n"<<">>";
            cin>>n;

            for(int i =0; i<n-1;i++){

                mB *= mA;
            }

            cout<<"\nMatriz resultado : \n\n"<<mB<<"\n";
        }
            break;
        case 4:{
            system("clear");
            cout<<"Cuarto punto. Hallar la inversa de la matriz A \n";
            Matriz3x3f mA;

            mA<< 1,-1,0,
                 0,1,0,
                 2,0,1;


            cout<<"Hallando matriz inversa de : \n\n";
            cout<<"\n A: \n \n"<<mA<<"\n\n";
            cout<<" Resultado :\n\n"<<mA.inverse()<<"\n";
        }
            break;
        case 5:{
            system("clear");
            cout<<"Quinto punto. Resolver sistema de ecuaciones\n\n";
            Matriz2x3f mA, mB, mC, mD, mE;

             mA<<1,2,2,
                -2,1,0;

             mB<<-4,-3,-2,
                 -1,0,-1;
             mC = Matriz2x3f::Identity();

             mD = Matriz2x3f::Identity();
            cout<<"Operando ECUACIÓN 2 (Para despejar B)\n\n";
            cout<<"2 * ecuaciones : \n\n";
            cout<<"1. 2A + B = \n\n"<<mA<<"\n\n2. -2A + 6B\n\n"<<mB*-2<<"\n\n";

            cout<<"Sumando Ecuaciones y Matrices (Matriz resultado) :\n";
            mC = mA+(mB*-2);
            cout<<"7B = \n\n"<<mC<<"\n\n";

            cout<<"3. Ecuación resultado : B = Matriz_Resultado/7\n\n";
            cout<<"B = \n"<<mC.array()/7<<"\n\n";

            cout<<"***************************************************************\n\n";

            cout<<"Operando ECUACIÓN 1 (Para despejar A)\n\n";
            cout<<"3 * ecuaciones : \n\n";
            cout<<"1. 6A + 3B = \n\n"<<mA*3<<"\n\n2. A - 3B\n\n"<<mB<<"\n\n";

            cout<<"Sumando Ecuaciones y Matrices (Matriz resultado) :\n";
            mE = mA*3+mB;
            cout<<"7A = \n\n"<<mC<<"\n\n";

            cout<<"3. Ecuación resultado : A = Matriz_Resultado/7\n\n";
            cout<<"A = \n"<<mE.array()/7<<"\n\n";}
            break;
        case 6:{
            system("clear");
            cout<<"Sexto punto. Análisis y solución de problema usando matrices\n";
            MatrizDinamica mA(2,3), mB(3,2);


            // Inicialización matriz Producción
            // Filas: Modelos A, B; Columnas:  Terminaciones N, L, S
            mA<<400,200,50,
                300,100,30;
            // Inicialización matriz Coste horas
            // Filas:  Terminaciones N, L, S; Columnas:  Coste en horas: T, A

            mB<<25,1,
                30,1.2,
                33,1.3;

            cout<<"\n\nMatriz de Producción : \n\n"<<mA;
            cout<<"\n\nMatriz de Coste horas : \n\n"<<mB<<"\n\n";

            cout<<"Se debe multiplicar la matriz de costos con la matriz de producción ";
            cout<<"\n\nMatriz que expresa las horas de taller "
            "y de administración para cada uno de los modelos :\n\n";
            cout<<"P * C = \n\n"<<mA*mB<<"\n\n";}
            break;
        case 7:{

            cout<<"Septimo punto. Calcular el rango de la matriz\n";
            system("clear");
            Matriz3x4f mA;
            mA<< 2,-1,0,7,
                  1,0,1,3,
                  3,2,7,7;

            //FullPivLu de eigen ofrece la capacidad de hallar el rango de
            //una matriz

            Eigen::FullPivLU<Matriz3x4f> lu_decomp(mA);
            cout<<"\n\nMatriz : \n\n"<<mA;
            cout<<"\n\nRango de la matriz : "<<lu_decomp.rank()<<"\n\n";}
            break;
        case 8:{
            system("clear");
            cout<<"Octavo punto. Calcular el rango de la matriz\n";
            Matriz2x2f mA, mB, mC, mI, mD,mE;

            mA<<1,1,
                3,4;

            mB<<2,1,
                1,1;

            mC<<1,2,
                1,3;

            mI = Matriz2x2f::Identity();

            cout<<"\n\nSean las matrices :\n\n"
                  "A =\n\n"<<mA<<"\n\nB =\n\n"<<mB
                  <<"\n\nC =\n\n"<<mC;

            cout<<"\n\nCalcular el valor de X en las siguientes "
                  "ecuaciones : \n\n";
            cout<<"1. XA = B + I \n\n";
            cout<<"2. AX + B = C \n\n";
            cout<<"3. XA + B = 2C \n\n";
            cout<<"4. AX + BX = C \n\n";
            cout<<"5. XAB - Xc = 2C \n\n";
            cout<<"\n\n\t\t\t\tS   O   L   U   C   I   Ó   N   \n\n";
            mD = mB.array()+mI.array();
            cout<<"\n1. Despejando la X : \n\n"<<"X = (B+I)A-¹\n\n";
            cout<<">>> Reemplazando y resolviendo (B+I)A-¹ : \n\nX =\n\n"
               <<(mD*mA.inverse())<<"\n\n";
            mD = mC.array()-mB.array();
            cout<<"\n2. Despejando la X : \n\n"<<"X = A-¹(C-B)\n\n";
            cout<<">>> Reemplazando y resolviendo A-¹(C-B) : \n\nX =\n\n"
               <<(mA.inverse()*mD)<<"\n\n";
            mD = 2*mC - mB;
            cout<<"\n3. Despejando la X : \n\n"<<"X = (2C-B)A-¹\n\n";
            cout<<">>> Reemplazando y resolviendo (2C-B)A-¹ : \n\nX =\n\n"
               <<(mD*mA.inverse())<<"\n\n";
            mD = (mA.array()+ mB.array());
            mE = mD.inverse();
            cout<<"\n4. Despejando la X : \n\n"<<"X = (A+B)-¹C\n\n";
            cout<<">>> Reemplazando y resolviendo (A+B)-¹C : \n\nX =\n\n"
               <<(mE*mC)<<"\n\n";
            mD = ((mA*mB)-mC);
            mE = mD.inverse();
            cout<<"\n5. Despejando la X : \n\n"<<"X = 2C(AB-C)-¹\n\n";
            cout<<">>> Reemplazando y resolviendo 2C(AB-C)-¹ : \n\nX =\n\n"
               <<(2*mC*mE)<<"\n\n";}
            break;
        case 9:{
            system("clear");
            cout<<"Noveno punto. Resolver de forma matricial el sistema de ecuaciones\n";
            Matriz3x3f A;
            MiVector3f b;

            A << 1,1,1,
                 1,2,5,
                 1,4,25;

            b << 6, 12, 36;
            cout << "\n\nSea la matricez :\n\n" << A <<"\n\n";
            cout << "Sea el vector :\n\n" << b << endl;
            MiVector3f x = A.colPivHouseholderQr().solve(b);
            cout << "\nSolución :\n\n";
            cout << "X = " << x[0] <<"\n";
            cout << "Y = " << x[1] <<"\n";
            cout << "Z = " << x[2] <<"\n";
        }
            break;
            default:
            cout << "\n\nUsted ha ingresado una opción incorrecta !";
        }
    }

    return 0;
}
