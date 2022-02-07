/*
  Fecha : 25-01-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Introducción a la programación en c++
  Materia : Hpc para IA 5
  
*/

/*Se importan las interfaces correspondientes */
/*La interfaz es un enlace para que la fuente reconozca funciones de otro archivo (Biblioteca)*/

#include <iostream>
#define SIZE(x) sizeof(x)*8
/*Se declara el dominio de espacio para la función STD*/

using namespace std;

/*Main es el proceso/progrma principal, el cual llaa a los demas procesos o funciones*/

int main() {
	
	/*Crear un programa que permita determinar el tipo de dato y la capacidad de almacenamiento*/
	cout<<"*****************************************************************************************************\n";
	cout<<"		Type   "<< "		Significado   "<<"		bytes   "<<"		bits   \n";
	cout<<"*****************************************************************************************************\n";
	cout<<"		bool		 "<<"boolean		  "<<sizeof(bool)<<"			 "<<SIZE(bool)<<endl;
	cout<<"		char		 "<<"character		  "<<sizeof(char)<<"			 "<<SIZE(char)<<endl;
	cout<<"		wchar_t		 "<<"widw character		  "<<sizeof(wchar_t)<<"			 "<<SIZE(wchar_t)<<endl;
	/*cout<<"		char16_t		 "<<"unicode character		  "<<sizeof(char16_t)<<"			 "<<SIZE(char16_t)<<endl;*/
	/*cout<<"		char32_t		 "<<"unicode character		  "<<sizeof(char32_t)<<"			 "<<SIZE(char32_t)<<endl;*/
	cout<<"		short		 "<<"short integer		  "<<sizeof(short)<<"			 "<<SIZE(short)<<endl;
	cout<<"		int		 "<<"integer		  "<<sizeof(int)<<"			 "<<SIZE(int)<<endl;
	cout<<"		long		 "<<"long integer		  "<<sizeof(long)<<"			 "<<SIZE(long)<<endl;
	cout<<"		long long	 "<<"long long integer		"<<sizeof(long long)<<"			 "<<SIZE(long long)<<endl;
	cout<<"		float		 "<<"single precision floating point		  "<<sizeof(float)<<"			 "<<SIZE(float)<<endl;
	cout<<"		double		 "<<"doble precision floating point		  "<<sizeof(double)<<"			 "<<SIZE(double)<<endl;
	cout<<"		long double		 "<<"doble precision floating point		  "<<sizeof(double)<<"			 "<<SIZE(double)<<endl;
	
	
	return 0;
}
