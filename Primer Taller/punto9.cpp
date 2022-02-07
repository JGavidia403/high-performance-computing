/*
  Fecha : 8-02-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Programa que calcula 
  		una secuencia númerica 
		de acuerdo a un patron
		especifico. Además imprime
		dicha secuencia de forma 
		piramidal         
  Materia : Hpc para IA 5
  
*/

#include <iostream>

using namespace std;

string espaciar(int n){
	
	string espacios="";
	for(int i=0;i<n;i++){
		
		espacios +="\t";
	}
	
	return espacios;
}

int main(){
	
	int aux =0;
	int filas=12;
	int aux_filas=filas;
	int cont;
	int cont2=0;
	int aux_2=0;
	int aux_3 =0;
	int cont3=0;
	int n_espacios;
	int aux_ =0;
	int cont_ =0;
	int kM = 0;
	int hM=0;
	int gM=0;
	
	cout<<"\n\n\n\n";
	for(int i =0; i<filas;i++){
		cout<<espaciar(aux_filas--);
			
			aux_2 = (2*i+1);
			aux_ = 2*cont_+1;
			cont_++;

			if((i+1)%5==0 && i!=0){
				aux_=9;
				cont_=0;
			}

		for(int j=0;j<aux_2;j++){
			//cuando j es par
			if(j%2==0){
				//aux_3 = aux_2 - ((aux_2-1)/2)+1
				if(j==(aux_2-1)/2){
					cout<<aux_<<"\t";
				}else if (j%2==0 && j!=(aux_2-1)/2 && i%2==0 && j<(aux_2-1)/2){
					cout<</*((aux_2-1)/2)+1*/"hm"<<"\t";
				}else if(j%2==0 && j!=(aux_2-1)/2 && i%2==0 && j>(aux_2-1)/2){
					
					if(aux_-kM-1<0){
						cout<<aux_-kM+10<<"\t";
					}else{
						cout<<aux_-kM<<"\t";
					}
					hM = hM+2;
				}else if(j%2==0 && j!=(aux_2-1)/2 && i%2!=0 && j<(aux_2-1)/2){
					cout<<"gm"<<"\t";
				}else if(j%2==0 && j!=(aux_2-1)/2 && i%2!=0 && j>(aux_2-1)/2){
					
					if(aux_-kM-1<0){
						cout<<aux_-kM-1+10<<"\t";
					}else{
						cout<<aux_-kM-1<<"\t";
					}
					gM = gM+2;
					
					
					
				}
			//cuando j es impar
			}else if(j%2!=0){
				
				if(j==(aux_2-1)/2){
					cout<<aux_<<"\t";
				}else if(j<(aux_2-1)/2){
					cout<<"km"<<"\t";
					/*km=km+2;*/
				}else if(j>(aux_2-1)/2 ){
					
					if(aux_-gM-1<0 && i%2!=0){
						cout<<aux_-gM+10<<"\t";
					}else if(aux_-hM-1<0 && i%2==0) {
						cout<<aux_-hM-1+10<<"\t";
					}else if(i%2==0) {
						cout<<aux_-hM-1<<"\t";
					}else if(i%2!=0) {
						cout<<aux_-gM<<"\t";
					}
					
					
					kM=kM+2;
				}
			}
		}
		gM=0;
		hM =0;
		kM=0;
		cont2++;
		cout<<"\n\n";
	}
	
	
	return 0; 
}
