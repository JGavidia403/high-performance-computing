/*
  Fecha : 8-02-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Programa que calcula 
  		la suma de los enteros
  		de una fecha         
  Materia : Hpc para IA 5
  
*/

#include<iostream>

using namespace std;

int sumarDigitos(int n){
	
	int aux;
	int i =0;
	int sum;
	int cont=1;
	
	while(n>0){
		
		aux=n%10;
		n = n/10;
		sum += aux;
		i++;
		if(n==0){
			n = sum;
			
			if(cont==3){
				break;
			}else{
				sum = 0;
			}
			cont++;
		}

	}
	
	return aux;
	
}
int calcular(int dia, int mes, int anio){
	
	if((dia>0 && dia<=31) && (mes>0 && mes<=12)
		 && (anio>0 && anio<=2022)){
		 	
		int aux = dia+mes+anio;
		int nums = sumarDigitos(aux);
		cout<<"\n\n>>> El número es : "<<nums;
		
	}else{
		cout<<"\nFormato de fecha o parámetros no validos\n";
	}
	 
	
}

int main(){
	setlocale(LC_ALL, "spanish");
	
	int dia,mes,anio;
	cout<<"\n>>> Ingrese los datos en formato númerico...\n\n";
	cout<<"\n- Ingrese el día \n\n      ";
	cin>>dia;
	cout<<"\n- Ingrese el mes \n\n      ";
	cin>>mes;
	cout<<"\n- Ingrese el año \n\n     ";
	cin>>anio;
	
	calcular(dia,mes,anio);
	
	return 0;
}
