/*
 primero necesitamos crear un puntero que apunte a head, que es el primer elemento de la lista
 Entonces, al inicio, este puntero se comportara de la siguiente forma.apunta directamente a lo que esté en head, o sea
 el primer nodo de la lista. Si la lista esta vacia, head sera NULL
 y no habra ningún nodo, asi que tenemos que verificar eso

 Luego  este nodo al que apuntamos tiene dos cosas el valor (dato) y un puntero al siguiente nodo (siguiente)
 Ahora, lo que queremos hacer aqui es devolver el valor almacenado en el nodo al que apunta head

antes de eso, si no hay ningun nodo deberiamos devolver algún valor que indique que la lista esta vacia
 como por ejemplo -1, o podemos dar un mensaje de advertencia que diga "La lista esta vacia"

Entonces, para simplificar, estamos creando un puntero que apunta a head, verificamos si head es NULL
 y si no lo es, devolvemos el valor del nodo


*/


// Retorna el elemento al comienzo

#include <iostream>
using namespace std;

// Definimos la estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};


class ListaEnlazada {
private:
    Nodo* cabeza; // puntero a la cabeza (primer nodo) de la lista

public:

    ListaEnlazada() {
        cabeza = NULL; //  al principio la lista esta vacia
    }


    void agregar_frente(int valor) {
        cout << "agregando " << valor << " al frente de la lista " << endl;
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = valor; // asignamos el valor al nodo
        nuevo_nodo->siguiente = cabeza; // el siguiente nodo sera la antigua cabeza
        cabeza = nuevo_nodo; // actualizamos cabeza para que apunte al nuevo nodo
    }

    // para retornar el primer elemento
    int front() {
        // verificamos si la lista esta vacia
        if (cabeza == NULL) {
            cout << "La lista esta vacia " << endl;
            return -1; // valor que indica que la lista esta vacia
        }

        // Devolvemos el valor almacenado en la cabeza
        return cabeza->dato;
    }
};

int main() {
    ListaEnlazada lista;


    lista.agregar_frente(10);
    lista.agregar_frente(20);
    lista.agregar_frente(30);


    cout << "El primer elemento es: " << lista.front() << endl;

    return 0;
}
