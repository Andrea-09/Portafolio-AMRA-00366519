#include <iostream>
using namespace std;
void encontrar(int *i, int *f, int n){
	if(i < f){
		if(*i == n){
			cout<<*i<<" es igual al numero buscado\n";
			cout<<"\nSe encontro el numero\n";
		}else{
			cout<< *i <<" no es igual a " << n << endl;
			encontrar(i + 1, f, n);
		}
	}else{
		cout<<"\nNo se encontro el numero\n";
	}
}
int main() {
	int arr[10], numero;
	cout<<"Arreglo\n";
	for(int i = 0; i < 10; i++){
		cout<<"Ingrese el "<<i+1<<" valor: ";
		cin>>arr[i];
	} 
	cout<<"\nIngrese el numero a buscar: ";
	cin>>numero;
	encontrar(arr, arr + 10, numero);
	return 0;
}