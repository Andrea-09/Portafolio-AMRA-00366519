#include <iostream>
#include <string>
using namespace std;

struct Pedido{
    string apellido;
    int mesa;
    int sushiCalifornia;
    int sushiPhiladelphia;
    int sushiTempura;
};

// Tipo de dato que contendran los nodos de la Cola
typedef Pedido unPedido;
const unPedido noValido = {{" "},-1,-1,-1,-1,};

// Registros: nodo y Cola
struct Nodo{
    unPedido elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

// Prototipos de funciones para Cola
void initialize(Cola *p);
bool empty(Cola *p);
unPedido front(Cola *p);
unPedido back(Cola *p);
void enqueue(Cola *p, unPedido x);
unPedido dequeue(Cola *p);
int size(Cola *p);

struct Sushi{
    Cola colaPedidos;
    int pedidosHechos;
};
 Sushi Soho;

void agregarPedidos();
void consultar();
void Despachar();


int main(){
    initialize(&Soho.colaPedidos);
    Soho.pedidosHechos = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregarPedidos(); break;
            case 2: consultar(); break;
            case 3: Despachar(); break;
            case 4: continuar = false; break;
            default: cout << "Opcion invalida"; break;
        }
    }while(continuar);

    return 0;
}

// Implementacion de funciones
void initialize(Cola *p){
    p->frente = NULL;
    p->final = NULL;
}

bool empty(Cola *p){
    return (p->frente==NULL) ? true : false;
}

unPedido front(Cola *p){
    if(empty(p)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (p->frente)->elemento;
}

unPedido back(Cola *p){
    if(empty(p)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (p->final)->elemento;
}

void enqueue(Cola *p, unPedido x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(p->final==NULL)
        p->frente = unNodo;
    else
        (p->final)->siguiente = unNodo;
        
    p->final = unNodo;
}

unPedido dequeue(Cola *p){
    if(empty(p)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = p->frente;
    unPedido x = unNodo->elemento;
    p->frente = unNodo->siguiente;
    if(p->frente==NULL)
        p->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *p){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    // Transfiriendo desde p hasta colaTemporal
    while(!empty(p)){
        unPedido elemento = dequeue(p);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta p
    while(!empty(&colaTemporal)){
        unPedido elemento = dequeue(&colaTemporal);
        enqueue(p, elemento);
    }
    return contador;
}

// Funciones 
void agregarPedidos(){
    // Solicitar datos del pedido
    Pedido unPedido;
    cout << "Digite el apellido de la familia: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Rollos California: "; cin >> unPedido.sushiCalifornia; cin.ignore();
    cout << "Rollos Philadelphia: "; cin >> unPedido.sushiPhiladelphia; cin.ignore();
    cout << "Rollos Tempura: "; cin >> unPedido.sushiTempura; cin.ignore();
    
    // Agregar a la cola
    enqueue(&Soho.colaPedidos, unPedido);
    // Modificar contadores
    Soho.pedidosHechos += (unPedido.sushiCalifornia+unPedido.sushiPhiladelphia+unPedido.sushiTempura);
}

void consultar(){
    cout << "Pedidos en espera: " << size(&Soho.colaPedidos) << endl;
    cout << "Pedidos terminados: " << Soho.pedidosHechos << endl;
}

void Despachar(){
    Pedido pedidoDespachado = dequeue(&Soho.colaPedidos);
    cout << "El pedido de la familia " << pedidoDespachado.apellido << " esta listo"<<endl;
    cout << "Servir a la mesa " << pedidoDespachado.mesa << endl;
}


