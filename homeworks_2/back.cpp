/*
creamos un puntero temporal que apunte a la cabeza de la lista, como lo hicimos con front()
 Este puntero va a recorrer la lista desde head hasta encontrar el ultimo nodo
el ultimo nodo es aquel cuyo campo siguiente es NULL,
 lo que significa que no tiene ningun nodo después de el
 Entonces, lo que haremos es mover el puntero desde el primer nodo
 y mientras siguiente no sea NULL, avanzamos al siguiente nodo

Cuando encontramos un nodo cuyo siguiente sea NULL, ese sera nuestro ultimo nodo y simplemente retornamos el valor que contiene

si la lista esta vacia, igual que con front(), tenemos que manejar ese caso y devolver un valor que indique que no hay nodos, como -1
*/

//T back(); // Retorna el elemento al final

#include <iostream>
using namespace std;

// Definimos la estructura de un nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};


class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista

public:

    ListaEnlazada() {
        cabeza = NULL; // La lista empieza vacia
    }

    // metodo para agregar un elemento al frente de la lista
    void agregar_frente(int valor) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;
        nuevo_nodo->siguiente = cabeza;
        cabeza = nuevo_nodo;
    }

    // para retornar el ultimo elemento
    int back() {
        // verificamos si la lista está vacia
        if (cabeza == NULL) {
            cout << "La lista esta vacia." << endl;
            return -1; // Valor que indica que la lista está vacia
        }

        // creamos un puntero temporal para recorrer la lista
        Nodo* temp = cabeza;

        // recorremos la lista hasta que el siguiente nodo sea NULL
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }

        // retornamos el dato del iltimo nodo
        return temp->dato;
    }
};

int main() {
    ListaEnlazada lista;


    lista.agregar_frente(10);
    lista.agregar_frente(20);
    lista.agregar_frente(30);


    cout << "El ultimo elemento es: " << lista.back() << endl;

    return 0;
}
