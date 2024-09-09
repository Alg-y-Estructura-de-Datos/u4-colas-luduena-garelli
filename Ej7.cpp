#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Documento
{
  string nombre;
  int paginas;

  Documento(const string &nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

  void mostrar() const
  {
    cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
  }
};

void mostrarCola(Cola<Documento> &datos)
{
  Cola<Documento> cola_aux;
  Documento aux;

  while (!datos.esVacia())
  {
    aux = datos.desencolar();
    cout << "Nombre: " << aux.nombre << "Paginas: " << aux.paginas << endl;
    cola_aux.encolar(aux);
  }

  while (!cola_aux.esVacia())
  {
    datos.encolar(cola_aux.desencolar());
  }
}

int main()
{

  Cola<Documento> colaImpresion;
  int opcion;

  do
  {
    cout << "\n--- Menu de Opciones ---\n";
    cout << "1. Mostrar cola de impresion\n";
    cout << "2. Agregar nuevo documento a la cola\n";
    cout << "3. Imprimir siguiente documento\n";
    cout << "4. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      mostrarCola(colaImpresion);
      break;
    case 2:
      agregarDocumento(colaImpresion);
      break;
    case 3:
      imprimirDocumento(colaImpresion);
      break;
    case 4:
      cout << "Saliendo del programa..." << endl;
      break;
    default:
      cout << "Opción invalida. Intentelo de nuevo." << endl;
      break;
    }
  } while (opcion != 4);

  return 0;
}
