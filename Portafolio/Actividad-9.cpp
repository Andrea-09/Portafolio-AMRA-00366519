#include <iostream>
#include <queue>
#include <string> 

using namespace std;

struct actividad{
    string nombre;
    string tiempo;
    int duracion;
    string descripcion;
    char tipo;
};
typedef struct actividad Act;

struct agenda{
    queue <actividad> toDoList;
};
typedef struct agenda Agenda;

Agenda personalAgenda;

void agregar();
void borrar();
void borrarTodas();
void mostrarTodas();


int main(){
    bool cont = true;
    do{
        int option = 0;
        cout << "\t1. Insertar una actividad.\n";
        cout << "\t2. Borrar una actividad.\n";
        cout << "\t3. Borrar todas las actividades.\n";
        cout << "\t4. Ver todas las actividades.\n";
        cout << "\t5. Salir.\n";
        cin >> option;
        cin.ignore();

        switch(option){
        case 1:
            agregar();
            break;
        case 2:
            borrar();
            break;
        case 3:
            borrarTodas();
            break;
        case 4:
            mostrarTodas();
            break;
        case 5:
            cont = false;
            break;
        default:
            break;
        }
    }while(cont == true);


    return 0;
}

void agregar(){
    Act nuevaActividad;
    cout << "Digite el nombre de la actividad.\n";
    getline(cin, nuevaActividad.nombre);
    cout << "Digite la hora de la actividad.\n";
    getline(cin, nuevaActividad.tiempo);
    cout << "Ingrese la duracion de la actividad.\n";
    cin >> nuevaActividad.duracion;
    cin.ignore();
    cout << "Ingrese una descripcion de la actividad.\n";
    getline(cin, nuevaActividad.descripcion);
    cout << "Ingrese el tipo de la actividad.\n \tE - Educacion\t R - Recreacion\n";
    cin >> nuevaActividad.tipo;

    personalAgenda.toDoList.push(nuevaActividad);
}

void borrar(){
    if(!personalAgenda.toDoList.empty()){
        Act current = personalAgenda.toDoList.front();
        cout << "La actividad a borrar es: \n";
        cout << "Nombre: " << current.nombre << endl;
        cout << "Hora: " << current.tiempo << endl;
        cout << "Duracion: " << current.duracion << endl;
        cout << "Descripcion: " << current.descripcion << endl;
        cout << "Tipo: " << current.tipo << endl;
        personalAgenda.toDoList.pop();
    }
    else{
        cout << "ESTA VACIO" << endl;
    }
}

void borrarTodas(){
    if(personalAgenda.toDoList.empty()){
        cout << "ESTA VACIO" << endl;
    }
    while(!personalAgenda.toDoList.empty()){
        Act current = personalAgenda.toDoList.front();
        cout << "La actividad a borrar es: \n";
        cout << "Nombre: " << current.nombre << endl;
        cout << "Hora: " << current.tiempo << endl;
        cout << "Duracion: " << current.duracion << endl;
        cout << "Descripcion: " << current.descripcion << endl;
        cout << "Tipo: " << current.tipo << endl;
        personalAgenda.toDoList.pop();
    }
}

void mostrarTodas(){
    Agenda T;
    if(personalAgenda.toDoList.empty()){
        cout << "ESTA VACIO" << endl;
    }
    while(!personalAgenda.toDoList.empty()){
        Act current = personalAgenda.toDoList.front();
        T.toDoList.push(current);
        cout << "La actividad es: \n";
        cout << "Nombre: " << current.nombre << endl;
        cout << "Hora: " << current.tiempo << endl;
        cout << "Duracion: " << current.duracion << endl;
        cout << "Descripcion: " << current.descripcion << endl;
        cout << "Tipo: " << current.tipo << endl;
        personalAgenda.toDoList.pop();
    }
    while(!T.toDoList.empty()){
        Act current = T.toDoList.front();
        personalAgenda.toDoList.push(current);
        T.toDoList.pop();
    }
}