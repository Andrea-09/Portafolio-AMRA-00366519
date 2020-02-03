#include <iostream>
#include <string>
using namespace std;

enum genre{scifi, adventure, police, romance, mistery};

struct book{
    int ISBN;
    string title;
    string author;
    genre bookGenre;
    bool spanish;
};

struct node{
    book nodeBook;
    node* nextNode;
};
node* list;

book provideData();
void showData(book currentBook);
bool compareBook(book bookA, book bookB);
int countData();
void insertBegin(book addedBook);
void insertEnd(book addedBook);
void insertAfter(book addedBook);
void insertBefore(book addedBook);
void add();
void showAll();
void deleteBook();
void search();
void invertList(node **startingNode);
void emptyList(node** startingNode);
int countInstances();
book access();

string printGenre[] = {"Ciencia Ficcion", "Aventura", "Policia", "Romance", "Misterio"};
const book invalidBook = {0, "", "", scifi, false};

int main(){
    list = NULL;
    bool cont = true;
    do{
        int option = 0;
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
        cin >> option;
        cin.ignore();

        switch(option){
            case 1:
                add();
                break;
            case 2:
                showAll();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                search();
                break;
            case 5:
                invertList(&list);
                break;
            case 6:
                emptyList(&list);
                break;
            case 7:
                cout << "Hay " << countData() << " datos.\n";
                break;
            case 8:
                cout << "Esta " << countInstances() << " veces.\n";
                break;
            case 9:
                access();
                break;
            case 10:
                showSpanish();
                break;
            case 11:
                showMistery();
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

book provideData(){
    book currentBook;

    cout << "Ingrese el ISBN.\n";
    cin >> currentBook.ISBN;
    cin.ignore();
    cout << "Ingrese el titulo del libro.\n";
    getline(cin, currentBook.title);
    cout << "Ingrese el autor del libro.\n";
    getline(cin, currentBook.author);

    bool cont = true;
    do{
        char option = '0';
        cout << "Ingrese el genero:\n \tA- Ciencia Ficcion\n \tB- Aventura\n \tC- Policial\n \tD- Romance\n \tE- Misterio\n";
        cin >> option;
        cin.ignore();switch (option)
        {
        case 'a':
        case 'A':
            currentBook.bookGenre = scifi;
            cont = false;
            break;
        case 'b':
        case 'B':
            currentBook.bookGenre = adventure;
            cont = false;
            break;
        case 'c':
        case 'C':
            currentBook.bookGenre = police;
            cont = false;
            break;
        case 'd':
        case 'D':
            currentBook.bookGenre = romance;
            cont = false;
            break;
        case 'e':
        case 'E':
            currentBook.bookGenre = mistery;
            cont = false;
            break;
        default:
        cout << "Opcion no soportada.\n";
            break;
        }

        
    }while(cont);
    cont = true;
    do{
        char option = '0';
        cout << "Esta el libro en espanol? S/N\n";
        cin >> option;
        cin.ignore();
        switch(option){
            case 's':
            case 'S':
                currentBook.spanish = true;
                break;
            case 'n':
            case 'N':
                currentBook.spanish = false;
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }while(cont);

    return currentBook;
}

void showData(book currentBook){
    cout << "ISBN: " << currentBook.ISBN << endl;
    cout << "Titulo: " << currentBook.title << endl;
    cout << "Autor: " << currentBook.author << endl;
    cout << "Genero: " << printGenre[currentBook.bookGenre] << endl;
    cout << "Idioma: ";
    (currentBook.spanish) ? cout << "Espanol\n" : cout << "Otro\n";
}

bool compareBook(book bookA, book bookB){
    return (bookA.ISBN == bookB.ISBN) && (bookA.author == bookB.author) && (bookA.bookGenre == bookB.bookGenre) && (bookA.title == bookB.title) && (bookA.spanish == bookB.spanish);
}

int countData(){
    node* temp;

    int counter = 0;

    while(temp != NULL){
        temp = temp->nextNode;
        counter++;
    }

    return counter;
}

void insertBegin(book addedBook){
    node *newNode = new node;
    newNode->nodeBook = addedBook;
    newNode->nextNode = list;

    list = newNode;
}

void insertEnd(book addedBook){
    node *newNode;
    newNode->nodeBook = addedBook;
    newNode->nextNode = NULL;

    if(list == NULL){
        list = newNode;
    }
    else{
        node *temp1 = list;
        node *temp2 = NULL;
        while(temp1 != NULL){
            temp2 = temp1;
            temp1 = temp1->nextNode;
        }
        temp2->nextNode = newNode;
    }
}

void insertAfter(book addedBook){
    cout << "Libro a referenciar: ";
    book reference = provideData();

    node *temp = list;

    while(temp != NULL && !compareBook(temp->nodeBook, reference)){
        temp = temp->nextNode;
    }
    if(temp == NULL){
        cout << "El libro referenciado no existe.\n";
        return;
    }
    
    node *newNode = new node;
    newNode->nodeBook = addedBook;
    newNode->nextNode = temp->nextNode;

    temp->nextNode = newNode;

    cout << "Libro insertado exitosamente.\n";
}

void insertBefore(book addedBook){
    cout << "Libro a referenciar: ";
    book reference = provideData();

    node *temp = list;
    node *temp2 = NULL;

    while(temp != NULL && !compareBook(temp->nodeBook, reference)){
        temp2 = temp;
        temp = temp->nextNode;
    }
    if(temp == NULL){
        cout << "El libro referenciado no existe.\n";
        return;
    }
    
    node *newNode = new node;
    newNode->nodeBook = addedBook;
    newNode->nextNode = temp;

    if(temp2 == NULL){
        list = newNode;
    }
    else{
        temp->nextNode = newNode;
    }

    cout << "Libro insertado exitosamente.\n";
}

void add(){
    book currentBook = provideData();
    bool cont = true;
    do{
        int option = 0;
        cout << "\t1) Al principio\n";
        cout << "\t2) Al final\n";
        cout << "\t3) Despues de\n";
        cout << "\t4) Antes de\n";
        cout << "\tOpcion elegida: ";
        cin >> option;
        switch(option){
            case 1: 
                insertBegin(currentBook); 
                cont = false; 
                break;
            case 2: 
                insertEnd(currentBook); 
                cont = false; 
                break;
            case 3: 
                insertAfter(currentBook); 
                cont = false; 
                break;
            case 4: 
                insertBefore(currentBook); 
                cont = false; 
                break;
            default: 
                cout << "Error" << endl; 
                break;
        }
    }while(cont);
}

void showAll(){
    node *temp = list;

    while(temp != NULL){
        showData(temp->nodeBook);
        temp = temp->nextNode;
    }
}

void deleteBook(){
    cout << "Book to be deleted: ";
    book deletedBook = provideData();

    node *temp = list;
    node *temp2 = NULL;

    while(temp != NULL && !compareBook(temp->nodeBook, deletedBook)){
        temp2 = temp;
        temp = temp->nextNode;
    }
    if(temp == NULL){
        cout << "El libro a borrar no existe.\n";
        return;
    }
    if(temp2 == NULL){
        list = temp->nextNode;
    }
    else{
        temp2->nextNode = temp->nextNode;
    }
    delete(temp);
    cout << "Libro borrado exitosamente.\n";
}

void search(){
    cout << "Book to search for: ";
    book searchedBook = provideData();

    node *temp = list;

    while(temp != NULL && !compareBook(temp->nodeBook, searchedBook)){
        temp = temp->nextNode;
    }

    if(temp != NULL){
        cout << "El libro si existe.\n";
    }
    else{
        cout << "El libro no existe.\n";
    }
}

void invertList(node **startingNode){
    node* result = NULL;
    node* current = *startingNode;
    node* next;

    while(current != NULL){
        next = current->nextNode;
        current->nextNode = result;
        result = current;

        current = next;
    }
    *startingNode = result;
}

void emptyList(node** startingNode){
    node* current = *startingNode;
    node* next;

    while(current != NULL){
        next = current->nextNode;
        delete(current);
        current = next;
    }
    *startingNode = NULL;
}

int countInstances(){
    cout << "Book to search for: ";
    book searchedBook = provideData();

    node* current = list;
    int counter = 0;

    while(current != NULL){
        if(compareBook(current->nodeBook, searchedBook)){
            counter++;
        }
        current = current->nextNode;
    }
    return counter;
}

book access(){
    int index;
    cout << "Index to access.\n";
    cin >> index;
    cin.ignore();

    if(index >=0 && index < countData()){
        node *temp = list;
        for(int i = 0; i < index; i++){
            temp = temp->nextNode;
        }
        showData(temp->nodeBook);
        return temp->nodeBook;
    }
    else{
        cout << "Error, invalid index.\n";
        return invalidBook;
    }
}

void showSpanish(){
    int counter = 0;
    node* temp = list;
    while(temp != NULL){
        if((*temp).nodeBook.spanish){
            showData((*temp).nodeBook);
            counter++;
        }
    }
    if(counter == 0){
        cout << "No hay libros en espanol.\n";
    }
    cout << "Finalizado.\n";
}

void showMistery(){
    int counter = 0;
    node* temp = list;
    while(temp != NULL){
        if((*temp).nodeBook.bookGenre == mistery){
            showData((*temp).nodeBook);
            counter++;
        }
    }
    if(counter == 0){
        cout << "No hay libros en espanol.\n";
    }
    cout << "Finalizado.\n";
}

void deleteSciFi(){
    node* temp0 = NULL;
    node* temp1 = list;
    node* temp2;
    while(temp1 != NULL){
        if((*temp1).nodeBook.bookGenre == scifi){
            temp2 = temp1->nextNode;
            if(!(temp0))
                temp0->nextNode = temp2;
            else
                temp0 = temp2;
            delete(temp1);
            temp1 = temp2;
        }
        temp0 = temp1;
        temp1 = temp1->nextNode;
    }
}