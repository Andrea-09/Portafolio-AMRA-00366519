#include <iostream>
#include <string>
using namespace std;

enum genero{scifi, aventura, policiaco, romance, misterio};

struct libros{
    int ISBN;
    string titulo;
    string autor;
    genero generoLibro;
    bool espanol;
};

struct nodo{
    libros nodoLibro;
    nodo* siguiente;
};
nodo* lista;

libros ingresar();
void mostrarDatos(libros Libro);
bool comparar(libros Libro1, libros Libro2);
int contador();
void insertaInicio(libros nuevoLibro);
void insertarFinal(libros nuevoLibro);
void insertaDespues(libros nuevoLibro);
void insertarAntes(libros nuevoLibro);
void agregar();
void mostrarTodos();
void eliminar();
void buscar();
void invertir(nodo** pInicio);
void vaciar(nodo** pInicio);
int contarCoincidencias();
libros accesar();

string MostrarGenero[] = {"Ciencia Ficcion", "Aventura", "Policia", "romance", "Misterio"};


int main(){
    lista = NULL;
    bool cont = true;
    do{
        int opcion = 0;
        cout << "Menu:\n";
        cout << "\t1. Agregar\n";
        cout << "\t2. Mostrar todos\n";
        cout << "\t3. Eliminar\n";
        cout << "\t4. Buscar\n";
        cout << "\t5. Invertir\n";
        cout << "\t6. Vaciar\n";
        cout << "\t7. Cantidad\n";
        cout << "\t8. Contar Ocurrencias\n";
        cout << "\t9. Acceder\n";
        cout << "\t10. Mostrar libros en espanol\n";
        cout << "\t11. Mostrar libros de misterio\n";
        cout << "\t12. Remover todos los libros de ciencia ficcion\n";
        cout << "\t0. Salir\n";
        cout << "Su opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1:
                agregar();
                break;
            case 2:
                mostrarTodos();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                buscar();
                break;
            case 5:
                invertir(&lista);
                break;
            case 6:
                vaciar(&lista);
                break;
            case 7:
                cout << "Datos: " << contador() << endl;
                break;
            case 8:
                cout << "Exite " << contarCoincidencias() << " veces.\n";
                break;
            case 9:
                accesar();
                break;
            case 10:
                showespanol();
                break;
            case 11:
                showmisterio();
                break;
            case 12:
                deleteSciFi();
                break;
            case 0:
                cont = false;
                break;
            default:
                cout << "Error\n";
                break;
        }
    }while(cont);

    return 0;
}

libros ingresar(){
    libros Libro;

    cout << "Ingrese el ISBN.\n";
    cin >> Libro.ISBN;
    cin.ignore();
    cout << "Ingrese el titulo del libro.\n";
    getline(cin, Libro.titulo);
    cout << "Ingrese el autor del libro.\n";
    getline(cin, Libro.autor);

    bool cont = true;
    do{
        char opcion = '0';
        cout << "Ingrese el genero: (A- Ciencia Ficcion, B- Aventura, C- Policial, D- romance, E- Misterio)\t";
        cin >> opcion;
        cin.ignore();switch (opcion)
        {
        case 'a':
        case 'A':
            Libro.generoLibro = scifi;
            cont = false;
            break;
        case 'b':
        case 'B':
            Libro.generoLibro = aventura;
            cont = false;
            break;
        case 'c':
        case 'C':
            Libro.generoLibro = policiaco;
            cont = false;
            break;
        case 'd':
        case 'D':
            Libro.generoLibro = romance;
            cont = false;
            break;
        case 'e':
        case 'E':
            Libro.generoLibro = misterio;
            cont = false;
            break;
        default:
        cout << "Opcion invalida.\n";
            break;
        }

        
    }while(cont);
    cont = true;
    do{
        char opcion = '0';
        cout << "Esta el libro en espanol? S/N\n";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
            case 's':
            case 'S':
                Libro.espanol = true;
                break;
            case 'n':
            case 'N':
                Libro.espanol = false;
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    }while(cont);

    return Libro;
}

void mostrarDatos(libros Libro){
    cout << "ISBN: " << Libro.ISBN << endl;
    cout << "Titulo: " << Libro.titulo << endl;
    cout << "Autor: " << Libro.autor << endl;
    cout << "Genero: " << MostrarGenero[Libro.generoLibro] << endl;
    cout << "Idioma: ";
    (Libro.espanol) ? cout << "Espanol\n" : cout << "Otro\n";
}

bool comparar(libros Libro1, libros Libro2){
    return (Libro1.ISBN == Libro2.ISBN) && (Libro1.autor == Libro2.autor) && (Libro1.generoLibro == Libro2.generoLibro) && (Libro1.titulo == Libro2.titulo) && (Libro1.espanol == Libro2.espanol);
}

int contador(){
    nodo* aux;

    int Contador = 0;

    while(aux != NULL){
        aux = aux->siguiente;
        Contador++;
    }

    return Contador;
}

void insertaInicio(libros nuevoLibro){
    nodo *newnodo = new nodo;
    newnodo->nodoLibro = nuevoLibro;
    newnodo->siguiente = lista;

    lista = newnodo;
}

