#include "iostream"
#include "queue"
#include "fstream"
#include "thread"
#include "chrono"
using namespace std;
using namespace std::chrono_literals;

// Funcion responsable de la creacion de archivos
void creacionDeArchivos(queue<string>& archivo, const string& path){

    // Variable que almacena el nombre del archivo
    string nombre;
    // Variable que almacena la cantidad de hojas
    string contenido;

    // Loop para la creacion de archivos consecutivos
    while(true) {
        fflush(stdin);
        cout << "Nombre del archivo: " << endl;
        getline(cin, nombre);

        // Verifica que el nombre no este vacio, en caso tal, sale del loop y deja de crear archivos
        if (nombre.empty()){
            return;
        }

        cout << "Contenido: " << endl;

        fstream myFile;
        myFile.open(path+nombre, ios::out); // Write
        if (myFile.is_open()){
            while (true){
                getline(cin, contenido);

                if (contenido.empty()){
                    break;
                }
                myFile << contenido << endl;
            }
            myFile.close();
            archivo.push(nombre);
        }
    }
}

// Funcion responsable de la impresion
void impresion(queue<string>& archivo, const string& path){
    // Loop que itera por todos los archivos
    while (!archivo.empty()) {
        fflush(stdin);
        string nombre = archivo.front();
        cout << "Titulo: " << nombre << endl;

        ifstream myFile(path+nombre);
        if (myFile.is_open()){
            char character;
            while (myFile.get(character)){
                cout << character;
                this_thread::sleep_for(500ms);
            }
        }
        cout << "" << endl;

        // Eliminacion del archivo
        archivo.pop();
    }
}

int main(){

    // Creacion de la cola de impresion
    queue<string> colaDeImpresion;

    string path = "C:/Users/Usuario/Desktop/archivos/";

    while(true){

        // Creacion de los archivos a imprimir
        creacionDeArchivos(colaDeImpresion, path);

        if (colaDeImpresion.empty()){
            break;
        }

        // Impresion de los archivos
        impresion(colaDeImpresion, path);

    }
}