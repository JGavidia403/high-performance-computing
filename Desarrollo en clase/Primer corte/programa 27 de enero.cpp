

/* Fecha : 27 de enero de 2022
   Autor: Jofre Eduardo Oliveros Gavidia
   Materia: HPC 6
   Tema: Uso de la clase vector */
   
   #include <iostream>
   #include <vector>
/* Se tiene una clase vector, que presenta 
   los metodos para acceder a posiciones 
   de cada vector y sus correspondientes 
   operaciones de creación (reserva de memoria),
   aritmetica, entre otras */
   using namespace std;
   
/*Se quiere crear na matriz usando vectores
  pero se requiere que los elementos sean 
  del tipo "double"*/
   
int main() {
	
	/*se crea un vector inicializado*/
	/**/
	
	vector<int> v(3);	 	
	cin>>v[0];
	cin>>v[1];
	cin>>v[2];
	cout<<v[0]<<endl;
	return 0;
}
