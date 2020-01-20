#include <iostream>
using namespace std;

//prototipo
int suma(int num);



int main(){
    int num = 0;
    cout << "Suma de n digitos " <<endl;
    cout << "Ingrese la cantdad de digitos a sumar: ";
    cin >>  num;
    int contador = suma(num);
    cout << "El resultado es: " << contador <<endl;

}

//definicion
int suma(int num){
    int respuesta = 0;
   
    if(num == 1){
        cout << " Caso base: " << num  <<endl;
        respuesta = 1;
       
    }
    else{
        int a = num - 1;
        respuesta = num + suma(a);
    }
    return respuesta;
}