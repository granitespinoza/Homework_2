/*
 primero que tenemos que hacer es crear un nuevo nodo con el valor que queremos insertar.
 Esto es igual que en las funciones anteriores.

Luego, dependiendo de la posición en la que queramos insertar el nodo, hay dos casos:

Si la posición es el inicio (posición 0), simplemente usamos la misma lógica que en push_frente,
 hacemos que el nuevo nodo apunte a la heada y luego actualizamos heada para que apunte al nuevo nodo.

Si la posición es en cualquier otra parte de la lista, tenemos que recorrer la lista hasta llegar
 a la posición justo anterior a donde queremos insertar. Entonces, creamos un puntero temporal que empieza
 en heada y lo movemos por la lista nodo a nodo hasta que estemos en la posición anterior. Una vez ahí,
 hacemos que el nodo anterior apunte al nuevo nodo, y el nuevo nodo apunte al siguiente.

Si la posición es mayor que el tamaño de la lista, lo mejor sería simplemente agregar el nodo al final.
*/


// Retorna el elemento al comienzo

#include <iostream>
using namespace std;

// Definimos la estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Clase ListaEnlazada
class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero a la cabeza (primer nodo) de la lista

public:
    // Constructor
    ListaEnlazada() {
        cabeza = NULL; // Al principio, la lista esta vacia
    }

    // Método para agregar un elemento al frente de la lista
    void agregar_frente(int valor) {
        cout << "Agregando " << valor << " al frente de la lista." << endl; // Mensaje de depuración
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor; // Asignamos el valor al nodo
        nuevo_nodo->siguiente = cabeza; // El siguiente nodo sera la antigua cabeza
        cabeza = nuevo_nodo; // Actualizamos cabeza para que apunte al nuevo nodo
    }

    // Método front para retornar el primer elemento
    int front() {
        // Verificamos si la lista esta vacia
        if (cabeza == NULL) {
            cout << "La lista esta vacia." << endl;
            return -1; // Valor que indica que la lista esta vacia
        }

        // Devolvemos el valor almacenado en la cabeza
        return cabeza->dato;
    }
};

int main() {
    ListaEnlazada lista;

    // Agregamos elementos a la lista
    lista.agregar_frente(10);
    lista.agregar_frente(20);
    lista.agregar_frente(30);

    // Mostramos el primer elemento
    cout << "El primer elemento es: " << lista.front() << endl;

    return 0;
}
