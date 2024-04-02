#include <iostream>
#include <vector>
using namespace std;

struct Contacto{
    string nombre;
    string email;
    char telefonos[3][50];
    char direcciones[2][50];
    string notas;
};

//Funcion responsable de crear un nuevo contacto
void agregarUnContacto(vector<Contacto>& agenda){//Vector agenda que almacena los contactos (& agenda -> para modificar directamente los datos en agenda)
    //Inicialización de variable nuevoContacto de tipo Contacto
    Contacto nuevoContacto;

    cout << "Nuevo contacto: " << endl;
    cout << "" << endl;

    //Se le pide la informacion del nuevo contacto al usuario
    cout << "Nombre: ";
    getline(cin, nuevoContacto.nombre, '\n');
    cout << "Email: ";
    getline(cin, nuevoContacto.email, '\n');

    //Telefonos para el contacto
    for(int i=0; i<3; i++){
        cout << "Telefono " << i+1 << ": ";
        cin.getline(nuevoContacto.telefonos[i], 50, '\n');

        //No toma los campos de telefono que no se hayan llenado
        if(nuevoContacto.telefonos[i][0] == '\0'){
            break;
        }
    }

    //Direcciones para el contacto
    for(int i=0; i<2; i++){
        cout << "Direccion " << i+1 << ": ";
        cin.getline(nuevoContacto.direcciones[i], 50, '\n');

        //No toma los campos de telefono que no se hayan llenado
        if(nuevoContacto.direcciones[i][0] == '\0'){
            break;
        }
    }

    //Notas para el contacto
    cout << "Notas: " << endl;
    getline(cin, nuevoContacto.notas, '\n');
    cout << "" << endl;
    cout << "Contacto creado exitosamente!" << endl
         << "" << endl;

    agenda.push_back(nuevoContacto); //Agrega el nuevo contacto al vector agenda
}

void mostrarTodosLosContactos(const vector<Contacto>& agenda){ //Se usa como constante para evitar la edicion del vector, y su direccion para evitar la creacion de copias cada iteracion

    if(agenda.empty()){
        cout << "La agenda esta vacía." << endl
             << "" << endl;
    }

    cout << "Contactos:" << endl
         << "" << endl;

    //Cicla por los contactos en agenda
    for(int i=0; i<agenda.size(); i++){
        cout << "Contacto " << i+1 << ":" << endl
             << "" << endl;
        cout << "Nombre: " << agenda[i].nombre << endl;
        cout << "Email: " << agenda[i].email << endl;

        //Impresion de los numero para el contacto
        for(int j=0; j<3; j++){
            if(agenda[i].telefonos[j][0] != '\0'){
                cout << "Telefono " << j+1 << ": " << agenda[i].telefonos[j] << endl;
            }
        }

        //Impresion de las direcciones para el contacto
        for(int j=0; j<2; j++){
            if(agenda[i].direcciones[j][0] != '\0'){
                cout << "Direccion " << j+1 << ": " << agenda[i].direcciones[j] << endl;
            }
        }

        cout << "Notas:" << endl
             << agenda[i].notas << endl
             << "" << endl;
    }
}

int buscarPorNombre(vector<Contacto>& agenda, int *index, string *nombreABuscar){

    *index=0;

    //Cicla entre los contactos
    for(*index; *index<=agenda.size(); (*index)++){

        //Revisa si el nombre existe entre los contactos
        if(agenda[*index].nombre == *nombreABuscar){
            return *index; //El contacto fue encontrado y devuelve su index
        }
    }

    cout << "El contacto no existe." << endl
         << "" << endl;
    return -1; //El contacto no fue encontrado
}

