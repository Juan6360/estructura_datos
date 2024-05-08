

#include "iostream"
using namespace std;

struct Node{
    int dato;
    Node* izq;
    Node* der;
};

Node* creacionNodo(int num){
    Node* nuevoNodo = new Node();
    nuevoNodo->dato = num;
    nuevoNodo->izq = nuevoNodo->der = nullptr;
    return nuevoNodo;
}

Node* copiaDeArbol(Node* &raiz_1){
    Node* raiz_2 = new Node();
    if (raiz_1 == nullptr){
        raiz_2 = nullptr;
    }else {
        raiz_2->dato = raiz_1->dato;
        raiz_2->izq = copiaDeArbol(raiz_1->izq);
        raiz_2->der = copiaDeArbol(raiz_1->der);
    }
    return raiz_2;
}

// preorder
void impresionArbol(Node* raiz){
    if (raiz == nullptr) return;

    cout << raiz->dato << endl;
    impresionArbol(raiz->izq);
    impresionArbol(raiz->der);
}

void inorder(Node* raiz){
    if (raiz == nullptr) return;

    inorder(raiz->izq);
    cout << raiz->dato << endl;
    inorder(raiz->der);
}

void postorder(Node* raiz){
    if (raiz == nullptr) return;

    postorder(raiz->izq);
    postorder(raiz->der);
    cout << raiz->dato << endl;
}

void insertar(Node* &raiz, int num){
    if (raiz == nullptr){
        raiz = creacionNodo(num);
        return;
    }
    if (num == raiz->dato){
        cout << "No se puede ingresar un dato duplicado" << endl;
        return;
    }
    if (num < raiz->dato){
        insertar(raiz->izq, num);
    }else {
        insertar(raiz->der, num);
    }
}

void eliminar(Node* &raiz, int num){
    if (raiz == nullptr){
        cout << "El dato no existe" << endl;
        return;
    }
    if (num == raiz->dato){
        if (raiz->izq == nullptr and raiz->der == nullptr){
            raiz = nullptr;
            return;
        }else if (raiz->der == nullptr){
            raiz = raiz->izq;
            return;
        }else if (raiz->izq == nullptr){
            raiz = raiz->der;
            return;
        }else {
             // Propuesta
        }
    }
    if (num < raiz->dato){
        eliminar(raiz->izq, num);
    }else {
        eliminar(raiz->der, num);
    }
}

int main(){
    Node* raiz_1 = creacionNodo(20);

    // Conjunto Izquierdo del Arbol
    raiz_1->izq = creacionNodo(15);
    raiz_1->izq->izq = creacionNodo(8);
    raiz_1->izq->der = creacionNodo(17);

    // Conjunto Derecho del Arbol
    raiz_1->der = creacionNodo(30);
    raiz_1->der->izq = creacionNodo(25);
    raiz_1->der->der = creacionNodo(40);

    cout << "Arbol #1" << endl;
    impresionArbol(raiz_1);

    cout << " " << endl;

    cout << "Arbol #2 (preorder)" << endl;
    Node* raiz_2 = copiaDeArbol(raiz_1);
    impresionArbol(raiz_2);

    cout << " " << endl;

    cout << "Arbol #1 (inorder)" << endl;
    inorder(raiz_1);

    cout << " " << endl;

    cout << "Arbol #2 (postorder)" << endl;
    postorder(raiz_2);

    cout << " " << endl;

    cout << "Arbol #2 (insercion)" << endl;
    insertar(raiz_2, 7);
    insertar(raiz_2,18);
    insertar(raiz_2, 41);
    impresionArbol(raiz_2);



    cout << " " << endl;

    cout << "Arbol #2 (eliminacion)" << endl;
    eliminar(raiz_2, 7);
    eliminar(raiz_2, 17);
    eliminar(raiz_2, 40);
    impresionArbol(raiz_2);
}


