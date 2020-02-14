#include <iostream>
#include <string>
using namespace std;

struct Puesto{
    string nombre;
    float salario;
};

// Funciones que dependen del tipo de dato de los nodos
Puesto solicitarDato(){
    Puesto unPuesto;
    cout << "Nombre del puesto: ";
    getline(cin, unPuesto.nombre);
    cout << "Salario: $";
    cin >> unPuesto.salario; cin.ignore();
    return unPuesto;
}
void mostrarDato(Puesto unPuesto){
    cout << "Nombre del puesto: " << unPuesto.nombre;
    cout << ". Salario: $" << unPuesto.salario;
}

enum comparacion{menorque,mayorque,igualque};

bool comparar(Puesto a, comparacion operador, Puesto b){
    bool resultado = false;
    switch(operador){
        case menorque: resultado = a.salario < b.salario; break;
        case mayorque: resultado = a.salario > b.salario; break;
        case igualque: resultado = a.salario == b.salario; break;
    }
    return resultado;
}


//------ Creacion de nodo y de arbol ------
typedef Puesto T;

struct Nodo{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void recorrerArbol(Arbol a);
void crearPersonalizado(Arbol p);

//Calcula la profundidad
int profundidad(Arbol a);

int main(){
    cout<<"Inicializando arbol...\nValor contenido en la raiz:\n";
    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nMenu: \n";
        cout << "\t1) Agregar\n";
        cout << "\t2) Recorrer\n";
        cout << "\t3) Calcular la profundidad del arbol\n";
        cout << "\t4) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion; cin.ignore();
        switch(opcion){
            case 1: agregarNodo(arbol); break;
            case 2: recorrerArbol(arbol); break;
            case 3: profundidad(arbol); break;
            case 4: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
    
    return 0;
}

// Implementacion de funciones de arboles
Arbol crearArbol(T x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (dato a agregar)
    cout << "Dato a agregar:\n";
    T unDato = solicitarDato();
    
    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        if(comparar(unDato, igualque, p->info)){
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        else if(comparar(unDato, menorque, p->info)){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    //agregar el nuevo nodo
    if(comparar(unDato, menorque, p->info))
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << "\n"; mostrarDato(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << "\n"; mostrarDato(a->info);
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << "\n"; mostrarDato(a->info);
    }
}

void recorrerArbol(Arbol a){
    cout << "\nRecorrido PRE orden:-----"; preorden(a); cout << endl;
    cout << "\nRecorrido IN orden:-----"; inorden(a); cout << endl;
    cout << "\nRecorrido POST orden:-----"; postorden(a); cout << endl;
}

//Calcula la profundidad del arbol
int profundidad(Arbol a){
    
    if(a = NULL){
        return 0;   //Si el arbol esta vacio entonces retorna null
    }
    else{
        int lDepth = profundidad(a -> izq);  //Caso contrario, lDepth va almacenar lo que este a la izquierda
        int rDepth = profundidad(a ->der);   //rDepth almacena lo que este a la derecha

        if (lDepth > rDepth)    //Si lDepth es mayor que rDepth
            return(lDepth + 1);  //Retorna lDepth + 1
        else return(rDepth + 1);  //rDepth + 1
    }   
    return profundidad(a);
}