void insertarFinal(libros nuevoLibro){
    nodo *newnodo;
    newnodo->nodoLibro = nuevoLibro;
    newnodo->siguiente = NULL;

    if(lista == NULL){
        lista = newnodo;
    }
    else{
        nodo *aux1 = lista;
        nodo *aux2 = NULL;
        while(aux1 != NULL){
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        aux2->siguiente = newnodo;
    }
}

void insertaDespues(libros nuevoLibro){
    cout << "Ingrese el libro que desea referenciar: ";
    libros referencia = ingresar();

    nodo *aux = lista;

    while(aux != NULL && !comparar(aux->nodoLibro, referencia)){
        aux = aux->siguiente;
    }
    if(aux == NULL){
        cout << "El libro no existe." << endl;
        return;
    }
    
    nodo *newnodo = new nodo;
    newnodo->nodoLibro = nuevoLibro;
    newnodo->siguiente = aux->siguiente;

    aux->siguiente = newnodo;

    cout << "Libro insertado exitosamente.\n";
}

void insertarAntes(libros nuevoLibro){
    cout << "Ingrese el nombre del libro: ";
    libros referencia = ingresar();

    nodo *aux = lista;
    nodo *aux2 = NULL;

    while(aux != NULL && !comparar(aux->nodoLibro, referencia)){
        aux2 = aux;
        aux = aux->siguiente;
    }
    if(aux == NULL){
        cout << "El libro no existe.\n";
        return;
    }
    
    nodo *newnodo = new nodo;
    newnodo->nodoLibro = nuevoLibro;
    newnodo->siguiente = aux;

    if(aux2 == NULL){
        lista = newnodo;
    }
    else{
        aux->siguiente = newnodo;
    }

    cout << "Libro insertado exitosamente.\n";
}

void agregar(){
    libros Libro = ingresar();
    bool cont = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n";
        cout << "\t2) Al final\n";
        cout << "\t3) Despues de\n";
        cout << "\t4) Antes de\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: 
                insertaInicio(Libro); 
                cont = false; 
                break;
            case 2: 
                insertarFinal(Libro); 
                cont = false; 
                break;
            case 3: 
                insertaDespues(Libro); 
                cont = false; 
                break;
            case 4: 
                insertarAntes(Libro); 
                cont = false; 
                break;
            default: 
                cout << "Adios" << endl; 
                break;
        }
    }while(cont);
}

void mostrarTodos(){
    nodo *aux = lista;

    while(aux != NULL){
        mostrarDatos(aux->nodoLibro);
        aux = aux->siguiente;
    }
}

void eliminar(){
    cout << "Ingrese el libro que desea borrar: ";
    libros eliminados = ingresar();

    nodo *aux = lista;
    nodo *aux2 = NULL;

    while(aux != NULL && !comparar(aux->nodoLibro, eliminados)){
        aux2 = aux;
        aux = aux->siguiente;
    }
    if(aux == NULL){
        cout << "El libro no existe.\n";
        return;
    }
    if(aux2 == NULL){
        lista = aux->siguiente;
    }
    else{
        aux2->siguiente = aux->siguiente;
    }
    delete(aux);
    cout << "Libro borrado exitosamente.\n";
}

void buscar(){
    cout << "Que libro desea buscar?: ";
    libros buscaredlibros = ingresar();

    nodo *aux = lista;

    while(aux != NULL && !comparar(aux->nodoLibro, buscaredlibros)){
        aux = aux->siguiente;
    }

    if(aux != NULL){
        cout << "Libro encontrado." << endl;
    }
    else{
        cout << "No se encontro el libro" << endl;
    }
}

void invertir(nodo **pInicio){
    nodo* resultado = NULL;
    nodo* actual = *pInicio;
    nodo* sig;

    while(actual != NULL){
        sig = actual->siguiente;
        actual->siguiente = resultado;
        resultado = actual;

        actual = sig;
    }
    *pInicio = resultado;
}

void vaciar(nodo** pInicio){
    nodo* actual = *pInicio;
    nodo* sig;

    while(actual != NULL){
        sig = actual->siguiente;
        delete(actual);
        actual = sig;
    }
    *pInicio = NULL;
}

int contarCoincidencias(){
    cout << "Ocurrencias: ";
    libros buscaredlibros = ingresar();

    nodo* actual = lista;
    int Contador = 0;

    while(actual != NULL){
        if(comparar(actual->nodoLibro, buscaredlibros)){
            Contador++;
        }
        actual = actual->siguiente;
    }
    return Contador;
}

libros accesar(){
    int index;
    cout << "Plantilla de acceso." << endl;
    cin >> index;
    cin.ignore();

    if(index >=0 && index < contador()){
        nodo *aux = lista;
        for(int i = 0; i < index; i++){
            aux = aux->siguiente;
        }
        mostrarDatos(aux->nodoLibro);
        return aux->nodoLibro;
    }
    else{
        cout << "Error" << endl;
    }
}

void showespanol(){
    int Contador = 0;
    nodo* aux = lista;
    while(aux != NULL){
        if((*aux).nodoLibro.espanol){
            mostrarDatos((*aux).nodoLibro);
            Contador++;
        }
    }
    if(Contador == 0){
        cout << "No hay libros en espanol.\n";
    }
    cout << "Finalizado.\n";
}

void showmisterio(){
    int Contador = 0;
    nodo* aux = lista;
    while(aux != NULL){
        if((*aux).nodoLibro.generoLibro == misterio){
            mostrarDatos((*aux).nodoLibro);
            Contador++;
        }
    }
    if(Contador == 0){
        cout << "No hay libros en espanol.\n";
    }
    cout << "Finalizado.\n";
}

void deleteSciFi(){
    nodo* aux0 = NULL;
    nodo* aux1 = lista;
    nodo* aux2;
    while(aux1 != NULL){
        if((*aux1).nodoLibro.generoLibro == scifi){
            aux2 = aux1->siguiente;
            if(!(aux0))
                aux0->siguiente = aux2;
            else
                aux0 = aux2;
            delete(aux1);
            aux1 = aux2;
        }
        aux0 = aux1;
        aux1 = aux1->siguiente;
    }
}