/*
creamos un nuevo nodo, igual que hicimos para agregar elementos al frente 
 Este nodo tendra un valor que queremos insertar, y asignamos este valor al campo dato del nuevo nodo

Lo siguiente que hacemos es recorrer la lista desde el primer nodo (head) hasta encontrar el ultimo nodo
 El ultimo nodo es aquel que tiene su puntero siguiente apuntando a NULL, porque no hay mas nodos despues de el
 Entonces, creamos un puntero temporal que apunte a head, y empezamos a avanzar nodo por nodo hasta que lleguemos al final

Cuando encontramos el ultimo nodo, hacemos que su puntero siguiente apunte al nuevo nodo que acabamos de crear
 De esta forma, el nuevo nodo queda conectado al final de la lista

Si la lista esta vacia, es decir, si head es NULL, simplemente hacemos que el nuevo nodo se convierta en head

*/


// Retorna el elemento al comienzo

#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};


class ListaEnlazada {
private:
    Nodo* head;

public:
    ListaEnlazada() {
        head = NULL;
    }

    // para agregar un elemento al final de la lista
    void push_back(int valor) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;
        nuevo_nodo->siguiente = NULL; // el nuevo nodo sera el ultimo, por lo que su siguiente es NULL

        if (head == NULL) {
            head = nuevo_nodo; // si la lista esta vacia el nuevo nodo es la nueva head
        } else {
            Nodo* temporal = head;
            while (temporal->siguiente != NULL) {
                temporal = temporal->siguiente; // recorremos la lista hasta el ultimo nodo
            }
            temporal->siguiente = nuevo_nodo; // el ultimo nodo ahora apunta al nuevo nodo
        }
    }

    // para mostrar la lista (para comprobar el resultado)
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

    // agregamos elementos al final de la lista
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    // Mostramos la lista
    lista.mostrar_lista(); 

    return 0;
}