//Funcion encargada de mostrar la información del contacto buscado
void mostrarUnContacto(vector<Contacto>& agenda, const int *index){

    cout << "Contacto " << *index+1 << ":" << endl
         << "" << endl;
    cout << "Nombre: " << agenda[*index].nombre << endl;
    cout << "Email: " << agenda[*index].email << endl;

    //Impresion de los numero para el contacto
    for(int j=0; j<3; j++){
        if(agenda[*index].telefonos[j][0] != '\0'){
            cout << "Telefono " << j+1 << ": " << agenda[*index].telefonos[j] << endl;
        }
    }

    //Impresion de las direcciones para el contacto
    for(int j=0; j<2; j++){
        if(agenda[*index].direcciones[j][0] != '\0'){
            cout << "Direccion " << j+1 << ": " << agenda[*index].direcciones[j] << endl;
        }
    }

    cout << "Notas:" << endl
         << agenda[*index].notas << endl
         << "" << endl;
}

//Funcion encargada de editar la informacion del contacto
void editarContacto(vector<Contacto>& agenda, const int *index) {

    Contacto &contacto = agenda[*index]; //Referencia al contacto con el indice especifico, con el fin de acceder y modificar su información

    //Información nueva para el contacto
    cout << "Contacto " << *index + 1 << ": " << endl
         << "" << endl;
    cout << "Nombre: ";
    getline(cin, contacto.nombre);
    cout << "Email: ";
    getline(cin, contacto.email);

    //Numeros del contacto
    for (int i=0; i<3; i++) {
        cout << "Telefono " << i + 1 << ": ";
        cin.getline(contacto.telefonos[i], 50, '\n');

        //No toma los campos de telefono que no se hayan llenado
        if (contacto.telefonos[i][0] == '\0') {
            break;
        }
    }

    //Direcciones del contacto
    for (int i=0; i<2; i++) {
        cout << "Direccion " << i + 1 << ": ";
        cin.getline(contacto.direcciones[i], 50, '\n');

        //No toma los campos de telefono que no se hayan llenado
        if (contacto.direcciones[i][0] == '\0') {
            break;
        }
    }

    //Notas
    cout << "Notas:" << endl;
    getline(cin, contacto.notas);
    cout << "" << endl
         << "Contacto editado exitosamente!" << endl
         << "" << endl;
}

//Funcion encargada de eliminar el contacto encontrado
void eliminarContacto(vector<Contacto>& agenda, const int* index){

    agenda.erase(agenda.begin() + *index);
    cout << "Contacto eliminado exitosamente!" << endl
         << "" << endl;
}

int main() {
    vector<Contacto> agenda; //Declaracion del vector agenda, tipo: Contacto

    int opcionMenu; //Variable que almacena la opcion del menu digitada por el usuario

    while(true){
        cout << "1) Agregar un contacto." << endl
             << "2) Buscar un contacto." << endl
             << "3) Mostrar todos los contactos." << endl
             << "4) salir." << endl;
        cin >> opcionMenu;

        //El  usuario desea agreagar un contacto
        if(opcionMenu == 1){
            fflush(stdin);
            agregarUnContacto(agenda);

        }

        //El usuario desea encontrar un contacto por su nombre
        if(opcionMenu == 2){
            string nombreABuscar; //Variable que almacena el nombre del contacto que se desea encontrar
            int index; //Variable que almacena el index del contacto que se encontró
            int opcionEditar; //Variable que almacena la opcion del menu de edición digitada por el usuario

            fflush(stdin);
            cout << "Ingrese el nombre del contacto que desea encontrar: ";
            getline(cin, nombreABuscar);

            if(buscarPorNombre(agenda, &index, &nombreABuscar) != -1){
                mostrarUnContacto(agenda, &index);

                //Menu de edición
                cout << "1) Editar contacto." << endl
                     << "2) Eliminar contacto." << endl
                     << "3) Salir al menu principal." << endl
                     << "" << endl;
                cin >> opcionEditar;

                //El usuario desea editar el contacto
                if(opcionEditar == 1){
                    fflush(stdin);
                    editarContacto(agenda, &index);
                }

                //El usuario desea eliminiar el contacto
                if(opcionEditar == 2){
                    eliminarContacto(agenda, &index);
                }
            }
        }

        //El usuario desea ver todos los contactos en la agenda
        if(opcionMenu == 3){
            fflush(stdin);
            mostrarTodosLosContactos(agenda);
        }

        //El usuario desea terminar el programa
        if(opcionMenu == 4){
            break;
        }
    }
    return 0;
}