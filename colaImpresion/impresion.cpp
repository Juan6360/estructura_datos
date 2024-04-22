#include <unistd.h>
#include "iostream"
#include "queue"
using namespace std;

// Estructura del archivo
struct Archivo{
    string nombre;
    queue<int> hojas;
};

// Funcion responsable de la creacion de archivos
void creacionDeArchivos(queue<Archivo>& archivo){

    // Variable que almacena el nombre del archivo
    string nombre;
    // Variable que almacena la cantidad de hojas
    int hojas;

    // Loop para la creacion de archivos consecutivos
    while(true) {
        fflush(stdin);
        cout << "Nombre del archivo: " << endl;
        getline(cin, nombre);

        // Verifica que el nombre no este vacio, en caso tal, sale del loop y deja de crear archivos
        if (nombre.empty()){
            return;
        }

        cout << "Hojas a imprimir: " << endl;
        cin >> hojas;

        // Variable que almacena el archivo a crear
        Archivo nuevoArchivo;
        nuevoArchivo.nombre = nombre;

        // Creacion de las hojas del archivo
        for (int i = 0; i < hojas; i++) {
            nuevoArchivo.hojas.push(i+1);
        }

        // Se añade a la fila el archivo finalizado
        archivo.push(nuevoArchivo);
    }
}

// Funcion responsable de la impresion
void impresion(queue<Archivo>& archivo){

    // Loop que itera por todos los archivos
    while (!archivo.empty()) {
        fflush(stdin);
        cout << "Titulo: " << archivo.front().nombre << endl;

        // Loop que itera entre las hojas del archivo
        while(!archivo.front().hojas.empty()) {
            fflush(stdin);
            cout << "Imprimiendo pag." << archivo.front().hojas.front() << "..." << endl;

            // Eliminacion de las hojas
            archivo.front().hojas.pop();
            sleep(2);
        }
        cout << "" << endl;

        // Eliminacion del archivo
        archivo.pop();
    }
}

int main(){

    // Creacion de la cola de impresion
    queue<Archivo> colaDeImpresion;

    while(true){

        // Creacion de los archivos a imprimir
        creacionDeArchivos(colaDeImpresion);

        if (colaDeImpresion.empty()){
            break;
        }

        // Impresion de los archivos
        impresion(colaDeImpresion);

    }
}