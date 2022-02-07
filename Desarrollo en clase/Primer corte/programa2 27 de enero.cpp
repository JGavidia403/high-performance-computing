

/* Fecha : 27 de enero de 2022
   Autor: Jofre Eduardo Oliveros Gavidia
   Materia: HPC 6
   Tema: Uso de la clase vector */
   
   #include <iostream>
   #include <vector>
   #include<random>
/* Se tiene una clase vector, que presenta 
   los metodos para acceder a posiciones 
   de cada vector y sus correspondientes 
   operaciones de creación (reserva de memoria),
   aritmetica, entre otras */
   using namespace std;
   
/*Se quiere crear na matriz usando vectores
  pero se requiere que los elementos sean 
  del tipo "double"*/
  
  
void imprimirmatrix( vector< vector<double> > Matrix){
	
	/*Se imprime la matriz*/
	
	int i,j;
			
	for(i=0; i<Matrix.size();i++){
		for(j=0; j<Matrix.size();j++){
		
			cout<<Matrix[i][j] <<" ";
				
	} 
		cout<<"  \n";
		} 
}

/*Se implementa la función de inicialización 
  de la matriz*/
  
vector< vector<double> > initMatrix(vector< vector<double> > Matrix){
	
	
	int i,j,k;
	
	/*Se inicializa la matriz, con números aleatorios*/
	
	float minAleatorio = 1.0001, maxAleatorio = 9.9999;
	random_device rd; /*Se usa para inicializar la semilla*/
	mt19937 gen(rd());
	uniform_real_distribution<> dis(minAleatorio, maxAleatorio);
	for(i=0; i<Matrix.size();i++){
		for(j=0; j<Matrix.size();j++){	
				Matrix[i][j] = dis(gen);
	} 
		} 
		
		return Matrix;
	
} 

/*Función para multiplicar las matrices*/


vector< vector<double> > multiMatrix(vector< vector<double> > Ma,
									vector< vector<double> > Mb){
	
	int i,j,k;
	
	vector< vector<double> > Mr(Ma.size(),vector<double>(Ma.size(),0));
	
		for(i=0; i<Ma.size();i++){
			for(j=0; j<Ma.size();j++){	
				for(k=0; k<Ma.size();k++){	
				
				Mr[i][j] += Ma[i][k]*Mb[k][j];
				
	} 
		} 
			} 
	
		
		return Mr;
	
} 


   
int main(int argc, char**argv) {
	
	/*Ingrese el tamaño de la matriz por argumento*/
	int N = atoi(argv[1]);
	
	
	/*se crea un vector inicializado*/
	/**/
	
	vector< vector<double> > M1(N,vector<double>(N,0));
	vector< vector<double> > M2(N,vector<double>(N,0));
	vector< vector<double> > MR(N,vector<double>(N,0));
	
	M1=initMatrix(M1);
	M2=initMatrix(M2);
	cout<<"*******************************************\n";
	imprimirmatrix(M1);
	cout<<"\n\n";
	cout<<"*******************************************\n";
	imprimirmatrix(M2);
	cout<<"\n\n";
	cout<<"*******************************************\n";
	
	MR = multiMatrix(M1,M2);
	imprimirmatrix(MR);
		



	return 0;
}
