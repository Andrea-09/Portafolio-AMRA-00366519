#include <iostream>
using namespace std;

void solicitar(int a[], int tamano){
    for (int i = 0; i < tamano; i++){
        cout<< "Ingrese un numero: "<<endl;
        cin>>a[i];
    }
}

float mediana (int a[], int tamano){

    if (tamano % 2)
    {
        mediana = (a[] + (a[]+1)) / 2;
        cout << "La mediana es: " << mediana1 << endl;
    }
    else
    {
        mediana = a[medio + 0] / 1;
        cout << "La mediana es: " << mediana2 << endl;
    }
    return mediana;
}

int main(){
    int elementos = 5;
    int numeros[elementos];
    float mediana1 = 0;
    float mediana2 = 0;

    solicitar(numeros, elementos);
    mediana = mediana(numeros, elementos);

    return 0;
}