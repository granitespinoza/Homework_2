/*
creamos un nuevo nodo este nodo va a contener el valor que queremos agregar al frente de la lista
 etoncesasignamos el valor al nodo

este nuevo nodo tiene que apuntar al nodo que actualmente es la cabeza de la lista
 Así que tomamos el puntero siguiente de nuestro nuevo nodo y lo apuntamos a lo que era la cabeza
 Esto significa que el nuevo nodo se pondr al frente, y la antigua cabeza de la lista será el siguiente nodo

luego actualizamos el puntero cabeza para que apunte al nuevo
 ahora la cabeza de la lista es este nuevo nodo
Si la lista estaba vacía (es decir, si cabeza es NULL), no hay que preocuparse, porque el nuevo nodo se convierte
 directamente en la cabeza y no tendrá que apuntar a ningún otro nodo

*/


// void push_front(T); // Agrega un elemento al comienzo
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

    void push_frente(int valor) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor;
        nuevo_nodo->siguiente = heada; // el nuevo nodo apunta a la antigua heada
        heada = nuevo_nodo; // La nueva heada ahora es el nuevo nodo
    }

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

    lista.push_frente(10);
    lista.push_frente(20);
    lista.push_frente(30);

    lista.mostrar_lista();




    return 0;
}
