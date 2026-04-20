#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

Nodo* head = NULL;
Nodo* tail = NULL;

void insertarInicio(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head != NULL)
        head->anterior = nuevo;
    else
        tail = nuevo;

    head = nuevo;
}


void insertarFinal(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

    if (tail != NULL)
        tail->siguiente = nuevo;
    else
        head = nuevo; 

    tail = nuevo;
}


void mostrarAdelante() {
    Nodo* actual = head;
    cout << "\nLista hacia adelante: ";
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}


void mostrarAtras() {
    Nodo* actual = tail;
    cout << "\nLista hacia atras: ";
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->anterior;
    }
    cout << "NULL\n";
}


void buscar(int valor) {
    Nodo* actual = head;
    int pos = 1;
    while (actual != NULL) {
        if (actual->dato == valor) {
            cout << "Encontrado en posicion: " << pos << endl;
            return;
        }
        actual = actual->siguiente;
        pos++;
    }
    cout << "No encontrado\n";
}


void eliminar(int valor) {
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor)
        actual = actual->siguiente;

    if (actual == NULL) {
        cout << "Valor no encontrado\n";
        return;
    }


    if (actual == head)
        head = actual->siguiente;


    if (actual == tail)
        tail = actual->anterior;

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;

    delete actual;
    cout << "Nodo eliminado\n";
}


void contarNodos() {
    Nodo* actual = head;
    int contador = 0;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    cout << "Total nodos: " << contador << endl;
}


void liberarLista() {
    Nodo* actual = head;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}


int main() {
    int opcion, valor;
	cout <<"Codigo mejorado por JAVIER DAVID RODRIGUEZ ROSALES 9941-24-71";
    do {
        cout << "\n1.Insertar inicio";
        cout << "\n2.Insertar final";
        cout << "\n3.Mostrar adelante";
        cout << "\n4.Mostrar atras";
        cout << "\n5.Buscar";
        cout << "\n6.Eliminar";
        cout << "\n7.Contar nodos";
        cout << "\n8.Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Valor: ";
            cin >> valor;
            insertarInicio(valor);
            break;
        case 2:
            cout << "Valor: ";
            cin >> valor;
            insertarFinal(valor);
            break;
        case 3:
            mostrarAdelante();
            break;
        case 4:
            mostrarAtras();
            break;
        case 5:
            cout << "Valor a buscar: ";
            cin >> valor;
            buscar(valor);
            break;
        case 6:
            cout << "Valor a eliminar: ";
            cin >> valor;
            eliminar(valor);
            break;
        case 7:
            contarNodos();
            break;
        case 8:
            liberarLista();
            cout << "Programa finalizado\n";
            break;
        }
    } while (opcion != 8);

    return 0;
}