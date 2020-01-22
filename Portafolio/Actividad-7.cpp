#include <iostream>
#include <string>
using namespace std;

struct cajas{
    string contenido;
    int peso;
    string tipo;
};
typedef struct cajas unasCajas;


struct nodo{
    unasCajas elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void Push(Pila *s, unasCajas e);
unasCajas pop(Pila *s);
unasCajas top(Pila *s);


int main(){
   
    Pila pilaDecajas;
    initialize(&pilaDecajas);
   
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nDesea apilar una caja? (s/n): ";
        cin >> opcion; cin.ignore();
       
        if(opcion == 's'){
            unasCajas Cajas;
            cout << "Contenido: "; getline(cin, Cajas.contenido);
            cout << "Peso: "; cin >> Cajas.peso;
            cin.ignore();
            cout << "Tipo: "; getline(cin, Cajas.tipo);
            Push(&pilaDecajas, Cajas);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
   
    while(!empty(&pilaDecajas)){
         unasCajas cajasdeEncima = top(&pilaDecajas);
            cout << "cajas [" << cajasdeEncima.contenido;
            cout << ", " << cajasdeEncima.peso;
            cin.ignore();
            cout << ", " << cajasdeEncima.tipo << "]\n";
           
            pop(&pilaDecajas);
           
            cout << "Pila de cajas vacia" << endl;
    }
   
    return 0;
}


//Funcion de inicializar
void initialize(Pila *s){
    *s = NULL;
}


//Funcion de empty
bool empty(Pila *s){
    return *s == NULL;
}

//Funcion de Push
void Push(Pila *s, unasCajas e){
    struct nodo *unNodo = new struct nodo;
    unNodo -> elemento = e;
    unNodo -> siguiente = *s;
    *s = unNodo;
}

//Funcion de pop
unasCajas pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        unasCajas e = (*s) -> elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else{
        cout << "Underflow!" <<endl;
       
    }
}

//Funcion de top
unasCajas top(Pila *s){
    if(!empty(s)){
        return (*s)->elemento;
    }
       
    else{
        cout << "Underflow!" <<endl;
       
    }
       
}
