/*
  Fecha : 8-02-2022
  Autor : Jofre Eduardo Oliveros Gavidia
  Tema: Programa que calcula 
  		el centro númerico 
		de una lista de números         
  Materia : Hpc para IA 5
  
*/

#include <iostream>
#include <conio.h>
 
 using namespace std;
int main()
{
	int x,acu1,acu2;
   cout<<"\n\n\t\t\tCENTRO NUMERICO";
   cout<<"\n\nEl programa calcula los centros numericos entre 1 y n";
   cout<<"\n\n\nIngrese el maximo de la lista de enteros (n) : ";
   cin>>x;
   for(int i=1;i<=x;i++)
   {
   	acu1=acu2=0;
      for(int j=1;j<=i;j++) acu1+=j;
      for(int j=x;j>=i+2;j--) acu2+=j;
      if(acu1==acu2)
      {cout<<"\n\nEl centro numerico es: "<<(i+1); break;}
      if(acu1>acu2 || i==x-1 || x==1)
      {cout<<"\n\nNo existe centro numerico con la cifra dada"; break;}
   }
   getch();
   return 0;
}
