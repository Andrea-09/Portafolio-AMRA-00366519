#include <iostream>
#include <string>
using namespace std;

struct pais{
string nombre;
string capital;
int habitantes;
};
struct pais continente[5];
int suma = 0;

//Prototipo ingresoDatos
void ingresoDatos();
//Prototipo sumaPoblacion
int sumaPoblacion(struct pais *punt, int suma);
//Prototipo mayorPoblacion
void mayorPoblacion(struct pais *punt);

//Inicio
int main (){
ingresoDatos();    

    

    return 0;
    
}

//Definicion ingresoDatos
void ingresoDatos(){
    for(int i = 0; i < 5; i++){
        cout<<"Ingrese el nombre de un pais: ";
    getline (cin, continente[i].nombre);

    cout<<"Ingrese el nombre de la capital: ";
    getline (cin, continente[i].capital);

    cout<<"Ingrese el numero de habitantes: ";
    cin>>continente[i].habitantes;
    cin.ignore();
    }


//Definicion sumaPoblacion
int sumaPoblacion(struct pais *punt, int suma){
    for(int i = 0; i < 5; i++){
        suma += continente[i].habitantes;
        cout << "La suma total de la poblacion es: " << suma << endl;
    }
}

//Definicion mayorPoblacion
void mayorPoblacion(struct pais *punt){
    for(int i = 0; i < 5; i++){
        if(continente[i].habitantes > )
    }
}

