#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct cajas{
    string contenido;
    int peso;
    string tipo;
};
typedef struct cajas Cajas;

int main(){
    // 1) Creando pila de cajass vacia -------------
    stack<cajas> pilaDecajas;
    
    // 2) Apilando cajass --------------------------
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de cajas actual: " << pilaDecajas.size();
        cout << "\nDesea apilar otro caja? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            cajas unasCajas;
            cout << "Contenido: "; getline(cin, unasCajas.contenido);
            cout << "Peso: "; cin >> unasCajas.peso;
            cout << "Tipo: "; getline(cin, unasCajas.tipo);
            pilaDecajas.push(unasCajas); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    while(!pilaDecajas.empty()){
        // Obtener el cajas de encima (sin sacarlo de la pila)
        cajas cajasDeEncima = pilaDecajas.top();
        cout << "cajas [" << cajasDeEncima.contenido;
        cout << ", " << cajasDeEncima.peso;
        cout << ", " << cajasDeEncima.tipo << "]\n";
        
        // Sacando cajas de la pila
        pilaDecajas.pop();
    }
    cout << "Pila de cajass vacia." << endl;

    return 0;
}

