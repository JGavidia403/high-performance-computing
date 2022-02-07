#include<iostream>

using namespace std;

int calcular_multiplos(int a, int b){
	
	if(a>0 && b>0){
		if(a>b){
		
			int aux = b;
			b = a;
			a = aux; 	
		}
		
		for(int i=a;i<=b;i++){
			if(i%5==0){
				
				cout<<"\n "<<i;
					
			}
		}
	}
}

int main(){
	
	int a,b;
	cout<<"\nIngrese el valor de a ";
	cin>>a;
	cout<<"\nIngrese el valor de b ";
	cin>>b; 
	
	calcular_multiplos(a,b);
	
	
	return 0;
}
