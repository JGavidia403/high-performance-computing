/*
  Fecha : 8-02-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Programa que imprime
  		una secuencia de números
		de forma decreciente    
  Materia : Hpc para IA 5
  
*/

#include <iostream>

using namespace std;

int main(){
	
	int x=0,y=0;
	for(x=6; x>0;x-=2){
		for(y=0;y<2;y++){
			cout<<"\n"<<(x-y);
		}
	}
}
