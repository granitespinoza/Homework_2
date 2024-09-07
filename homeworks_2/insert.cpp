/*
 primero que tenemos que hacer es crear un nuevo nodo con el valor que queremos insertar
 Esto es igual que en las funciones anteriores

Luego, dependiendo de la posicion en la que queramos insertar el nodo, hay dos casos
Si la posicion es el inicio (posicion 0), simplemente usamos la misma logica que en push_frent

 hacemos que el nuevo nodo apunte a la head y luego actualizamos head para que apunte al nuevo nodo
Si la posicion es en cualquier otra parte de la lista, tenemos que recorrer la lista hasta llegar

 a la posicion justo anterior a donde queremos insertar. entonces creamos un puntero temporal que empieza
 en head y lo movemos por la lista nodo a nodo hasta que estemos en la posicion anterior una vez ahi
 hacemos que el nodo anterior apunte al nuevo nodo, y el nuevo nodo apunte al siguiente



*/


// Retorna el elemento al comienzo
#include <iostream>
using namespace std;

// Definimos la estructura de un nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Clase ListaEnlazada
class ListaEnlazada {
private:
    Nodo* head;

public:
    ListaEnlazada() {
        head = NULL;
    }

    // para insertar un elemento en cualquier posicion
    void insert(int valor, int posicion) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;

        if (posicion == 0) {
            // Insertar al inicio
            nuevo_nodo->siguiente = head;
            head = nuevo_nodo;

        } else {
            // Insertar en cualquier otra posicion
            Nodo* temporal = head;
            int contador = 0;

            // recorremos hasta el nodo anterior a la posicion deseada
            while (temporal != NULL && contador < posicion - 1) {
                temporal = temporal->siguiente;
                contador++;
            }

            // si encontramos la posicion correcta, insertamos el nodo
            if (temporal != NULL) {
                nuevo_nodo->siguiente = temporal->siguiente;
                temporal->siguiente = nuevo_nodo;
            } else {
                cout << "posicion fuera de rango. Insertando al final." << endl;
                push_back(valor); // Si la posicion está fuera de rango, lo agregamos al final
            }
        }
    }

    //  para agregar al final (usado en el caso de posicion fuera de rango)
    void push_back(int valor) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;
        nuevo_nodo->siguiente = NULL;

        if (head == NULL) {
            head = nuevo_nodo;
        } else {
            Nodo* temporal = head;
            while (temporal->siguiente != NULL) {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = nuevo_nodo;
        }
    }

    //  para mostrar la lista (para comprobar el resultado)
    void mostrar_lista() {
        Nodo* temporal = head;
        while (temporal != NULL) {
            cout << temporal->dato << " -> ";
            temporal = temporal->siguiente;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEnlazada lista;


    lista.insert(10, 0); // al inicio
    lista.insert(20, 1); // al final
    lista.insert(30, 1); // en la posicion 1
    lista.insert(40, 3); // insertar fuera de rango (se agrega al final)


    lista.mostrar_lista(); // deberia mostrar: 10 -> 30 -> 20 -> 40 -> NULL

    return 0;
}
