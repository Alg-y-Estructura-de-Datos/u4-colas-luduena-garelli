#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool CompararColas(Cola<int> cola1, Cola<int> cola2)
{
    while (!cola1.esVacia() && !cola2.esVacia())
    {
        if (cola1.peek() == cola2.peek())
        {
            cola1.desencolar();
            cola2.desencolar();
        }
        else
        {
            return false;
        }
    }
    return cola1.esVacia() && cola2.esVacia();
}

int main()
{

    Cola<int> Cola1, Cola2;
    Cola1.encolar(1);
    Cola1.encolar(2);
    Cola1.encolar(3);
    Cola1.encolar(4);
    Cola1.encolar(5);

    Cola2.encolar(1);
    Cola2.encolar(2);
    Cola2.encolar(3);
    Cola2.encolar(4);
    Cola2.encolar(5);

    if (CompararColas(Cola1, Cola2))
    {
        cout << "Las colas son iguales" << endl;
    }
    else
    {
        cout << "Las colas son diferentes" << endl;
    }
    return 0;
}
