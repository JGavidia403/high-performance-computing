#include <iostream>

using namespace std;

double sumatoria(int b){
	
	double suma;
	int x=2,y=3;
	
	for(int a =0; a<=b;a++){
		
		cout<<"a es : "<<a<<"\n";
		suma += 1/(x+a*y);
		
		cout<<"la suma es : "<<suma<<"\n";
		 
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
