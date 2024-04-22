#include "iostream"
#include "vector"
#include "stack"
using namespace std;

struct Producto {
    string nombre;
    string codigo;
    int precio;
    stack<int> unidades;
};

// Función encargada de imprimir la maquina
void maquina(const vector<Producto>& productos){
    cout << "------------- ------------" << endl;
    cout << "|    " << productos[0].codigo << "    | |    " << productos[1].codigo << "   |" << endl;
    cout << "| " << productos[0].nombre << " | |   " << productos[1].nombre << "  |" << endl;
    cout << "|   " << productos[0].precio << "    | |    " << productos[1].precio << "  |" << endl;
    cout << "------------- ------------" << endl;
    cout << "|    " << productos[2].codigo << "    | |    " << productos[3].codigo << "   |" << endl;
    cout << "|  " << productos[2].nombre << "   | |   " << productos[3].nombre << "  |" << endl;
    cout << "|   " << productos[2].precio << "    | |    " << productos[3].precio << "  |" << endl;
    cout << "------------- ------------" << endl;
    cout << "|    " << productos[4].codigo << "    | |    " << productos[5].codigo << "   |" << endl;
    cout << "|    " << productos[4].nombre << "    | |   " << productos[5].nombre << "  |" << endl;
    cout << "|   " << productos[4].precio << "    | |    " << productos[5].precio << "  |" << endl;
    cout << "------------- ------------" << endl;
}

// Funcion que imprime el menu de usuario
int menuUsuario(){

    // Variable que almacena el codigo digitado por el usuario
    int code;
    cout << "32 -> salir\n101 -> Aumentar unidades" << endl;
    cout << "Ingrese su codigo: ";
    cin >> code;
    cout << "" << endl;

    return code;
}

// Funcion encargada de agregar unidades a productos
void agregarProducto(Producto& producto, int cantidad){

    // Iteración de productos tipo Producto para editar sus unidades
    for (int i = 0; i < cantidad; ++i) {

        // Mejor opción para agregar elementos a un stack durante ejecución
        producto.unidades.emplace(i+1);
    }
}

void sacarUnidad(vector<Producto>& producto, int code){
    producto[code-1].unidades.pop();
}

void aumentarUnidades(vector<Producto>& producto, int codigo, int cantidad){

    // Iteración de productos tipo Producto para editar sus unidades
    for (int i = 0; i < cantidad; ++i) {

        // Mejor opción para agregar elementos a un stack durante ejecución
        producto[codigo-1].unidades.emplace(i+1);
    }
}

int main(){

    // Productos disponibles para venta
    vector<Producto> productos = {
            {"Coca-Cola", "001",1500, stack<int>()},
            {"Pepsi", "002",1600, stack<int>()},
            {"Sprite", "003",2500, stack<int>()},
            {"Fanta", "004",3000, stack<int>()},
            {"Hit", "005",2000, stack<int>()},
            {"Malta", "006",1250, stack<int>()},
    };

    // Llenado de la maquina
    for (auto & p : productos) {
        agregarProducto(p, 6);
    }

    while (true){

        // Impresion de la maquina dispensadora
        maquina(productos);

        //Impresión menu de usuario
        int code = menuUsuario();

        // El usuario desea agregar productos
        if (code == 101){
            int codigoProducto;
            int cantidadDeAumento;

            cout << "Ingrese el codigo del producto: " << endl;
            cin >> codigoProducto;
            cout << "Ingrese la cantidad a agregar: " << endl;
            cin >> cantidadDeAumento;

            // Verifica que haya espacio para agregar unidades del producto
            if ((cantidadDeAumento + productos[codigoProducto-1].unidades.size()) < 6){
                aumentarUnidades(productos, codigoProducto, cantidadDeAumento);
            }else {
                cout << "No hay espacio suficiente" << endl;
            }
        }

        // Verifica que el codigo ingresado por el usuario sea valido
        if (code >= 1 and code <= 6){

            // Verifica que el stack no este vacio
            if (!productos[code-1].unidades.empty()){
                // Sustrae una unidad del elemento escogido
                sacarUnidad(productos, code);
            }else {
                cout << "No quedan unidades disponibles." << endl;
            }
        }else{
            cout << "Codigo invalido" << endl;
        }

        if (code == 0){
            break;
        }
    }
}