#include <iostream>

using namespace std;

int main(){


   int t, km, toneladas;
   cout <<"Elige el medio de transporte" << endl;
   cout <<"(1) Bicicleta" << endl;
   cout <<"(2) Moto" << endl;
   cout <<"(3) Auto" << endl;
   cout <<"(4) Camion" << endl;
   cin >>t;

   if(t == 1){

       cout <<"Digita los Km recorridos" <<endl;

       cin>>km;

       cout<<"El total a pagar es:"<<km * 100<<endl;

       }else{

           if (t == 2 || t == 3){

               cout <<"Digita los Km recorridos" <<endl;

               cin>>km;

               cout<<"El total a pagar es:"<<km * 300<<endl;

           }else{

               cout <<"Teclea las toneladas del camion" <<endl;

               cin>>toneladas;

               cout <<"Digita los Km recorridos" <<endl;

               cin>>km;

               cout<<"El total a pagar es:"<<(km * 300)+(toneladas*250)<<endl;

    		}
		}
		
		return 0;
}
