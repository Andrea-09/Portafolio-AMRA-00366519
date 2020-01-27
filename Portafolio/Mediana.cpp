#include<iostream>
using namespace std;

float mediana(int a[], int tamano){
	int mediana;
	int b = 0;
	int c = 0;
	b = tamano/2;
	c = b+1;
	mediana = (a[b-1] + a[c-1]) / 2; 
	return mediana;
	
}

int main(){
	
	int a[6] = {2,3,6,8,10,14};
	int tamano = 6;
	int med = mediana(a, tamano);
	cout << "La mediana es: " << med;
	return 0;
}
