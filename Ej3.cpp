#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void RemplazarNumero(Cola<int> &datos, int n)
{
    Cola<int> cola_aux;
    int cont;

    while (!datos.esVacia())
    {
        if (datos.peek() == n)
        {
            cont++;
        }
        cola_aux.encolar(datos.desencolar());
    }
    while (!cola_aux.esVacia())
    {
        if (cola_aux.peek() != n || cont <= 1)
        {
            datos.encolar(cola_aux.desencolar());
        }
        else
        {
            cont--;
        }
    }
}

int main()
{

    Cola<int> datos;
    int dato;
    while (dato >= 0)
    {
        cout << "Ingrese un numero mayor o igual a 0: ";
        cin >> dato;
        datos.encolar(dato);
    }
    RemplazarNumero(datos, 5);

    while (!datos.esVacia())
    {
        cout << datos.peek() << " ";
        datos.desencolar();
    }
    return 0;
}
