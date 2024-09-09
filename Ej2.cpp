#include <iostream>
#include "Cola/Cola.h"
using namespace std;

/*Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original*/

void suprimirElementosMayores(Cola<int> &cola, int n)
{
    Cola<int> aux;
    while (!cola.esVacia())
    {
        if (cola.peek() <= n)
        {
            aux.encolar(cola.peek());
        }
        cola.desencolar();
    }
    while (!aux.esVacia())
    {
        cola.encolar(aux.peek());
        aux.desencolar();
    }
}

int main()
{
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(5);
    cola.encolar(4);
    cola.encolar(7);
    cola.encolar(12);
    cola.encolar(3);
    cola.encolar(1);

    suprimirElementosMayores(cola, 5);

    while (!cola.esVacia())
    {
        cout << cola.peek() << " ";
        cola.desencolar();
    }

    return 0;
}
