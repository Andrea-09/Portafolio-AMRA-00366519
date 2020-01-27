#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct insertarActividad{
  string Titulo;
  string Hora;
  int Duracion;
  string Descripcion;
  string Tipo;
};
typedef struct insertarActividad Actividad;

struct agenda{
    queue <Actividad> colaToDo;
};

agenda agendaPersonal;

void Insertar();
void VerActividades();
void borrarUna();
void borrarTodas();


int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar una actividad\n";
        cout << "2) Ver las actividades\n";
        cout << "3) Borrar una actividad\n";
        cout << "4) Borrar todas las actividades\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
       
        switch(opcion){
            case 1: Insertar(); break;
            case 2: VerActividades(); break;
            case 3: borrarUna(); break;
            case 4: borrarTodas(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);
}



void Insertar(){
    Actividad unaActividad;
    cout << "Ingrese su actividad del dia: ";
    getline(cin, unaActividad.Titulo);
    cout << "Ingrese la hora de su actividad: ";
    getline(cin, unaActividad.Hora);
    cout << "Cuanto dura su actividad?";
    cin >> unaActividad.Duracion;
    cin.ignore();
    cout << "Ingrese una descripcion de su actividad: ";
    getline(cin, unaActividad.Descripcion);
    cout << "Su actividad es de tipo: ";
    getline(cin, unaActividad.Tipo);
   
    //Agregar a la cola
    agendaPersonal.colaToDo.push(unaActividad);
}

void VerActividades(){
    cout << "Actividades del dia: " << agendaPersonal.colaToDo.size() <<endl;
   
}

void borrarUna(){
    int op;
    cout << "Desea borrar una actividad? Digite 1 para hacerlo o digite 2 para cancelar." << endl;
    cin >> op;
    if(op == 1){
        agendaPersonal.colaToDo.pop();
        cout << "Se ha borado la actividad" << endl;
      }
    }


void borrarTodas(){
    int op;
    cin >> op;
    cout << "Desea borrar todas las actividades? Digite 1 para hacerlo o digite 2 para cancelar." <<endl;
    if(op == 1){
        agendaPersonal.colaToDo.pop();
        cout << "Se han borrado todas las actividades" << endl;
    }
  }

//sNada mas arreglar la funcion de borrar todas y checkear la de mostrar todas
