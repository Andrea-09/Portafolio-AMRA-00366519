#include <iostream>
using namespace std;

//Prototipo de funcion
void pedirDatos();
int **puntero_matriz1,**puntero_matriz2;
int nFilas;
int nCol;
void mostrarMatrizResultado(int **puntero_matriz1, int nFilas, int nCol);
void sumarMatrices(int **puntero_matriz1, int **puntero_matriz2, int nFilas, int nCol);


int main(){

pedirDatos();
sumarMatrices(puntero_matriz1, puntero_matriz2, nFilas, nCol);
mostrarMatrizResultado(puntero_matriz1, nFilas, nCol);

    return 0;
}

//Definicion de funcion
void pedirDatos(){
    cout<< "Ingrese el numero de filas: "<<endl; 
    cin>>nFilas;
    cout<< "Ingrese el numero de columnas: "<< endl;
    cin>>nCol; 

//Resereva de memoria para la primera matriz
    puntero_matriz1 = new int*[nFilas];
    for (int i =0; i < nFilas; i++){
        puntero_matriz1[i] = new int[nCol];
    }

    cout<< "Digite los elementos de la primera matriz: "<< endl;
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            cout<< "Digite un numero["<<i<<"]["<<j<<"]: "<<endl;
            cin >> *(*(puntero_matriz1+i)+j);   //puntero_matriz1[i][j]
        }
    }

//Reservar memoria para la segunda matriz
    puntero_matriz2 = new int*[nFilas];
    for (int i =0; i < nFilas; i++){
        puntero_matriz2[i] = new int[nCol];
    }

    cout<< "Digite los elementos de la segunda matriz: "<< endl;
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            cout<< "Digite un numero["<<i<<"]["<<j<<"]: "<<endl;
            cin >> *(*(puntero_matriz2+i)+j);   //puntero_matriz2 [i][j]
        }
    }
}

//Definicion de funcion de suma
void sumarMatrices(int **puntero_matriz1, int **puntero_matriz2, int nFilas, int nCol){
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            *(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
        }
    }
}

//Definicion de funcion de mostrar el resultado
void mostrarMatrizResultado(int **puntero_matriz1, int nFila, int nCol){
    cout<< "La suma de las dos matrices es: "<<endl;

    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            cout << *(*(puntero_matriz1+i)+j)<< " | "; //puntero_matriz[i][j]
        }
        cout<<endl;
    }
}