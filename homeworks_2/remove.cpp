/*
 eliminar un nodo de la lista enlazada en una posición específica
 lo primero que tenemos que hacer es verificar si la lista está vacía
 porque si está vacía no podemos eliminar nada
 luego si la posición es 0 eso significa que queremos eliminar el primer nodo
 En este caso, simplemente hacemos que heada apunte al segundo nodo y eliminamos el primer nodo

 si la posición es cualquier otra, tenemos que recorrer la lista hasta llegar
 al nodo anterior al que queremos eliminar. Una vez que estamos en ese nodo
 hacemos que su puntero siguiente apunte al nodo después del que queremos eliminar
 y eliminamos el nodo en la posición indicada.



*/


// Retorna el elemento al comienzo
#include <iostream>
using namespace std;

// Definimos la estructura de un nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};


class ListaEnlazada {
private:
    Nodo* heada;

public:
    ListaEnlazada() {
        heada = NULL;
    }

    //  para agregar al frente (para propósitos de prueba)
    void push_front(int valor) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;
        nuevo_nodo->siguiente = heada;
        heada = nuevo_nodo;
    }

    //  para remover un nodo en cualquier posición
    void remove(int posicion) {
        if (heada == NULL) {
            cout << "La lista esta vacia, no hay nada que remover." << endl;
            return;
        }

        if (posicion == 0) {
            // Eliminar el primer nodo
            Nodo* temp = heada;
            heada = heada->siguiente;
            delete temp;



        } else {
            // Recorremos la lista hasta el nodo anterior al que queremos eliminar
            Nodo* temporal = heada;
            int contador = 0;

            while (temporal != NULL && contador < posicion - 1) {
                temporal = temporal->siguiente;
                contador++;
            }

            // Si llegamos a una posición válida eliminamos el nodo
            if (temporal != NULL && temporal->siguiente != NULL) {
                Nodo* nodo_a_eliminar = temporal->siguiente;
                temporal->siguiente = nodo_a_eliminar->siguiente;
                delete nodo_a_eliminar;
            } else {
                cout << "Posicion fuera de rango." << endl;
            }
        }
    }

    //  para mostrar la lista (para comprobar el resultado)
    void mostrar_lista() {
        Nodo* temporal = heada;
        while (temporal != NULL) {
            cout << temporal->dato << " -> ";
            temporal = temporal->siguiente;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEnlazada lista;


    lista.push_front(10);
    lista.push_front(20);
    lista.push_front(30);


    cout << ": ";
    lista.mostrar_lista(); // : 30 -> 20 -> 10 -> NULL


    lista.remove(1);
    cout << ": ";
    lista.mostrar_lista(); // : 30 -> 10 -> NULL

    return 0;
}
