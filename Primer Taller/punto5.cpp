#include<iostream>

using namespace std;

void fnx(int x){
	
	if(x){
		cout<<"\n"<<x;
	}
}

int main(){
	
	int i,a =12345;
	
	for(i=0;i<4;i++){
		fnx(a=a/10);
	}
	
	
	return 0;
}
