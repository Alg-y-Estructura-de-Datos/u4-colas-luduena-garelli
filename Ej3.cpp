#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void RemplazarNumero(Cola<int> &datos, int n)
{
    Cola<int> cola_aux;
    int cont = 0;

    while (!datos.esVacia())
    {
        if (datos.peek() == n)
        {
            cont++;
        }
        cola_aux.encolar(datos.desencolar());
    }

    if (cont <= 1)
    {
        while (!cola_aux.esVacia())
        {
            if (cola_aux.peek() != n)
            {
                datos.encolar(cola_aux.desencolar());
            }
            else
            {
                cola_aux.desencolar();
            }
        }
    }
    else
    {
        while (cont >= 1 && !cola_aux.esVacia())
        {
            if (cola_aux.peek() != n || cont <= 1)
            {
                datos.encolar(cola_aux.desencolar());
            }
            else
            {
                cont--;
                cola_aux.desencolar();
            }
        }
    }

}

int main()
{

    Cola<int> datos;
    int dato = 0;
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
