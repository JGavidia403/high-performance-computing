/*
  Fecha : 8-02-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Programa que calcula 
  		una sumatoria desde
		i = 0 hasta n        
  Materia : Hpc para IA 5
  
*/

#include <iostream>

using namespace std;

double sumatoria(int b){
	
	double suma;
	int x=2,y=3;
	
	for(int a =0; a<=b;a++){
		
		suma += 1/(x+a*y);
		 
	}
	
	return suma;
	
}
int main(){
	
	int limit;
	cout<<"- Ingrese el limite de la sumatoria \n";
	cin>>limit;
	cout<<"Resultado de la sumatoria desde a = 0 hasta b = "<<limit<<" :\n  "<<sumatoria(limit);
	
	
	
	return 0;
}
